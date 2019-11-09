/*
 * ReversiConsoleView.cpp
 *
 *  Created on: Nov 8, 2019
 *      Author: Aadarshxp
 */
#include "iostream"

using namespace std;

#include "ReversiConsoleView.h"

ReversiConsoleView::ReversiConsoleView(ReversiBoard *boardObjView)
{
	m_BoardObjView = boardObjView;
}

void ReversiConsoleView::printBoard()
{
	cout<<endl;
	cout <<"\t0\t1\t2\t3\t4\t5\t6\t7" <<endl;
	for (int i = 0;i <REVERSIBOARDSIZE ; i++)
	{
		cout << i<<"\t";
		for (int j=0; j<REVERSIBOARDSIZE;j++)
		{
			cout<<m_BoardObjView->getBoardElement(i,j) <<"\t";
		}
		cout << endl;
	}
	cout <<endl<<endl ;
}
