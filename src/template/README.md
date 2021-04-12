# `template` variant

This variant is derived from:
* The readability of the [Arduino](../arduino) variant
* The efficiency of the [AVR](../avr) variant

By using C++ templates, we can create pin definitions at compile time for our
target board, which the compiler can properly optimize to optimal instructions
as the AVR variant provides.

This also allows us to split various parts of the API to allow platform-independence:
* [`Templateduino.h`](Templateduino.h): entry point. This is a
  platform-independent interface definition. After defining common types, depending on compiler definitions we include the right *board definition file*.
* [`TemplateduinoUno.h`](TemplateduinoUno.h): board definition file for the
  Arduino Uno. This header uses the *platform definition file* and declares the
  actual board layout, i.e. mappings from Arduino pin numbers (D13 for the
  built-in LED) to physical pins (`PB5` on the ATMega328P).
* [`TemplateduinoAvr.h`](TemplateduinoAvr.h): platform definition file for AVR
  platforms. This contains common code used to implement definitions for the
  various boards using the same AVR platform.

Note that even with all those abstraction layers, the following entry point
will compile to the exact same assembly as the optimal [AVR variant](../avr).

```cpp
#include "Templateduino.h"

int main() {
  BuiltinLed.setMode(PinMode::Output);

  while (1) {
    BuiltinLed.write(HIGH);
    BuiltinLed.write(LOW);
  }
}
```
