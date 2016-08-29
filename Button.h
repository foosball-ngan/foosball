#ifndef Button_h
#define Button_h

#include <inttypes.h>

class Button {
	public:
		Button(uint8_t pin);
		bool pressed();

	private:
		uint8_t _pin;
		uint8_t _state;
};

#endif

