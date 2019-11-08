/*
 * CReversiConsoleView.h
 *
 *  Created on: Nov 8, 2019
 *      Author: Aadarshxp
 */

#ifndef CREVERSICONSOLEVIEW_H_
#define CREVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

class CReversiConsoleView
{
	ReversiBoard *m_BoardObjView;

public:
	CReversiConsoleView(ReversiBoard *boardObjView);
	void printBoard();
};

#endif /* CREVERSICONSOLEVIEW_H_ */
