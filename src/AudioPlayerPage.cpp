#include "Pages.h"
#include "Keypad.h"
#include "TelephoneController.h"
#include "AudioPlayer.h"
#include "LCD.h"

// there isn't a way to get the file name from the SD card, so we have to hardcode the track names
// https://github.com/Makuna/DFMiniMp3/issues/97
const char *AudioPlayerPage::tracksByIndex[11] =
    {
        "IRWTSAYH",
        "Elevator Music",
        "Let You Down",
        "Phantom Liberty",
        "INFATUATION",
        "GLOOMTOWN BRATS",
        "Dont Fence Me In",
        "gone",
        "Ghost",
        "The Honcho",
        "Never Say No"
    };

uint8_t pauseIcon[8] = {0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b, 0x1b};
uint8_t playIcon[8] = {0x10, 0x18, 0x1c, 0x1e, 0x1e, 0x1c, 0x18, 0x10};

int AudioPlayerPage::trackNumber = 0;
bool AudioPlayerPage::isPlaying = true;
int AudioPlayerPage::frameCount = 0;
int AudioPlayerPage::trackNameLength = 0;
const char *AudioPlayerPage::trackName = "";

void AudioPlayerPage::start()
{
    trackName = tracksByIndex[trackNumber - 1];
    trackNameLength = strlen(trackName);

    audioPlayer_playTrack(trackNumber);

    lcd.createChar(0, pauseIcon);
    lcd.createChar(1, playIcon);
    
    refreshDisplay();
}

void AudioPlayerPage::loop()
{
    frameCount++;

    if (keypad.isButtonDown(Button::FIVE))
    {
        isPlaying = !isPlaying;
        if (isPlaying)
        {
            dfmp3.start();
        }
        else
        {
            dfmp3.pause();
        }

        refreshDisplay();
    }

    if (keypad.isButtonDown(Button::TWO))
    {
        audioPlayer_volumeUp();
        refreshDisplay();
    }

    if (keypad.isButtonDown(Button::EIGHT))
    {
        audioPlayer_volumeDown();
        refreshDisplay();
    }

    if (keypad.isButtonDown(Button::STAR))
    {
        dfmp3.stop();
        //loadPage(AudioSelectionPage::ID);
    }

    delay(1);
}

void AudioPlayerPage::refreshDisplay() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(trackName);

    lcd.setCursor(0, 1);
    lcd.write(isPlaying ? 1 : 0);

    lcd.print(" VOL: ");
    lcd.print(volume);
    lcd.print(" ");
}

void AudioPlayerPage::onTrackComplete() {
    isPlaying = false;
    refreshDisplay();
    lcd.print("FINISH");
}