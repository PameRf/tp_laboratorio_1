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
#define CANTIDAD_PASAJEROS 8


int main(void) {

	setbuf(stdout,NULL);

	int opcionMenu;
	int validarMenu;
	int flagMenu;
	Passenger pasajeros[CANTIDAD_PASAJEROS];
	Passenger auxPasajero;
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
	printf("5. Carga forzada de pasajeros \n");
	printf("6. Salir\n");

	validarMenu= pedirNumero(&opcionMenu, "Ingrese una opcion \n", "Error! Ingrese una opcion valida: \n",1, 6, 2);

	if(validarMenu== 0){
		switch(opcionMenu){
			case 1:
				auxPasajero= cargarUnPax();
				if(addPassenger(pasajeros, CANTIDAD_PASAJEROS, auxPasajero.id, auxPasajero.name, auxPasajero.lastName,auxPasajero.price, auxPasajero.typePassenger,auxPasajero.flycode,auxPasajero.statusFlight)==0){

					printf("Se pudo cargar el pasajero \n");
					flagMenu=1;
				}
				else{

					printf("No se pudo cargar el pasajero");
				}
				break;
			case 2:

				if(flagMenu==1 || flagMenu==2){
				modificarPasajero(pasajeros, CANTIDAD_PASAJEROS, 1001);
				}
				else{
					printf("Primero debe estar cargado algun pasajero\n");
				}
				break;
			case 3:
				if(flagMenu==1 || flagMenu==2){
					if(removePassenger(pasajeros, CANTIDAD_PASAJEROS, 1001)==0){

						printf("El pasajero pudo darse de baja, nueva lista de pasajeros\n");
						printPassenger(pasajeros, CANTIDAD_PASAJEROS);
					}
					else{
						printf("El pasajero no pudo darse de baja id invalido \n");
					}
				}
				else{
					printf("Primero debe estar cargado algun pasajero\n");
				}

				break;
			case 4:
				if(flagMenu==1 || flagMenu==2){

					printPassenger(pasajeros, CANTIDAD_PASAJEROS);
					printf("\n\n");
					sortPassengers(pasajeros, CANTIDAD_PASAJEROS, 0);
					printf("\n\n");
					printf("Pasajeros ordenados alfabeticamente y por tipo si son iguales \n");
					printPassenger(pasajeros, CANTIDAD_PASAJEROS);
					printf("\n\n");
					calcularPrecioPromedio(pasajeros, CANTIDAD_PASAJEROS);
					printf("\n\n");
					printPassenger(pasajeros, CANTIDAD_PASAJEROS);
					printf("\n\n");
					sortPassengersByCode(pasajeros, CANTIDAD_PASAJEROS, 0);
					printf("Pasajeros ordenados por codigo de vuelo y por estado de vuelo si son iguales\n");
					printPassenger(pasajeros, CANTIDAD_PASAJEROS);
					printf("\n\n");
				}
				else{
					printf("Primero debe estar cargado algun pasajero\n");
				}
				break;
			case 5:
				cargaForzadaDePax(pasajeros);
				printPassenger(pasajeros, CANTIDAD_PASAJEROS);
				flagMenu=2;
				break;
			case 6:
				printf("Gracias por elegir Smart Travel\n");
				break;
		}
	}

	}while(opcionMenu != 6);

	return EXIT_SUCCESS;
}

