#pragma once

#include <Arduino.h>

class MainPage
{
public:
    static const int ID = 0;
    static void start();
    static void loop();
};

class AudioSelectionPage
{
public:
    static const int ID = 1;
    static void start();
    static void loop();
};

class AudioPlayerPage
{
public:
    static const int ID = 2;
    static int trackNumber;
    static void start();
    static void loop();
    static void onTrackComplete();
private:
    static bool isPlaying;

    static bool playFinished;
    static int trackNameLength;
    static const char* trackName;
    static const char *tracksByIndex[11];

    static int frame;
    
    static void refreshDisplay();
};

class NumpadPage
{
public:
    static const int ID = 3;
    static void start();
    static void loop();
};

class GamingPage
{
public:
    static const int ID = 4;
    static void start();
    static void loop();
};