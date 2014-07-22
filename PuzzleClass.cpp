#include <iostream>
#include <string>
using namespace std;

class Puzzle{
	private:
	int PuzzleArray[9][9] = {0};
	int RowIndex = 0;
	int ColumnIndex = 0;
	
	
	public:

	{
		void StoreRow(int InputArray[]){
			int ArraySize = sizeof(InputArray) / sizeof(InputArray[0];
				for(; ColumnIndex < ArraySize; ++ColumnIndex){
				PuzzleArray[RowIndex][ColumnIndex] = InputArray[ColumnIndex];
				}
				++RowIndex;
			}
		}
		void CheckPuzzle(){
			int CheckCounter = 0;
			int DoubleCounter = 0;
			while CheckCounter < 9{
				for (; RowIndex < ArraySize; ++RowIndex){
				DoubleCounter = 0;
					for (; ColumnIndex < ArraySize; ++ColumnIndex){
						if PuzzleArray[RowIndex][ColumnIndex] == CheckCounter{
							++DoubleCounter;
						}
						if DoubleCounter > 1{
						cout << "This is not a proper Sudoku puzzle!" << endl;
						}
					}
				}
				++CheckCounter;
			}
			RowIndex = 0;
			ColumnIndex = 0;
			CheckCounter = 0;
			DoubleCounter = 0;
			while CheckCounter < 9{
				for (; ColumnIndex < ArraySize; ++ColumnIndex){
				DoubleCounter = 0;
					for (; RowIndex < ArraySize; ++RowIndex){
						if PuzzleArray[RowIndex][ColumnIndex] == CheckCounter
							++DoubleCounter;
						if DoubleCounter > 1{
						cout << "This is not a proper Sudoku puzzle!" << endl;
						}
					}
				}
				++CheckCounter;
			}
			
			RowIndex = 0;
			ColumnIndex = 0;
			int SquareRowIndex = 0;
			int SquareColumnIndex = 0;
			CheckCounter = 0;
			DoubleCounter = 0;
			SquareCounter = 0;
			while SquareCounter < 9{
				for (;SquareRowIndex < (ArraySize / 3); ++SquareRowIndex){
					for (;SquareColumnIndex < (ArraySize /3); ++SquareColumnIndex){
						while CheckCounter < 9{
						DoubleCounter = 0;
							for (; RowIndex < (ArraySize / 3); ++RowIndex){
								for (; ColumnIndex < (ArraySize / 3); ++ColumnIndex){
									if PuzzleArray[RowIndex + (3 * (SquareRowIndex + 1))][ColumnIndex + (3 * (SquareColumnIndex =1))] == CheckCounter{
									++DoubleCounter;
									}	
									if DoubleCounter > 1{
									cout << "This is not a proper Sudoku puzzle!" << endl;
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
		}				
		
		void SolvePuzzle(){

			
		}
			
			
				
						
			
			
			
			
			
			
			
			
			
			
			
			
	
}