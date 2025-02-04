//
// Created by Endie on 04.02.2025.
//

#ifndef MESSAGES_H
#define MESSAGES_H
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "stdlib.h"

void HelloMessage();

void ScreenDelay();

// Version Message Cursor is 0,0 (left top)
void VersionMessage(char *result);

// Status screen Cursor is 0,12 (+1 to Y)
void StatusScreenSetup();

void ClearSection(int8_t length, int8_t cursorX, int8_t cursorY);
#endif //MESSAGES_H
