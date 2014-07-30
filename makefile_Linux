CPP = g++
FLAGS = -Wall -g -std=c++11

all: main

main: main.o Solver.o Parser.o PuzzleClass.o PossibilitiesSquare.o
	$(CPP) $(FLAGS) -o main main.o Solver.o Parser.o PuzzleClass.o PossibilitiesSquare.o
main.o: main.cpp Solver.hpp Parser.hpp PuzzleClass.hpp PossibilitiesSquare.hpp
	$(CPP) $(FLAGS) -c main.cpp 
Solver.o: Solver.cpp Solver.hpp PuzzleClass.hpp PuzzleClass.cpp PossibilitiesSquare.hpp PossibilitiesSquare.cpp
	$(CPP) $(FLAGS) -c Solver.cpp
Parser.o: Parser.hpp Parser.cpp PuzzleClass.hpp PuzzleClass.cpp
	$(CPP) $(FLAGS) -c Parser.cpp
PuzzleClass.o: PuzzleClass.cpp PuzzleClass.hpp PuzzleClass.cpp PossibilitiesSquare.hpp PossibilitiesSquare.cpp
	$(CPP) $(FLAGS) -c PuzzleClass.cpp
PossibilitiesSquare.o: PossibilitiesSquare.cpp PossibilitiesSquare.hpp PuzzleClass.hpp PuzzleClass.cpp
	$(CPP) $(FLAGS) -c PossibilitiesSquare.cpp

clean:
	rm -rf main *.o