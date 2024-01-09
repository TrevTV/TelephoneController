#pragma once

#include "Page.h"
#include "Keypad.h"

extern Page *activePage;
extern Keypad *keypad;

void loadPage(Page *page);

Keypad *getKeypad();