/*
 * ModuloNDigit.h
 *
 *  Created on: Oct 31, 2019
 *      Author: Aadarsh Kumar Singh
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

#include "ModuloNCounter.h"

class ModuloNDigit
{
	int m_noOfDigits;
	ModuloNCounter *m_ptr ;



public:
	ModuloNDigit(int noOfDigits, int max_count);
	~ModuloNDigit();
	int counterMultiDigit();
};

#endif /* MODULONDIGIT_H_ */
