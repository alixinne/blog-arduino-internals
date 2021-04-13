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
const uintptr_t DirD = reinterpret_cast<uintptr_t>(&DDRD);
const uintptr_t PortB = reinterpret_cast<uintptr_t>(&PORTB);
const uintptr_t PortD = reinterpret_cast<uintptr_t>(&PORTD);

// Actual pin definitions: using static since these objects are stateless
static const ArduinoPin<AvrPinTraits<DirD, PortD, PD0>> D0{};
static const ArduinoPin<AvrPinTraits<DirD, PortD, PD1>> D1{};
static const ArduinoPin<AvrPinTraits<DirD, PortD, PD2>> D2{};
static const ArduinoPin<AvrPinTraits<DirD, PortD, PD3>> D3{};
static const ArduinoPin<AvrPinTraits<DirD, PortD, PD4>> D4{};
static const ArduinoPin<AvrPinTraits<DirD, PortD, PD5>> D5{};
static const ArduinoPin<AvrPinTraits<DirD, PortD, PD6>> D6{};
static const ArduinoPin<AvrPinTraits<DirD, PortD, PD7>> D7{};
static const ArduinoPin<AvrPinTraits<DirB, PortB, PB0>> D8{};
static const ArduinoPin<AvrPinTraits<DirB, PortB, PB1>> D9{};
static const ArduinoPin<AvrPinTraits<DirB, PortB, PB2>> D10{};
static const ArduinoPin<AvrPinTraits<DirB, PortB, PB3>> D11{};
static const ArduinoPin<AvrPinTraits<DirB, PortB, PB4>> D12{};
static const ArduinoPin<AvrPinTraits<DirB, PortB, PB5>> D13{};

// Alias pin names using references
static const auto &BuiltinLed{D13};

#endif /* _TEMPLATEDUINO_UNO_H_ */
