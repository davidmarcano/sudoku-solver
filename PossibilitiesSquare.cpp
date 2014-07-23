#include <iostream>
#include <string>
#include "PossibilitiesSquare.hpp"
#include "PuzzleClass.hpp"

//inputs NumbersSeenArray per row/column and updates the corresponding boxes
void PossibilitiesSquare::SetPossibilities(int InputArray[]){ 
	int ArraySize = sizeof(InputArray) / sizeof(InputArray[0]);
	for (int i = 0; i < ArraySize; i++) {
		if (InputArray[i] == 1) {
			this->possibleNumbers[i - 1] = 0;
		}
	}
}

//overload SetPossibilities so we can update WITHOUT NumbersSeenArray?

void PossibilitiesSquare::SetnumberPossible(){
	for (int i = 0; i < 9; ++i){
		if (this->possibleNumbers[i] != 0){
			++(this->numberpossible);
	}
		}
}
int PossibilitiesSquare::GetnumberPossible(){
	return this->numberpossible;
}

int PossibilitiesSquare::GetValue() {
	return this->value;
}



PossibilitiesSquare Maximum;
minimumSquare->EnterValue();
//This function takes the square with the least available numbers as input, and enters the smallest one available as it's value.
int PossibilitiesSquare::EnterValue(){
	for (; this->historyCounter < 10; ++i){
		if (historyCounter == 9){
			this->value = 0;
		}
		else{
			this->value = this->possibleNumbers[historyCounter];
			//We need a function here that keeps track of what is lost
			if (this->value > 0){
				++(this->historyCounter);
			return this->value;
			 //I want this to stop after I return this value. is this the best way to do that.
			}		
		}//we need to reset historycounter when a Square is "poped" of the ExternalHistoryArray
		++historyCounter;
	}
	//This function sends the above square to the ReverseUpdateArray if there are no more available values.
	PossibilitiesSquare::ReverseUpdateExternalArray();
//	Once a number is chosen, we need to make sure every affected row/column/box looses this number as a possibility. 	
}

void PossibilitiesSquare::SetValue(int val) {
	this->value = val;
}

//idea: make an array of CHANGED objects, so that when we need to reverse, we "pop" that object out an reverse.
// and use that object to change the AFFECTED boxes only. Each box will have an internal array keeping track
// of history ONLY related to it's rows/columns/boxes.

void PossibilitiesSquare::UpdateExternalArray(PossibilitiesSquare * add){
	if (historyArray == startingpoint){
		++historyArray;}
	historyArray = add;
	++historyArray;
	//
	if ((sizeof(historyArray) / sizeof(historyArray[0])) == 82 - NUMBER OF INITIALIZED){
		cout << "Puzzle is Solved!" << endl;
	}
}
void PuzzleClass::ReverseUpdateExternalArray(){//We need to change header files for this Class change
	--historyArray;
	if (historyArray == startingpoint);
	cout << "Unsolvable Puzzle!" << endl;
	//Create a new pointer to refer to the beginning.
	//sends the object located here to the EnterValue Function to 
	historyArray->EnterValue();

}
//We need to change historyArray to externalhistoryArray.