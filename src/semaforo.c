/*
 * semaforo.c
 *
 *  Created on: 9 jul. 2020
 *      Author: francisco
 */

#include "semaforo.h"

delay_t tiempo;

void establecerInicio() {
	estado_semaforo = ROJO_STATE;
	encender((LED_t) ROJO);
	return;
}

void establecerEstado(estado_t nuevo_estado) {
	estado_semaforo = nuevo_estado;
	return;
}

void actualizarSemaforo() {
	if (estado_semaforo == VERDE_STATE) {
		if (statusLed() == (LED_t) ROJO) {
			encender((LED_t) AMARILLO);
			delayInit(&tiempo, 1000);
		} else if (statusLed() == (LED_t) AMARILLO) {
			if (delayRead(&tiempo))
				encender((LED_t) VERDE);
		} else
			encender((LED_t) VERDE);
	}
	if (estado_semaforo == AMARILLO_STATE) {
		if (delayRead(&tiempo)) {
			if (statusLed() == (LED_t) APAGADO)
				encender((LED_t) AMARILLO);
			else
				apagarTodo();
			delayInit(&tiempo, 1000);
		}
	}
	if (estado_semaforo == ROJO_STATE) {
		if (statusLed() == (LED_t) VERDE) {
			encender((LED_t) AMARILLO);
			delayInit(&tiempo, 1000);
		} else if (statusLed() == (LED_t) AMARILLO) {
			if (delayRead(&tiempo)) {
				encender((LED_t) ROJO);
			}
		} else
			encender((LED_t) ROJO);
	}
	return;
}
