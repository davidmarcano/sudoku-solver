#ifndef _PUZZLECLASS_H
#define _PUZZLECLASS_H

#include <iostream>
#include <string>
#include <stdio.h>
#include "PossibilitiesSquare.hpp"


class PuzzleClass{
	private:
	PossibilitiesSquare ** PuzzleArray = new PossibilitiesSquare*[9]; //we need to initialize this
	int i = 0, j = 0;
	
	public:	
		void insertIntoRowOfSquares(int * , PossibilitiesSquare *);
		//void StoreRow(int[]);

		bool CheckerAndInitializer(int * , int, int, int);

		bool CheckPuzzle();

		void SolvePuzzle();

		PossibilitiesSquare ** GetPuzzle();

		void MinimumSquare(PossibilitiesSquare *, int, PossibilitiesSquare *);
};

#endif //_PUZZLECLASS_H