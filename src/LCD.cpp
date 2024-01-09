#include "LCD.h"

hd44780_I2Cexp lcd;

void lcd_initialize()
{
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.clear();
}