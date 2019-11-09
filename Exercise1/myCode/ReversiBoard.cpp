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
	initValidMove();
	createBoard();
}

void ReversiBoard::createBoard()
{
	for (int i = 0;i <REVERSIBOARDSIZE ; i++)
		for (int j=0; j<REVERSIBOARDSIZE;j++)
		{
			m_board[i][j] = EMPTY;

			if ((i==3  && j ==3) || (i==4 && j== 4))
			{
				m_board[i][j] = TILE_X ;
			}

			else if ((i==3  && j ==4) || (i==4 && j== 3))
			{
				m_board[i][j] = TILE_O ;
			}
		}
}

BoardState_t ReversiBoard::queryBoardFieldState(int m, int n)
{
	BoardState_t state ;

	switch(m_board[m][n])
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

int ReversiBoard::identifyValidMoves(char player)
{
	int noOfmoves = 0;

	/* initialize valid move array to zero */
	initValidMove();


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
		return 1 ;
	}
	else
	{
		return 0 ;
	}


}


void ReversiBoard::checkValidMove(int nonEmptyRow, int nonEmptyCol, char player,int* noOfMoves)
{
	int traverseRow = 0;
	int traverseCol = 0;

	// get the rival player
	char rival = (player == 'x')?'o':'x' ;


	// Check the AVAILABLE options by traversing each row and column
	for (int rowshift =-1 ; rowshift <= 1 ; rowshift++)
	{
		for (int colshift =-1 ; colshift <= 1 ; colshift++)
		{
			traverseRow = nonEmptyRow + rowshift ;
			traverseCol = nonEmptyCol + colshift ;

			// Check if while traversing the size of the board overflows
			// Also check if its the same unfilled box around which we
			// are checking
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

					// if AVAILABLE keep transversing in the same direction untill board
					// size overflows or we get EMPTY dot or we get player dot , make
					// that row and column of board as AVAILABLE.
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

							m_validMoves[nonEmptyRow][nonEmptyCol] = AVAILABLE;   /* Mark as AVAILABLE */
							(*(noOfMoves))++;
							break;
						}
					}

				}
			}
		}
	}

}

void ReversiBoard::FlipOpponent(int urow, int ucol, char player)
{
	int traverseRow = 0;
	int traverseCol = 0;

	// Remove the AVAILABLE pieces on the board as after this move we need to set
	// AVAILABLE pieces again

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

	m_board[urow][ucol] = player ;


	// Check the AVAILABLE options by traversing each row and column
	for (int rowshift =-1 ; rowshift <= 1 ; rowshift++)
	{
		for (int colshift =-1 ; colshift <= 1 ; colshift++)
		{
			traverseRow = urow + rowshift ;
			traverseCol = ucol + colshift ;

			// Check if while traversing the size of the board overflows
			// Also check if its the same unfilled box around which we
			// are checking
			if ( traverseRow < 0 || traverseRow >= REVERSIBOARDSIZE ||
					traverseCol < 0 || traverseCol >= REVERSIBOARDSIZE ||
					(urow == traverseRow && ucol == traverseCol))
			{
				continue;
			}
			else
			{
				// Check if rival is present in and around the player
				if (static_cast<char>(m_board[traverseRow][traverseCol]) == rival)
				{

					// if AVAILABLE keep transversing in the same direction untill board
					// size overflows or we get EMPTY dot or we get player dot , make
					// that row and column of board as AVAILABLE.
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
								// if rival , then turn to player
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

char ReversiBoard::readBoardElement(int row, int column)
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

