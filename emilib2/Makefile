all:run-test1 run-test2 run-test run-test-ens1 run-test-ens2 run-test-ens

run-test1:test1.cpp ../common.c
	$(CXX) -O3 -Wall -std=c++17 $< -o $@

run-test2:test2.cpp ../common.c
	$(CXX) -O3 -Wall -std=c++17 $< -o $@

run-test:test.cpp ../common.c
	$(CXX) -O3 -Wall -std=c++17 $< -o $@

run-test-ens1:test-ens1.cpp ../common.c
	$(CXX) -O3 -Wall -std=c++17 $< -o $@

run-test-ens2:test-ens2.cpp ../common.c
	$(CXX) -O3 -Wall -std=c++17 $< -o $@

run-test-ens:test-ens.cpp ../common.c
	$(CXX) -O3 -Wall -std=c++17 $< -o $@

clean:
	rm -f run-test*
