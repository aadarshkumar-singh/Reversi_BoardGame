/**
 * \file CDisplay.h
 * \author Aadarsh Kumar Singh
 * \date 06.11.2019
 *
 * \brief CDisplay.h
 * \n Provides API to display the error messages and print the temperature
 *    sensor value and the temperature value specified by the user
 */

#ifndef CDISPLAY_H_
#define CDISPLAY_H_

/**
 * \brief Maximum text that can be displayed on the LCD Display
 */
#define DISPLAY_TEXT_LIMIT 50

/**
 * \brief
 * Provides APIs to display the Room temperature sensed by the sensor and
 * the temperature set by the user. It also can displays error messages if any .
 * The property m_display_text is char array of size DISPLAY_TEXT_LIMIT
 */
class CDisplay
{
	char m_displayText[DISPLAY_TEXT_LIMIT];

public:

	/**
	 * Initializes the instance with the display text Temperature controller
	 */
	CDisplay();

	/**
	 * Displays the temperature value specified by the user
	 *
	 * @param userTemperature : Temperature value set by the user
	 */
	void DisplayTemperatureData(float userTemperature);

	/**
	 * Displays the temperature value specified by the user along with
	 * mean temperature from the primary and secondary sensor
	 *
	 * @param userTemperature Temperature value set by the user
	 * @param sensorData Temperature data received from the sensor
	 */
	void DisplayTemperatureData(float userTemperature, float sensorData);

	/**
	 * Displays the messages passed as parameter on the screen
	 *
	 * @param displaytext[50] : Charecter array that has to printed on screen
	 */
	void DisplayMessages(const char *displaytext);

};

#endif /* CDISPLAY_H_ */
