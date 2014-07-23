#ifndef _PUZZLECLASS_H
#define _PUZZLECLASS_H

#include <iostream>
#include <string>
#include <stdio.h>
#include "PossibilitiesSquare.hpp"


class PuzzleClass{
	private:
	PossibilitiesSquare PuzzleArray[9][9] = {{}};
	int i = 0, j = 0;
	
	public:	
		void insertIntoSquare(int * , PossibilitiesSquare *);
		//void StoreRow(int[]);

		bool PuzzleClass::CheckerAndInitializer(int & NumbersSeenArray[], int, PuzzleClass, int, int)

		bool CheckPuzzle();

		void SolvePuzzle();

		PossibilitiesSquare ** GetPuzzle();

		void PuzzleClass::MinimumSquare(PossibilitiesSquare InputSquare)
};

#endif