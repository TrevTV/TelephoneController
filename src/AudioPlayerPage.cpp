#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "AudioPlayer.h"
#include "LCD.h"

AudioPlayerPage::AudioPlayerPage(int track)
{
    trackNumber = track;
}

void AudioPlayerPage::start()
{
    Serial.println("AudioPlayerPage::start()");
    lcd.print("AUDIO");
    lcd.setCursor(0, 1);
}

void AudioPlayerPage::loop()
{
    if (getKeypad()->isButtonDown(Button::ONE))
    {
        Serial.println("AudioPlayerPage::loop() - Button 1 pressed");
        audioPlayer_playTrack(trackNumber);
    }
}