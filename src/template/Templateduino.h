#ifndef _TEMPLATEDUINO_H_
#define _TEMPLATEDUINO_H_

#include <stddef.h>
#include <stdint.h>

// Platform-independent code

/// Pin operation mode
enum class PinMode {
  Input,
  Output,
};

/// Hardware pin wrapper
template <typename PinTraits> struct DigitalPin : PinTraits {
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

/// Compile-time pin mapping entry
template <uint8_t N, typename T> struct PinMapEntry {
  static const uint8_t Number = N;
  typedef T Pin;
};

/// Compile-time pin mapping structure
template <typename T, typename... Ts> struct PinMap {
  void pinMode(const uint8_t pin, const PinMode mode) const {
    if (T::Number == pin) {
      typename T::Pin{}.setMode(mode);
    } else if (T::Number < pin) {
      PinMap<Ts...>{}.pinMode(pin, mode);
    }
  }

  void write(const uint8_t pin, const uint8_t val) const {
    if (T::Number == pin) {
      typename T::Pin{}.write(val);
    } else if (T::Number < pin) {
      PinMap<Ts...>{}.write(pin, val);
    }
  }
};

template <typename T> struct PinMap<T> {
  void pinMode(const uint8_t pin, const PinMode mode) const {
    if (T::Number == pin) {
      typename T::Pin{}.setMode(mode);
    } else {
      // TODO: Throw an error?
    }
  }

  void write(const uint8_t pin, const uint8_t val) const {
    if (T::Number == pin) {
      typename T::Pin{}.write(val);
    } else {
      // TODO: Throw an error?
    }
  }
};

/// Runtime pin table
struct PinTable {
  void pinMode(const uint8_t pin, const PinMode mode) const;
  void write(const uint8_t pin, const uint8_t val) const;
};

// Include board definitions, could match on -D flags
#ifdef ARDUINO_AVR_UNO
#include "TemplateduinoAvr.h"
#include "TemplateduinoUno.h"
#else
#error "Unsupported platform!"
#endif

#endif /* _TEMPLATEDUINO_H_ */
