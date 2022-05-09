/*
 * ArrayPassenger.h
 *
 *  Created on: 9 may. 2022
 *      Author: pamel
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"

typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
} Passenger;

int initPassengers(Passenger* list, int len);

#endif /* ARRAYPASSENGER_H_ */
