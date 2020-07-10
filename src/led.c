/*
 * led.c
 *
 *  Created on: 9 jul. 2020
 *      Author: francisco
 */

#include "led.h"

void encender(LED_t led) {
	gpioWrite(ROJO, OFF);
	gpioWrite(AMARILLO, OFF);
	gpioWrite(VERDE, OFF);
	gpioWrite(led, ON);
	return;
}

void apagarTodo() {
	gpioWrite(ROJO, OFF);
	gpioWrite(AMARILLO, OFF);
	gpioWrite(VERDE, OFF);
	return;
}

LED_t statusLed() {
	if (gpioRead((LED_t) VERDE))
		return (LED_t) VERDE;
	else if (gpioRead((LED_t) AMARILLO))
		return (LED_t) AMARILLO;
	else if (gpioRead((LED_t) ROJO))
		return (LED_t) ROJO;
	else
		return (LED_t) APAGADO;
}
