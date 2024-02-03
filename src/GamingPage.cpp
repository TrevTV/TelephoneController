#include <Arduino.h>
#include <HID-Project.h>
#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "LCD.h"

void GamingPage::start()
{
    lcd.print("GAMING MODE");
    lcd.setCursor(0, 1);
    lcd.print("PRESS * TO EXIT");
}

void GamingPage::loop()
{
    if (keypad.isButtonDown(Button::STAR)) {
        loadPage(MainPage::ID);
        return;
    }

    if (keypad.isButton(Button::FIVE)) {
        Keyboard.press('w');
    }
    else {
        Keyboard.release('w');
    }

    if (keypad.isButton(Button::SEVEN)) {
        Keyboard.press('a');
    }
    else {
        Keyboard.release('a');
    }

    if (keypad.isButton(Button::EIGHT)) {
        Keyboard.press('s');
    }
    else {
        Keyboard.release('s');
    }

    if (keypad.isButton(Button::NINE)) {
        Keyboard.press('d');
    }
    else {
        Keyboard.release('d');
    }

    if (keypad.isButton(Button::FOUR)) {
        Keyboard.press(KEY_LEFT_SHIFT);
    }
    else {
        Keyboard.release(KEY_LEFT_SHIFT);
    }

    if (keypad.isButton(Button::POUND)) {
        Keyboard.press(KEY_SPACE);
    }
    else {
        Keyboard.release(KEY_SPACE);
    }
}