#pragma once

#include <Arduino.h>
#include "Page.h"

class MainPage : public Page
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
    int trackNumber;
};