/*
 * ModuloNCounter.h
 *
 *  Created on: Oct 31, 2019
 *  Author: Aadarsh Kumar Singh
 */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_


#define MODULOBINARYCOUNTER      2
#define MODULODECIMALCOUNTER     10
#define MODULOOCTALCOUNTER   	 8
#define MODULOHEXADECIMALCOUNTER 16

enum SingleCounterErrorCode_e
{
	SINGLECOUNTER_INVALID_MAXCOUNT,
	SINGLECOUNTER_INIT_SUCCESS,
};

enum ModuloNCounterOverFlowFlag_e
{
	COUNT_OVERFLOW,
	COUNT_NO_OVERFLOW,
};

enum ModuloNCounterType_e
{
	BINARY_COUNTER = 2 ,
	OCTAL_COUNTER = 8,
	DECIMAL_COUNTER = 10 ,
	HEXADECIMAL_COUNTER =16,
};


typedef SingleCounterErrorCode_e SingleCounterErrorCode_t;

typedef ModuloNCounterOverFlowFlag_e ModuloNCounterOverFlowFlag_t ;



/**
 * Modulo N counter class is used to count single digit (SD)
 * from 0 to N-1 untill the limit specified by the user.
 */

class ModuloNCounter
{
private:
	int m_curCount;  	  /* Variable to store the current count value of the counter.*/
	int m_maxCount;  	  /* Variable to store the maximum count till the counter will count.*/
	SingleCounterErrorCode_t setCounterSD(int countertype);

public:

	ModuloNCounter(int userEntryCounterType = 10);
	SingleCounterErrorCode_t initializeSingleDigitCounter(int maxCount);
	ModuloNCounterOverFlowFlag_t countSingleDigit();
	ModuloNCounterOverFlowFlag_t operator++();
	void printSingleDigit();
};

/**
 * @Description Sets the  counter Limit . It is invoked from initCounter function
 * 				which is exposed to outside world.
 *
 * @param 		counterLimit No of times counter will be executed
 *
 * @return  	SINGLECOUNTER_INIT_SUCCESS : For valid counterLimit values i.e parameter passed should be > 1
 * 				SINGLECOUNTER_INVALID_MAXCOUNT : For invalid parameters
 */

#endif /* MODULONCOUNTER_H_ */
