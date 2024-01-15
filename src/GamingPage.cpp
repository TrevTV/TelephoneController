#include <Arduino.h>
#include <HID-Project.h>
#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "LCD.h"

void GamingPage::start()
{
    Serial.println("GamingPage::start()");
    lcd.print("GAMING MODE");
    lcd.setCursor(0, 1);
    lcd.print("PRESS * TO EXIT");
}

void GamingPage::loop()
{
    /* if (keypad->isButtonDown(Button::STAR)) {
        Serial.println("GamingPage::loop() - Button::STAR");
        loadPage(new MainPage());
    } */

    if (keypad->isButton(Button::FIVE)) {
        Serial.println("GamingPage::loop() - Button::FIVE");
        Keyboard.press('w');
    }
    else {
        Keyboard.release('w');
    }

    if (keypad->isButton(Button::SEVEN)) {
        Serial.println("GamingPage::loop() - Button::SEVEN");
        Keyboard.press('a');
    }
    else {
        Keyboard.release('a');
    }

    if (keypad->isButton(Button::EIGHT)) {
        Serial.println("GamingPage::loop() - Button::EIGHT");
        Keyboard.press('s');
    }
    else {
        Keyboard.release('s');
    }

    if (keypad->isButton(Button::NINE)) {
        Serial.println("GamingPage::loop() - Button::NINE");
        Keyboard.press('d');
    }
    else {
        Keyboard.release('d');
    }

    if (keypad->isButton(Button::FOUR)) {
        Serial.println("GamingPage::loop() - Button::FOUR");
        Keyboard.press(KEY_LEFT_SHIFT);
    }
    else {
        Keyboard.release(KEY_LEFT_SHIFT);
    }

    if (keypad->isButton(Button::POUND)) {
        Serial.println("GamingPage::loop() - Button::POUND");
        Keyboard.press(KEY_SPACE);
    }
    else {
        Keyboard.release(KEY_SPACE);
    }
}