#include "Button.h"
#include <Arduino.h>

Button::Button(uint8_t pin) {
	_pin = pin;
	_state = LOW;
}

bool Button::pressed(void) {
	uint8_t newState = digitalRead(_pin);
	bool result = (_state == LOW && newState == HIGH);
	_state = newState;
	return result;
}

