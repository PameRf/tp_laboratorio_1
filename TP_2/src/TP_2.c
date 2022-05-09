/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "ArrayPassenger.h"
#define CANTIDAD_PASAJEROS 4


int main(void) {

	setbuf(stdout,NULL);

	int opcionMenu;
	int validarMenu;
	//int flagMenu;
	Passenger pasajeros[CANTIDAD_PASAJEROS];
	int validarRetorno;

	validarRetorno=initPassengers(pasajeros, CANTIDAD_PASAJEROS);

	printf("Se pudo inicializar %d\n",validarRetorno);

	do{
	printf("1. ALTAS: Se debe permitir ingresar un pasajero calculando automáticamente el \n"
			"número de Id. El resto de los campos se le pedirá al usuario \n");
	printf("2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido \n"
			"o Precio o Tipo de pasajero o Código de vuelo \n");
	printf("3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema\n");
	printf("4. INFORMAR:\n"
			"1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
			"2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio\n"
			"promedio.\n"
            "3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
	printf("5. Salir\n");

	validarMenu= pedirNumero(&opcionMenu, "Ingrese una opcion \n", "Error! Ingrese una opcion valida: \n",1, 5, 2);

	if(validarMenu== 0){
		switch(opcionMenu){
			case 1: printf("Esta en altas\n");
				break;
			case 2: printf("Esta en modificar\n");
				break;
			case 3: printf("Esta en bajas\n");
				break;
			case 4: printf("Esta en informar\n");
				break;
			case 5: printf("salir");
				break;
		}
	}

	}while(opcionMenu != 5);

	return EXIT_SUCCESS;
}
