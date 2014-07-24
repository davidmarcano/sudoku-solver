#include <iostream>
#include <string>
#include <typeinfo>
#include "PuzzleClass.hpp"
#include "PossibilitiesSquare.hpp"




void PuzzleClass::insertIntoSquare(int * value, PossibilitiesSquare * puzzle) {
	int ArraySize = sizeof(puzzle) / sizeof(puzzle[0]);
	for (int i = 0; i < ArraySize; i++ ) {
			puzzle[i].SetValue(value[i]);

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

bool PuzzleClass::CheckerAndInitializer(int & NumbersSeenArray[], int ArraySize, PuzzleClass PuzzleArray, int i, int j) {
	for (; i < ArraySize; ++i){
		//resets DoubleCounter when moving from row to row
		for (; j < ArraySize; ++j){
			//builds NumbersSeenArray for a row and checks for validity
			if ((this->PuzzleArray[i][j].GetValue() > 0)) {
				int PuzzleNumber = PuzzleArray[i][j].GetValue();
				++NumbersSeenArray[PuzzleNumber - 1];
				if (NumbersSeenArray[PuzzleNumber - 1] > 1){
					std::cout << "This is not a proper Sudoku puzzle!" << std::endl;
					return false;
				}
				
			}
		}
		//go through the Square objects and update them based on NumbersSeenArray
		for (int k = 0; k < ArraySize; k++){
			PuzzleArray[i][k].PossibilityUpdater(NumbersSeenArray);
		}
		

	}
	return true;
}

void clearArray(int array[]&) {
	int ArraySize = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < ArraySize; i++) {
		array[i] = 0;
	}   
}
//This function uses NumbersSeenArray to update the available possibilities of each object in a row/column/box
void PuzzleClass::PossibilityUpdater(int * NumbersSeenArray) {
	for (int k = 0; k < ArraySize; ++k) {
		PuzzleArray[i][k].PossibilitiesSquare::SetPossibilities(NumbersSeenArray, k);
	}	
}

//returns true if the puzzle is proper, false otherwise.
bool PuzzleClass::CheckPuzzle() {	
	this->i = 0;
	this->j = 0;
	//reset i and j in case they were previously used
	int ArraySize = sizeof(this->PuzzleArray[0]) / sizeof(this->PuzzleArray[0][0]);
	std::cout << ArraySize << std::endl;
	//this is to check the row validity
	//while (CheckCounter < 9) {
	int NumbersSeenArray[9] = {0};

	PuzzleClass::Checker(NumbersSeenArray, ArraySize, this->PuzzleArray, this->i, this->j);
	clearArray(NumbersSeenArray);

	this->i = 0;
	this->j = 0;
	PuzzleClass::Checker(NumbersSeenArray, ArraySize, this->PuzzleArray, this->j, this->i);
	
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
				CheckCounter = 0;
					//similar to Checking for row/column validity, only within each Square
				while (CheckCounter < 9) {
					DoubleCounter = 0;
					for (; i < (ArraySize / 3); ++i){
						for (; j < (ArraySize / 3); ++j){
							if (PuzzleArray[i + (3 * Squarei)][j + (3 * Squarej)] == CheckCounter) {
							++DoubleCounter;
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
	return true;
}				

void PuzzleClass::SolvePuzzle(){
	std::cout << "You've solved the puzzle!" << std::endl;
	PuzzleClass::CheckPuzzle();


}

PuzzleClass ** GetPuzzle() {
	return this->PuzzleArray;
}
//Inputs: Takes a square and compares its number of possible values to a minimum value. If it is the minimum, we keep track of it via a pointer.
void PuzzleClass::MinimumSquare(PossibilitiesSquare InputSquare, int minimum, PossibilitiesSquare * minimumSquare){
	//int minimum = 9 This will go to our main function
	//This needs to be placed outside the function before the function is called
	//PossibilitiesSquare * minimumSquare = new PossibilitiesSquare();
	//minimumSquare = &InputSquare;
	if (InputSquare.GetnumberPossible < minimum){
		minimum = InputSquare.GetnumberPossible;
		
	}
}
			
				
						
			
			
			
			
			
			
			
			
			
			
			