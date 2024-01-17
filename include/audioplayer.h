#pragma once

#include <Arduino.h>
#include <DFMiniMp3.h>
#include <SoftwareSerial.h>
#include "Pages.h"

class Mp3Notify
{
public:
  static void OnError([[maybe_unused]] DFMiniMp3<SoftwareSerial, Mp3Notify> &mp3, uint16_t errorCode)
  {
  }
  static void OnPlayFinished([[maybe_unused]] DFMiniMp3<SoftwareSerial, Mp3Notify> &mp3, [[maybe_unused]] DfMp3_PlaySources source, uint16_t track)
  {
  }
  static void OnPlaySourceOnline([[maybe_unused]] DFMiniMp3<SoftwareSerial, Mp3Notify> &mp3, DfMp3_PlaySources source)
  {
  }
  static void OnPlaySourceInserted([[maybe_unused]] DFMiniMp3<SoftwareSerial, Mp3Notify> &mp3, DfMp3_PlaySources source)
  {
  }
  static void OnPlaySourceRemoved([[maybe_unused]] DFMiniMp3<SoftwareSerial, Mp3Notify> &mp3, DfMp3_PlaySources source)
  {
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