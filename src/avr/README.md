# `avr` variant

On AVRs microcontrollers, each I/O port gets:
* A `DDRx` register (Data Direction Register), where a `1` bit indicates the
  corresponding pin is an output
* A `PORTx` register, where a `1` indicates a high output level, and a `0` a
  low level on the corresponding pin

Each port also has `Pxy` definitions, where `x` is the port name (`A`, `B`,
`C`, etc.) and `y` is the pin number on that port (`0` to `7`).

To match the Arduino pin number with the physical pin number, you'll have to
look at the [Arduino Uno
schematic](https://content.arduino.cc/assets/UNOSMD_V3_sch.pdf) (since we're
using an Arduino Uno for testing here), and follow the built-in LED path to its
input on the ATMega328P: the `PB5` pin (port B, pin 5).

Using bit operators, you can then toggle the output on and off, which is
essentially what `digitalWrite` does.

```cpp
#include <avr/io.h>

int main() {
  DDRB |= (1 << PB5);

  while (1) {
    PORTB |= (1 << PB5);
    PORTB &= ~(1 << PB5);
  }
}
```
