#include "AudioPlayer.h"

SoftwareSerial secondarySerial(10, 11);
DFMiniMp3<SoftwareSerial, Mp3Notify> dfmp3(secondarySerial);

void audioPlayer_initialize()
{
  Serial.println("AudioPlayer::initialize()");

  dfmp3.begin();
  dfmp3.reset();

  dfmp3.setVolume(8);
}

void audioPlayer_loop()
{
  dfmp3.loop();
}

void audioPlayer_playTrack(int track)
{
  dfmp3.playMp3FolderTrack(track);
}