/**
 * \file ModuloNCounter.h
 * \author Aadarsh Kumar Singh
 * \date 06.11.2019
 *
 * \brief ModuloNCounter.h
 * \n Provides APIs to count a single digit from 0 to counterType-1, supported counterTypes are
 *    Binary,Octal,Decimal,Hexadecimal.
 */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_


#define MODULOBINARYCOUNTER      2
#define MODULODECIMALCOUNTER     10
#define MODULOOCTALCOUNTER   	 8
#define MODULOHEXADECIMALCOUNTER 16

/**
 * Error Codes for Single Counter Initialization
 */
enum SingleCounterErrorCode_e
{
	SINGLECOUNTER_INVALID_MAXCOUNT,//!< Invalid max count value
	SINGLECOUNTER_INIT_SUCCESS,    //!< Initialization successful
};

/**
 * Defines the Overflow flag,
 */
enum ModuloNCounterOverFlowFlag_e
{
	COUNT_OVERFLOW,   //!< counter reaches max_value set to COUNT_OVERFLOW
	COUNT_NO_OVERFLOW,//!< counter doesn't reach max_value set to COUNT_NO_OVERFLOW
};
typedef ModuloNCounterOverFlowFlag_e ModuloNCounterOverFlowFlag_t ;

/**
 * defines the type of Counter (Binary,Octal,Decimal,Hexadecimal)
 */
enum ModuloNCounterType_e
{
	BINARY_COUNTER = 2 ,    //!< counts till 1
	OCTAL_COUNTER = 8,      //!< counts till 7
	DECIMAL_COUNTER = 10 ,  //!< counts till 9
	HEXADECIMAL_COUNTER =16,//!< counts till 15
};
typedef SingleCounterErrorCode_e SingleCounterErrorCode_t;

/**
 * \brief
 * counts single digit from 0 to counterType-1
 * When overflow occurs it sets the flag m_overFlowFlag to COUNT_OVERFLOW
 * data members: m_curCount , m_maxCount are of type int
 */
class ModuloNCounter
{
private:

	int m_curCount;  	  /* Variable to store the current count value of the counter.*/
	int m_maxCount;  	  /* Variable to store the maximum count till the counter will count.*/
	ModuloNCounterOverFlowFlag_t m_overFlowFlag ;
	/**
	 * Sets the type of counter to maxcount value ,
	 * if counter type is supported(binary,octal,decimal, hexadecimal)
	 *
	 * @param countertype : binary,octal,decimal, hexadecimal
	 * @return  	SINGLECOUNTER_INIT_SUCCESS : type of counter is 2,8,10,16
	 * 				SINGLECOUNTER_INVALID_MAXCOUNT : For invalid type of counter
	 */
	SingleCounterErrorCode_t setCounterSD(int countertype);

public:

	/**
	 * Initializes the instance with given value , if given value is invalid
	 * decimal counter is initialized by default
	 *
	 * @param userEntryCounterType : type of counter , by default 10
	 */
	ModuloNCounter(int userEntryCounterType = 10);

	/**
	 * Sets the type of counter (binary,octal,decimal,hexadecimal) ,
	 * if invalid returns the errorCode
	 *
	 * @param maxCount : type of counter specified by the user
	 * @return  	SINGLECOUNTER_INIT_SUCCESS : type of counter is 2,8,10,16
	 * 				SINGLECOUNTER_INVALID_MAXCOUNT : For invalid type of counter
	 */
	SingleCounterErrorCode_t initializeSingleDigitCounter(int maxCount);

	/**
	 * Increments the current count value by 1 till max count is reached,
	 * When Reached it resets the current count value to 0 and updates
	 * the overflow flag
	 */
	void countSingleDigit();

	/**
	 * returns the overflow flag of single digit counter
	 *
	 * @return ModuloNCounterOverFlowFlag_t : Overflow Flag
	 */
	ModuloNCounterOverFlowFlag_t getSingleCounterOverFlowFlag();

	/**
	 * Overload pre increment operator for ModuloNCounter
	 *
	 * @return ModuloNCounterOverFlowFlag_t :  Overflow flag
	 */
	ModuloNCounterOverFlowFlag_t operator++();

	/**
	 * Overloads post increment operator for ModuloNCounter
	 *
	 * @param postIncrement : Differentiates post and pre increment
	 * @return ModuloNCounterOverFlowFlag_t : Overflow flag.
	 */
	ModuloNCounterOverFlowFlag_t operator++(int postIncrement);

	/**
	 * Prints the current value of the single digit counters
	 */
	void printSingleDigit();
};

#endif /* MODULONCOUNTER_H_ */
