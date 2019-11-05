/*
 *  ModuloNCounter.cpp
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */

#include <iostream>
#include "ModuloNCounter.h"

using namespace std;

ModuloNCounter::ModuloNCounter(int userEntryCounterType)
{
	m_curCount = 0 ;
	m_overFlowFlag = COUNT_NO_OVERFLOW ;

	if (setCounterSD(userEntryCounterType) == SINGLECOUNTER_INVALID_MAXCOUNT)
		cout <<" Counter type not supported , initializing DECIMAL_COUNTER as Default " <<endl ;

}

SingleCounterErrorCode_t ModuloNCounter::setCounterSD(int countertype)
{
	SingleCounterErrorCode_t errorCode = SINGLECOUNTER_INIT_SUCCESS ;

	switch(countertype)
	{

	case BINARY_COUNTER :
		m_maxCount = BINARY_COUNTER ;
		break;

	case OCTAL_COUNTER :
		m_maxCount = OCTAL_COUNTER ;
		break;

	case DECIMAL_COUNTER :
		m_maxCount = DECIMAL_COUNTER ;
		break;

	case HEXADECIMAL_COUNTER :
		m_maxCount = HEXADECIMAL_COUNTER ;
		break;

	default :
		m_maxCount = DECIMAL_COUNTER ;
		errorCode = SINGLECOUNTER_INVALID_MAXCOUNT;
		break;
	}

	return errorCode ;

}

SingleCounterErrorCode_t ModuloNCounter::initializeSingleDigitCounter(int maxCount)
{
	SingleCounterErrorCode_t errorCode = SINGLECOUNTER_INIT_SUCCESS ;

	m_curCount = 0 ;

	errorCode = setCounterSD(maxCount);

	return errorCode ;
}

void ModuloNCounter::countSingleDigit()
{
	m_overFlowFlag = COUNT_NO_OVERFLOW;

	if (m_curCount < (m_maxCount -1))
	{
		++m_curCount;
	}
	else
	{
		m_curCount = 0 ;
		m_overFlowFlag = COUNT_OVERFLOW ;
	}

}

ModuloNCounterOverFlowFlag_t ModuloNCounter::getSingleCounterOverFlowFlag()
{
	return (m_overFlowFlag);
}

void ModuloNCounter::printSingleDigit()
{
	cout << hex <<m_curCount ;
}

ModuloNCounterOverFlowFlag_t ModuloNCounter::operator ++()
{
	countSingleDigit();
	return(this->m_overFlowFlag);
}

ModuloNCounterOverFlowFlag_t ModuloNCounter::operator ++(int postIncrement)
{
	ModuloNCounter copySingleCounter = *this ;
	countSingleDigit();
	return(copySingleCounter.m_overFlowFlag);
}

