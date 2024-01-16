#include <Arduino.h>
#include <HID-Project.h>
#include "TelephoneController.h"
#include "Keypad.h"
#include "LCD.h"
#include "Pages.h"
#include "AudioPlayer.h"

Keypad keypad;
int activePage = -1;

void loadPage(int page)
{
  if (page == activePage)
  {
    return;
  }

  lcd.clear();
  activePage = page;

  switch (activePage) {
    case MainPage::ID:
      MainPage::start();
      break;
    case AudioSelectionPage::ID:
      AudioSelectionPage::start();
      break;
    case AudioPlayerPage::ID:
      AudioPlayerPage::start();
      break;
    case NumpadPage::ID:
      NumpadPage::start();
      break;
    case GamingPage::ID:
      GamingPage::start();
      break;
  }
}

void setup()
{
  Serial.begin(9600);

  keypad.initialize();
  audioPlayer_initialize();
  lcd_initialize();

  loadPage(MainPage::ID);
}

void loop()
{
  keypad.checkButtonStates();

  switch (activePage) {
    case MainPage::ID:
      MainPage::loop();
      break;
    case AudioSelectionPage::ID:
      AudioSelectionPage::loop();
      break;
    case AudioPlayerPage::ID:
      AudioPlayerPage::loop();
      break;
    case NumpadPage::ID:
      NumpadPage::loop();
      break;
    case GamingPage::ID:
      GamingPage::loop();
      break;
  }
}