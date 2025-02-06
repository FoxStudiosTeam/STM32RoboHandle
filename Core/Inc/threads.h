//
// Created by Endie on 06.02.2025.
//

#ifndef THREADS_H
#define THREADS_H
#include <stm32f1xx_hal_rcc.h>
#include <stdio.h>
#include <messages.h>

static void MainDisplayMessagesThread(void const *argument) {
    ssd1306_Init();
    HelloMessage();
    StatusScreenSetup();
}

static void LedTaskThread(void const *argument) {
    void **args = (void **) argument;

    GPIO_TypeDef *ledPinGroup = (GPIO_TypeDef *) args[0];
    uint16_t ledPin = (uint16_t)(uintptr_t)args[1];

    while (1) {
        HAL_Delay(500);
        HAL_GPIO_WritePin(ledPinGroup, ledPin, GPIO_PIN_SET);
        HAL_Delay(500);
        HAL_GPIO_WritePin(ledPinGroup, ledPin, GPIO_PIN_RESET);
    }
}
#endif //THREADS_H
