/**
 * \file ReversiConsoleView.h
 * \author Aadarsh Kumar Singh
 * \date 06.11.2019
 *
 * \brief ReversiConsoleView.h
 *
 * Provides API to print the Board of the Reversi Game.
 *
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

/**
 * \brief Provides the API to print the Board of the Reversi game.
 * The property m_BoardObjView is pointer Object to The Reversi class.
 */
class ReversiConsoleView
{
	ReversiBoard *m_BoardObjView;

public:
	/**
	 * Initializes the instance with a pointer of ReversiBoard class Object
	 *
	 * @param boardObjView Pointer object of ReversiBoard Class
	 */
	ReversiConsoleView(ReversiBoard *boardObjView);

	/**
	 * Obtains the state of the field of the Board and prints it .
	 */
	void printBoard();
};

#endif /* REVERSICONSOLEVIEW_H_ */
