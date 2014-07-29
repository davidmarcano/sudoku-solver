#include <iostream>
#include <string>
#include "PossibilitiesSquare.hpp"
#include "PuzzleClass.hpp"



//inputs NumbersSeenArray per row/column and updates the corresponding boxes
//This function goes through the NumbersSeenArray for ONE box
void PossibilitiesSquare::SetPossibilities(int * NumbersSeenArray, const int ArraySize){ 
	for (int i = 0; i < ArraySize; i++) {
		if (NumbersSeenArray[i] == 1) {
			this->possibleNumbers[i - 1] = 0;
			--numberpossible;

		}
	}

}

//This function takes the square with the least available numbers as input, and enters the smallest one available as it's value.
int PossibilitiesSquare::EnterValue(){
	for (; this->historyCounter < 10; ++i){
		//needed to reset the value to zero before reversing the update array.
		if (this->historyCounter == 9){
			this->value = 0;
		}
		else{
			this->value = this->possibleNumbers[historyCounter];
			//We need a function here that keeps track of what is lost
			if (this->value > 0){
				++(this->historyCounter);
				PuzzleClass::UpdateExternalArray(1)
			return this->value;
			}		
		}//we need to reset historycounter when a Square is "poped" of the externalhistoryArray
		++(this->historyCounter);
	}
	//reset history counter so it can go through values again once it fails.
	this->historyCounter = 0;
	//This function sends the above square to the ReverseUpdateArray if there are no more available values.
	PuzzleClass::UpdateExternalArray(-1);
//	Once a number is chosen, we need to make sure every affected row/column/box looses this number as a possibility. 	
}

void PossibilitiesSquare::UpdatePossibilities(int FLAG){
	if (FLAG == 1){
		if (this->possibleNumbers[(this->internalhistoryArray) - 1] != 0){
			this->possibleNumbers[(this->internalhistoryArray) -1] = 0;
			--(this->numberpossible);
		}
		++(this->internalhistoryArray);
		
	}
	else if (FLAG == -1){
		--(this->internalhistoryArray);
		if (this->possibleNumbers[(this->internalhistoryArray) - 1] == 0){
			this->possibleNumbers[(this->internalhistoryArray) - 1] = this->internalhistoryArray;
			++(this->numberpossible);
		}
	}
}


int PossibilitiesSquare::GetValue() {
	return this->value;
}

void PossibilitiesSquare::SetValue(int val) {
	this->value = val;
}

int PossibilitiesSquare::Getlocationi(){
	return this->locationi;
}

int PossibilitiesSquare::Getlocationj(){
	return this->locationj;
}
//Not sure if this is needed
int PossibilitiesSquare::Get

int PossibilitiesSquare::GetnumberPossible(){
	return this->numberpossible;
}

//idea: make an array of CHANGED objects, so that when we need to reverse, we "pop" that object out an reverse.
// and use that object to change the AFFECTED boxes only. Each box will have an internal array keeping track
// of history ONLY related to it's rows/columns/boxes.


//Takes value of the most recent change and uses that to update InternalArrays
//Many things are wrong with the following code. I leave it here in case we need some of its functionality.
/*void PossibilitiesSquare::UpdateInternalArray(int FLAG, PossibilitiesSquare * minimumSquare){
	if (FLAG == 1){
		//gets the value of the minimumSquare
			this->PuzzleArray[i][j].UpdateValue() = minimumSquare.GetValue();
			minimumSquare.PossibilityUpdater(1);// should we make a new function for this or code it inside?
			++internalhistoryArray;
		}
	}
	else if (FLAG == -1){
		//for loop goes here to reverse update affected row/column/box
		--internalhistoryArray;
		mimimumSquare.PossibilityUpdater(-1);
	}

}
*/