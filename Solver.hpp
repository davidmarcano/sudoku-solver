#ifndef _SOLVER_H
#define _SOLVER_H

#include <iostream>
#include <string>
#include "PuzzleClass.hpp"
#include "PossibilitiesSquare.hpp"
#include "Parser.hpp"

class Solver {
	private:
		int solverIteration = 0;
		bool skipSetMinimumSquare = false;
	public:

		void SolvePuzzle(PuzzleClass*, Parser*);

};


#endif //_SOLVER_H