#include <iostream>
#include <string>
#include <typeinfo>
#include "Solver.hpp"
#include "PuzzleClass.hpp"
#include "PossibilitiesSquare.hpp"


void Solver::SolvePuzzle(PuzzleClass* Puzzle, Parser* Parser){
	if (Puzzle->CheckPuzzle()){
		do {
			Puzzle->SetMinimumSquare();
			if (Puzzle->PlaceSquare()) {
				Puzzle->UpdateExternalArray(1);
				++(this->solverIteration);
				Puzzle->UpdateInternalArray(1);
			}
			 else {
			 	Puzzle->UpdateInternalArray(-1);
				--(this->solverIteration);
				Puzzle->UpdateExternalArray(-1);
				
			}
		} while ((solverIteration == 82 - Parser->GetinitializationCounter()) && solverIteration != 0);

		if (solverIteration == 0)
			std::cout << "Puzzle is unsolvable!" << std::endl;
		else
			std::cout << "Puzzle is solved!" << std::endl;
	}
	else
		std::cout << "Puzzle is not proper!" << std::endl;
}
