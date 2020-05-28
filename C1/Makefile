all: main clean

main: main.o
	g++ -o main main.cpp

main.o: main.cpp
	g++ -c main.cpp

generate: generate_array.cpp
	g++ -o generate generate_array.cpp

clean:
	rm -f *.o
