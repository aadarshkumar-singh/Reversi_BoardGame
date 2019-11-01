/*
 *  main.cpp
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */

// Standard (system) header files
#include <iostream>
#include <stdlib.h>


using namespace std;

// Add your project's header files here
// #include "CFraction.h"

enum BoardState_e
{
	empty     = '.',
	available = '?',
	player1   = 'x',
	player2   = 'o',
};

typedef BoardState_e BoardState_t ;

//query field state
BoardState_t queryBoardFieldState(int row, int column, char aptr[8][8]);


// Main program
int main (void)
{
	cout << "ReversiBoardGame started." << endl << endl;

	BoardState_t fieldState;
	int row ;
	int column;
	char a[8][8];

	for (int i = 0;i <8 ; i++)
		for (int j=0; j<8;j++)
		{
			a[i][j] = empty;

			if ((i==3  && j ==3) || (i==4 && j== 4))
			{
				a[i][j] = player1 ;
			}

			else if ((i==3  && j ==4) || (i==4 && j== 3))
			{
				a[i][j] = player2 ;
			}
		}


	for (int i = 0;i <8 ; i++)
	{
		for (int j=0; j<8;j++)
			cout<<a[i][j] <<"\t";
		cout << endl;
	}

    cout <<"Enter the row to be queried ";
    cin >> row ;
    cout <<"Enter the column to be queried ";
    cin >> column ;

    fieldState = queryBoardFieldState(row,column,a);
	cout <<"The state of the field is " << static_cast<char>(fieldState) ;

	return 0;
}

BoardState_t queryBoardFieldState(int m , int n , char aptr[8][8])
{
	BoardState_t state ;

	switch(aptr[m][n])
	{

	case '.':
		state = empty ;
		break ;

	case '?':
		state = available ;
		break ;

	case 'x':
		state = player1 ;
		break ;

	case 'o':
		state = player2 ;
		break ;

	}

	return state ;

}



