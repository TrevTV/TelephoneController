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
        AudioPlayerPage::resetWithTrack(1);
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::TWO))
    {
        AudioPlayerPage::resetWithTrack(2);
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::THREE))
    {
        AudioPlayerPage::resetWithTrack(3);
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::FOUR))
    {
        AudioPlayerPage::resetWithTrack(4);
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::FIVE))
    {
        AudioPlayerPage::resetWithTrack(5);
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::SIX))
    {
        AudioPlayerPage::resetWithTrack(6);
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::SEVEN))
    {
        AudioPlayerPage::resetWithTrack(7);
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::EIGHT))
    {
        AudioPlayerPage::resetWithTrack(8);
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::NINE))
    {
        AudioPlayerPage::resetWithTrack(9);
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::ZERO))
    {
        AudioPlayerPage::resetWithTrack(10);
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::POUND))
    {
        AudioPlayerPage::resetWithTrack(11);
        loadPage(AudioPlayerPage::ID);
    }

    if (keypad.isButtonDown(Button::STAR))
    {
        dfmp3.stop();
        loadPage(MainPage::ID);
    }
}