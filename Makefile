main: input.o compare.o output.o main.o
	g++ -o main input.o compare.o output.o main.o -g
input.o: input.cpp
	g++ -c -o input.o input.cpp
compare.o: compare.cpp
	g++ -c -o compare.o compare.cpp
output.o: output.cpp
	g++ -c -o output.o output.cpp
main.o: main.cpp
	g++ -c -o main.o main.cpp
clean:
	rm *.o main