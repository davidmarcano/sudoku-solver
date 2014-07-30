#ifndef _PUZZLECLASS_H
#define _PUZZLECLASS_H

#include <iostream>
#include <string>
#include <stdio.h>
#include "PossibilitiesSquare.hpp"


class PuzzleClass{
	private:

		int i = 0, j = 0;
		int minimum = 0;
		int squarei = 0, squarej = 0;
		PossibilitiesSquare * externalhistoryArray = new PossibilitiesSquare();
		const PossibilitiesSquare * startingpoint = externalhistoryArray;
		PossibilitiesSquare ** PuzzleArray = new PossibilitiesSquare*[9];
		PossibilitiesSquare * minimumSquare;

	
	public:	

		void InitializePuzzleArray();

		void insertIntoRowOfSquares(int * , PossibilitiesSquare *);
		//void StoreRow(int[]);

		bool CheckPuzzle();

		bool CheckerAndInitializer(int *, int, int, int);

		bool CheckerAndInitializer(int *, const int, int, int, int, int);

		void SetPuzzleArray(int *, const int);

		void SetPuzzleArray(int *, const int, int, int);

		void clearArray(int *);

		PossibilitiesSquare ** GetPuzzle();

		void SetMinimumSquare();

		int PlaceSquare();

		void UpdateExternalArray(int);
		
		void UpdateInternalArray(int);
};

#endif //_PUZZLECLASS_H