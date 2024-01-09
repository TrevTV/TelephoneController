#pragma once
#include "pagebase.h"
#include "keypad.h"

extern Page *activePage;
extern Keypad *keypad;

void loadPage(Page *page);

static Keypad *getKeypad() {
    return keypad;
}