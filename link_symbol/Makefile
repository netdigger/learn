all: test.out  test1.out

touch_event.o: touch_event.cpp
	c++ -fPIC -c touch_event.cpp -o touch_event.o

key_event.o: key_event.cpp
	c++ -fPIC -c key_event.cpp -o key_event.o

libsgui-static.a: touch_event.o key_event.o
	ar qc libsgui-static.a touch_event.o key_event.o

libsgui.so: touch_event.o key_event.o 
	c++ -shared -fPIC touch_event.o key_event.o -o libsgui.so

libqvfb.so: qvfb.cpp
	c++ -shared -fPIC qvfb.cpp -o libqvfb.so

archive = -Wl,--whole-archive -lsgui-static -Wl,--no-whole-archive 

test.out: main.cpp libsgui-static.a libqvfb.so
	c++ main.cpp -I. -L. -Wl,-export-dynamic $(archive) -ldl -o test.out

test1.out: main.cpp libsgui.so libqvfb.so
	c++ main.cpp -I. -L. -lsgui -ldl -Wl,-rpath=. -o test1.out

clean:
	rm *.o *.a *.so *.out
