#ifndef _TEMPLATEDUINO_UNO_H_
#define _TEMPLATEDUINO_UNO_H_

#include <stddef.h>
#include <stdint.h>

// Board definition

// Workaround for _IO macros not being constexpr
// They will be constant-folded away
const uintptr_t DirB = reinterpret_cast<uintptr_t>(&DDRB);
const uintptr_t DirD = reinterpret_cast<uintptr_t>(&DDRD);
const uintptr_t PortB = reinterpret_cast<uintptr_t>(&PORTB);
const uintptr_t PortD = reinterpret_cast<uintptr_t>(&PORTD);

// Actual pin definitions: using static since these objects are stateless
static const DigitalPin<AvrPinTraits<DirD, PortD, PD0>> D0{};
static const DigitalPin<AvrPinTraits<DirD, PortD, PD1>> D1{};
static const DigitalPin<AvrPinTraits<DirD, PortD, PD2>> D2{};
static const DigitalPin<AvrPinTraits<DirD, PortD, PD3>> D3{};
static const DigitalPin<AvrPinTraits<DirD, PortD, PD4>> D4{};
static const DigitalPin<AvrPinTraits<DirD, PortD, PD5>> D5{};
static const DigitalPin<AvrPinTraits<DirD, PortD, PD6>> D6{};
static const DigitalPin<AvrPinTraits<DirD, PortD, PD7>> D7{};
static const DigitalPin<AvrPinTraits<DirB, PortB, PB0>> D8{};
static const DigitalPin<AvrPinTraits<DirB, PortB, PB1>> D9{};
static const DigitalPin<AvrPinTraits<DirB, PortB, PB2>> D10{};
static const DigitalPin<AvrPinTraits<DirB, PortB, PB3>> D11{};
static const DigitalPin<AvrPinTraits<DirB, PortB, PB4>> D12{};
static const DigitalPin<AvrPinTraits<DirB, PortB, PB5>> D13{};

// Alias pin names using references
static const auto &BuiltinLed{D13};
// Pin number for the LED_BUILTIN Arduino compatibility definition
static const uint8_t BuiltinLedPinNumber = 13;

// Declare compile-time pin map
static const PinMap<
    PinMapEntry<0, decltype(D0)>, PinMapEntry<1, decltype(D1)>,
    PinMapEntry<2, decltype(D2)>, PinMapEntry<3, decltype(D3)>,
    PinMapEntry<4, decltype(D4)>, PinMapEntry<5, decltype(D5)>,
    PinMapEntry<6, decltype(D6)>, PinMapEntry<7, decltype(D7)>,
    PinMapEntry<8, decltype(D8)>, PinMapEntry<9, decltype(D9)>,
    PinMapEntry<10, decltype(D10)>, PinMapEntry<11, decltype(D11)>,
    PinMapEntry<12, decltype(D12)>, PinMapEntry<13, decltype(D13)>>
    TemplateduinoPins{};

// Run-time pin map declaration
static const PinTable TemplateduinoPinTable{};

// Pin mapping tables
#ifdef TEMPLATEDUINO_MAIN
#define NOT_A_PORT 0

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#define PE 5
#define PF 6
#define PG 7
#define PH 8
#define PJ 10
#define PK 11
#define PL 12

// clang-format off
const uint16_t PROGMEM port_to_mode_PGM[] = {
    NOT_A_PORT,
    NOT_A_PORT,
    (uint16_t)&DDRB,
    (uint16_t)&DDRC,
    (uint16_t)&DDRD,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
    NOT_A_PORT,
    NOT_A_PORT,
    (uint16_t)&PORTB,
    (uint16_t)&PORTC,
    (uint16_t)&PORTD,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
    NOT_A_PORT,
    NOT_A_PORT,
    (uint16_t)&PINB,
    (uint16_t)&PINC,
    (uint16_t)&PIND,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
    PD, /* 0 */
    PD,
    PD,
    PD,
    PD,
    PD,
    PD,
    PD,
    PB, /* 8 */
    PB,
    PB,
    PB,
    PB,
    PB,
    PC, /* 14 */
    PC,
    PC,
    PC,
    PC,
    PC,
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
    _BV(0), /* 0, port D */
    _BV(1),
    _BV(2),
    _BV(3),
    _BV(4),
    _BV(5),
    _BV(6),
    _BV(7),
    _BV(0), /* 8, port B */
    _BV(1),
    _BV(2),
    _BV(3),
    _BV(4),
    _BV(5),
    _BV(0), /* 14, port C */
    _BV(1),
    _BV(2),
    _BV(3),
    _BV(4),
    _BV(5),
};
// clang-format on
#endif /* TEMPLATEDUINO_MAIN */

#endif /* _TEMPLATEDUINO_UNO_H_ */
