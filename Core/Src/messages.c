//
// Created by Endie on 04.02.2025.
//
#include "messages.h"
#include "variables.h"
#include "stdio.h"

void HelloMessage(){
  char version[50];
  VersionMessage(version);
}

void ScreenDelay(){
  ssd1306_Fill(White);
  ssd1306_UpdateScreen();
  HAL_Delay(1000);
}

void StatusScreenSetup(){
  int cursorX = 0;
  int cursorY = 16;

  ssd1306_SetCursor(cursorX,cursorY);
  ssd1306_WriteString("Hello", Font_6x8,White);
  ssd1306_UpdateScreen();
  HAL_Delay(500);

  int i = 0;
  int size = (sizeof(char) * 100) + 8;
  // 108/128
  char* c = malloc(size);
  while(1){
    ClearSection(size, cursorX, cursorY);
    ssd1306_SetCursor(cursorX,cursorY);
    i++;
    sprintf(c,"Count %d", i);
    ssd1306_WriteString(c, Font_6x8, White);
    if(i == 100){
      i = 0;
    }
    ssd1306_UpdateScreen();
    HAL_Delay(1000);
  }
}

void VersionMessage(char *result){
  char version[50];
  sprintf(version,"Robo-hand %s", CODEBASE_VERSION);
  ssd1306_WriteString(version, Font_6x8, White);
  ssd1306_UpdateScreen();
}

void ClearSection(int8_t length, int8_t cursorX, int8_t cursorY){
  ssd1306_FillRectangle(cursorX, cursorY + 8, length * 6, cursorY, Black);
  ssd1306_UpdateScreen();
}