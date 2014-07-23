#ifndef _POSSIBILITIESSQUARE_H
#define _POSSIBILITIESSQUARE_H

#include <iostream>
#include <string>
#include <stdio.h>

class PossibilitiesSquare {
	private:
		int value;
		int possibleNumbers[9] = {1,2,3,4,5,6,7,8,9};
		int	numberpossible;
		int * historyArray[];
		int historyCounter = 0;
	public:
		int GetValue();

		void SetPossibilities(int InputArray[], int k = 0);

		void SetnumberPossible();

		void MinimumSquare();

		int GetnumberPossible();

		int EnterValue();

		void UpdateArray();

		void ReverseUpdateArray();

		void SetValue(int);

};
#endif