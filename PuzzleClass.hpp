#ifndef _PUZZLECLASS_H
#define _PUZZLECLASS_H

#include <iostream>
#include <string>
#include <stdio.h>
#include "PossibilitiesSquare.hpp"


class PuzzleClass{
	private:
		PossibilitiesSquare ** PuzzleArray = new PossibilitiesSquare*[9];
		int minimum = 9
		int i = 0, j = 0;
		PossibilitiesSquare * externalhistoryArray;
		PossibilitiesSquare * minimumSquare;
		const PossibilitiesSquare * startingpoint = externalhistoryArray;

	
	public:	

		void InitializePuzzleArray (PossibilitiesSquare ** PuzzleArray);

		void insertIntoRowOfSquares(int * , PossibilitiesSquare *);
		//void StoreRow(int[]);

		bool CheckerAndInitializer(int * , int, int, int);

		bool CheckPuzzle();

		void SolvePuzzle();

		PossibilitiesSquare ** GetPuzzle();

		void MinimumSquare(PossibilitiesSquare *, int, PossibilitiesSquare *);

		void UpdateExternalArray(int, PossibilitiesSquare *);
};

#endif //_PUZZLECLASS_H