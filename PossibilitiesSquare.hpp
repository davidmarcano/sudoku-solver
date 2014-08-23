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
		int Squarei = 0;
		int Squarej = 0;
		//std::array<int, 9> possibleNumbers;
		//int possibleNumbers[9] = {1,2,3,4,5,6,7,8,9};
		int	numberpossible = 9;
		int timesthrough = 0;
		//int * internalhistoryArray = new int();
		int * internalhistoryArray = new int[162];
		int internalupdateValue = 0;
		int historyCounter = 0;

	public:

		static int possibleNumbers[9];

		//int possibleNumbers[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

		void GetValueAddress();

		int Getnumberpossible();

		void ResetexternalArray(int);

		int GetValue();

		void SetValue(int);

		int EnterValue();

		int Getlocationi();

		int Getlocationj();

		void Setlocationi(int);

		void Setlocationj(int);

		void SetPossibilities(int *, const int);

		void UpdatePossibilities(int);

		void UpdateinternalhistoryArray(int); 

		void PrintInternalHistoryArray();



		//void PossibilityUpdater(int *, int);

		//void UpdateInternalArray(int, PossibilitiesSquare *) //Is there a problem here?

		

};

#endif //_POSSIBILITIESSQUARE_H