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
	
	std::cout << "Welcome to the Sudoku Solver." << endl;
	char jixu = 'y';
	while (jixu == 'y') {
		std::cout << "Would you like to enter the puzzle values manually or via a file? (m/f): " << std::endl;
		char choice = 'm';
		std::cin >> choice;
		ifstream * pfile = new ifstream;
		GlobalPuzzle->InitializePuzzleArray();
		GlobalPuzzle->InitializeExternalArray();	

		if (choice == 'm'){
			std::cout << "You chose manually. Please enter values one row at a time: " << std::endl;
			string ENTERVALUES = " ";
			for (int i = 0; i < 9; i++) {
				std::cin >> ENTERVALUES;
				//check for input error
				if ((ENTERVALUES.size() < 9) || (ENTERVALUES.size() > 9)) {
					cout << "Invalid input, please re-input that line" << endl;
					i--;
				}
				else {
					GlobalParser->ParseManualInput(ENTERVALUES, i, GlobalPuzzle);
				}
			}
			std::cout << "Press any letter to start the Sudoku Sovler!" << std::endl;
			string START = " ";
			std::cin >> START;
		}

		else if (choice == 'f'){
			string filename = " ";
			std::cout << "You chose via a file. Please enter name of text file: " << std::endl;
			std::cin >> filename;
			

			pfile->open(filename);
			if (!pfile->good()) {
				cout << "Error opening File" << endl;
				return 1;
			}
			std::cout << "Press any letter to start the Sudoku Sovler!" << std::endl;
			string START = " ";
			std::cin >> START;
			GlobalParser->ParseInput(pfile, GlobalPuzzle);
			pfile->close();
		}

		else {
			std::cout << "Quit program? (y/n) " << std::endl;
			char endprogram = 'n';
			std::cin >> endprogram;
			if (endprogram == 'y')
				return 1;
		}
		cout << "Before solving: " << endl;
		GlobalPuzzle->PrintPuzzle();

		PuzzleSolver->SolvePuzzle(GlobalPuzzle, GlobalParser);

		std::cout << "Printing solved values:" << std::endl;
		GlobalPuzzle->PrintPuzzle();
		cout << endl;
		GlobalParser->ResetInitializationCounter();
		cout << "Would you like to input another puzzle? (y/n) " << endl;
		cin >> jixu;
		

	}
	std::cout << "Application finished. Shutting down..." << std::endl;

	return 0;
}