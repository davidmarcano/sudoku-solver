#include <iostream>
#include <string>
#include "PossibilitiesSquare.hpp"
#include "PuzzleClass.hpp"

	void PossibilitiesSquare::SetPossibilities(int InputArray[], int k){ 
		int ArraySize = sizeof(InputArray) / sizeof(InputArray[0]);
		for (int i = 0; i < ArraySize; i++) {
			if (InputArray[i] == 1) {
				this->possibleNumbers[i - 1] = 0;
			}
		}

	void PossibilitiesSquare::SetnumberPossible(){
		for (int i = 0; i < 9; ++i){
			if (this->possibleNumbers[i] != 0){
				++numberpossible;
			}

		}
	}
	int PossibilitiesSquare::GetnumberPossible(){
		return this->numberpossible;
	}

	int PossibilitiesSquare::GetValue() {
		return this->value;
	}
	//This doesn't actually go here
	void PossibilitiesSquare::MinimumSquare(PossibilitiesSquare InputSquare){
		//int minimum = 9 This will go to our main function
		PossibilitiesSquare * minimumSquare = new PossibilitiesSquare();
		if (InputSquare.GetnumberPossible < minimum){
			minimum = InputSquare.GetnumberPossible;
			minimumSquare-> InputSquare;
		}
	}
	//This function takes the square with the least available numbers as input, and enters the smallest one available as it's value.
	int PossibilitiesSquare::EnterValue(PossibilitiesSquare * minimum){
		for (; historyCounter < 9; ++i){
		value = minimum->possibleNumbers[historyCounter];
			//We need a function here that keeps track of what is lost
			if (value > 0){
				++historyCounter;
			break;
			 //I want this to stop after I return this value. is this the best way to do that.
			}
			++historyCounter;
		}
		//This function sends the above square to the ReverseUpdateArray if there are no more available values.
		PossibilitiesSquare::ReverseSetUpdateArray(minimum);
		
	}
	
	void PossibilitiesSquare::UpdateArray(PossibilitiesSquare * add){
		* historyArray = &add;
		++historyArray;
		if sizeof()
	}

	void PossibilitiesSquare::ReverseUpdateArray(PossibilitiesSquare * cancel){
		--historyArray;
		//sends the object located here to the EnterValue Function to 
		PossibilitiesSquare::EnterValue(historyArray);
	}
};