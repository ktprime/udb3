all:run-test run-test-ens

run-test:test.cpp ../common.c
	$(CXX) -O3 -Wall -std=c++17 -DNO_PARALLEL $< -o $@

run-test-ens:test.cpp ../common.c
	$(CXX) -O3 -Wall -std=c++17 $< -o $@

clean:
	rm -f run-test run-test-ens
