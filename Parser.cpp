#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "Parser.hpp"


void Parser::ParseInput(FILE * file) {
	std::string * line = new std::string;

	bool endFlag;

	while (!(endFlag = Parser::getLine(file, line))) {
		std::cout << *line << std::endl;
		line->clear();
	} 
	
	//print the last line
	std::cout << (*line) << std::endl;
	//Check for validity via a helper function
	//Change the string values to integer values
	//Put values into array
}

//returns true for EOF, false otherwise
bool Parser::getLine(FILE * file, std::string *line) {
	char c;
	int i = 0;
	bool endFlag = false;
	char * cline = new char;


	while (((c = getc(file)) != EOF) && (c != '\n')) {
		(*cline) = c;
		cline++;
		i++;
	}
	if (c == EOF) {
		endFlag = true;
	}
	
	(*cline) = '\0';
	line->append(cline - i);
	return endFlag;
}
	

	bool Parser::checkValidity() {
		return false;
	}
