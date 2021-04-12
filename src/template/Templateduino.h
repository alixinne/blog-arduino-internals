#ifndef _TEMPLATEDUINO_H_
#define _TEMPLATEDUINO_H_

#include <stdint.h>

// Platform-independent code

#define LOW 0
#define HIGH 1

/// Pin operation mode
enum class PinMode {
  Input,
  Output,
};

/// Hardware pin wrapper
template <typename PinTraits> struct ArduinoPin : PinTraits {
  /// Set the pin operating mode
  void setMode(const PinMode mode) const { PinTraits::setMode(mode); }

  /// Clear the output pin (set LOW)
  void clear() const { PinTraits::clear(); }

  /// Set the input pin (set HIGH)
  void set() const { PinTraits::set(); }

  /// Write the pin value
  void write(const uint8_t val) const {
    if (val) {
      set();
    } else {
      clear();
    }
  }
};

// Include board definitions, could match on -D flags
#ifdef ARDUINO_AVR_UNO
#include "TemplateduinoUno.h"
#else
#error "Unsupported platform!"
#endif

#endif /* _TEMPLATEDUINO_H_ */
