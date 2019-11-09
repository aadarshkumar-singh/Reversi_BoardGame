/*
 * ReversiBoard.cpp
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */
#include "iostream"
#include "ReversiBoard.h"

using namespace std;

ReversiBoard::ReversiBoard()
{
	/*
	 * Create the Reversi game Board array and initialize valid moves to empty
	 */
	initValidMove();
	createBoard();
}

void ReversiBoard::createBoard()
{
	/*
	 * Find the center tile and place x and o alternatively
	 */
	int findCenter = (REVERSIBOARDSIZE / 2);
	int findSecondCenter = ((REVERSIBOARDSIZE / 2) - 1);

	for (int i = 0;i <REVERSIBOARDSIZE ; i++)
		for (int j=0; j<REVERSIBOARDSIZE;j++)
		{
			m_board[i][j] = EMPTY;
			if ((i==findSecondCenter  && j ==findSecondCenter) || (i==findCenter && j== findCenter))
			{
				m_board[i][j] = TILE_X ;
			}
			else if ((i==findSecondCenter  && j ==findCenter) || (i==findCenter && j== findSecondCenter))
			{
				m_board[i][j] = TILE_O ;
			}
		}
}

BoardState_t ReversiBoard::queryBoardFieldState(int row, int column)
{
	BoardState_t state ;

	switch(m_board[row][column])
	{

	case '.':
		state = EMPTY ;
		break ;

	case '_':
		state = AVAILABLE ;
		break ;

	case 'x':
		state = TILE_X ;
		break ;

	case 'o':
		state = TILE_O ;
		break ;

	}

	return state ;

}

void ReversiBoard::initValidMove()
{
	for (int i = 0;i <REVERSIBOARDSIZE ; i++)
		for (int j=0; j<REVERSIBOARDSIZE;j++)
			m_validMoves[i][j] = EMPTY;
}

ValidMovesFlag_t ReversiBoard::identifyValidMoves(char player)
{
	int noOfmoves = 0;

	/* initialize valid move array to zero */
	initValidMove();

	/*
	 * checks if tile is empty, if empty calls check valid move
	 * to check player can place tile in which all coordinates
	 * returns valid move is available or not
	 */
	for (int row =0 ; row < REVERSIBOARDSIZE ; row++)
	{
		for (int col =0 ; col < REVERSIBOARDSIZE ;col++)
		{
			if (m_board[row][col] != EMPTY)
			{
				continue ;
			}
			else
			{
				checkValidMove(row,col,player,&noOfmoves);
			}
		}
	}

	/*
	 * If tiles are available for the player to move
	 * assign tile state to available
	 */
	for (int row =0 ; row < REVERSIBOARDSIZE ; row++)
	{
		for (int col =0 ; col < REVERSIBOARDSIZE ;col++)
		{
			if (m_validMoves[row][col] == AVAILABLE)
			{
				m_board[row][col] = AVAILABLE;

			}
		}
	}

	if (noOfmoves)
	{
		return VALID_MOVES_AVAILABLE ;
	}
	else
	{
		return NO_VALID_MOVES ;
	}
}


void ReversiBoard::checkValidMove(int nonEmptyRow, int nonEmptyCol, char player,int* noOfMoves)
{
	int traverseRow = 0;
	int traverseCol = 0;

	// get the rival player
	char rival = (player == 'x')?'o':'x' ;


	// Check the valid moves by traversing along all directions of the given row and column
	for (int rowshift =-1 ; rowshift <= 1 ; rowshift++)
	{
		for (int colshift =-1 ; colshift <= 1 ; colshift++)
		{
			traverseRow = nonEmptyRow + rowshift ;
			traverseCol = nonEmptyCol + colshift ;

			/*
			 * Check if while traversing the size of the board overflows, also
			 * if its the same tile around which we are checking
			 */
			if ( traverseRow < 0 || traverseRow >= REVERSIBOARDSIZE ||
					traverseCol < 0 || traverseCol >= REVERSIBOARDSIZE ||
					(nonEmptyRow == traverseRow && nonEmptyCol == traverseCol))
			{
				continue;
			}
			else
			{
				// Check if rival is present in and around the player
				if (static_cast<char>(m_board[traverseRow][traverseCol]) == rival)
				{

					/*
					 * if rival present keep traversing in the same direction untill board
					 * size overflows or we get EMPTY dot or we get player dot , make
					 * that row and column of board as AVAILABLE.
					 */
					while(1)
					{
						traverseRow += rowshift;
						traverseCol += colshift;

						if(traverseRow < 0 || traverseRow >= REVERSIBOARDSIZE || traverseCol < 0 || traverseCol >= REVERSIBOARDSIZE)
							break;


						if(m_board[traverseRow][traverseCol] == EMPTY)
							break;


						if(static_cast<char>(m_board[traverseRow][traverseCol]) == player)
						{
							// Populate the valid move array with available state
							m_validMoves[nonEmptyRow][nonEmptyCol] = AVAILABLE;
							(*(noOfMoves))++;
							break;
						}
					}

				}
			}
		}
	}

}

void ReversiBoard::placeTileOfPlayerAndFlipOpponent(int row, int column, char player)
{
	int traverseRow = 0;
	int traverseCol = 0;

	/*
	 * Replace the tiles with available state to empty state
	 * as available states have to be rechecked after placing the
	 * tile in the current move
	 */
	for (int i = 0 ; i< REVERSIBOARDSIZE ;i++)
	{
		for (int j = 0 ; j< REVERSIBOARDSIZE ;j++)
		{
			if (m_board[i][j] == AVAILABLE )
			{
				m_board[i][j] = EMPTY ;
			}
		}
	}

	// get the rival player
	char rival = (player == 'x')?'o':'x' ;

	m_board[row][column] = player ;


	// Move one tile in all direction and check if rival is present
	for (int rowshift =-1 ; rowshift <= 1 ; rowshift++)
	{
		for (int colshift =-1 ; colshift <= 1 ; colshift++)
		{
			traverseRow = row + rowshift ;
			traverseCol = column + colshift ;

			/*
			 * Check if while traversing the size of the board overflows, also
			 * if its the same tile around which we are checking
			 */
			if ( traverseRow < 0 || traverseRow >= REVERSIBOARDSIZE ||
					traverseCol < 0 || traverseCol >= REVERSIBOARDSIZE ||
					(row == traverseRow && column == traverseCol))
			{
				continue;
			}
			else
			{
				// Check if rival is present in and around the player
				if (static_cast<char>(m_board[traverseRow][traverseCol]) == rival)
				{

					/*
					 * if rival present keep traversing in the same direction untill board
					 * size overflows or we get EMPTY dot or we get player dot , Flip the
					 * all the opponent tile if player dot is encountered
					 */
					while(1)
					{
						traverseRow += rowshift;
						traverseCol += colshift;

						if(traverseRow < 0 || traverseRow >= REVERSIBOARDSIZE || traverseCol < 0 || traverseCol >= REVERSIBOARDSIZE)
							break;


						if(m_board[traverseRow][traverseCol] == EMPTY)
							break;


						if(static_cast<char>(m_board[traverseRow][traverseCol]) == player)
						{
							// move to the next consequtive square and search for rivals
							traverseRow = traverseRow - rowshift;
							traverseCol = traverseCol - colshift ;

							// checking if its rival player
							while(m_board[traverseRow][traverseCol] == rival)
							{
								// if rival , then turn tile to player
								m_board[traverseRow][traverseCol] = player ;
								// keep traversing in the same direction untill rival is encountered
								traverseRow = traverseRow - rowshift;
								traverseCol = traverseCol - colshift ;
							}
							break;

						}
					}

				}
			}
		}
	}

}

void ReversiBoard::calculateScores()
{
	int tileXscore = 0 ;
	int tileOscore = 0 ;

	for (int i = 0 ; i< REVERSIBOARDSIZE ;i++)
	{
		for (int j = 0 ; j< REVERSIBOARDSIZE ;j++)
		{
			if (m_board[i][j] == TILE_X )
			{
				tileXscore++ ;
			}
			else if (m_board[i][j] == TILE_O)
			{
				tileOscore++;
			}
		}
	}

	cout << "Total x tiles ::" <<tileXscore <<endl ;
	cout << "Total o tiles ::" <<tileOscore <<endl ;

	if (tileXscore > tileOscore)
	{
		cout << "Winner is player denoted by Tile " <<static_cast<char>(TILE_X)
											 <<" With margin of "<<(tileXscore - tileOscore)<<endl;
	}
	else
	{
		cout << "Winner is player denoted by Tile " <<static_cast<char>(TILE_O)
											 << " With margin of "<<(tileOscore - tileXscore)<<endl;
	}
}

char ReversiBoard::getBoardElement(int row, int column)
{
	return(m_board[row][column]);
}

PlayerInfo_t ReversiBoard::selectTileToStart()
{
	PlayerInfo_t startingPlayer = INVALID_PLAYER;
	char selectTile ;

	cout <<"Enter first player wants which tile :: x/o"<<endl;
	cin>>selectTile;

	selectTile = tolower(selectTile);

	if (selectTile == 'x')
	{
		startingPlayer = PLAYER_TILE_X;
	}
	else if (selectTile == 'o')
	{
		startingPlayer = PLAYER_TILE_O;
	}
	else
	{
		startingPlayer = INVALID_PLAYER;
	}

	return startingPlayer;
}

