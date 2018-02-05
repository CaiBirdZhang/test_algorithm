c=g++ -std=c++11
exe: main.o
	$c -o $@ $^ -g

main.o: main.cpp bst.h
	$c -c $<


clean:
	rm -rf exe *.o
