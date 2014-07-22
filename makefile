CXX = g++
FLAGS = -Wall -g -std=c++11

main: Parser.o PuzzleClass.o main.o
	$(CXX) $(FLAGS) -o Parser.o PuzzleClass.o main.o
main.o: main.cpp Parser.h PuzzleClass.h
	$(CXX) $(FLAGS) -c main.cpp
Parser.o: Parser.cpp Parser.h
	$(CXX) $(FLAGS) -c Parser.cpp
PuzzleClass.o: PuzzleClass.h PuzzleClass.cpp
	$(CXX) $(FLAGS) -c PuzzleClass.cpp

clean:
	rm *.o