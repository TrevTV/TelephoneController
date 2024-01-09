#include <Arduino.h>
#include "TelephoneController.h"
#include "keypad.h"
#include "audioplayer.h"
#include "pagebase.h"
#include "pages.h"

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

  activePage = page;
  activePage->start();
}

void setup()
{
  Serial.begin(9600);
  keypad = new Keypad();
  keypad->initialize();
  audioPlayer_initialize();

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
