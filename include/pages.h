#pragma once

#include <Arduino.h>
#include "Page.h"

class MainPage : public Page
{
public:
    void start();
    void loop();
};

class AudioSelectionPage : public Page
{
public:
    void start();
    void loop();
};

class AudioPlayerPage : public Page
{
public:
    AudioPlayerPage(int track);
    void start();
    void loop();
private:
    bool isPlaying;

    int frameCount;
    int trackNumber;
    const char* trackName;
    const static char *tracksByIndex[12];
};

class NumpadPage : public Page
{
public:
    void start();
    void loop();
};

class GamingPage : public Page
{
public:
    void start();
    void loop();
};