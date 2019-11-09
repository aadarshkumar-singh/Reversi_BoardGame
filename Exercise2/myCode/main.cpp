/**
 * \file main.cpp
 * \author Aadarsh Kumar Singh
 * \date 06.11.2019
 *
 * \brief main.cpp
 * \n starts MultiDigit counting of m digits from 0 to counterType-1, supported counterTypes are
 *    Binary,Octal,Decimal,Hexadecimal. It returns error when number of digits are invalid and
 *    the count limit is out of bounds.
 */

// Standard (system) header files
#include <iostream>
#include <stdlib.h>

using namespace std;

// project's header files here
#include "ModuloNCounter.h"
#include "ModuloNDigit.h"


/**
 * Error codes of Multidigit counter
 */
enum CounterApplicationErrorCode_e
{
	RETURN_INVALID_DIGITS,      	//!< when no of digits entered is invalid e.g negative number
	RETURN_INVALID_COUNTER_TYPE,	//!< when entered type of counter is invalid
	RETURN_COUNT_LIMIT_OUTOFBOUNDS, //!< when arbitary count value entered by user is out of bounds
	RETURN_COUNT_SUCCESS,       	//!< when counting successful
};
typedef CounterApplicationErrorCode_e CounterApplicationErrorCode_t;

/**
 * Application for Multidigit Counter , it takes count limit, counter type and number
 * of digits from user and starts counting from (0 to counterType-1) till count limit is
 * reached.
 *
 * @return CounterApplicationErrorCode_t : RETURN_COUNT_SUCCESS - when counting successful
 * 										   RETURN_INVALID_DIGITS- when invalid digits entered
 *										   RETURN_INVALID_COUNTER_TYPE- when type of counter is invalid
 */
CounterApplicationErrorCode_t applicationModuloDigitCounter();

// Main program
int main (void)
{
	CounterApplicationErrorCode_t errorCode;
	cout <<" ---------------------------------------------" <<endl;
	cout <<" This program executes Modulo N digit counter "  <<endl;
	cout <<" ---------------------------------------------" <<endl;

	/* Check if Digit counter counted successfully */
	errorCode = applicationModuloDigitCounter();

	if (errorCode == RETURN_COUNT_SUCCESS)
	{
		cout <<endl<<"MultiDigit Counter implemented successfully"<<endl;
	}
	else
	{
		cout <<"Multidigit counting error"<<endl;
	}

	return 0;
}

CounterApplicationErrorCode_t applicationModuloDigitCounter()
{
	int noOfDigits;
	int counterType ;
	int totalCounts ;

	ModuloNDigit digitCounter(3,10);
	CounterApplicationErrorCode_t applicationErrorCode ; /* ErrorCode for application*/
	DigitCounterErrorCode_t errorCode ; 				 /* Error Code for MultiDigit Counter */

	cout<<"Enter the number of times counter should count "<<endl;
	cin>>totalCounts ;

	/* Check if count limit is within range */
	if (totalCounts <= 0 || totalCounts > MAXIMUM_POSSIBLE_COUNT)
	{
		cout <<"Counting Limit out of bounds "<<endl;
		applicationErrorCode = RETURN_COUNT_LIMIT_OUTOFBOUNDS ;
	}
	else
	{
		cout <<"Enter Number of digits for the Module Digit Counter" <<endl ;
		cin >> noOfDigits ;

		/* Check Validity of Number of Digits */
		if (noOfDigits <= 0)
		{
			cout <<"Number of Digits which is invalid " <<endl;
			applicationErrorCode = RETURN_INVALID_DIGITS;
		}
		else
		{
			cout <<"Enter the type of Module Digit Counter i.e enter its base :: 2 /8 / 10/ 16 " <<endl ;
			cin >>counterType ;

			/* Check Validity of Counter type */
			errorCode = digitCounter.initializeMultiDigitCounter(noOfDigits,counterType);

			if (errorCode != MULTIDIGIT_SUCCESS)
			{
				cout <<"Counter type not supported " <<endl ;
				applicationErrorCode = RETURN_INVALID_COUNTER_TYPE;
			}
			else
			{	/* Start Counting till count limit entered by user */
				digitCounter.startCount(totalCounts,counterType);
				applicationErrorCode = RETURN_COUNT_SUCCESS;
			}
		}
	}
	return applicationErrorCode;
}
