#ifndef _ARDUINO_H_
#define _ARDUINO_H_

// Arduino compatibility definitions

#include "Templateduino.h"

#define HIGH 0x1
#define LOW 0x0

#define INPUT 0x0
#define OUTPUT 0x1

void pinMode(const uint8_t pin, const uint8_t mode);
void digitalWrite(const uint8_t pin, const uint8_t val);

#define LED_BUILTIN BuiltinLedPinNumber

#endif /* _ARDUINO_H_ */
