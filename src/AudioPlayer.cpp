#include "audioplayer.h"

SoftwareSerial secondarySerial(10, 11);
DFMiniMp3<SoftwareSerial, Mp3Notify> dfmp3(secondarySerial);