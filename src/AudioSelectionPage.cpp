#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "AudioPlayer.h"
#include "LCD.h"

void AudioSelectionPage::start()
{
    lcd.print("AUDIO SELECT");
}

void AudioSelectionPage::loop()
{
    if (keypad.isButtonDown(Button::ONE))
    {
        AudioPlayerPage::trackNumber = 1;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::TWO))
    {
        AudioPlayerPage::trackNumber = 2;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::THREE))
    {
        AudioPlayerPage::trackNumber = 3;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::FOUR))
    {
        AudioPlayerPage::trackNumber = 4;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::FIVE))
    {
        AudioPlayerPage::trackNumber = 5;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::SIX))
    {
        AudioPlayerPage::trackNumber = 6;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::SEVEN))
    {
        AudioPlayerPage::trackNumber = 7;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::EIGHT))
    {
        AudioPlayerPage::trackNumber = 8;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::NINE))
    {
        AudioPlayerPage::trackNumber = 9;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::ZERO))
    {
        AudioPlayerPage::trackNumber = 10;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::POUND))
    {
        AudioPlayerPage::trackNumber = 11;
        loadPage(AudioPlayerPage::ID);
    }

    if (keypad.isButtonDown(Button::STAR))
    {
        dfmp3.stop();
        loadPage(MainPage::ID);
    }
}