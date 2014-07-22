#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "Parser.h"


void Parser::ParseInput(FILE * file) {
	std::string line = Parser::getLine(file);
	std::cout << line << std::endl;
	//Check for validity via a helper function
	//Change the string values to integer values
	//Put values into array
}

std::string Parser::getLine(FILE * file) {
	char c;
	char * cline;
	std::string line = "";
	while ((c = getc(file)) != EOF || (c != '\n')) {
		(*cline) = c;
		cline++;
	}
	
	(*cline) = '\0';
	return line.append(cline);
}
	

	bool Parser::checkValidity() {
		return false;
	}
