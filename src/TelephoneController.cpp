#include <Arduino.h>
#include "TelephoneController.h"
#include "Keypad.h"
#include "AudioPlayer.h"
#include "Page.h"
#include "Pages.h"
#include "LCD.h"

Page *activePage = nullptr;
Keypad *keypad = nullptr;

void loadPage(Page *page)
{
  if (page == activePage)
  {
    return;
  }

  if (activePage != nullptr)
  {
    delete activePage;
  }

  lcd.clear();
  activePage = page;
  activePage->start();
}

void setup()
{
  Serial.begin(9600);

  keypad = new Keypad();
  keypad->initialize();

  audioPlayer_initialize();
  lcd_initialize();

  loadPage(new MainPage());
}

void loop()
{
  audioPlayer_loop();

  if (activePage != nullptr)
  {
    activePage->loop();
  }
}