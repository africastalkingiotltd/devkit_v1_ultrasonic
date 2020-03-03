/*
 * hcsr04.h
 *
 *  Created on: Mar 2, 2020
 *      Author: kennedyotieno
 */

#ifndef HCSR04_H_
#define HCSR04_H_

#include <stdint.h>

uint32_t getUltrasonicTime(void);
uint32_t getDistance(uint32_t pin_time);

#endif /* HCSR04_H_ */
