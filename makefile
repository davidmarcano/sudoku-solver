CPP = g++
FLAGS = -Wall -g -std=c++11

all: main.exe

main.exe: Parser.obj PuzzleClass.obj main.obj
	$(CPP) $(FLAGS) -o main.exe Parser.obj PuzzleClass.obj main.obj
main.obj: main.cpp Parser.hpp PuzzleClass.hpp
	$(CPP) $(FLAGS) -o main.obj -c main.cpp
Parser.obj: Parser.cpp Parser.hpp
	$(CPP) $(FLAGS) -o Parser.obj -c Parser.cpp
PuzzleClass.obj: PuzzleClass.hpp PuzzleClass.cpp
	$(CPP) $(FLAGS) -o PuzzleClass.obj -c PuzzleClass.cpp

clean:
	rm -rf main.exe \*.obj