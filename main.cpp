#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
#include "PossibilitiesSquare.hpp"
#include "PuzzleClass.hpp"
#include "Parser.hpp"
#include "Solver.hpp"

using std::ifstream;
using namespace std;

Solver * PuzzleSolver = new Solver();
Parser * GlobalParser = new Parser();
PuzzleClass * GlobalPuzzle = new PuzzleClass();



int main(int argc, char * argv[]) {
	
	ifstream * pfile = new ifstream;
	pfile->open("test1.txt");
	if (!pfile->good()) {
		cout << "Error opening File" << endl;
		//return 1;
	}

	GlobalPuzzle->InitializePuzzleArray();

	GlobalParser->ParseInput(pfile, GlobalPuzzle);
	pfile->close();

	PuzzleSolver->SolvePuzzle(GlobalPuzzle, GlobalParser);
	
	return 0;
}