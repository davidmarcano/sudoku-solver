sudoku-solver
=============

This contains our solution for a sudoku solver in C++

Solution was written before learning about basic DFS stack algorithm in school.
Plans to formalize this solution with a proper stack ADT implementation and 
compare runtimes and memory usage.
Can eventually be modularized to handle any 2^n sized sudoku puzzles.
Commenting will be added regularly as the semester winds down


Basic Algorithnm:

We employ a DFS search, testing open squares with the minimum possible choices 
to ensure a faster average runtime than a brute force method. 
We then simply loop until all squares on the board are filled in. 


Class and function structure:
1.
main() - asks user for sudoku puzzle from file or by hand (any open space is 
represented by a 0)

2.
Parser class - parses inputted file or manual input and sends information to
the puzzle class.

3.
Puzzle class - contains game board and external history array, which stores
the order of all currently placed squares. Also in charge of printing puzzle

4.
Square class - contains value of square; the possible numbers array, 
which determines which values the square can still be; and the internal 
history array, which logs all changes to squares that share a commmon row, 
column and/or box.

5.
Solver class - invoked to check if puzzle is valid and handles the 
solving algorithm.

Current gameplan:
  Simplify code structure by employing stack ADT implementation
  Create flowchart to show algorithm process
  Comment more and reduce line length
  Compare runtimes and memory usage between current implementation
  and future one.

