#include <Arduino.h>
#include "keypad.h"
#include "pagebase.h"
#include "pages.h"

static Page *activePage = nullptr;

static void loadPage(Page *page)
{
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
  Keypad::initialize();

  loadPage(new MainPage());
}

void loop()
{
  if (activePage != nullptr)
  {
    activePage->loop();
  }
}
