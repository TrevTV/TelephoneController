#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "LCD.h"

void MainPage::start()
{
    lcd.print("MAIN");
    lcd.setCursor(0, 1);
}

void MainPage::loop()
{
    if (keypad.isButtonDown(Button::ONE))
    {
        loadPage(AudioSelectionPage::ID);
    }
    if (keypad.isButtonDown(Button::TWO))
    {
        loadPage(NumpadPage::ID);
    }
    if (keypad.isButtonDown(Button::THREE))
    {
        loadPage(GamingPage::ID);
    }
}