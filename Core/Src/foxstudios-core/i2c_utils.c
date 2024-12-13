#include "i2c_utils.h"

#include "stdio.h"
#include "stm32f1xx_hal.h"
#include "stdlib.h"

void i2c_init(){
    init_scl1_pin();
    init_sda1_pin();
}

void init_scl1_pin(void){
    GPIO_InitTypeDef I2C_SCL1_PIN_InitStructure = {0};
    //SCL1
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
    I2C_SCL1_PIN_InitStructure.Pin = GPIO_PIN_6;
    I2C_SCL1_PIN_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
    I2C_SCL1_PIN_InitStructure.Pull = GPIO_NOPULL;
    I2C_SCL1_PIN_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;

}

void init_sda1_pin(){
    GPIO_InitTypeDef I2C_SDA1_PIN_InitStructure = {0};
    //SDA1
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
    I2C_SDA1_PIN_InitStructure.Pin = GPIO_PIN_7;
    I2C_SDA1_PIN_InitStructure.Mode = GPIO_MODE_OUTPUT_OD;
    I2C_SDA1_PIN_InitStructure.Pull = GPIO_NOPULL;
    I2C_SDA1_PIN_InitStructure.Speed = GPIO_SPEED_FREQ_LOW;
}