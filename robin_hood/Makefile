all:run-test

run-test:test.cpp ../common.c robin_hood.h
	$(CXX) -O3 -Wall -std=c++17 $< -o $@

clean:
	rm -f run-test
