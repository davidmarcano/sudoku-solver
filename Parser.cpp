#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Parser.hpp"



void Parser::ParseInput(std::ifstream * file, PuzzleClass * puzzle) {
	//char * line = new char;
	//char * begin = line;

	//bool endFlag;
	std::string buffer;

	int j = 0;
	int result;
	while (!(file->eof())) {
		getline((*file), buffer);
		std::cout << buffer << std::endl;
		//convert from string to int.
		convert(result, buffer); //must figure out a way to store each digit in int*
		puzzle->insertIntoSquare(result, puzzle->GetPuzzle()[j]);
		j++;
	}
	/*while (!(endFlag = Parser::getLine(file, line))) {
		begin = line;
		std::cout << begin << std::endl;
	} 
	
	//print the last line
	std::cout << begin << std::endl;*/
	//Check for validity via a helper function
	//Change the string values to integer values
	//Put values into array
}



int Parser::convert(int result, std::string buffer) {
	std::stringstream convertion (buffer);

	if (!(convertion >> result)) {
		result = 0;
	}
	return result;

}
//returns true for EOF, false otherwise
/*bool Parser::getLine(std::ifstream * file, char * line) {
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

	line = (cline - i);
	return endFlag;
}
	

	bool Parser::checkValidity() {
		return false;
	}
*/