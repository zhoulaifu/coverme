.PHONY: gcov_bva gcov_rand clean lno

#gcov for bva
gcov_bva: 
	cp ../foo.c .
	gcc cov_2d.c foo.c libm.a -fprofile-arcs -ftest-coverage -o cov
	./cov 0
	gcov foo.c -b
#gcov for rand
gcov_rand:
	@echo "First copy foo.c from ../"
	cp ../foo.c .

	gcc cov_2d.c foo.c libm.a -fprofile-arcs -ftest-coverage -o cov
	./cov 1
	gcov foo.c -b

lno: 
	cp ../foo.c .
	clang foo.c -c -emit-llvm -o foo.bc
	opt -stats -analyze -instcount foo.bc

clean:
	rm -f *.gcno *.gcda *.gcov *.bc *.o

