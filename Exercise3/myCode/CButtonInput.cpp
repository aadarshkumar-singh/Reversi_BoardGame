/*
 * CButtonInput.cpp
 *
 * Created on: Nov 6, 2019
 * Author: Aadarsh Kumar Singh
 */

#include "CButtonInput.h"


CButtonInput::CButtonInput()
{
	m_buttonInput = NO_BUTTON;
}

void CButtonInput::setButtonPressedByUser(Button_Input_t ButtonInput)
{
	/**
	 * The interrupt will be triggered as soon as button is pressed detecting the rising edge on I/O pin,
	 * The interrupt will return a flag depending on the button pressed , which is then set to the
	 * m_buttonInput
	 */
	m_buttonInput = ButtonInput ;
}

Button_Input_t CButtonInput::getButtonPressedByUser()
{
	return (m_buttonInput);
}
