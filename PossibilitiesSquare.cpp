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

void PossibilitiesSquare::UpdatePossibilities(int FLAG){
	if (FLAG == 1){
		this->possibleNumbers[internalhistoryArray -1] = 0;
		--numberpossible;
		++internalhistoryArray;
	}
	elseif (FLAG == -1){
		--internalhistoryArray;
		this->possibleNumbers[internalhistoryArray - 1] = internalhistoryArray;
		--numberpossible;
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
			//minimumSquare needs to be changed to Puzzle?
		minimumSquare->UpdateInternalArray(minimumSquare, 1);
		}
	}
	//originally ReverseUpdateExternalArray
	elseif (FLAG == -1){
		--externalhistoryArray;
		if (externalhistoryArray == startingpoint);
		cout << "Unsolvable Puzzle!" << endl;
		//Create a new pointer to refer to the beginning.
		//sends the object located here to the EnterValue Function to 
		minimumSquare->UpdateInternalArray(minimumSquare, -1);
		externalhistoryArray->EnterValue();
	}
}
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
	elseif (FLAG == -1){
		//for loop goes here to reverse update affected row/column/box
		--internalhistoryArray;
		mimimumSquare.PossibilityUpdater(-1);
	}

}
*/