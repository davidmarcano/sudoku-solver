#include <iostream>
#include <string>
#include <typeinfo>
#include "Solver.hpp"
#include "PuzzleClass.hpp"
#include "PossibilitiesSquare.hpp"


void Solver::SolvePuzzle(PuzzleClass* Puzzle, Parser* Parser){
	if (Puzzle->CheckPuzzle()){
		std::cout << "Puzzle is proper! Beginning testing..." << std::endl;
		do {
			if (Puzzle->CheckPuzzle()){
				std::cout << "Puzzle is proper through iteration " << solverIteration << std::endl;
				Puzzle->PrintPuzzle();
			}
			
			std::cout << solverIteration << std::endl;
			if (!skipSetMinimumSquare){
				Puzzle->SetMinimumSquare();
			}

			if (Puzzle->PlaceSquare()) {
				Puzzle->UpdateInternalArray(1);
				++(this->solverIteration);
				Puzzle->UpdateExternalArray(1);


				skipSetMinimumSquare = false;
			}
			else {
			 	std::cout << "We have gone backwards!" << std::endl;
				Puzzle->UpdateExternalArray(-1);
				--(this->solverIteration);
			 	Puzzle->UpdateInternalArray(-1);

				skipSetMinimumSquare = true;
			}
		} while ((solverIteration < 81 - 30) && (solverIteration != -1));//26Parser->GetinitializationCounter()) && solverIteration != 0);

		if (solverIteration == -1)
			std::cout << "Puzzle is unsolvable!" << std::endl;
		else
			std::cout << "Puzzle is solved!" << std::endl;
	}
	else
		std::cout << "Puzzle is not proper!" << std::endl;
}
