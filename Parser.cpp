#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include "Parser.hpp"

void Parser::ResetInitializationCounter() {
	this->initializationCounter = 0;
}

int Parser::GetinitializationCounter(){
	return initializationCounter;
}

void Parser::ParseManualInput(std::string buffer, int i, PuzzleClass * puzzle) {
	int j = 0;
	char * pbuffer = NULL;
	int * result = NULL;

	pbuffer = new char[buffer.size() + 1];
	result = new int[buffer.size()];
	pbuffer[buffer.size()] = '\0';
	strcpy(pbuffer, buffer.c_str());
	//std::strcpy(realBuffer, pbuffer);
	while (pbuffer[j] != '\0') {
		//convert from string to int.
		if (result != NULL){
			convert(result, pbuffer, j); //must figure out a way to store each digit in int*
			//Have to change result to int*
			//puzzle->insertIntoRowOfSquares(result, puzzle->GetPuzzle()[j]);
			//Hey it's Dylan and I am adding the following two lines so I can know how many non-zero ints are initialized.
			if (result[j] !=0){
				++initializationCounter;
			}
			++j;
		}
		else {
			std::cout << "Result is uninitialized" << std::endl;
		}
	}
	j = 0;
	/*int section[9] = {0};
		for (int j = 0; j < 9; ++j){
		section[j] = PuzzleNumbers[j + (9 * i)];	
		//std::cout << section[j] << std::endl;
	}*/
	puzzle->insertIntoRowOfSquares(result, (puzzle->GetPuzzleRow(i)));

}

void Parser::ParseInput(std::ifstream * file, PuzzleClass * puzzle) {
	//char * line = NULL;
	//line = new char;
	//char * begin = line;
	//bool endFlag;
	//Make notes here for clarity
	std::string buffer = "";
	//char * realBuffer = NULL;
	int j = 0;
	int i = 0;
	//{0,0,6,0,0,0,0,0,4,0,0,0,8,6,0,7,3,0,0,4,0,3,5,0,0,0,2,1,7,0,4,0,0,6,0,0,0,9,0,0,0,0,0,8,0,0,0,8,0,0,6,0,1,7,2,0,0,0,8,1,0,4,0,0,6,7,0,4,3,0,0,0,8,0,0,0,0,0,3,0,0};

	//int PuzzleNumbers[81] = {0,0,0,1,0,5,0,6,8,0,0,0,0,0,0,7,0,1,9,0,1,0,0,0,0,3,0,0,0,7,0,2,6,0,0,0,5,0,0,0,0,0,0,0,3,0,0,0,8,7,0,4,0,0,0,3,0,0,0,0,8,0,5,1,0,5,0,0,0,0,0,0,7,9,0,4,0,1,0,0,0};
	//int PuzzleNumbers[81] = {0,0,9,7,4,8,0,0,0,7,0,0,0,0,0,0,0,0,0,2,0,1,0,9,0,0,0,0,0,7,0,0,0,2,4,0,0,6,4,0,1,0,5,9,0,0,9,8,0,0,0,3,0,0,0,0,0,8,0,3,0,2,0,0,0,0,0,0,0,0,0,6,0,0,0,2,7,5,9,0,0};
	//int PuzzleNumbers[81] = {6,0,0,0,0,0,0,4,0,0,0,5,0,0,2,0,0,7,7,2,9,0,0,0,0,0,3,0,9,0,0,4,0,0,0,1,0,0,0,0,6,0,0,0,0,4,0,0,0,8,0,0,7,0,3,0,0,0,0,0,1,6,5,2,0,0,4,0,0,8,0,0,0,5,0,0,0,0,0,0,4};
	//int PuzzleNumbers[81] = {8,0,0,0,0,0,0,0,0,0,0,3,6,0,0,0,0,0,0,7,0,0,9,0,2,0,0,0,5,0,0,0,7,0,0,0,0,0,0,0,4,5,7,0,0,0,0,0,1,0,0,0,3,0,0,0,1,0,0,0,0,6,8,0,0,8,5,0,0,0,1,0,0,9,0,0,0,0,4,0,0};

	

	/*0,0,9,6,0,7,4,3,1,
	8,0,0,0,5,3,0,0,9,
	0,6,0,2,0,0,5,0,0,
	0,0,8,9,0,0,0,0,6,
	0,0,2,0,4,0,7,0,5,
	0,0,0,0,0,1,0,0,0,
	0,0,0,5,9,4,3,0,2,
	0,2,7,0,3,0,0,1,0,
	4,0,0,1,0,2,6,5,0,*/
	//!(file->std::ifstream::eof())
	char * pbuffer = NULL;
	int * result = NULL;
	while (i < 9) {
		
		std::getline((*file), buffer, '\n');
		pbuffer = new char[buffer.size() + 1];
		result = new int[buffer.size()];
		pbuffer[buffer.size()] = '\0';
		strcpy(pbuffer, buffer.c_str());
		//std::strcpy(realBuffer, pbuffer);

		while (pbuffer[j] != '\0') {
			//convert from string to int.
			if (result != NULL){
				convert(result, pbuffer, j); //must figure out a way to store each digit in int*
				//Have to change result to int*
				//puzzle->insertIntoRowOfSquares(result, puzzle->GetPuzzle()[j]);
				//Hey it's Dylan and I am adding the following two lines so I can know how many non-zero ints are initialized.
				if (result[j] !=0){
					++initializationCounter;
				}
				++j;
			}
			else {
				std::cout << "Result is uninitialized" << std::endl;
			}
		}
		j = 0;
		/*int section[9] = {0};
		for (int j = 0; j < 9; ++j){
			section[j] = PuzzleNumbers[j + (9 * i)];	
			//std::cout << section[j] << std::endl;
		}*/
		puzzle->insertIntoRowOfSquares(result, (puzzle->GetPuzzleRow(i)));

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

int * Parser::convert(int * result, char * singleChar, int j) {
	
	result[j] = singleChar[j] - 48;
	if ((0 <= result[j]) && (result[j] <= 9)) {
		return result;
	}
	else {
		std::cout << "invalid input" << std::endl;
		result[j] = 0;
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