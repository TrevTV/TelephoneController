#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "AudioPlayer.h"
#include "LCD.h"

void AudioSelectionPage::start()
{
    Serial.println("AudioPlayerPage::start()");
    lcd.print("AUDIO SELECT");
}

void AudioSelectionPage::loop()
{
    if (keypad.isButtonDown(Button::ONE))
    {
        Serial.println("AudioSelectionPage::loop() - Button::ONE");
        AudioPlayerPage::trackNumber = 1;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::TWO))
    {
        Serial.println("AudioSelectionPage::loop() - Button::TWO");
        AudioPlayerPage::trackNumber = 2;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::THREE))
    {
        Serial.println("AudioSelectionPage::loop() - Button::THREE");
        AudioPlayerPage::trackNumber = 3;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::FOUR))
    {
        Serial.println("AudioSelectionPage::loop() - Button::FOUR");
        AudioPlayerPage::trackNumber = 4;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::FIVE))
    {
        Serial.println("AudioSelectionPage::loop() - Button::FIVE");
        AudioPlayerPage::trackNumber = 5;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::SIX))
    {
        Serial.println("AudioSelectionPage::loop() - Button::SIX");
        AudioPlayerPage::trackNumber = 6;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::SEVEN))
    {
        Serial.println("AudioSelectionPage::loop() - Button::SEVEN");
        AudioPlayerPage::trackNumber = 7;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::EIGHT))
    {
        Serial.println("AudioSelectionPage::loop() - Button::EIGHT");
        AudioPlayerPage::trackNumber = 8;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::NINE))
    {
        Serial.println("AudioSelectionPage::loop() - Button::NINE");
        AudioPlayerPage::trackNumber = 9;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::ZERO))
    {
        Serial.println("AudioSelectionPage::loop() - Button::ZERO");
        AudioPlayerPage::trackNumber = 10;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::POUND))
    {
        Serial.println("AudioSelectionPage::loop() - Button::POUND");
        AudioPlayerPage::trackNumber = 11;
        loadPage(AudioPlayerPage::ID);
    }

    if (keypad.isButtonDown(Button::STAR))
    {
        Serial.println("AudioSelectionPage::loop() - Button::STAR");
        dfmp3.stop();
        loadPage(MainPage::ID);
    }
}