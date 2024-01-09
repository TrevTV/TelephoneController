#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "AudioPlayer.h"

AudioPlayerPage::AudioPlayerPage(int track)
{
    trackNumber = track;
}

void AudioPlayerPage::start()
{
    Serial.println("AudioPlayerPage::start()");
}

void AudioPlayerPage::loop()
{
    if (getKeypad()->isButtonDown(Button::ONE))
    {
        Serial.println("AudioPlayerPage::loop() - Button 1 pressed");
        audioPlayer_playTrack(trackNumber);
    }
}