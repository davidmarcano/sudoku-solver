#ifndef _PUZZLECLASS_H
#define _PUZZLECLASS_H

#include <iostream>
#include <string>
#include <stdio.h>
#include "PossibilitiesSquare.hpp"


class PuzzleClass{
	private:
		PossibilitiesSquare ** PuzzleArray = new PossibilitiesSquare*[9];
		int i = 0, j = 0;
		int minimum = 0;
		PossibilitiesSquare * externalhistoryArray;
		PossibilitiesSquare * minimumSquare;
		const PossibilitiesSquare * startingpoint = externalhistoryArray;

	
	public:	

		void InitializePuzzleArray (PossibilitiesSquare **);

		void insertIntoRowOfSquares(int * , PossibilitiesSquare *);
		//void StoreRow(int[]);

		void SolvePuzzle();

		bool CheckPuzzle();

		bool CheckerAndInitializer(int * , int, int, int);

		void SetPuzzleArray(int *, const int);

		void clearArray(int *);

		PossibilitiesSquare ** GetPuzzle();

		void SetMinimumSquare();

		void UpdateExternalArray(int);
		
		void UpdateInternalArray(int);
};

#endif //_PUZZLECLASS_H