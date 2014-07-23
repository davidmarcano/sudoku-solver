#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "PuzzleClass.hpp"
#include "Parser.hpp"

using std::ifstream;
using namespace std;


int main(int argc, char * argv[]) {
	Parser * parser = new Parser();
	PuzzleClass * puzzle = new PuzzleClass();

	puzzle->PuzzleClass::SolvePuzzle();

	ifstream * pfile = new ifstream;
	pfile->open("test1.txt");
	if (!pfile->good()) {
		cout << "Error opening File" << endl;
		//return 1;
	}
	parser->Parser::ParseInput(pfile);
	pfile->close();
	return 0;
}