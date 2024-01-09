#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

extern hd44780_I2Cexp lcd;

void lcd_initialize();