test: main.o Tree.o
	g++ main.o Tree.o -o test

main.o: main.cpp
	g++ -Wall -Werror -std=c++17 main.cpp -c
Tree.o: Tree.cpp
	g++ -Wall -Werror -std=c++17 Tree.cpp -c

clean:
	rm -f *.o
	rm -f test