CXX = g++
FLAGS = -Wall -g -std=c++11

main: Parser.o PuzzleClass.o main.o
	$(CXX) $(FLAGS) -o main Parser.o PuzzleClass.o main.o
main.o: main.cpp Parser.hpp PuzzleClass.hpp
	$(CXX) $(FLAGS) -c main.cpp
Parser.o: Parser.cpp Parser.hpp
	$(CXX) $(FLAGS) -c Parser.cpp
PuzzleClass.o: PuzzleClass.hpp PuzzleClass.cpp
	$(CXX) $(FLAGS) -c PuzzleClass.cpp

clean:
	rm main *.o