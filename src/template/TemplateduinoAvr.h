#ifndef _TEMPLATEDUINO_AVR_H_
#define _TEMPLATEDUINO_AVR_H_

// Include Platform-independent API
#include "Templateduino.h"

// Load AVR headers
#include <avr/io.h>

// Platform API (AVR)
template <uintptr_t DdrAddr, uintptr_t PortAddr, uint8_t Pin>
struct AvrPinTraits {
  void setMode(const PinMode mode) const {
    switch (mode) {
    case PinMode::Input:
      *((volatile uint8_t *)DdrAddr) &= ~(1 << Pin);
      break;
    case PinMode::Output:
      *((volatile uint8_t *)DdrAddr) |= (1 << Pin);
      break;
    }
  }

  void clear() const { *((volatile uint8_t *)PortAddr) &= ~(1 << Pin); }

  void set() const { *((volatile uint8_t *)PortAddr) |= (1 << Pin); }
};

#endif /* _TEMPLATEDUINO_AVR_H_ */
