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
	
	std::cout << "Welcome to the Sudoku Solver. Would you like to enter the";
	std::cout << " puzzle values manually or via a file? (m/f): " << std::endl;
	char choice = 'm';
	std::cin >> choice;
	if (choice == 'm'){
		std::cout << "You chose manually. Please enter values one row at a time: " << std::endl;
		string ENTERVALUES = " ";
		std::cin >> ENTERVALUES;
		std::cout << "Press any letter to start the Sudoku Sovler!" << std::endl;
		string START = " ";
		std::cin >> START;
	}

	else if (choice == 'f'){
		string filename = " ";
		std::cout << "You chose via a file. Please enter name of text file: " << std::endl;
		std::cin >> filename;
		std::cout << "Press any letter to start the Sudoku Sovler!" << std::endl;
		string START = " ";
		std::cin >> START;
	}

	else {
		std::cout << "Quit program? (y/n) " << std::endl;
		char endprogram = 'n';
		std::cin >> endprogram;
		if (endprogram == 'y')
			return 1;
	}

	ifstream * pfile = new ifstream;
	pfile->open("test1.txt");
	if (!pfile->good()) {
		cout << "Error opening File" << endl;
		//return 1;
	}

	GlobalPuzzle->InitializePuzzleArray();
	GlobalPuzzle->InitializeExternalArray();

	GlobalParser->ParseInput(pfile, GlobalPuzzle);
	pfile->close();

	PuzzleSolver->SolvePuzzle(GlobalPuzzle, GlobalParser);

	std::cout << "Printing values:" << std::endl;
	GlobalPuzzle->PrintPuzzle();
	std::cout << "Application finished. Shutting down..." << std::endl;

	return 0;
}