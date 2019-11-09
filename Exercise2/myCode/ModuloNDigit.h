/**
 * \file ModuloNDigit.h
 * \author Aadarsh Kumar Singh
 * \date 06.11.2019
 *
 * \brief ModuloNDigit.h
 * \n Provides APIs to count m digits from 0 to counterType-1, supported counterTypes are
 *    Binary,Octal,Decimal,Hexadecimal.
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

#include "ModuloNCounter.h"


/**
 * Maximum possible count Value
 */
#define MAXIMUM_POSSIBLE_COUNT 65535

/**
 * Error codes for Multidigit counter
 */
enum DigitCounterErrorCode_e
{
	MULTIDIGIT_INVALID_COUNTER_TYPE_PARAM,//!< user enter counter type other than 2,8,10,16
	MULTIDIGIT_INVALID_DIGITS_PARAM,      //!< user enters invalid number of digits
	MUTLTIDIGIT_INVALID_COUNT_LIMIT,	  //!< count limit out of bounds
	MULTIDIGIT_SUCCESS,                   //!< when counting is successful
};
typedef DigitCounterErrorCode_e DigitCounterErrorCode_t;

/**
 * \brief
 * Provides APIs to count m digits from 0 to counterType-1, supported counterTypes are
 * Binary,Octal,Decimal,Hexadecimal.
 * Data Members :  m_noOfDigits type integer , m_digitCounterPtr is pointer to ModuloNCounter Class object.
 */
class ModuloNDigit
{
	int m_noOfDigits;
	ModuloNCounter *m_digitCounterPtr ;

public:
	/**
	 * Initializes the instance with given values , if values are not valid
	 * default values are taken for initialization
	 *
	 * @param noOfDigits : no of digits for counting, Default value is 3
	 * @param counterType: Value untill counter needs to count, Default value is 10
	 */
	ModuloNDigit(int noOfDigits = 3, int counterType = 10 );

	/**
	 * Copy constructor of ModuloNDigit Class Objects
	 *
	 * @param copyDigitCounter : the object to copy from
	 */
	ModuloNDigit(const ModuloNDigit &copyDigitCounter);

	/**
	 * Assignment operator overloading for ModuloNDigit class objects
	 *
	 * @param copyFromDigitCounter
	 * @return ModuloNDigit& Reference of the Modulo N digit object
	 */
	ModuloNDigit& operator=(const ModuloNDigit &copyFromDigitCounter);

	/**
	 * Destructor of ModuloNdigit Class Objects
	 */
	~ModuloNDigit();

	/**
	 * Checks the overflow flag of each of the Modulo N counter and increments
	 * each digit from LSB to MSB one by one
	 */
	void countMultiDigit();

	/**
	 * Prints the values of all digits
	 */
	void printMultiDigit();

	/**
	 * Sets number of digits and type of counter specified by the user. If they are invalid returns
	 * error codes.
	 *
	 * @param noOfDigits 	: Number of digits for counting
	 * @param counterType	: type of counters(binary, octal, decimal,hexadecimal)
	 * @return DigitCounterErrorCode_t : MULTIDIGIT_INVALID_COUNTER_TYPE_PARAM,
										 MULTIDIGIT_INVALID_DIGITS_PARAM,
										 MULTIDIGIT_SUCCESS,
	 */
	DigitCounterErrorCode_t initializeMultiDigitCounter(int noOfDigits , int counterType);

	/**
	 * Counts till the counting limit specified by the user is reached and
	 * prints the counter value
	 *
	 * @param countLimit: Number of times the counter should count
	 * @param countType : type of counter
	 * @return DigitCounterErrorCode_t : MUTLTIDIGIT_INVALID_COUNT_LIMIT
										 MULTIDIGIT_SUCCESS,
	 */
	DigitCounterErrorCode_t startCount(int countLimit,int countType);

	/**
	 * Overload pre increment operator for Modulo Digit Counter
	 *
	 * @return ModuloNDigit object:  with incremented value
	 */
	ModuloNDigit operator ++();

	/**
	 * Overloads post increment operator for Modulo Digit Counter
	 *
	 * @param postIncrement : Differentiates post and pre increment
	 * @return ModuloNDigit object : the current digit counter is increased by 1 , but returns the old
	 * 								 digit counter.
	 */
	ModuloNDigit operator ++(int postIncrement);

};

#endif /* MODULONDIGIT_H_ */
