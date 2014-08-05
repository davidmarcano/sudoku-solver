#include <iostream>
#include <string>
#include <typeinfo>
#include "Solver.hpp"
#include "PuzzleClass.hpp"
#include "PossibilitiesSquare.hpp"


void Solver::SolvePuzzle(PuzzleClass* Puzzle, Parser* Parser){
	int counter = 0;
	if (Puzzle->CheckPuzzle()){
		std::cout << "Puzzle is proper! Beginning testing..." << std::endl;
		do {
			std::cout << "Number through: " << ++counter << std::endl;
			Puzzle->PrintPuzzle();
			std::cout << "Solver iteration: " << solverIteration << std::endl;
			if (!skipSetMinimumSquare){
				Puzzle->SetMinimumSquare();
			}

			if (Puzzle->PlaceSquare()) {
				std::cout << "Square is placed" << std::endl;
				Puzzle->UpdateInternalArray(1);
				++(this->solverIteration);
				Puzzle->UpdateExternalArray(1);
				skipSetMinimumSquare = false;
			}
			else {
				Puzzle->UpdateExternalArray(-1);
				--(this->solverIteration);
				Puzzle->UpdateInternalArray(-1);
			 

				skipSetMinimumSquare = true;
				std::cout << "We updated internal Array!" << std::endl;
			}
		} while ((solverIteration < 81) && (solverIteration != -1));//26Parser->GetinitializationCounter()) && solverIteration != 0);

		if (solverIteration == -1)
			std::cout << "Puzzle is unsolvable!" << std::endl;
		else
			std::cout << "Puzzle is solved!" << std::endl;
	}
	else
		std::cout << "Puzzle is not proper!" << std::endl;
}
