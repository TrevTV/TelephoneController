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

const int memory_test[8] = {1, 2, 3, 4, 5, 6, 7, 8};

void loop()
{
  keypad->checkButtonStates();
  audioPlayer_loop();

  if (activePage != nullptr)
  {
    activePage->loop();
  }

  for (int i = 0; i < 8; i++)
  {
    Serial.println("Memory test: " + String(memory_test[i]));
    if (memory_test[i] > 8 || memory_test[i] < 1)
    {
      Serial.println("Memory test failed with value: " + String(memory_test[i]));
      while (true)
      {
        /* code */
      }
      
    }
  }
}