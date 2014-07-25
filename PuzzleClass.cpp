#include <iostream>
#include <string>
#include <typeinfo>
#include "PuzzleClass.hpp"
#include "PossibilitiesSquare.hpp"


void PuzzleClass::SetPuzzleArray(PossibilitiesSquare ** PuzzleArray){
	for (;this->i < 9; ++(this->i){
		for (;this->j < 9; ++(this->j){
				this->PuzzleArray[this->i][this->j] = 0;
			}
		}
	}
}

void PuzzleClass::SolvePuzzle(){
	PuzzleClass::CheckPuzzle();
	//Something else needs to happen to continue the application.
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

	this->CheckerAndInitializer(NumbersSeenArray, ArraySize, this->i, this->j);
	clearArray(NumbersSeenArray);

	this->i = 0;
	this->j = 0;
	this->CheckerAndInitializer(NumbersSeenArray, ArraySize, this->j, this->i);
	clearArray(NumbersSeenArray);
	
	//Eventually this will be done for the boxes too
	/*CheckCounter = 0;
	DoubleCounter = 0;
	while (CheckCounter < 9) {
		for (; j < ArraySize; ++j){
		DoubleCounter = 0;
			for (; i < ArraySize; ++i){
				if (PuzzleArray[i][j] == CheckCounter) {
					++DoubleCounter;
				}
				if (DoubleCounter > 1) {
				std::cout << "This is not a proper Sudoku puzzle!" << std::endl;
				return false;
				}
			}
		}
		++CheckCounter;
	}*/
	
	//this is to check box validity
	
/*---------------------------------------------------------------------------
	this->i = 0;
	this->j = 0;
	int Squarei = 0;
	int Squarej = 0;
	CheckCounter = 0;
	DoubleCounter = 0;
	//squareCounter is the index of the square within the 3x3 puzzle
	int SquareCounter = 0;
	while (SquareCounter < 9) {
		for (;Squarei < (ArraySize / 3); ++Squarei) {
			//reset Squarej when moving to the next row of Squares
				Squarej = 0;
			for (;Squarej < (ArraySize /3); ++Squarej) {
				//reset CheckCounter when moving to another Square
				//CheckCounter = 0;
					//similar to Checking for row/column validity, only within each Square
				while (CheckCounter < 9) {
					//DoubleCounter = 0;
					for (; i < (ArraySize / 3); ++i){
						for (; j < (ArraySize / 3); ++j){
							if (PuzzleArray[i + (3 * Squarei)][j + (3 * Squarej)] == CheckCounter) {
							//++DoubleCounter;
							}	
							if (DoubleCounter > 1) {
							std::cout << "This is not a proper Sudoku puzzle!" << std::endl;
							return false;
							}
						}	
					}
				++CheckCounter;
				}
			}
		}
		++SquareCounter;
	}
	
	std::cout<< "The entered Sudoku board is proper." << std::endl;
	--------------------------------------------------------------------------------*/
	return true;

}				

bool PuzzleClass::CheckerAndInitializer(int * NumbersSeenArray, const int ArraySize, int i, int j) {
	for (; i < ArraySize; ++i){
		//resets DoubleCounter when moving from row to row
		for (; j < ArraySize; ++j){
			//builds NumbersSeenArray for a row/column and checks for validity
			if ((this->PuzzleArray[i][j].GetValue() > 0)) {
				int puzzleNumber = this->PuzzleArray[i][j].GetValue();
				NumbersSeenArray[puzzleNumber - 1]++;//is there a problem here?
				if (NumbersSeenArray[puzzleNumber - 1] > 1){
					std::cout << "This is not a proper Sudoku puzzle!" << std::endl;
					return false;

					//We need to add functionality to check for the boxes too!! FUCKKK
				}
				
			}
		}
		//goes through the row/column and updates each square's Possibilities via NumbersSeenArray
		this->j = 0;
		this->PuzzleArray->UpdatePuzzleArray(NumbersSeenArray, ArraySize);//check input
		}
		

	}
	return true;
}

void PuzzleClass::UpdatePuzzleArray(int * NumbersSeenArray, const int ArraySize){
		for (;this->j < ArraySize; ++(this->j){
				this->PuzzleArray[this->i][this->j]->SetPossibilities(NumbersSeenArray, ArraySize);
		}
		this->j = 0;
}

//Inputs: Takes a square and compares its number of possible values to a minimum value. If it is the minimum, we keep track of it via a pointer.
//This needs to be called by the function that intializes each square's numberpossible.
void PuzzleClass::MinimumSquare(PossibilitiesSquare * InputSquare,){
	//int minimum = 9 This will go to our main function
	//minimumSquare = &InputSquare;
	if (InputSquare->GetnumberPossible() < minimum){
		minimumSquare = InputSquare;
		minimum = InputSquare->GetnumberPossible();
		
	}
}

void PuzzleClass::SetMinimumSquare(){
	for (int i = 0; i < 9; ++i){
		for (int j = 0; j < 9; ++j){
			
		}
	}
}
void PuzzleClass::UpdateInternalArray(int FLAG){
	
	if (FLAG == 1){
		this->i = this->minimumSquare->Getlocationi();
		for (this->j = 0; this->j < 9; ++(this->j){
			this->PuzzleArray[this->i][this->j]->internalhistoryArray = this->minimumSquare->GetValue();
			this->PuzzleArray[this->i][this->j]->UpdatePossibilities(1);
		}

		this->j = this->minimumSquare->Getlocationj();
		for (this->i = 0; this->i < 9; ++i){
			this->PuzzleArray[this->i][this->j]->internalhistoryArray = this->minimumSquare->GetValue();
			this->PuzzleArray[this->i][this->j]->UpdatePossibilities(1);
		//We need another for loop here for the box.
		}
	}
	if (FLAG == -1){
		this->i = this->minimumSquare->Getlocationi();
		for (this->j = 0; this->j < 9; ++(this->j){
			this->PuzzleArray[this->i][this->j]->UpdatePossibilities(-1);
		}
		this->j = this->minimumSquare->Getlocationj();
		for (this->i = 0; this->i < 9; ++i){
			this->PuzzleArray[this->i][this->j]->UpdatePossibilities(-1);
		//We need another for loop here for the box.
		}
	}
}


//This function uses NumbersSeenArray to update the available possibilities of each object in a row/column/box
//this function goes through EACH square of each row.
//We can move this into CheckerAndInitializer if we want.
void PuzzleClass::PossibilityUpdater(int * NumbersSeenArray, int ArraySize) {
	for (int k = 0; k < ArraySize; ++k) {//does this k get destroyed each time the function is finished?
		PuzzleArray[i][k]->SetPossibilities(NumbersSeenArray, ArraySize);
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

			
			
			
			
			
			
			
			
			
			