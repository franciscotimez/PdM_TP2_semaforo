/*
 * led.c
 *
 *  Created on: 9 jul. 2020
 *      Author: francisco
 */

#include "led.h"


void encender(LED_t led){
	gpioWrite(ROJO, OFF);
	gpioWrite(AMARILLO, OFF);
	gpioWrite(VERDE, OFF);
	gpioWrite(led, ON);
	return;
}

