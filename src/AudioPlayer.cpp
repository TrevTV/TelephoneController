#include "AudioPlayer.h"

SoftwareSerial secondarySerial(10, 11);
DFMiniMp3<SoftwareSerial, Mp3Notify> dfmp3(secondarySerial);
int volume = 8;

void audioPlayer_initialize()
{
  dfmp3.begin();
  dfmp3.reset();

  dfmp3.setVolume(volume);
}

void audioPlayer_loop()
{
  dfmp3.loop();
}

void audioPlayer_playTrack(int track)
{
  dfmp3.playMp3FolderTrack(track);
}

void audioPlayer_volumeUp()
{
  if (volume < 30)
  {
    volume++;
    dfmp3.setVolume(volume);
  }
}

void audioPlayer_volumeDown()
{
  if (volume > 0)
  {
    volume--;
    dfmp3.setVolume(volume);
  }
}