#include <iostream>
#include <string>
#include "PossibilitiesSquare.hpp"
#include "PuzzleClass.hpp"



//inputs NumbersSeenArray per row/column and updates the corresponding boxes
//This function goes through the NumbersSeenArray for ONE box
//overload SetPossibilities so we can update WITHOUT NumbersSeenArray?
void PossibilitiesSquare::SetPossibilities(int * NumbersSeenArray, int ArraySize){ 
	for (int i = 0; i < ArraySize; i++) {
		if (NumbersSeenArray[i] == 1) {
			this->possibleNumbers[i - 1] = 0;
			--numberpossible;
		}
	}

}

int PossibilitiesSquare::GetnumberPossible(){
	return this->numberpossible;
}

int PossibilitiesSquare::GetValue() {
	return this->value;
}

void PossibilitiesSquare::SetValue(int val) {
	this->value = val;
}

//This will eventually be the minimumSquare we need to start updating External/Internal Arrays. This is not the one we actually want
PossibilitiesSquare* minimumSquare = new PossibilitiesSquare();
minimumSquare->EnterValue();
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
				PuzzleClass::UpdateExternalArray(1, this->minimumSquare)
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

//idea: make an array of CHANGED objects, so that when we need to reverse, we "pop" that object out an reverse.
// and use that object to change the AFFECTED boxes only. Each box will have an internal array keeping track
// of history ONLY related to it's rows/columns/boxes.

void PuzzleClass::UpdateExternalArray(int FLAG, PossibilitiesSquare * minimumSquare){
	//originally UpdateExternalArray
	if (FLAG == 1){
		if (externalhistoryArray == startingpoint){
			++externalhistoryArray;
			externalhistoryArray = this->minimumSquare;
			++externalhistoryArray;
		}
		//checks to see if the puzzle is solved. 82 instead of 81 because I added to externalhistoryArray twice in the beginning.
		if ((sizeof(externalhistoryArray) / sizeof(externalhistoryArray[0])) == 82 - InitializationCounter){
			cout << "Puzzle is Solved!" << endl;
		minimumSquare->UpdateInternalArray(1);
		}
	}
	//originally ReverseUpdateExternalArray
	elseif (FLAG == -1){
		--externalhistoryArray;
		if (externalhistoryArray == startingpoint);
		cout << "Unsolvable Puzzle!" << endl;
		//Create a new pointer to refer to the beginning.
		//sends the object located here to the EnterValue Function to 
		minimumSquare->UpdateInternalArray(-1);
		externalhistoryArray->EnterValue();
	}
}
//Need another function to change those boxes affected by by the change.
void PuzzleClass::
//Takes value of the most recent change and uses that to update InternalArrays
void PossibilitiesSquare::UpdateInternalArray(int FLAG){
	if (FLAG ==1){
		//gets the value of the minimumSquare
		for (int j = 0; j < 9; ++j){//for loop goes here to update affected row/column/box (we need to change 9 also) this might need to be in update external array?
			puzzle[locationofdata][j].UpdateValue() = minimumSquare.GetValue();
			minimumSquare.PossibilityUpdater();// should we make a new function for this or code it inside?
			++internalhistoryArray;
		}
	}
	elseif (FLAG == -1){
		//for loop goes here to reverse update affected row/column/box
		--internalhistoryArray;
		mimimumSquare.PossibilityUpdater();
	}

}
//Takes last value of InternalArray and uses that to update possibilities. Overloaded from above.
//This has problems. Should be in PuzzleClass. Will be done soon.
void PossibilitiesSquare::PossibilityUpdater(int FLAG){
	if (FLAG == 1){
		this->possibleNumbers[internalhistoryArray -1] = 0;
	}
	elseif (FLAG == -1){
		this->possibleNumbers[internalhistoryArray - 1] = internalhistoryArray;
	}
	//We also want to overload the NumberofPossibilities function to handle this PossibilityUpdater.
}
