/*
 * ModuloNDigit.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Aadarsh Kumar Singh
 */

#include <iostream>
#include "ModuloNDigit.h"

using namespace std;

ModuloNDigit::ModuloNDigit(int noOfDigits, int counterType)
{
	DigitCounterErrorCode_t errorCode = MULTIDIGIT_SUCCESS;

	errorCode = initializeMultiDigitCounter(noOfDigits,counterType);

	if (errorCode != MULTIDIGIT_SUCCESS)
	{
		cout<<"Invalid Input parameters for Initialization " <<endl;
		cout << " Initializing with Defaults , noOfDigits = 3 , counter type = 10  " <<endl;

		m_noOfDigits = 3;
		m_digitCounterPtr = new ModuloNCounter[3];
		for (int i = 0 ; i < m_noOfDigits ;i++ )
		{
			m_digitCounterPtr[i].initializeSingleDigitCounter(10);
		}
	}

}

ModuloNDigit::ModuloNDigit(const ModuloNDigit &copyDigitCounter):m_noOfDigits{copyDigitCounter.m_noOfDigits},
						    m_digitCounterPtr{new ModuloNCounter[copyDigitCounter.m_noOfDigits]}
{
	for (int i =0 ; i< m_noOfDigits; i++)
		m_digitCounterPtr[i]=copyDigitCounter.m_digitCounterPtr[i];
}

ModuloNDigit& ModuloNDigit::operator =(const ModuloNDigit &copyFromDigitCounter)
{
	delete[] m_digitCounterPtr;

	m_noOfDigits = copyFromDigitCounter.m_noOfDigits ;
	m_digitCounterPtr = new ModuloNCounter[m_noOfDigits];

	for (int i =0 ; i<m_noOfDigits ; i++)
	{
		m_digitCounterPtr[i]= copyFromDigitCounter.m_digitCounterPtr[i];
	}
	return *this;
}

ModuloNDigit::~ModuloNDigit()
{
	delete[] m_digitCounterPtr ;
}

DigitCounterErrorCode_t ModuloNDigit::initializeMultiDigitCounter(int noOfDigits, int counterType)
{
	DigitCounterErrorCode_t errorCode = MULTIDIGIT_SUCCESS;
	SingleCounterErrorCode_t errorCodeSingleCounter = SINGLECOUNTER_INIT_SUCCESS;

	if (noOfDigits < 0)
	{
		errorCode = MULTIDIGIT_INVALID_DIGITS_PARAM ;
	}
	else
	{
		m_noOfDigits = noOfDigits ;
		m_digitCounterPtr = new ModuloNCounter[noOfDigits];

		for (int i = 0 ; i < m_noOfDigits ;i++ )
		{
			errorCodeSingleCounter = m_digitCounterPtr[i].initializeSingleDigitCounter(counterType);

			if (errorCodeSingleCounter == SINGLECOUNTER_INVALID_MAXCOUNT)
			{
				errorCode = MULTIDIGIT_INVALID_COUNTER_TYPE_PARAM ;
				break;
			}
		}
	}

	return errorCode ;
}

void ModuloNDigit::countMultiDigit()
{

	for(int i=0;i<m_noOfDigits;i++)
	{
		m_digitCounterPtr[i]++ ;

		if(m_digitCounterPtr[i].getSingleCounterOverFlowFlag() == COUNT_NO_OVERFLOW)
		{
			break;
		}
		else
		{
			continue ;
		}
	}
}

void ModuloNDigit::printMultiDigit()
{
	for(int j =m_noOfDigits-1 ; j >= 0; j--)
	{
		m_digitCounterPtr[j].printSingleDigit();
	}
}

ModuloNDigit ModuloNDigit::operator ++()
{
	countMultiDigit();
	return *this;
}

ModuloNDigit ModuloNDigit::operator ++(int postIncrement)
{
	ModuloNDigit tempObj = *this ;
	countMultiDigit();
	return tempObj;
}
