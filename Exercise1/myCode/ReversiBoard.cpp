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

void ReversiBoard::initValidMove()
{
	for (int i = 0;i <REVERSIBOARDSIZE ; i++)
		for (int j=0; j<REVERSIBOARDSIZE;j++)
			m_validMoves[i][j] = empty;
}


void ReversiBoard::printBoard()
{

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

	for (int i = 0;i <REVERSIBOARDSIZE ; i++)
	{
		for (int j=0; j<REVERSIBOARDSIZE;j++)
			cout<<m_board[i][j] <<"\t";
		cout << endl;
	}
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

	if (noOfmoves)
	{
		return 1 ;
	}
	else
	{
		return 0 ;
	}


}


void ReversiBoard::checkEmptyDotValidMove(int vrow, int vcol, char player,int* noOfMoves)
{
	int trow = 0;
	int tcol = 0;

	// get the rival player
	char rival = (player == 'x')?'o':'x' ;


	// Check the available options by traversing each row and column
	for (int rowshift =-1 ; rowshift <= 1 ; rowshift++)
	{
		for (int colshift =-1 ; colshift <= 1 ; colshift++)
		{

			if (vrow + rowshift < 0 || vrow + rowshift >= REVERSIBOARDSIZE ||
				vcol + colshift < 0 || vcol + colshift >= REVERSIBOARDSIZE ||
				(rowshift == 0 && colshift == 0))
			{
				continue;
			}
			else
			{

				if (static_cast<char>(m_board[vrow + rowshift][vcol + colshift]) == rival)
				{
					trow = vrow + rowshift ;
					tcol = vcol + colshift ;

					while(1)
					{
						trow += rowshift;                  /* Go to next square */
						tcol += colshift;                  /* in delta direction*/
						/* Board size overflow , then break  */
						if(trow < 0 || trow >= REVERSIBOARDSIZE || tcol < 0 || tcol >= REVERSIBOARDSIZE)
							break;

						/* if found blank square , break */
						if(m_board[trow][tcol] == empty)
							break;

						/*  If the dot has player */
						/*  then we have a valid move */
						if(static_cast<char>(m_board[trow][tcol]) == player)
						{

							m_validMoves[vrow][vcol] = available;   /* Mark as available */
							(*(noOfMoves))++;
							break;
						}
					}

				}
			}
		}
	}

}
