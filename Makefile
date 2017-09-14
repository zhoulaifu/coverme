BVA_ROOT := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
ifdef BVA_FUNC 
   $(shell echo $(BVA_FUNC) > BVA_FUNC.txt)
endif
ifdef BVA_FILE
   $(shell echo $(BVA_FILE) > BVA_FILE.txt)
endif
ifdef BVA_TYPE
   $(shell echo $(BVA_TYPE) > BVA_TYPE.txt)
endif

BVA_FUNC:= $(shell cat BVA_FUNC.txt)
BVA_FILE:= $(shell cat BVA_FILE.txt) 
BVA_TYPE:= $(shell cat BVA_TYPE.txt)

file := theBench.txt
ifdef bench
  $(shell echo $(bench) > $(file))
endif


bva_option?=-S0 -n5 -N500

bench := $(shell cat ${file})
#BVA_FUNC?=__ieee754_j0
#BVA_FILE?=benchs/fdlibm53/e_j0.c
compilation_level?=-O0


LIBM := benchs/libm_c_ieee.a
Include := -I $(BVA_ROOT)/include -I $(BVA_ROOT)/$(dir $(BVA_FILE)) 


define BVA_echo
	@echo "[DONE] $1 "
endef
CXX := g++ -fPIC -std=c++11
CXXFLAGS := -fno-rtti -O0 -g
CC := clang -fPIC
.PHONY: default clean 

all: copy pass instrument representing_function test

debug: DB = -DDEBUG -g 
debug: all
hello:
	echo "hello, world"

# create .bc from source
%.bc:	%.c
	$(CC)  $(DB) $< -c -emit-llvm  -o $@ $(Include)

# create human-readable assembly (.ll) from .bc
%.ll: %.bc
	llvm-dis -f $^

%.o: %.bc
	$(CC)    $(CXXFLAGS)   -c      -o $@    $<


copy: build/loader.cpp build/loader.py build/test.cpp build/foo_raw.c build/cov.c
	$(BVA_echo) Copy some dependencies  
build/foo_raw.c: $(BVA_FILE)
	@mkdir -p build
	cp $^ $@
build/loader.py: src/Type_$(BVA_TYPE)/loader.py
	@mkdir -p build
	cp $^ $@
build/loader.cpp: src/Type_$(BVA_TYPE)/loader.cpp
	@mkdir -p build
	cp $^ $@
build/test.cpp: src/Type_$(BVA_TYPE)/test.cpp
	@mkdir -p build
	cp $^ $@
build/cov.c: src/Type_$(BVA_TYPE)/cov.c
	@mkdir -p build
	cp $^ $@
instrument: build/foo_i.bc 
	$(BVA_echo) The instrumented program in LLVM bitcode: $< 
build/foo_i.bc : build/foo_raw.bc 
	opt -lowerswitch $< -o $<
	opt -load lib/libATGMO.so -hello2 -funcname=$(BVA_FUNC) < $<  -o $@

pass: lib/libATGMO.so 
	$(BVA_echo) The shared library of the LLVM transformation pass: $<
lib/libATGMO.so: build/ATGMO.o
	@mkdir -p lib
	$(CXX)  $(CXXFLAGS) $(DB) $< -Wall -shared -o $@ -fPIC $(Include)
build/ATGMO.o: src/ATGMO.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $(DB) $< -Wall -c -fno-rtti  `llvm-config --cppflags` -g -fPIC -o $@  $(Include)

#Put penalty wraper and the instrumented code together (so we have a double->double representing function)
representing_function: build/libr.so 
	$(BVA_echo) The shared library for the representing function: $<
build/libr.so: lib/pen.o lib/r.o build/foo_i.o build/loader.o benchs/libm_c_ieee.a #the last one is for fdlibm only
	$(CXX) $(CXXFLAGS) $(DB) $^ -Wall -shared -o $@ $(Include)
lib/r.o: src/r.cpp
	$(CXX) $(CXXFLAGS) $(DB) -c $^ -o $@ $(Include)
lib/pen.o: src/pen.cpp
	$(CXX) $(CXXFLAGS) $(DB) -c $^ -o $@ $(Include)



# A very simple test. Usage: LD_LIBRARY_PATH=build build/simple_test
test: build/simple_test
	$(BVA_echo) Making sanity test 
build/simple_test: build/test.o
	g++ -std=c++11 $(DB) $< -Wall  -lr -L build  -lm  -o $@ $(Include)
build/test.o: build/test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


run_test: build/simple_test
	LD_LIBRARY_PATH=build/ $<
clean:
	rm -rf build/*
	rm -rf lib/* 
	rm -rf output/*

#for debug purpose

diff: build/foo_raw.ll build/foo_i.ll
	diff -u $^  
benchmark: all
	python src/mcmc.py 
	make gcov_bva;\
	make gcov_rand
br:
	cat output/brInfo.txt
gcov_bva: $(BVA_ROOT)/build/cov.c $(BVA_ROOT)/build/foo_raw.c $(BVA_ROOT)/$(LIBM)
	cd build;\
	gcc -DROOT=\"$(BVA_ROOT)\" -DFUNC=$(BVA_FUNC) $^ -fno-builtin-$(BVA_FUNC) -fprofile-arcs -ftest-coverage  -o cov $(Include);\
	./cov 0;\
	echo   ;\
	gcov -f $(BVA_ROOT)/build/foo_raw.c -b
gcov_rand: $(BVA_ROOT)/build/cov.c $(BVA_ROOT)/build/foo_raw.c $(BVA_ROOT)/$(LIBM)
	cd build;\
	gcc  -DROOT=\"$(BVA_ROOT)\" -DFUNC=$(BVA_FUNC) $^ -fno-builtin-$(BVA_FUNC) -fprofile-arcs -ftest-coverage  -o cov $(Include);\
	./cov 1;\
	echo   ;\
	gcov -f $(BVA_ROOT)/build/foo_raw.c -b
