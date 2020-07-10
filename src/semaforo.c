/*
 * semaforo.c
 *
 *  Created on: 9 jul. 2020
 *      Author: francisco
 */

#include "semaforo.h"

LED_t ledEnc = VERDE;
delay_t tiempo;

void establecerInicio() {
	estado_semaforo = ROJO_STATE;
	gpioWrite((LED_t) ROJO, ON);
	return;
}

void establecerEstado(estado_t nuevo_estado) {
	estado_semaforo = nuevo_estado;
	return;
}

void actualizarSemaforo() {
	if (estado_semaforo == VERDE_STATE) {
		if (gpioRead((LED_t) ROJO)) {
			gpioWrite((LED_t) ROJO, OFF);
			gpioWrite((LED_t) AMARILLO, ON);
			delayInit(&tiempo, 1000);
		} else if (gpioRead((LED_t) AMARILLO)) {
			if (delayRead(&tiempo)) {
				gpioWrite((LED_t) AMARILLO, OFF);
				gpioWrite((LED_t) VERDE, ON);
			}
		} else
			gpioWrite((LED_t) VERDE, ON);
	}
	if (estado_semaforo == AMARILLO_STATE) {
		gpioWrite((LED_t) VERDE, OFF);
		gpioWrite((LED_t) ROJO, OFF);
		if (delayRead(&tiempo)) {
			delayInit(&tiempo, 1000);
			gpioToggle((LED_t) AMARILLO);
		}
	}
	if (estado_semaforo == ROJO_STATE) {
		if (gpioRead((LED_t) VERDE)) {
			gpioWrite((LED_t) VERDE, OFF);
			gpioWrite((LED_t) AMARILLO, ON);
			delayInit(&tiempo, 1000);
		} else if (gpioRead((LED_t) AMARILLO)) {
			if (delayRead(&tiempo)) {
				gpioWrite((LED_t) AMARILLO, OFF);
				gpioWrite((LED_t) ROJO, ON);
			}
		} else
			gpioWrite((LED_t) ROJO, ON);
	}
	return;
}
