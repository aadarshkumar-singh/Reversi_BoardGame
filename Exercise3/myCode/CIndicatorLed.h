/**
* \file CIndicatorLed.h
* \author Aadarsh Kumar Singh
* \date 06.11.2019
*
* \brief CIndicatorLed.h
* \n Provides the APIs to switch on/off the LEDs based on the Led type(GREEN,RED,NO LED).
*/

#ifndef CINDICATORLED_H_
#define CINDICATORLED_H_

/**
 * \brief Types of the LED.
 */
enum Led_Types_e
{
  NO_LED,               /**< Operations on No led. */   //!< NO_LED
  LED_GREEN,           /**< Operations on Green Led */  //!< LED_GREEN
  LED_RED,             /**< Operations on Red Led. */   //!< LED_RED
} ;
typedef enum Led_Types_e Led_Types_t;

/**
 * \brief states of the Led
 */
enum Led_States_e
{
 LED_OFF,            	/**< LED state OFF */   //!< LED_OFF
 LED_ON,                /**< LED state ON   *///!< LED_ON
} ;

/**
 * \brief Error code of the LED
 */
enum Led_ErrCode_e
{
 LED_OK,            /**< Return on Success */ //!< LED_OK
 LED_ERROR,           /**< Return on Failure. *///!< LED_NOK
};
typedef enum Led_ErrCode_e Led_ErrCode_t;

/**
 * \brief
 * Provides the APIs to switch on/off the LEDs based on the Led type(GREEN,RED,NO LED).
 */
class CIndicatorLed
{
	Led_Types_t m_LedType;

public:

	/**
	 * \brief Initializes the instance with No led
	 */
	CIndicatorLed();

	/**
	 * Switches on the type of  Led passed as parameter
	 * @param ledType : Type of LED based on colour
	 * @return Led_ErrCode_t : LED_OK : When valid type of LED is passed
	 * 						   LED_NOK : When invalid type of LED is passed.
	 */
	Led_ErrCode_t ledSwitchOn(Led_Types_t ledType);

	/**
	 * Switches off the type of  Led passed as parameter
	 * @param ledType : Type of LED based on colour
	 * @return Led_ErrCode_t : LED_OK : When valid type of LED is passed
	 * 						   LED_NOK : When invalid type of LED is passed.
	 */	Led_ErrCode_t ledSwitchOff(Led_Types_t ledType);

};

#endif /* CINDICATORLED_H_ */
