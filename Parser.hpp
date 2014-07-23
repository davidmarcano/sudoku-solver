#ifndef _PARSER_H
#define _PARSER_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

class Parser{
	private:
	int Array[9] = {0};
	
	public:
		void ParseInput(FILE *);

		bool getLine(FILE *, std::string *);

		bool checkValidity();

};

#endif