#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "LCD.h"

void MainPage::start()
{
    Serial.println("MainPage::start()");
    lcd.print("MAIN");
    lcd.setCursor(0, 1);
}

void MainPage::loop()
{
    if (getKeypad()->isButtonDown(Button::ONE))
    {
        Serial.println("MainPage::loop() - Button 1 pressed");
        loadPage(new AudioPlayerPage(1));
    }
}