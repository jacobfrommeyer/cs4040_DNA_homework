prog1: prog1.cc
	g++ -g -Wall -o prog1 prog1.cc

#used for testing current program utilizing testcase files.
#rebuilds before running testcase
test:
	make

	./prog1 testcase1.txt
	./prog1 testcase2.txt
	./prog1 testcase3.txt
	./prog1 testcase4.txt
	./prog1 testcase5.txt
	./prog1 testcase6.txt
	./prog1 testcase7.txt

clean:
	-rm prog1