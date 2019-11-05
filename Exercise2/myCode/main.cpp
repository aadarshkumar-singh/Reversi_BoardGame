/*
 *  main.cpp
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */

// Standard (system) header files

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;
#include "ModuloNCounter.h"
#include "ModuloNDigit.h"


void testSDCounter();
int appMDCounter();

// Main program
int main (void)
{

	cout <<" ---------------------------------------------" <<endl;
	cout <<" This program executes Modulo N digit counter "  <<endl;
	cout <<" ---------------------------------------------" <<endl;

	//testSDCounter();


	appMDCounter();

	return 0;
}

void testSDCounter()
{
	ModuloNCounter c1;

	/**  Number of times the counter should count */
	int counterLimit = 1;

	/** Type of counter*/
	int CounterType;

	/** Variable to store the total number of counts for printing on console */
	int totalCounts ;

	int errorCode ;

	cout << "Enter the no of times counter should be executed  " <<endl;
	cin >> counterLimit ;

	if (counterLimit < 0)
	{
		cout <<"SD counter error : User entered invalid number of times for which counter should run" <<endl;
	}

	else
	{
		cout << "Enter the type of Single Digit Counter :: 2 /8 / 10/ 16 " <<endl ;
		cin >> CounterType ;

		if (CounterType < 0)
		{
			cout <<"SD counter error : User entered type of counter less than 0 " <<endl;
		}
		else
		{
			errorCode = c1.initializeSingleDigitCounter(CounterType);

			if (errorCode == SINGLECOUNTER_INVALID_MAXCOUNT)
			{
				cout <<" Counter type not supported , assigning DECIMAL_COUNTER as Default " <<endl ;
				CounterType = DECIMAL_COUNTER;
			}

			/**  Calculation could be done directly in for loop condition
						 but since the calculation will be done every time,
						 counter will become slower */
			totalCounts = counterLimit * CounterType ;

			for( int i = 0; i< totalCounts ; i++ )
			{
				c1.printSingleDigit();
				c1.countSingleDigit();
				cout<<endl;
			}

			cout <<"SD Counter implemented successfully"<<endl;
		}

	}
}



int appMDCounter()
{
	int noOfDigits;
	int counterType ;
	int totalCounts ;
	DigitCounterErrorCode_t errorCode ;
	ModuloNDigit digitCounter(3,10);

	cout <<"Enter Number of digits for the Module Digit Counter" <<endl ;
	cin >> noOfDigits ;

	if (noOfDigits < 0)
	{
		cout <<" User Entered Negative Value for Number of Digits which is invalid " <<endl;
	}
	else
	{
		cout <<"Enter the type of Module Digit Counter i.e enter its base :: 2 /8 / 10/ 16 " <<endl ;
		cin >>counterType ;

		errorCode = digitCounter.initializeMultiDigitCounter(noOfDigits,counterType);

		if (errorCode != MULTIDIGIT_SUCCESS)
		{
			//TODO : Remove assignment of default counter type
			cout <<" Counter type not supported , assigning DECIMAL_COUNTER as Default " <<endl ;
		}
		else
		{   //TODO: Add error handling
			totalCounts = pow(counterType,noOfDigits);

			for(int i = 0; i< totalCounts ; i++ )
			{
					digitCounter.printMultiDigit();
					++digitCounter;
					cout << endl;
			}

		}


	}

	return 1;
}
