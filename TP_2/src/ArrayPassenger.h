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
#define ECONOMY 1
#define PREMIUM ECONOMY 2
#define BUSINESS 3

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
int generarId();
int buscarEspacioLibre(Passenger* list, int len);
Passenger cargarUnPax();
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
int pedirFlyCode(char cadena[], char mensaje[], int len);
int mostrarUnPassenger(Passenger unPasajero);
int printPassenger(Passenger list[], int length);
int findPassengerById(Passenger* list, int len,int id);

#endif /* ARRAYPASSENGER_H_ */
