#ifndef _TEMPLATEDUINO_UNO_H_
#define _TEMPLATEDUINO_UNO_H_

#include <stddef.h>
#include <stdint.h>

// Include platform definition
#include "TemplateduinoAvr.h"

// Board definition

// Workaround for _IO macros not being constexpr
// They will be constant-folded away
const uintptr_t DirB = reinterpret_cast<uintptr_t>(&DDRB);
const uintptr_t PortB = reinterpret_cast<uintptr_t>(&PORTB);

// Actual pin definitions
const ArduinoPin<AvrPinTraits<DirB, PortB, PB5>> D13{};

// Alias pin names using references
const auto &BuiltinLed{D13};

#endif /* _TEMPLATEDUINO_UNO_H_ */
