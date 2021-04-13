#include "Templateduino.h"

#include "TemplateduinoAvr.h"

#include <util/atomic.h>

void PinTable::pinMode(const uint8_t pin, const PinMode mode) const {
  uint8_t port = pgm_read_byte(digital_pin_to_port_PGM + pin);
  uint8_t bitmask = pgm_read_byte(digital_pin_to_bit_mask_PGM + pin);
  volatile uint8_t *ddr = pgm_read_word(port_to_mode_PGM + port);

  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    switch (mode) {
    case PinMode::Input:
      *ddr &= ~bitmask;
      break;
    case PinMode::Output:
      *ddr |= bitmask;
      break;
    }
  }
}

void PinTable::write(const uint8_t pin, const uint8_t val) const {
  uint8_t port = pgm_read_byte(digital_pin_to_port_PGM + pin);
  uint8_t bitmask = pgm_read_byte(digital_pin_to_bit_mask_PGM + pin);
  volatile uint8_t *output = pgm_read_word(port_to_output_PGM + port);

  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    if (val) {
      *output |= bitmask;
    } else {
      *output &= ~bitmask;
    }
  }
}
