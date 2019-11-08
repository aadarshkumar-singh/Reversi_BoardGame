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
			m_board[i][j] = empty;

			if ((i==3  && j ==3) || (i==4 && j== 4))
			{
				m_board[i][j] = player1 ;
			}

			else if ((i==3  && j ==4) || (i==4 && j== 3))
			{
				m_board[i][j] = player2 ;
			}
		}
}

BoardState_t ReversiBoard::queryBoardFieldState(int m, int n)
{
	BoardState_t state ;

	switch(m_board[m][n])
	{

	case '.':
		state = empty ;
		break ;

	case '_':
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

void ReversiBoard::initValidMove()
{
	for (int i = 0;i <REVERSIBOARDSIZE ; i++)
		for (int j=0; j<REVERSIBOARDSIZE;j++)
			m_validMoves[i][j] = empty;
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
			if (m_board[row][col] != empty)
			{
				continue ;
			}
			else
			{
				checkEmptyDotValidMove(row,col,player,&noOfmoves);
			}
		}
	}

	for (int row =0 ; row < REVERSIBOARDSIZE ; row++)
	{
		for (int col =0 ; col < REVERSIBOARDSIZE ;col++)
		{
			if (m_validMoves[row][col] == available)
			{
				m_board[row][col] = available;

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


void ReversiBoard::checkEmptyDotValidMove(int nonEmptyRow, int nonEmptyCol, char player,int* noOfMoves)
{
	int traverseRow = 0;
	int traverseCol = 0;

	// get the rival player
	char rival = (player == 'x')?'o':'x' ;


	// Check the available options by traversing each row and column
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

					// if available keep transversing in the same direction untill board
					// size overflows or we get empty dot or we get player dot , make
					// that row and column of board as available.
					while(1)
					{
						traverseRow += rowshift;
						traverseCol += colshift;

						if(traverseRow < 0 || traverseRow >= REVERSIBOARDSIZE || traverseCol < 0 || traverseCol >= REVERSIBOARDSIZE)
							break;


						if(m_board[traverseRow][traverseCol] == empty)
							break;


						if(static_cast<char>(m_board[traverseRow][traverseCol]) == player)
						{

							m_validMoves[nonEmptyRow][nonEmptyCol] = available;   /* Mark as available */
							(*(noOfMoves))++;
							break;
						}
					}

				}
			}
		}
	}

}

void ReversiBoard::makeValidMoves(int urow, int ucol, char player)
{
	int traverseRow = 0;
	int traverseCol = 0;

	// Remove the available pieces on the board as after this move we need to set
	// available pieces again

	for (int i = 0 ; i< REVERSIBOARDSIZE ;i++)
	{
		for (int j = 0 ; j< REVERSIBOARDSIZE ;j++)
		{
			if (m_board[i][j] == available )
			{
				m_board[i][j] = empty ;
			}
		}
	}

	// get the rival player
	char rival = (player == 'x')?'o':'x' ;

	m_board[urow][ucol] = player ;


	// Check the available options by traversing each row and column
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

					// if available keep transversing in the same direction untill board
					// size overflows or we get empty dot or we get player dot , make
					// that row and column of board as available.
					while(1)
					{
						traverseRow += rowshift;
						traverseCol += colshift;

						if(traverseRow < 0 || traverseRow >= REVERSIBOARDSIZE || traverseCol < 0 || traverseCol >= REVERSIBOARDSIZE)
							break;


						if(m_board[traverseRow][traverseCol] == empty)
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

void ReversiBoard::calculateScores(int &p1Score, int &p2Score)
{
	p1Score = 0 ;
	p2Score = 0 ;

	for (int i = 0 ; i< REVERSIBOARDSIZE ;i++)
	{
		for (int j = 0 ; j< REVERSIBOARDSIZE ;j++)
		{
			if (m_board[i][j] == player1 )
			{
				p1Score++ ;
			}
			else if (m_board[i][j] == player2)
			{
				p2Score++;
			}
		}
	}

	cout << "Player 1 Scored ::" <<p1Score <<endl ;
	cout << "Player 2 Scored ::" <<p2Score <<endl ;

	if (p1Score > p2Score)
	{
		cout << "Winner is player 1 denoted by " <<static_cast<char>(player1)
					 << "With margin of "<<(p1Score - p2Score)<<endl;
	}
	else
	{
		cout << "Winner is player 2 denoted by (" <<static_cast<char>(player2)
					 << "), With margin of "<<(p2Score - p1Score)<<endl;
	}

}

char ReversiBoard::readBoardElement(int row, int column)
{
	return(m_board[row][column]);
}
