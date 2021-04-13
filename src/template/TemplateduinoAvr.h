#ifndef _TEMPLATEDUINO_AVR_H_
#define _TEMPLATEDUINO_AVR_H_

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

// Pin table definitions

#include <avr/pgmspace.h>

// On the ATmega1280, the addresses of some of the port registers are
// greater than 255, so we can't store them in uint8_t's.
extern const uint16_t PROGMEM port_to_mode_PGM[];
extern const uint16_t PROGMEM port_to_input_PGM[];
extern const uint16_t PROGMEM port_to_output_PGM[];

extern const uint8_t PROGMEM digital_pin_to_port_PGM[];
extern const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[];
extern const uint8_t PROGMEM digital_pin_to_timer_PGM[];

#endif /* _TEMPLATEDUINO_AVR_H_ */
