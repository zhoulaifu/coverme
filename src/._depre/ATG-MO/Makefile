
# add optLoads.o to the following line when ready
LIB=libHello.so
OBJS = Hello.o 


$(t_ATG-MO): $(OBJS)

	g++ $(OBJS) -shared -o $@ -fPIC

%.o: %.cpp
	g++ -c -fno-rtti -std=c++11 `llvm-config --cppflags` -g -fPIC $< -o $@

clean:
	rm -f $(LIB) $(OBJS)

