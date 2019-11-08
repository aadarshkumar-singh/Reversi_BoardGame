/**
 * \file CButtonInput.h
 * \author Aadarsh Kumar Singh
 * \date 06.11.2019
 *
 * \brief CButtonInput.h
 * \n This file defines the button for adjusting the temperature.
 * \n It provides API to determine the button pressed by the user
 * \n Button 1(INCREMENT_BUTTON) : Is used to increase the temperature by 1
 * \n Button 2(DECREMENT_BUTTON) : Is used to decrease the temperature by 1
 */

#ifndef CBUTTONINPUT_H_
#define CBUTTONINPUT_H_


/**
 * \brief
 * Defines the buttons available for adjusting and setting the temperature
 */
enum Button_Input_e
{
	NO_BUTTON,		   //!< Button input when no button is pressed
	DECREMENT_BUTTON , //!< On DECREMENT_BUTTON press temperature is decremented by 1
	INCREMENT_BUTTON , //!< On INCREMENT_BUTTON press temperature is increased by 1
};

typedef enum Button_Input_e Button_Input_t;

/**
 * \brief
 * Defines the states of the button , if pressed or remains unpressed
 */
enum Button_PressFlag_e
{
	BUTTON_UNPRESSED, //!< BUTTON_UNPRESSED defines that the button is not pressed.
	BUTTON_PRESSED,   //!< BUTTON_PRESSED defines that the button is pressed.
};
typedef enum Button_PressFlag_e Button_PressFlag_t;


/**
 * \brief
 * Provides the APIs to determine the button pressed by the user
 * to increase / decrease the temperature value or to power on/off the heating controller.
 * The property m_buttonInput is of enum type Button_Input_t
 */
class CButtonInput
{
	Button_Input_t m_buttonInput;

public:

	/**
	 * Initializes the instance with No button pressed
	 */
	CButtonInput();

	/**
	 * Assigns the button which is pressed by the user.
	 *
	 * @param ButtonInput : INCREMENT_BUTTON : when increment button is pressed by the user
	 *      			    DECREMENT_BUTTON : when decrement button is pressed by the user
	 * 		    		    NO_BUTTON		 : when no button is pressed
	 */
	void setButtonPressedByUser(Button_Input_t ButtonInput);

	/**
	 * Returns the button which is pressed by the user
	 *
	 * @return m_buttonInput : INCREMENT_BUTTON : when increment button is pressed by the user
	 * 		    			   DECREMENT_BUTTON : when decrement button is pressed by the user
	 * 		    			   NO_BUTTON		: when no button is pressed
	 */
	Button_Input_t getButtonPressedByUser();
};

#endif /* CBUTTONINPUT_H_ */
