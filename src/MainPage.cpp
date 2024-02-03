#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "LCD.h"

int MainPage::frame = 0;

void MainPage::start()
{
    lcd.setCursor(0, 0);
    lcd.print("0100100100101001010010010010100101001010");
    lcd.setCursor(0, 1);
    lcd.print("0010011001000101001001100100010101001100");
}

void MainPage::loop()
{
    frame++;

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

    if (frame % 10000 == 0)
    {
        lcd.scrollDisplayLeft();
        frame = 0;
    }
}