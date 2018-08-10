ALL: test.out

test.out: main.cpp TestA_test.cpp
	g++ -o test.out main.cpp TestA_test.cpp -lgtest -pthread

CLEAN:
	rm *.o *.out
