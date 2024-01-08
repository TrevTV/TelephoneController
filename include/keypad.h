#pragma once
#include "Arduino.h"

class Keypad {
public:
  enum Button {
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    STAR,
    ZERO,
    POUND,
  };

  static void initialize() {
    const int numPins = 7;
    const int pins[numPins] = { 2, 3, 4, 5, 6, 7, 8 };
    for (int i = 0; i < numPins; i++) {
      pinMode(pins[i], INPUT_PULLUP);
    }
  }

  static bool isButton(Button key) {
    const int *match = pinMatch[key];
    bool a = digitalRead(match[0]) == LOW;
    bool b = digitalRead(match[1]) == LOW;
    return a && b;
  }

  static bool isButtonUp(Button key) {
    static bool buttonStates[12] = { false };

    bool currentState = isButton(key);
    bool wasPressed = buttonStates[key] && !currentState;
    buttonStates[key] = currentState;

    return wasPressed;
  }

  static bool isButtonDown(Button key) {
    static bool buttonStates[12] = { false };

    bool currentState = isButton(key);
    bool wasReleased = !buttonStates[key] && currentState;
    buttonStates[key] = currentState;

    return wasReleased;
  }

  static char buttonToChar(Button key) {
    const char charList[12] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#' };
    return charList[key];
  }

private:
  const static int pinMatch[12][2];
};

const int Keypad::pinMatch[12][2] = {
  { 8, 6 }, /* ONE */
  { 8, 5 }, /* TWO */
  { 8, 2 }, /* THREE */
  { 7, 6 }, /* FOUR */
  { 7, 5 }, /* FIVE */
  { 7, 2 }, /* SIX */
  { 3, 6 }, /* SEVEN */
  { 3, 5 }, /* EIGHT */
  { 3, 2 }, /* NINE */
  { 4, 6 }, /* STAR */
  { 4, 5 }, /* ZERO */
  { 4, 2 }, /* POUND  */
};