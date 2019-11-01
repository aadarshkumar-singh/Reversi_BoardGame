/*
 * ModuloNDigit.cpp
 *
 *  Created on: Oct 31, 2019
 *      Author: Aadarsh Kumar Singh
 */

#include "ModuloNDigit.h"


ModuloNDigit::ModuloNDigit(int noOfDigits, int max_count)
{
	m_noOfDigits = noOfDigits;
	m_ptr = new ModuloNCounter[noOfDigits];
	for (int i = 0 ; i < m_noOfDigits ;i++ )
	{
		m_ptr[i].initCounterSD(max_count);
	}
}

ModuloNDigit::~ModuloNDigit()
{
	delete[] m_ptr ;
}

int ModuloNDigit::counterMultiDigit()
{

	for(int j =m_noOfDigits-1 ; j >= 0; j--)
	{
		m_ptr[j].printSD();
	}


	for(int i=0;i<m_noOfDigits;i++)
	{
		if(m_ptr[i].countSD() == COUNT_NO_OVERFLOW)
		{
			break;
		}
		else
		{
		   continue ;
		}
	}

	return 1 ;
}
