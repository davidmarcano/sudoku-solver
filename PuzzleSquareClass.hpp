#ifndef _PUZZLESQUARECLASS_H
#define _PUZZLESQUARECLASS_H

#include <iostream>
#include <string>
#include <stdio.hpp>

class PossibilitesSquare {
	private:
		int value;
		int possibleNumbers[9] = {1,2,3,4,5,6,7,8,9};
		int	numberpossible;
		int x = 0
		int * updateArray[];
	public:
		int GetValue();

		void SetPossibilities(int InputArray[], int k = 0);

		void SetnumberPossible();

		void MinimumSquare();

		int GetnumberPossible();

		void SetupdateArray();

};
#endif