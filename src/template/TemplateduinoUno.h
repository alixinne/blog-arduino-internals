#ifndef _TEMPLATEDUINO_UNO_H_
#define _TEMPLATEDUINO_UNO_H_

#include <stddef.h>
#include <stdint.h>

// Include platform definition
#include "TemplateduinoAvr.h"

// Board definition

// Workaround for _IO macros not being constexpr: those will be constant-folded
// away
const uintptr_t DirB = reinterpret_cast<uintptr_t>(&DDRB);
const uintptr_t PortB = reinterpret_cast<uintptr_t>(&PORTB);

// Actual pin definitions
const ArduinoPin<AvrPinTraits<DirB, PortB, PB0>> D13{};

// These are stateless, so we can  have aliases for free
const ArduinoPin<AvrPinTraits<DirB, PortB, PB0>> BuiltinLed{};

#endif /* _TEMPLATEDUINO_UNO_H_ */
