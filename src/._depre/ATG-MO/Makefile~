DEBUG = ../../Debug/lib
# add optLoads.o to the following line when ready
OBJS = printCode.o 

$(DEBUG)/P1.so: $(OBJS)
	mkdir -p $(DEBUG)
	g++ $(OBJS) -shared -o $@ -fPIC

%.o: %.cpp
	g++ -c -fno-rtti `llvm-config --cppflags` -g -fPIC $< -o $@

clean:
	rm -f $(DEBUG)/P1.so $(OBJS)
