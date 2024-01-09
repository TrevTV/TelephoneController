#include "Keypad.h"

bool Keypad::buttonStates[12] = {false};
const int Keypad::pinMatch[12][2] = {
    {8, 6}, /* ONE */
    {8, 5}, /* TWO */
    {8, 2}, /* THREE */
    {7, 6}, /* FOUR */
    {7, 5}, /* FIVE */
    {7, 2}, /* SIX */
    {3, 6}, /* SEVEN */
    {3, 5}, /* EIGHT */
    {3, 2}, /* NINE */
    {4, 6}, /* STAR */
    {4, 5}, /* ZERO */
    {4, 2}, /* POUND  */
};

void Keypad::initialize()
{
    const int numPins = 7;
    const int pins[numPins] = {2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < numPins; i++)
    {
        pinMode(pins[i], INPUT_PULLUP);
    }
}

bool Keypad::isButton(Button key)
{
    const int *match = pinMatch[key];
    bool a = digitalRead(match[0]) == LOW;
    bool b = digitalRead(match[1]) == LOW;
    return a && b;
}

bool Keypad::isButtonUp(Button key)
{
    bool currentState = isButton(key);
    bool wasPressed = buttonStates[key] && !currentState;
    buttonStates[key] = currentState;

    return wasPressed;
}

bool Keypad::isButtonDown(Button key)
{
    bool currentState = isButton(key);
    bool wasReleased = !buttonStates[key] && currentState;
    buttonStates[key] = currentState;

    return wasReleased;
}

char Keypad::buttonToChar(Button key)
{
    const char charList[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '0', '#'};
    return charList[key];
}