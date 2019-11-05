/*
 * ModuloNDigit.h
 *
 *  Created on: Oct 31, 2019
 *      Author: Aadarsh Kumar Singh
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

#include "ModuloNCounter.h"

enum DigitCounterErrorCode_e
{
	MULTIDIGIT_INVALID_COUNTER_TYPE_PARAM,
	MULTIDIGIT_INVALID_DIGITS_PARAM,
	MULTIDIGIT_SUCCESS,
};

typedef DigitCounterErrorCode_e DigitCounterErrorCode_t;

class ModuloNDigit
{
	int m_noOfDigits;
	ModuloNCounter *m_digitCounterPtr ;

public:
	ModuloNDigit(int noOfDigits = 3, int counterType = 10 );
	~ModuloNDigit();

	/* TODO : add error Handling  */
	void countMultiDigit();
	void printMultiDigit();
	DigitCounterErrorCode_t initializeMultiDigitCounter(int noOfDigits , int counterType);
	void operator ++();

};

#endif /* MODULONDIGIT_H_ */
