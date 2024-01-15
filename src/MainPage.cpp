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
    if (keypad->isButtonDown(Button::ONE))
    {
        Serial.println("MainPage::loop() - Button 1 pressed");
        loadPage(new AudioSelectionPage());
    }
    if (keypad->isButtonDown(Button::TWO))
    {
        Serial.println("MainPage::loop() - Button 2 pressed");
        loadPage(new NumpadPage());
    }
    if (keypad->isButtonDown(Button::THREE))
    {
        Serial.println("MainPage::loop() - Button 3 pressed");
        loadPage(new GamingPage());
    }
}