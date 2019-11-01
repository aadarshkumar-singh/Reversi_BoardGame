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

enum ModuloNCounterErrCode_e
{
	R_NOK,
	R_OK,
};

enum ModuloNCounterOverFlowFlag_e
{
	COUNT_OVERFLOW,
	COUNT_NO_OVERFLOW,
};


typedef ModuloNCounterErrCode_e ModuloNCounterErrCode_t;

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

public:

	ModuloNCounter();
	ModuloNCounterErrCode_t initCounterSD(int maxCount);
	ModuloNCounterOverFlowFlag_t  countSD();
	void printSD();
};

/**
 * @Description Sets the  counter Limit . It is invoked from initCounter function
 * 				which is exposed to outside world.
 *
 * @param 		counterLimit No of times counter will be executed
 *
 * @return  	R_OK : For valid counterLimit values i.e parameter passed should be > 1
 * 				R_NOK : For invalid parameters
 */

#endif /* MODULONCOUNTER_H_ */
