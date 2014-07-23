#ifndef _PARSER_H
#define _PARSER_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <fstream>
#include "PuzzleClass.hpp"

class Parser{
	private:
	int Array[9] = {0};
	
	public:
		void ParseInput(std::ifstream *, PuzzleClass *);

		void insertIntoSquare(int, PossibilitiesSquare*, int);

		int convert(int, std::string);

		bool getLine(std::ifstream *, char *);

		bool checkValidity();

};

#endif