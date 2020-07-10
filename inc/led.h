/*
 * led.h
 *
 *  Created on: 9 jul. 2020
 *      Author: francisco
 */

#ifndef MISPROGRAMAS_TP_SEMAFORO_INC_LED_H_
#define MISPROGRAMAS_TP_SEMAFORO_INC_LED_H_

#include "sapi.h"

typedef enum {
		VERDE = LED3,
		AMARILLO = LED1,
		ROJO = LED2
}LED_t;

void encender(LED_t led);




#endif /* MISPROGRAMAS_TP_SEMAFORO_INC_LED_H_ */
