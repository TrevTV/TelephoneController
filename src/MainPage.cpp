#include "pages.h"
#include "keypad.h"
#include "telephonecontroller.h"

void MainPage::start()
{
    Serial.println("MainPage::start()");
}

void MainPage::loop()
{
    if (getKeypad()->isButtonDown(Button::ONE))
    {
        Serial.println("MainPage::loop() - Button 1 pressed");
        loadPage(new AudioPlayerPage(1));
    }
}