#include "Templateduino.h"

int main() {
  BuiltinLed.setMode(PinMode::Output);

  while (1) {
    BuiltinLed.write(HIGH);
    BuiltinLed.write(LOW);
  }
}
