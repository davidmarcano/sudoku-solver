CPP = g++
FLAGS = -Wall -g -std=c++11

all: main.exe

main.exe: main.obj Solver.obj Parser.obj PuzzleClass.obj PossibilitiesSquare.obj
	$(CPP) $(FLAGS) -o main.exe main.obj Solver.obj Parser.obj PuzzleClass.obj PossibilitiesSquare.obj
main.obj: main.cpp Solver.hpp Parser.hpp PuzzleClass.hpp PossibilitiesSquare.hpp
	$(CPP) $(FLAGS) -o main.obj -c main.cpp 
Solver.obj: Solver.cpp Solver.hpp PuzzleClass.hpp PuzzleClass.cpp PossibilitiesSquare.hpp PossibilitiesSquare.cpp
	$(CPP) $(FLAGS) -o Solver.obj -c Solver.cpp
Parser.obj: Parser.hpp Parser.cpp PuzzleClass.hpp PuzzleClass.cpp
	$(CPP) $(FLAGS) -o Parser.obj -c Parser.cpp
PuzzleClass.obj: PuzzleClass.cpp PuzzleClass.hpp PuzzleClass.cpp PossibilitiesSquare.hpp PossibilitiesSquare.cpp
	$(CPP) $(FLAGS) -o PuzzleClass.obj -c PuzzleClass.cpp
PossibilitiesSquare.obj: PossibilitiesSquare.cpp PossibilitiesSquare.hpp PossibilitiesSquare.cpp PuzzleClass.hpp PuzzleClass.cpp
	$(CPP) $(FLAGS) -o PossibilitiesSquare.obj -c PossibilitiesSquare.cpp

clean:
	rm -rf main.exe *.obj	