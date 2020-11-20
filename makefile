prog1: prog1.cc
	g++ -g -Wall -o prog1 prog1.cc

#used for testing current program utilizing testcase1.txt.
#rebuilds before running testcase
test:
	make
	./prog1 testcase1.txt

clean:
	-rm prog1