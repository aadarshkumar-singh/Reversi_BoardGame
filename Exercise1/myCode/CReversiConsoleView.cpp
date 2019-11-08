/*
 * CReversiConsoleView.cpp
 *
 *  Created on: Nov 8, 2019
 *      Author: Aadarshxp
 */
#include "iostream"

using namespace std;

#include "CReversiConsoleView.h"

CReversiConsoleView::CReversiConsoleView(ReversiBoard *boardObjView)
{
	m_BoardObjView = boardObjView;
}

void CReversiConsoleView::printBoard()
{
	for (int i = 0;i <REVERSIBOARDSIZE ; i++)
	{
		for (int j=0; j<REVERSIBOARDSIZE;j++)
			cout<<m_BoardObjView->readBoardElement(i,j) <<"\t";
		cout << endl;
	}
	cout <<endl<<endl ;
}
