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
    if (keypad->isButtonDown(Button::ONE)) {
        Serial.println("AudioSelectionPage::loop() - Button::ONE");
        loadPage(new AudioPlayerPage(1));
    }
    if (keypad->isButtonDown(Button::TWO)) {
        Serial.println("AudioSelectionPage::loop() - Button::TWO");
        loadPage(new AudioPlayerPage(2));
    }
}