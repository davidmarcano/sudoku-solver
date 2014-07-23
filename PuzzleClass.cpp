#include <iostream>
#include <string>
using namespace std;

class Puzzle{
	private:
	int PuzzleArray[9][9] = {0};
	int i = 0, j = 0;
	
	public:	

	void StoreRow(int InputArray[]) {
		int ArraySize = sizeof(InputArray) / sizeof(InputArray[0]);
		//reset i and j in case they were previously used
		i = 0;
		j = 0;
			for(; j < ArraySize; ++j){
			PuzzleArray[i][j] = InputArray[j];
			}
			++i;
		}

	//returns true if the puzzle is proper, false otherwise.
	bool CheckPuzzle(){
		int CheckCounter = 1;
		int DoubleCounter = 0;
		//reset i and j in case they were previously used
		i = 0;
		j = 0;
		int ArraySize = sizeof(InputArray) / sizeof(InputArray[0]);
		//this is to check the row validity
		while (CheckCounter < 9) {
			for (; i < ArraySize; ++i){
				//resets DoubleCounter when moving from row to row
				DoubleCounter = 0;
				for (; j < ArraySize; ++j){
					if (PuzzleArray[i][j] == CheckCounter) {
						++DoubleCounter;
					}
					if (DoubleCounter > 1) {
					cout << "This is not a proper Sudoku puzzle!" << endl;
					return false;
					}
				}
			}
			++CheckCounter;
		}

		//this is to check column validity
		i = 0;
		j = 0;
		CheckCounter = 0;
		DoubleCounter = 0;
		while (CheckCounter < 9) {
			for (; j < ArraySize; ++j){
			DoubleCounter = 0;
				for (; i < ArraySize; ++i){
					if (PuzzleArray[i][j] == CheckCounter) {
						++DoubleCounter;
					}
					if (DoubleCounter > 1) {
					cout << "This is not a proper Sudoku puzzle!" << endl;
					return false;
					}
				}
			}
			++CheckCounter;
		}
		
		//this is to check box validity
		i = 0;
		j = 0;
		int Squarei = 0;
		int Squarej = 0;
		CheckCounter = 0;
		DoubleCounter = 0;
		//squareCounter is the index of the square within the 3x3 puzzle
		SquareCounter = 0;
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
								if DoubleCounter > 1{
								cout << "This is not a proper Sudoku puzzle!" << endl;
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
		
		cout<< "The entered Sudoku board is proper." << endl;
		return true;
	}				
	
	void SolvePuzzle(){
			
	}
			
			
				
						
			
			
			
			
			
			
			
			
			
			
			
			
	
}