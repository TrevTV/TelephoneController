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
  bool isButton(Button key);
  bool isButtonUp(Button key);
  bool isButtonDown(Button key);
  char buttonToChar(Button key);

private:
  static bool buttonStates[12];
  const static int pinMatch[12][2];
};