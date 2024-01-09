#pragma once

#include <Arduino.h>
#include <DFMiniMp3.h>
#include <SoftwareSerial.h>

class Mp3Notify
{
public:
  static void PrintlnSourceAction(DfMp3_PlaySources source, const char *action)
  {
    if (source & DfMp3_PlaySources_Sd)
    {
      Serial.print("SD Card, ");
    }
    Serial.println(action);
  }
  static void OnError([[maybe_unused]] DFMiniMp3<SoftwareSerial, Mp3Notify> &mp3, uint16_t errorCode)
  {
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);
  }
  static void OnPlayFinished([[maybe_unused]] DFMiniMp3<SoftwareSerial, Mp3Notify> &mp3, [[maybe_unused]] DfMp3_PlaySources source, uint16_t track)
  {
    Serial.print("Play finished for #");
    Serial.println(track);
  }
  static void OnPlaySourceOnline([[maybe_unused]] DFMiniMp3<SoftwareSerial, Mp3Notify> &mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "online");
  }
  static void OnPlaySourceInserted([[maybe_unused]] DFMiniMp3<SoftwareSerial, Mp3Notify> &mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "inserted");
  }
  static void OnPlaySourceRemoved([[maybe_unused]] DFMiniMp3<SoftwareSerial, Mp3Notify> &mp3, DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "removed");
  }
};

extern SoftwareSerial secondarySerial;
extern DFMiniMp3<SoftwareSerial, Mp3Notify> dfmp3;

static inline void audioPlayer_initialize()
{
  Serial.println("AudioPlayer::initialize()");

  dfmp3.begin();
  dfmp3.reset();

  dfmp3.setVolume(8);
}

static inline void audioPlayer_loop()
{
  dfmp3.loop();
}

static inline void audioPlayer_playTrack(int track)
{
  dfmp3.playMp3FolderTrack(track);
}