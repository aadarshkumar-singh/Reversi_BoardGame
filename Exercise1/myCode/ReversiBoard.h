/*
 * ReversiBoard.h
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/**
 * \brief size of the reversi board
 */
#define REVERSIBOARDSIZE 8

/**
 * \brief
 * Defines state of available moves for placing tiles
 */
enum ValidMovesFlag_e
{
	NO_VALID_MOVES,
	VALID_MOVES_AVAILABLE,
};
typedef enum ValidMovesFlag_e ValidMovesFlag_t;

/**
 * \brief Define the states of the board
 */
enum BoardState_e
{
	EMPTY     = '.',	//!< EMPTY - no tile is placed on the board
	AVAILABLE = '_',	//!< AVAILABLE - player move is valid and can place the tile in the coordinate
	TILE_X   = 'x', 	//!< TILE_X - Represents Tile is occupied by x
	TILE_O   = 'o', 	//!< TILE_O - Represents Tile is occupied by o
};
typedef BoardState_e BoardState_t ;

/**
 * Defines the player i.e. if player is placing tile x / tile o or is invalid
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
	 * Checks all possible valid moves that the player can make and assign the
	 * corresponding coordinates to the valid moves array member.
	 *
	 * @param nonEmptyRow : row of an empty dot
	 * @param nonEmptyCol : coloumn of an empty dot
	 * @param player      : player for whom valid moves has to be checked
	 * @param noOfMoves [input/output] : no of valid moves
	 */
	void checkValidMove(int nonEmptyRow, int nonEmptyCol, char player, int* noOfMoves);

public:

	/**
	 * Initializes the instance by creating Board and valid moves are initialized to empty.
	 */
	ReversiBoard();

	/**
	 * Creates an 8x8 board for Reversi game
	 */
	void createBoard();

	/**
	 * Queries the field of the board based on row and column passed as parameter.
	 *
	 * @param row			: row of the field which needs to be queried
	 * @param column		: column of the field which needs to be queried
	 * @return BoardState_t : state of the board
	 * 						  EMPTY : no tiles are placed
	 * 						  AVAILABLE : the coordinate is valid for the player to move
	 * 						  TILE_X : x tile is placed
	 * 						  TILE_Y : y tile is placed
	 */
	BoardState_t queryBoardFieldState(int row , int column);

	/**
	 * Identifies valid moves are available or not for a player
	 *
	 * @param player			: player for whom valid moves need to be identified
	 * @return ValidMovesFlag_t : VALID_MOVES_AVAILABLE - If valid moves are available
	 *  						  NO_VALID_MOVES - If valid moves are not available
	 */
	ValidMovesFlag_t identifyValidMoves(char player);

	/**
	 * Places the tile of the player in the coordinates as per the given rows and column
	 * Flips the opponents based on the reversi logic
	 *
	 * @param row	 : row where the tile has to be placed
	 * @param column : column where the tile has to be placed
	 * @param player : player whose tile has to be placed in the coordinate
	 */
	void placeTileOfPlayerAndFlipOpponent (int row,int column,char player);

	/**
	 * Counts the number of x tiles and o tiles and determines the winner of the
	 * Reversi game.
	 */
	void calculateScores();

	/**
	 * Returns the board elements based on given row and column.
	 *
	 * @param row : row of the board element which needs to be read.
	 * @param column : column of the board element which needs to be read.
	 * @return char : board element, if its empty/available or occupied by TILE_X/TILE_Y
	 */
	char getBoardElement(int row , int column);

	/**
	 * Gets player tile who wants to start the game first
	 *
	 * @return PlayerInfo_t PLAYER_TILE_X  : player x starts first
	 * 						PLAYER_TILE_O  : player o starts first
	 * 						INVALID_PLAYER : if player enters invalid tile
	 */
	PlayerInfo_t selectTileToStart();

};

#endif /* REVERSIBOARD_H_ */
