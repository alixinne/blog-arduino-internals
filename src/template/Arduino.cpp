#include "Arduino.h"

#include <util/atomic.h>

// Arduino compatibility definitions

// The noexcept conditions dispatch the calls to the right implementations:
// - If the expression can be const-evaluated, use compile-time resolution of the pin mapping. This allows optimal code generation.
// - If the expression cannot be const-evaluated, default to a runtime lookup based on the original digitalWrite implementation from the Arduino framework.

void pinMode(const uint8_t pin, const uint8_t mode) {
  auto pinMode = mode == OUTPUT ? PinMode::Output : PinMode::Input;

  if (noexcept(TemplateduinoPins.pinMode(pin, pinMode))) {
    TemplateduinoPins.pinMode(pin, pinMode);
  } else {
    TemplateduinoPinTable.pinMode(pin, pinMode);
  }
}

void digitalWrite(const uint8_t pin, const uint8_t val) {
  if (noexcept(TemplateduinoPins.write(pin, val))) {
    TemplateduinoPins.write(pin, val);
  } else {
    TemplateduinoPinTable.write(pin, val);
  }
}
