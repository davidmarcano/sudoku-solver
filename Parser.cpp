#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include "Parser.hpp"

int Parser::GetinitializationCounter(){
	return initializationCounter;
}

void Parser::ParseInput(std::ifstream * file, PuzzleClass * puzzle) {
	//char * line = new char;
	//char * begin = line;
	//bool endFlag;
	//Make notes here for clarity
	//std::string buffer = "";
	//char * realBuffer;
	//int j = 0;
	int i = 0;
	//int * result = new int();
	int PuzzleNumbers[81] = {0,0,0,1,0,5,0,6,8,0,0,0,0,0,0,7,0,1,9,0,1,0,0,0,0,3,0,0,0,7,0,2,6,0,0,0,5,0,0,0,0,0,0,0,3,0,0,0,8,7,0,4,0,0,0,3,0,0,0,0,8,0,5,1,0,5,0,0,0,0,0,0,7,9,0,4,0,1,0,0,0};
	//!(file->std::ifstream::eof())
	while (i < 9) {
		std::cout <<"Enters while loop " << file << " " << *file << std::endl;
		/*
		std::getline((*file), buffer, '\n');
		std::cout << buffer << " " << file << " " << *file << std::endl;
		this->ChangetoC(buffer, realBuffer);
		std::cout << "There is a problem here" << std::endl;
		std::cout << file << " " << *file << std::endl;
		std::cout << realBuffer[3] << std::endl;
		while ((*realBuffer) != '\0') {
			//convert from string to int.
			if (result != NULL){
				convert(result[j], (*realBuffer)); //must figure out a way to store each digit in int*
				//Have to change result to int*
				//puzzle->insertIntoRowOfSquares(result, puzzle->GetPuzzle()[j]);
				//Hey it's Dylan and I am adding the following two lines so I can know how many non-zero ints are initialized.
				if (result[j] !=0){
					++initializationCounter;
				}
				realBuffer++;
				++j;
			}
			else {
				std::cout << "Result is uninitialized" << std::endl;
			}
		}*/
		int section[9] = {0};
		for (int j = 0; j < 9; ++j){
			section[j] = PuzzleNumbers[j + (9 * i)];	
			std::cout << section[j] << std::endl;
		}
				puzzle->insertIntoRowOfSquares(section, (puzzle->GetPuzzleRow(i)));
		i++;
		//buffer = "";
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


void Parser::ChangetoC(std::string buffer, char * realBuffer){
	for (int i = 0; i < 10; ++i){
		realBuffer[i] = buffer[i];
	}
}

int Parser::convert(int & result, char singleChar) {
	
	result = singleChar - 48;

	if ((0 <= result) && (result < 9)) {
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