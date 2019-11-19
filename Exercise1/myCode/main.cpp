/**
 * \file main.cpp
 * \author Aadarsh Kumar Singh
 * \date 06.11.2019
 *
 * \brief main.cpp
 * \n starts the Reversi Game. Uses object of ReversiClass to get the moves of the players,
 *  validate and make the move. Uses the Object of ReversiConsoleView to display the state
 *  of board.
 *
 */

// Standard (system) header files
#include <iostream>
#include <stdlib.h>

using namespace std;

// project's header files here
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

/**
 * \brief Maximum number of moves possible in 8*8 array
 */
#define MAXIMUM_NUMBER_OF_MOVES 64

/**
 * Displays the state of board with valid moves and Places the tile as per the players turn
 * in the valid coordinates. Also flips the opponents as per reversi game logic.
 *
 * @param 	isPlayerTile		   : is the tile to be placed as per players turn(x/o)
 * @param	board 	  			   : Object of the ReversiBoard Class
 * @param 	boardViewobj		   : Object of the ReversiConsoleView
 * @param 	noOfmoves[input/output]: Total no of moves played totally
 * @return 	ValidMovesLeft	 	   : VALID_MOVES_AVAILABLE - If valid moves are available
 * 								     NO_VALID_MOVES - If valid moves are not available
 */
ValidMovesFlag_t getCoordinateFromPlayer(char isPlayerTile ,ReversiBoard& board , ReversiConsoleView& boardViewobj, int& noOfmoves);

// Main program
int main (void)
{
	int noOfmoves = 0 ;
	int player = 0 ;
	ValidMovesFlag_t validMovesLeft = VALID_MOVES_AVAILABLE;
	ReversiBoard board;
	ReversiConsoleView boardViewobj(&board);

	cout <<"---------------------------------------------"<<endl;
	cout <<" Welcome to play the Reversi Game " <<endl <<endl ;
	cout <<" General Rules first " << endl<<endl;
	cout <<" Reversi Game is (8 x 8), 2 player game "<<endl ;
	cout <<" In the board , " <<endl <<" 'x'stands for player 1"<<endl<<" 'o' stands for player 2 " <<endl;
	cout <<" '.' stands for the EMPTY places"<<endl<< " '_' stands for AVAILABLE places for placing the piece " <<endl<<endl;
	cout <<" The player has to enter the row and column where they want to place there piece" <<endl ;
	cout <<" The values for rows and columns should be in the range (0-7)" <<endl<<endl;
	cout <<" Lets play the ReversiBoardGame." << endl ;
	cout <<"---------------------------------------------"<<endl<<endl ;

	/*
	 * Reads which tile x or o starts first
	 */
	player= board.selectTileToStart();

	if (player != INVALID_PLAYER)
	{
		/*
		 * Keeps Placing the tile as per player coordinates untill valid moves are available.
		 */
		do
		{
			noOfmoves = 4 ; // Since already 4 moves are done.

			if(player == PLAYER_TILE_X)
			{
				validMovesLeft = getCoordinateFromPlayer(TILE_X,board,boardViewobj,noOfmoves);
				player =PLAYER_TILE_O ;
			}

			else
			{
				validMovesLeft = getCoordinateFromPlayer(TILE_O,board,boardViewobj,noOfmoves);
				player =PLAYER_TILE_X ;
			}

		}while((noOfmoves < MAXIMUM_NUMBER_OF_MOVES) && (validMovesLeft == VALID_MOVES_AVAILABLE) );

		board.calculateScores();
	}
	else
	{
		cout<<"Invalid Input tile selected to start the game, please start the game again "<<endl;
	}

	return 0;
}


ValidMovesFlag_t getCoordinateFromPlayer(char isPlayerTile ,ReversiBoard& board , ReversiConsoleView& boardViewobj, int& noOfmoves)
{
	ValidMovesFlag_t validMovesLeft = VALID_MOVES_AVAILABLE ;
	int rowChoice = 0 ;
	int colChoice = 0 ;
	char playerTile = (static_cast<char>(isPlayerTile)) ;

	// Identify the valid moves
	if (board.identifyValidMoves(playerTile))
	{
		// Display the Board with Valid Moves
		boardViewobj.printBoard();

		cout<<playerTile<< " Player's turn " <<endl ;

		while(1)
		{
			cout << "Enter move row column "<<endl;
			cin>>rowChoice >> colChoice;

			/*
			 * Query the Field State , check if the entered row is within the board
			 * and the row and Coloumn is available for placing.
			 */
			if (rowChoice < 0 || rowChoice > REVERSIBOARDSIZE ||
					colChoice < 0 || colChoice > REVERSIBOARDSIZE ||
					board.queryBoardFieldState(rowChoice,colChoice) != AVAILABLE)
			{
				cout<<"Not a valid move , try again "<<endl ;
			}
			else
			{

				/*
				 * Make the move if available , flip the tiles as per Reversi Game Logic
				 */
				board.placeTileOfPlayerAndFlipOpponent(rowChoice,colChoice,playerTile);
				noOfmoves++ ;
				break;
			}
		}
	}
	else
	{
		/*
		 *  Print the Board and display no more valid moves remaining
		 */
		boardViewobj.printBoard();
		cout << "no valid moves remaining for ("<<playerTile<<") , Game Over !!!" <<endl;
		validMovesLeft = NO_VALID_MOVES;
	}

	return validMovesLeft ;
}
