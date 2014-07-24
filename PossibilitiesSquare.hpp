#ifndef _POSSIBILITIESSQUARE_H
#define _POSSIBILITIESSQUARE_H

#include <iostream>
#include <string>
#include <stdio.h>

class PossibilitiesSquare {
	private:
		int value = 0;
		int possibleNumbers[9] = {1,2,3,4,5,6,7,8,9};
		int	numberpossible;
		int * historyArray;
		int historyCounter = 0;
	public:
		void PossibilityUpdater(int *, int);

		int GetValue();

		void SetPossibilities(int InputArray[], int k = 0);

		void SetnumberPossible();

		int GetnumberPossible();

		int EnterValue();

		void UpdateArray();

		void ReverseUpdateArray();

		void SetValue(int);

};
#endif //_POSSIBILITIESSQUARE_H