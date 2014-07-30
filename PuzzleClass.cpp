#include <iostream>
#include <string>
#include <typeinfo>
#include "PuzzleClass.hpp"


void PuzzleClass::InitializePuzzleArray(){
	for (;this->i < 9; ++(this->i)){
		PuzzleArray[i] = new PossibilitiesSquare[9];
	}
	for (;this->i < 9; ++(this->i)){
		for (;this->j < 9; ++(this->j)){
				this->PuzzleArray[this->i][this->j].SetValue(0);
		}
	}
}


//returns true if the puzzle is proper, false otherwise.
bool PuzzleClass::CheckPuzzle() {	
	this->i = 0;
	this->j = 0;
	//reset i and j in case they were previously used
	const int ArraySize = sizeof(this->PuzzleArray[0]) / sizeof(this->PuzzleArray[0][0]);
	std::cout << ArraySize << std::endl;
	//this is to check the row validity
	//while (CheckCounter < 9) {
	int NumbersSeenArray[9] = {0};

	if (~(this->CheckerAndInitializer(NumbersSeenArray, ArraySize, this->i, this->j))){
		clearArray(NumbersSeenArray);
		return false;
	}

	this->i = 0;
	this->j = 0;
	if (~(this->CheckerAndInitializer(NumbersSeenArray, ArraySize, this->j, this->i))){
		clearArray(NumbersSeenArray);
		return false;
	}

	//overloading CheckAndInitializer for boxes:
	this->i = 0;
	this->j = 0;
	if (~(this->CheckerAndInitializer(NumbersSeenArray,ArraySize, this->i, this->j, this->squarei, this->squarej))){
		clearArray(NumbersSeenArray);
		return false;
	}

	return true;
}				

bool PuzzleClass::CheckerAndInitializer(int * NumbersSeenArray, const int ArraySize, int i, int j) {
	for (; i < ArraySize; ++i){
		//resets DoubleCounter when moving from row to row
		for (; j < ArraySize; ++j){
			//builds NumbersSeenArray for a row/column and checks for validity
			if (this->PuzzleArray[i][j].GetValue() > 0) {
				int puzzleNumber = this->PuzzleArray[i][j].GetValue();
				NumbersSeenArray[puzzleNumber - 1]++;//is there a problem here?
				if (NumbersSeenArray[puzzleNumber - 1] > 1){
					std::cout << "This is not a proper Sudoku puzzle!" << std::endl;
					return false;
				}
				
			}
		}
		//goes through the row/column and updates each square's Possibilities via NumbersSeenArray
		j = 0;
		this->SetPuzzleArray(NumbersSeenArray, ArraySize);
	}
	return true;
}

bool PuzzleClass::CheckerAndInitializer(int * NumbersSeenArray, const int ArraySize, int i, int j, int squarei, int squarej){
	for (;squarei < (ArraySize / 3); ++squarei) {
		for (;squarej < (ArraySize /3); ++squarej) {
			//similar to Checking for row/column validity, only within each Square
			for (; i < (ArraySize / 3); ++i){
				for (; j < (ArraySize / 3); ++j){
					if (this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].GetValue() > 0) {
						int puzzleNumber = this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].GetValue();
						NumbersSeenArray[puzzleNumber - 1]++;
						if (NumbersSeenArray[puzzleNumber - 1] > 1){
							return false;
						}
					}	
				}
				this->j = 0;
			}
			this->i = 0;
			this->SetPuzzleArray(NumbersSeenArray, ArraySize, squarei, squarej);
		}
		//reset squarej when moving to the next row of Squares
		squarej = 0;
	}
	squarei = 0;
	return true;
}
//Question about int i = 0

//goes through each row and column to update the possibleNumbers array for each square
void PuzzleClass::SetPuzzleArray(int * NumbersSeenArray, const int ArraySize){
		for (;this->j < ArraySize; ++(this->j)){
				this->PuzzleArray[this->i][this->j].SetPossibilities(NumbersSeenArray, ArraySize);
		}
		this->j = 0;
}

void PuzzleClass::SetPuzzleArray(int * NumbersSeenArray, const int ArraySize, int squarei, int squarej){
		for (int i = 0; i < (ArraySize / 3); ++i){
			for (int j = 0; j < (ArraySize / 3); ++i){
				this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].SetPossibilities(NumbersSeenArray, ArraySize);
			}
		}
}

//Inputs: Takes a square and compares its number of possible values to a minimum value. If it is the minimum, we keep track of it via a pointer.
//This needs to be called by the function that intializes each square's numberpossible.
//For now let's just use SetMinimumSquare
/*void PuzzleClass::UpdateMinimumSquare(PossibilitiesSquare * InputSquare,){
	//int minimum = 9 This will go to our main functions
	//minimumSquare = &InputSquare;
	if (InputSquare->GetnumberPossible() < minimum){
		minimumSquare = InputSquare;
		minimum = InputSquare->GetnumberPossible();
	}
}*/

void PuzzleClass::SetMinimumSquare(){
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j){
			if ((this->PuzzleArray[i][j].GetValue() == 0) && (this->PuzzleArray[i][j].GetnumberPossible() < minimum)){
				this->minimum = this->PuzzleArray[i][j].GetnumberPossible();
				this->minimumSquare = &(this->PuzzleArray[i][j]);
			}
		}
	}
	minimum = 9;
}

int PuzzleClass::PlaceSquare(){
	return minimumSquare->EnterValue();
}
void PuzzleClass::UpdateExternalArray(int FLAG){
	//originally UpdateExternalArray
	if (FLAG == 1){
		++(this->externalhistoryArray);
		this->externalhistoryArray = this->minimumSquare;
			}
	else if (FLAG == -1){
		--(this->externalhistoryArray);
	}
}

void PuzzleClass::UpdateInternalArray(int FLAG){
	if (FLAG == 1){
		this->i = this->externalhistoryArray->Getlocationi();
		for (this->j = 0; this->j < 9; ++(this->j)){
			this->PuzzleArray[this->i][this->j].UpdateinternalhistoryArray(this->externalhistoryArray->GetValue());
			this->PuzzleArray[this->i][this->j].UpdatePossibilities(1);
		}

		this->j = this->externalhistoryArray->Getlocationj();
		for (this->i = 0; this->i < 9; ++i){
			this->PuzzleArray[this->i][this->j].UpdateinternalhistoryArray(this->externalhistoryArray->GetValue());
			this->PuzzleArray[this->i][this->j].UpdatePossibilities(1);
		}
		this->squarei = (this->externalhistoryArray->Getlocationi() / 3);
		this->squarej = (this->externalhistoryArray->Getlocationj() / 3);
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
			this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].UpdateinternalhistoryArray(this->externalhistoryArray->GetValue());
			this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].UpdatePossibilities(1);
			}
		}
	}

	else if (FLAG == -1){
		this->i = this->externalhistoryArray->Getlocationi();
		for (this->j = 0; this->j < 9; ++(this->j)){
			this->PuzzleArray[this->i][this->j].UpdatePossibilities(-1);
		}
		this->j = this->externalhistoryArray->Getlocationj();
		for (this->i = 0; this->i < 9; ++i){
			this->PuzzleArray[this->i][this->j].UpdatePossibilities(-1);
		}
		this->squarei = (this->externalhistoryArray->Getlocationi() / 3);
		this->squarej = (this->externalhistoryArray->Getlocationj() / 3);
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
			this->PuzzleArray[i + (3 * squarei)][j + (3 * squarej)].UpdatePossibilities(-1);
			}
		}
	}
}

void PuzzleClass::clearArray(int * array) {
	int ArraySize = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < ArraySize; i++) {
		array[i] = 0;
	}   
}

//this function passes a row of PossibilitiesSquares to SetValue
//value is the array of integers to insert into the row of PossibilitiesSquare
void PuzzleClass::insertIntoRowOfSquares(int * value, PossibilitiesSquare * puzzleRow) {
	int ArraySize = sizeof(puzzleRow) / sizeof(puzzleRow[0]);
	for (int i = 0; i < ArraySize; i++ ) {
			puzzleRow[i].SetValue(value[i]);

	}

}

/*
//This function uses NumbersSeenArray to update the available possibilities of each object in a row/column/box
//this function goes through EACH square of each row.
//We can move this into CheckerAndInitializer if we want.
void PuzzleClass::PossibilityUpdater(int * NumbersSeenArray, int ArraySize) {
	for (int k = 0; k < ArraySize; ++k) {//does this k get destroyed each time the function is finished?
		PuzzleArray[i][k].SetPossibilities(NumbersSeenArray, ArraySize);
	}	
}

void PuzzleClass::StoreRow(int InputArray[]) {
	int ArraySize = sizeof(InputArray) / sizeof(InputArray[0]);
	//reset i and j in case they were previously used
	this->i = 0;
	this->j = 0;
		for(; j < ArraySize; ++j){
		this->PuzzleArray[i][j] = InputArray[j];
		}
		++i;
	}
*/

PossibilitiesSquare ** PuzzleClass::GetPuzzle() {
	return this->PuzzleArray;

}

			
			
			
			
			
			
			
			
			
			