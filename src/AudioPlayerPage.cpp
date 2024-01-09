#include "pages.h"
#include "keypad.h"
#include "telephonecontroller.h"
#include "audioplayer.h"

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