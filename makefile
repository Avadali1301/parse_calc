parseAndCalc: parseAndCalc.o tree.o stack.o calculate.o
	g++ -o parseAndCalc tree.o parseAndCalc.o stack.o calculate.o
stack.o: stack.cc
	g++ -c stack.cc
calculate.o: calculate.h calculate.cc stack.cc
	g++ -c calculate.cc
tree.o: tree.h tree.cc calculate.h
	g++ -c tree.cc
parseAndCalc.o: parseAndCalc.cc tree.h
	g++ -c parseAndCalc.cc
clean:
	rm -rf stack.o calculate.o tree.o parseAndCalc.o parseAndCalc