/*
 * semaforo.h
 *
 *  Created on: 9 jul. 2020
 *      Author: francisco
 */

#ifndef MISPROGRAMAS_TP_SEMAFORO_INC_SEMAFORO_H_
#define MISPROGRAMAS_TP_SEMAFORO_INC_SEMAFORO_H_

#include "led.h"
#include "sapi.h"

typedef enum {
	VERDE_STATE,
	AMARILLO_STATE,
	ROJO_STATE
} estado_t;

static estado_t estado_semaforo;

void establecerInicio();

void establecerEstado(estado_t nuevo_estado);

void actualizarSemaforo();



#endif /* MISPROGRAMAS_TP_SEMAFORO_INC_SEMAFORO_H_ */
