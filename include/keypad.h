#pragma once

#include <Arduino.h>

enum Button
{
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

class Keypad
{
public:
  void initialize();
  void checkButtonStates();
  bool isButton(Button key);
  bool isButtonUp(Button key);
  bool isButtonDown(Button key);
  char buttonToChar(Button key);

private:
  const static int pinCount;
  const static int pins[7];
  
  static bool buttonStates[12];
  static bool prevButtonStates[12];
  static int pinStates[7];

  bool pinActive(int pin);
  void parseRow(Button a, Button b, Button c);
};