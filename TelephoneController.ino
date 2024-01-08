#include "keypad.h"

void setup() {
  Serial.begin(9600);
  Keypad::initialize();
}

void loop() {
  // temp for testing
  for (int i = 0; i < 12; i++) {
    if (Keypad::isButtonDown(i)) {
      Serial.println(Keypad::buttonToChar(i));
    }
  }
}
