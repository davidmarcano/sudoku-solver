#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include "Parser.hpp"



void Parser::ParseInput(std::ifstream * file, PuzzleClass * puzzle) {
	//char * line = new char;
	//char * begin = line;

	//bool endFlag;
	std::string buffer;
	char * realBuffer;
	int j = 0;
	int i = 0;
	int * result;
	while (!(file->eof())) {
		getline((*file), buffer);
		std::cout << buffer << std::endl;
		std::strcpy(realBuffer, buffer.c_str());

		while ((*realBuffer) != '\0') {
			//convert from string to int.
			convert(result[j], (*realBuffer)); //must figure out a way to store each digit in int*
			//Have to change result to int*
			//puzzle->insertIntoRowOfSquares(result, puzzle->GetPuzzle()[j]);
			realBuffer++;
			j++;
		}
		puzzle->insertIntoRowOfSquares(result, (puzzle->GetPuzzle())[i]);
		i++;
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



int Parser::convert(int & result, char singleChar) {
	
	result = singleChar - 48;

	if ((0 < result) && (result < 9)) {
		return result;
	}
	else {
		std::cout << "invalid input" << std::endl;
		result = 0;
		return result;
	}

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