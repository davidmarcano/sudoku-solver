#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "PuzzleClass.hpp"
#include "Parser.hpp"

using namespace std;

int main(int argc, char * argv[]) {
	Parser * parser = new Parser();
	PuzzleClass * puzzle = new PuzzleClass();

	puzzle->PuzzleClass::SolvePuzzle();

	FILE * pfile;
	pfile = fopen("test1.txt", "r");
	if (pfile == NULL) {
		cout << "Error opening File" << endl;
		//return 1;
	}
	parser->Parser::ParseInput(pfile);
	fclose(pfile);
	return 0;
}