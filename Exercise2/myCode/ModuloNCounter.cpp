/*
 *  ModuloNCounter.cpp
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */

#include <iostream>
#include "ModuloNCounter.h"

using namespace std;

ModuloNCounter::ModuloNCounter()
{
	m_curCount = 0 ;
	m_maxCount = 8 ;
}

ModuloNCounterErrCode_t ModuloNCounter::initCounterSD(int maxCount)
{
	ModuloNCounterErrCode_t errCode = R_OK ;

	m_curCount = 0 ;

	if (maxCount <= 0 || maxCount >= 60000)
	{
		errCode = R_NOK ;
	}
	else
	{
		m_maxCount = maxCount ;
	}

	return errCode ;
}

ModuloNCounterOverFlowFlag_t ModuloNCounter::countSD()
{
	ModuloNCounterOverFlowFlag_t counterFlag = COUNT_NO_OVERFLOW;

	if (m_curCount < (m_maxCount -1))
	{
		++m_curCount;
	}
	else
	{
		m_curCount = 0 ;
		counterFlag = COUNT_OVERFLOW ;
	}

	return counterFlag ;
}

void ModuloNCounter::printSD()
{
	cout << hex <<m_curCount ;
}
