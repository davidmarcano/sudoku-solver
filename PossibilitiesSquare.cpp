#include <iostream>
#include <string>
#include "PossibilitiesSquare.hpp"
#include "PuzzleClass.hpp"

int PossibilitiesSquare::possibleNumbers[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

void PossibilitiesSquare::GetValueAddress() {
	std::cout <<  &(this->value) << std::endl;
}

int PossibilitiesSquare::GetValue() {
	return this->value;
}

void PossibilitiesSquare::SetValue(int value) {
	//std::cout << "I set value!" << std::endl;
	this->value = value;
}

int PossibilitiesSquare::Getlocationi(){
	return this->locationi;
}

int PossibilitiesSquare::Getlocationj(){
	return this->locationj;
}

void PossibilitiesSquare::Setlocationi(int locationi){
	//std::cout << "I set locationi!" << std::endl;
	this->locationi = locationi;
}

void PossibilitiesSquare::Setlocationj(int locationj){
	//std::cout << "I set locationj" << std::endl;
	this->locationj = locationj;
}
//We should do SetSquarei and SetSquarej eventually too.
/*Not sure if this is needed
int PossibilitiesSquare::Get
*/
int PossibilitiesSquare::Getnumberpossible(){
	return this->numberpossible;
}

void PossibilitiesSquare::UpdateinternalhistoryArray(int squarevalue){
	if (this->possibleNumbers[squarevalue - 1] != 0){
		((this->internalhistoryArray)++);
		//this->internalhistoryArray = new int[1];
		*(this->internalhistoryArray) = squarevalue;
	}
	else if (this->possibleNumbers[squarevalue - 1] == 0){
		((this->internalhistoryArray)++);
		//this->internalhistoryArray = new int[1];
		*(this->internalhistoryArray) = 0;
	}
}

void PossibilitiesSquare::ResetexternalArray(int FLAG){ //should change the name for this
	if (FLAG == 1){
		//this->possibleNumbers[value - 1] = 0;
		--numberpossible;
	}

	if (FLAG == -1){
		//this->possibleNumbers[value -1] = value;
		++numberpossible;
	}
}

//inputs NumbersSeenArray per row/column and updates the corresponding boxes
//This function goes through the NumbersSeenArray for ONE box
void PossibilitiesSquare::SetPossibilities(int * NumbersSeenArray, const int ArraySize){ 
	for (int i = 0; i < ArraySize; i++) {
		if ((NumbersSeenArray[i] == 1) && (possibleNumbers[i] != 0)) {
			this->possibleNumbers[i] = 0;
			--(this->numberpossible);		
		}
	}

}

//This function takes the square with the least available numbers as input, and enters the smallest one available as it's value.
int PossibilitiesSquare::EnterValue(){
	//std::cout << "Value of numberpossible: " << numberpossible << std::endl;
	for (; this->historyCounter < 10; ++(this->historyCounter)){
		//needed to reset the value to zero before reversing the update array.
		if (this->historyCounter == 9){
			this->value = 0;
		}
		else{
			this->value = this->possibleNumbers[historyCounter];
			//We need a function here that keeps track of what is lost
			if (this->value > 0){
				++(this->historyCounter);
				//++timesthrough;
				//std::cout << "Value placed: " << this->value << std::endl;
				//std::cout << "location of placed square: " << locationi << " " << locationj << std::endl;				
				return 1;
			}		
		}
	}
	//reset history counter so it can go through values if square is reused
	this->historyCounter = 0;
	//for (int i = 0; i < timesthrough; ++i){
	//	this->ResetexternalArray(-1);
	//}
	//std::cout << "Could not place properly" <<std::endl;
	return 0; 	
}

void PossibilitiesSquare::UpdatePossibilities(int FLAG){
	if (FLAG == 1){
		if (*(this->internalhistoryArray) != 0){
			if (this->possibleNumbers[*(this->internalhistoryArray) - 1] != 0){
				this->possibleNumbers[*(this->internalhistoryArray) -1] = 0;
				--(this->numberpossible);
			}
		}
	}

	else if (FLAG == -1){
		if (*(this->internalhistoryArray) == 0){
			//delete[] this->internalhistoryArray;
			--(this->internalhistoryArray);
		}

		else {
			if ((this->possibleNumbers[(*(this->internalhistoryArray)) - 1]) == 0) {
				this->possibleNumbers[(*(this->internalhistoryArray)) - 1] = *(this->internalhistoryArray);
				++(this->numberpossible); //There are problems here!
				//delete[] this->internalhistoryArray;
				--(this->internalhistoryArray);
			}
		}
	}
}

void PossibilitiesSquare::PrintInternalHistoryArray() {
	//std::cout << "internal history: " << *(this->internalhistoryArray) << std::endl;

	//std::cout << "possibleNumbers: ";
	for (int i = 0; i < 9; i++) {
		std::cout << (this->possibleNumbers)[i];
	}
	std::cout << std::endl;
}
/*void PossibilitiesSquare::GetpossibleNumbers(){
	for (int k = 0; k < 9; ++k){
		std::cout << possibleNumbers[k] <<std::endl;
	}
}
//idea: make an array of CHANGED objects, so that when we need to reverse, we "pop" that object out an reverse.
// and use that object to change the AFFECTED boxes only. Each box will have an internal array keeping track
// of history ONLY related to it's rows/columns/boxes.


//Takes value of the most recent change and uses that to update InternalArrays
//Many things are wrong with the following code. I leave it here in case we need some of its functionality.
void PossibilitiesSquare::UpdateInternalArray(int FLAG, PossibilitiesSquare * minimumSquare){
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