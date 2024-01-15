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
    if (keypad.isButtonDown(Button::ONE)) {
        Serial.println("AudioSelectionPage::loop() - Button::ONE");
        AudioPlayerPage::trackNumber = 1;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::TWO)) {
        Serial.println("AudioSelectionPage::loop() - Button::TWO");
        AudioPlayerPage::trackNumber = 2;
        loadPage(AudioPlayerPage::ID);
    }
    if (keypad.isButtonDown(Button::STAR))
    {
        Serial.println("AudioSelectionPage::loop() - Button::STAR");
        dfmp3.stop();
        loadPage(MainPage::ID);
    }
}