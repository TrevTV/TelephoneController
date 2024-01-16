#include <Arduino.h>
#include <HID-Project.h>
#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "LCD.h"

void NumpadPage::start()
{
    lcd.print("NUMPAD MODE");
    lcd.setCursor(0, 1);
    lcd.print("PRESS * TO EXIT");
}

void NumpadPage::loop()
{
    if (keypad.isButtonDown(Button::STAR)) {
        //loadPage(new MainPage());
    }

    for (int i = 0; i < 12; i++)
    {
        if (i == 10) continue; // Skip the * key

        if (keypad.isButtonDown((Button)i)) {
            char key = keypad.buttonToChar((Button)i);
            Keyboard.print(key);
        }
    }
}