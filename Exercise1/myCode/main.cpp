/*
 *  main.cpp
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */

// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include "ReversiBoard.h"

using namespace std;

// Add your project's header files here
// #include "CFraction.h"


int testQueryBoard(ReversiBoard board);



// Main program
int main (void)
{
	cout << "ReversiBoardGame started." << endl << endl;
	int check = 0;
	ReversiBoard board;


	check = board.identifyValidMoves('o');
	board.printBoard();
	if (check)
	{
		cout << "Correct" <<endl;

	}
	else
	{
		cout <<"Something wrong"<<endl;
	}
	//testQueryBoard(board);

	return 0;
}


int testQueryBoard(ReversiBoard board)
{
	BoardState_t fieldState;
	int row ;
	int column;
	cout <<"Enter the row to be queried ";
	cin >> row ;
	cout <<"Enter the column to be queried ";
	cin >> column ;

	fieldState = board.queryBoardFieldState(row,column);

	cout <<"The state of the field is " << static_cast<char>(fieldState) ;

	return 1 ;



}



