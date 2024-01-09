#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "AudioPlayer.h"
#include "LCD.h"

// there isn't a way to get the file name from the SD card, so we have to hardcode the track names
// https://github.com/Makuna/DFMiniMp3/issues/97
const char *AudioPlayerPage::tracksByIndex[12] =
    {
        "I Really Want To Stay At Your House",
        "Elevator Music",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };

AudioPlayerPage::AudioPlayerPage(int track)
{
    trackNumber = track;
    trackName = tracksByIndex[trackNumber - 1];
}

void AudioPlayerPage::start()
{
    Serial.println("AudioPlayerPage::start()");

    audioPlayer_playTrack(trackNumber);

    lcd.print(trackName);
    lcd.setCursor(0, 1);
    lcd.print("TRACK ");
    lcd.print(trackNumber);
}

void AudioPlayerPage::loop()
{
    frameCount++;

    if (keypad->isButtonDown(Button::FIVE))
    {
        Serial.println("AudioPlayerPage::loop() - Button::FIVE");
        isPlaying = !isPlaying;
        if (isPlaying)
        {
            dfmp3.start();
        }
        else
        {
            dfmp3.pause();
        }
    }

    if (keypad->isButtonDown(Button::TWO))
    {
        Serial.println("AudioPlayerPage::loop() - Button::TWO");
        audioPlayer_volumeUp();
    }

    if (keypad->isButtonDown(Button::EIGHT))
    {
        Serial.println("AudioPlayerPage::loop() - Button::EIGHT");
        audioPlayer_volumeDown();
    }

    if (keypad->isButtonDown(Button::STAR))
    {
        Serial.println("AudioPlayerPage::loop() - Button::STAR");
        dfmp3.stop();
        loadPage(new AudioSelectionPage());
    }

    if (frameCount % 600 == 0)
    {
        lcd.scrollDisplayLeft();
        frameCount = 0;
    }

    delay(1);
}