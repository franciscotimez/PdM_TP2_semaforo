/*=============================================================================
 * Copyright (c) 2020, Francisco Timez <franciscotimez@gmail.com>
 * All rights reserved.
 * License: mit (see LICENSE.txt)
 * Date: 2020/07/09
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "TP_semaforo.h"
#include "sapi.h"
#include "semaforo.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/
estado_t estadoActual = ROJO_STATE;
delay_t tiempoColor;
/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main(void) {
	// ----- Setup -----------------------------------
	boardInit();
	establecerInicio();
	// ----- Repeat for ever -------------------------
	while (true) {
		if (!gpioRead(TEC1)) {
			delay(10);
			if (estadoActual == AMARILLO_STATE) {
				estadoActual = ROJO_STATE;
				establecerEstado(estadoActual);
			} else {
				estadoActual = AMARILLO_STATE;
				establecerEstado(estadoActual);
			}

		}
		if (estadoActual == VERDE_STATE && delayRead(&tiempoColor)) {
			estadoActual = ROJO_STATE;
			establecerEstado(estadoActual);
			delayInit(&tiempoColor, 3000);
		} else if (estadoActual == ROJO_STATE && delayRead(&tiempoColor)) {
			estadoActual = VERDE_STATE;
			establecerEstado(estadoActual);
			delayInit(&tiempoColor, 3000);
		}
		actualizarSemaforo();

	}

	// YOU NEVER REACH HERE, because this program runs directly or on a
	// microcontroller and is not called by any Operating System, as in the
	// case of a PC program.
	return 0;
}
