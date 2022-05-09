/*
 * ArrayPassenger.c
 *
 *  Created on: 9 may. 2022
 *      Author: pamel
 */
#include "ArrayPassenger.h"

int initPassengers(Passenger* list, int len){

	int retorno;
	retorno=-1;

		if (list != NULL && len > 0) {
			for (int i = 0; i < len; i++) {
				list[i].isEmpty = 1;
				retorno=0;
			}
		}
	return retorno;
}

