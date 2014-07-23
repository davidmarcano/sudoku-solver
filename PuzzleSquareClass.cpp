#include <iostream>
#include <string>
#include "PuzzleSquareClass.hpp"

	void PuzzleSquareClass::SetPossibilities(int InputArray[], int k){ //IS THERE ANY WAY TO INHEREIT VALUE K?
		int ArraySize = sizeof(InputArray) / sizeof(InputArray[0]);
		for (int i = 0; i < ArraySize; i++) {
			if (InputArray[i] == 1) {
				this->possibleNumbers[i - 1] = 0;
			}
		}

	void PuzzleSquareClass::SetnumberPossible(){
		for (; x < 9; ++l){
			if (possibleNumbers[x] != 0){
				++numberpossible;
			}

		}
	}
	int PuzzleSquareClass::GetnumberPossible(){
		return this->numberpossible;
	}

	int PuzzleSquareClass::GetValue() {
		return this->value;
	}
	//This doesn't actually go here
	void PuzzleSquareClass::MinimumSquare(PossibilitiesSquare InputSquare){
		int minimum = 9;
		PossibilitiesSquare * minimumSquare = new PossibilitiesSquare();
		if (InputSquare.GetnumberPossible < minimum){
			minimum = InputSquare.GetnumberPossible;
		}
	}

	void PuzzleSquareClass::SetupdateArray(){

	}
};