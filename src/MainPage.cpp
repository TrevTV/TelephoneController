#include "pages.h"
#include "keypad.h"

void MainPage::start()
{
    Serial.println("MainPage::start()");
}

void MainPage::loop()
{
    // temp for testing
    for (int i = 0; i < 12; i++)
    {
        if (Keypad::isButtonDown(static_cast<Keypad::Button>(i)))
        {
            Serial.print("Button down: ");
            Serial.println(Keypad::buttonToChar(static_cast<Keypad::Button>(i)));
        }
    }
}