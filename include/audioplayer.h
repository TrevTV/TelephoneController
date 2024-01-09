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
extern int volume;

void audioPlayer_initialize();

void audioPlayer_loop();

void audioPlayer_playTrack(int track);

void audioPlayer_volumeUp();

void audioPlayer_volumeDown();