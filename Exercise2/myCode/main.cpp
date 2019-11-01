/*
 *  main.cpp
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */

// Standard (system) header files

#include <iostream>
#include <stdlib.h>

using namespace std;
#include "ModuloNCounter.h"
#include "ModuloNDigit.h"

int testSDCounter();
int testMDCounter();
// Main program
int main (void)
{
	//testSDCounter();
	testMDCounter();



	return 0;
}

int testSDCounter()
{
	ModuloNCounter c1;
	int i ;
	int totalCounter ;
	int counterLimit = 1;
	int maxCount;
	int errCode ;
	cout << "Enter the no of times counter should be executed  " <<endl;
	cin >> counterLimit ;

	cout << "Enter the maximum count value " <<endl ;
	cin >> maxCount ;

	totalCounter = counterLimit * maxCount ;

	errCode = c1.initCounterSD(maxCount);


	if(errCode == R_OK && counterLimit > 0)
	{
		for( i = 0; i< totalCounter ; i++ )
		{
			c1.countSD();
			c1.printSD();
		}
	}

  return 1 ;
}


int testMDCounter()
{
	ModuloNDigit c1(2,16) ;

	for(int i = 0; i< 256 ; i++ )
	{
		c1.counterMultiDigit();
		cout << endl;
	}

	return 1;
}
