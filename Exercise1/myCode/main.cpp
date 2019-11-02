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

	int rowChoice = 0 ;
	int colChoice = 0 ;
	int noOfGames = 0 ; // its user choice to play the next game or not, first game player 1 plays first, then 2nd game player 2 plays first, but always player 1 is x player 2 is o
	int noOfmoves = 0 ;
	char playAgain = 'n';
	int player = 0 ;
	ReversiBoard board;

	do
	{
		++noOfGames ; // keep incrementing no of games if user plays again

		player = noOfGames % 2 ; // to decide of player 1 or player 2 plays first
		noOfmoves = 4 ; // Since already 4 moves are done.

		do
		{

			if(player % 2)
			{
				if (board.identifyValidMoves(static_cast<char>(player1)))
				{
					board.printBoard();

					cout << "Player-1 : turn , denoted by " <<static_cast<char>(player1) << endl ;

					while(1)
					{
						cout << "Enter move row column "<<endl;
						cin>>rowChoice >> colChoice;


						if (rowChoice < 0 || rowChoice > REVERSIBOARDSIZE ||
								colChoice < 0 || colChoice > REVERSIBOARDSIZE ||
								board.queryBoardFieldState(rowChoice,colChoice) == available)
						{
							board.makeValidMoves(rowChoice,colChoice,static_cast<char>(player1));
							noOfmoves++ ;
							break;
						}
						else
						{
							cout<<"Not a valid move , try again "<<endl ;
						}

					}

				}
				else
				{
					cout << "no valid moves remaining " ;
				}

				player++;
			}

			else
			{
				if (board.identifyValidMoves(static_cast<char>(player2)))
				{
					board.printBoard();

					cout << "Player-2 : turn , denoted by " <<static_cast<char>(player2) << endl ;

					while(1)
					{
						cout << "Enter move row column "<<endl;
						cin>>rowChoice >> colChoice;

						if (rowChoice < 0 || rowChoice > REVERSIBOARDSIZE ||
								colChoice < 0 || colChoice > REVERSIBOARDSIZE ||
								board.queryBoardFieldState(rowChoice,colChoice) == available)
						{
							board.makeValidMoves(rowChoice,colChoice,static_cast<char>(player2));
							noOfmoves++ ;
							break;
						}
						else
						{
							cout<<"Not a valid move , try again "<<endl ;
						}

					}

				}
				else
				{
					cout << "no valid moves remaining " ;
				}

				player++;
			}

		}while(noOfmoves < (REVERSIBOARDSIZE * REVERSIBOARDSIZE) );


		cout<<"Do you want to play again(y/n)"<<endl ;
		cin>>playAgain ;
		playAgain = tolower(playAgain);

	}while (playAgain == 'y');








/*

	check = board.identifyValidMoves('o');
	board.makeValidMoves(3,2,'o');

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
*/

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



