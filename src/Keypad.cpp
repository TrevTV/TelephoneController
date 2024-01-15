#include <Arduino.h>
#include "Keypad.h"

bool Keypad::buttonStates[12] = {false};
bool Keypad::prevButtonStates[12] = {false};

const int Keypad::pinCount = 7;
const int Keypad::pins[7] = { 2, 3, 4, 5, 6, 7, 8 };
int Keypad::pinStates[7] = { HIGH };

void Keypad::initialize()
{
    for (int i = 0; i < pinCount; i++)
    {
        pinMode(pins[i], INPUT_PULLUP);
    }
}

void Keypad::checkButtonStates()
{
    for (int i = 0; i < 12; i++)
    {
        prevButtonStates[i] = buttonStates[i];
        buttonStates[i] = false;
    }

    for (int i = 0; i < pinCount; i++)
    {
        pinStates[i] = digitalRead(pins[i]);
    }

    if (pinActive(8))
    {
        parseRow(Button::ONE, Button::TWO, Button::THREE);
    }

    if (pinActive(7))
    {
        parseRow(Button::FOUR, Button::FIVE, Button::SIX);
    }

    if (pinActive(3))
    {
        parseRow(Button::SEVEN, Button::EIGHT, Button::NINE);
    }

    if (pinActive(4))
    {
        parseRow(Button::STAR, Button::ZERO, Button::POUND);
    }
}

void Keypad::parseRow(Button a, Button b, Button c) {
    if (pinActive(6)) {
        buttonStates[a] = true;
    }
    else {
        buttonStates[a] = false;
    }

    if (pinActive(5)) {
        buttonStates[b] = true;
    }
    else {
        buttonStates[b] = false;
    }

    if (pinActive(2)) {
        buttonStates[c] = true;
    }
    else {
        buttonStates[c] = false;
    }
}

bool Keypad::pinActive(int pin) {
    // We subtract 2 from the pin number as the array is 0-indexed and the pin numbers start at 2
    return pinStates[pin - 2] == LOW;
}

bool Keypad::isButton(Button key)
{
    return buttonStates[key];
}

bool Keypad::isButtonUp(Button key)
{
    return prevButtonStates[key] && !buttonStates[key];
}

bool Keypad::isButtonDown(Button key)
{
    return !prevButtonStates[key] && buttonStates[key];
}

char Keypad::buttonToChar(Button key)
{
    const char charList[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#'};
    return charList[key];
}
