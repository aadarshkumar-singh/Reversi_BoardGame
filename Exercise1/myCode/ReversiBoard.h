/*
 * ReversiBoard.h
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

#define REVERSIBOARDSIZE 8

/**
 * \brief Define the states of the board
 */
enum BoardState_e
{
	EMPTY     = '.',	//!< EMPTY - no tile is placed on the board
	AVAILABLE = '_',	//!< AVAILABLE - player move is valid and can place the tile in the coordinate
	TILE_X   = 'x', 	//!< TILE_X - Represents the Tile of the player
	TILE_O   = 'o', 	//!< TILE_O - Represents Tile of opponent
};
typedef BoardState_e BoardState_t ;

/**
 * Defines the player
 */
enum PlayerInfo_e
{
	INVALID_PLAYER,//!< INVALID_PLAYER : user provides invalid value (other than x/o)
	PLAYER_TILE_X, //!< PLAYER_TILE_X  : Player placing x tile
	PLAYER_TILE_O, //!< PLAYER_TILE_O  : Player placing o tile
};
typedef PlayerInfo_e PlayerInfo_t ;

/**
 * \brief Provides APIs to :
 * \n Create and assign initial states to the board. Get the coordinates from players
 * and check there validity , If valid place the tile and flip the opponets tile as per
 * Reversi game logic.
 * \n Data Members : 2-D char array represents board and valid move array
 */
class ReversiBoard
{
	char m_board[REVERSIBOARDSIZE][REVERSIBOARDSIZE];
	char m_validMoves[REVERSIBOARDSIZE][REVERSIBOARDSIZE];

	/**
	 *	Initializes the valid move with empty values
	 */
	void initValidMove();

	/**
	 * Check all possible valid moves that the player can make and assign the
	 * corresponding coordinates to the valid moves array member.
	 *
	 * @param nonEmptyRow : row of an empty dot
	 * @param nonEmptyCol : coloumn of an empty dot
	 * @param player      : player for whom valid moves has to be checked
	 * @param noOfMoves [input/output] : no of valid moves
	 */
	void checkValidMove(int nonEmptyRow, int nonEmptyCol, char player, int* noOfMoves);

public:
	ReversiBoard();
	void createBoard();
	BoardState_t queryBoardFieldState(int m , int n);
	int identifyValidMoves(char player);
	void FlipOpponent (int urow,int ucol,char player);
	void calculateScores();
	char readBoardElement(int row , int column);
	PlayerInfo_t selectTileToStart();

};

#endif /* REVERSIBOARD_H_ */
