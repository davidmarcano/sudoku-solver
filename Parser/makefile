CPP = g++
FLAGS = -Wall -g -std=c++11

all: main.exe

main.exe: Parser.obj
	$(CPP) $(FLAGS) -o main.exe Parser.obj
main.obj: main.cpp Parser.hpp
	$(CPP) $(FLAGS) -o main.obj -c main.cpp
Parser.obj: Parser.cpp Parser.hpp
	$(CPP) $(FLAGS) -o Parser.obj -c Parser.cpp

clean:
	rm -rf main. *.obj