/*
 * ReversiBoard.h
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

#define REVERSIBOARDSIZE 8


enum BoardState_e
{
	empty     = '.',
	available = '?',
	player1   = 'x',
	player2   = 'o',
};

typedef BoardState_e BoardState_t ;


class ReversiBoard
{
	char m_board[REVERSIBOARDSIZE][REVERSIBOARDSIZE];
	char m_validMoves[REVERSIBOARDSIZE][REVERSIBOARDSIZE];

	void initValidMove();
	void checkEmptyDotValidMove(int nonEmptyRow, int nonEmptyCol, char player, int* noOfMoves);

public:
	ReversiBoard();
	void createBoard();
	BoardState_t queryBoardFieldState(int m , int n);
	void printBoard();
	int identifyValidMoves(char player);
};

#endif /* REVERSIBOARD_H_ */
