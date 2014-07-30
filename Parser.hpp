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
	int initializationCounter = 0;
	
	public:

		int GetinitializationCounter();

		void ParseInput(std::ifstream *, PuzzleClass *);

		int convert(int &, char);

		bool getLine(std::ifstream *, char *);

		bool checkValidity();

};

#endif //_PARSER_H