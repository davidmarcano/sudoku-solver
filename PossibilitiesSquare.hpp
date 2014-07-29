#ifndef _POSSIBILITIESSQUARE_H
#define _POSSIBILITIESSQUARE_H

#include <iostream>
#include <string>
#include <stdio.h>

class PossibilitiesSquare {
	private:
		int value = 0;
		int locationi = 0;
		int locationj = 0;
		int possibleNumbers[9] = {1,2,3,4,5,6,7,8,9};
		int	numberpossible = 9;
		int * internalhistoryArray;
		int internalupdateValue;
		int historyCounter = 0;

	public:
		int GetValue();

		void SetValue(int);

		int EnterValue();

		int Getlocationi();

		int Getlocationj();

		int GetnumberPossible();

		void SetPossibilities(int *, const int);

		void UpdatePossibilities(int);

		//void PossibilityUpdater(int *, int);

		//void UpdateInternalArray(int, PossibilitiesSquare *) //Is there a problem here?

		

};

#endif //_POSSIBILITIESSQUARE_H