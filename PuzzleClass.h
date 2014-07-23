#ifndef _PUZZLECLASS_H
#define _PUZZLECLASS_H

#include <iostream>
#include <string>
#include <stdio.h>


class PuzzleClass{
	private:
	int PuzzleArray[9][9] = {{0}};
	int i = 0, j = 0;
	
	public:	
		void StoreRow(int[]);

		bool CheckPuzzle();

		void SolvePuzzle();
};

#endif