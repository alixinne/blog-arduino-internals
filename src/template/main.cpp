#include "Arduino.h"

int main() {
  pinMode(LED_BUILTIN, OUTPUT);

  while (1) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
