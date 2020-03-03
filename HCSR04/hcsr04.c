/*
 * hcsr04.c
 *
 *  Created on: Mar 2, 2020
 *      Author: kennedyotieno
 */

#include "stm32f1xx_hal.h"
#include "gpio.h"
#include <stdint.h>
#include "main.h"
#include "hcsr04.h"

uint32_t pin_timer;

uint32_t getUltrasonicTime(void)
{
    pin_timer  = 0;
    HAL_GPIO_WritePin(TRIGGER_PORT, TRIGGER_PIN, RESET);
    delayMicroseconds(5);
    HAL_GPIO_WritePin(TRIGGER_PORT, TRIGGER_PIN, SET);
    delayMicroseconds(10);
    HAL_GPIO_WritePin(TRIGGER_PORT, TRIGGER_PIN, RESET);

    while(!(HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN)));
    while (HAL_GPIO_ReadPin(ECHO_PORT, ECHO_PIN))
    {
        pin_timer++;
        delayMicroseconds(1);
    }
    return pin_timer;
}

uint32_t getDistance(uint32_t pin_time)
{
    return ((pin_time ) * (.034));
}

