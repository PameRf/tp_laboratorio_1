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
#define CANTIDAD_PASAJEROS 2000


int main(void) {

	setbuf(stdout,NULL);

	int opcionMenu;
	int validarMenu;
	int flagMenu;
	Passenger pasajeros[CANTIDAD_PASAJEROS];
	Passenger auxPasajero;
	int validarRetorno;
	int validarPax;
	int idModificar;
	int order;
	int opcionSort;
	int seguir;


	validarRetorno=initPassengers(pasajeros, CANTIDAD_PASAJEROS);

	//printf("Se pudo inicializar %d\n",validarRetorno);

	do{

		mostrarMenuPrincipal();

		validarMenu= pedirNumero(&opcionMenu, "Ingrese una opcion \n", "Error! Ingrese una opcion valida: \n",1, 6, 2);

		if(validarMenu== 0){
		switch(opcionMenu){
			case 1:
				auxPasajero= cargarUnPax(&validarPax);
				if(validarPax==0){
					auxPasajero.id=generarId(pasajeros, CANTIDAD_PASAJEROS);

					if(auxPasajero.id >0 && addPassenger(pasajeros, CANTIDAD_PASAJEROS, auxPasajero.id, auxPasajero.name, auxPasajero.lastName,auxPasajero.price, auxPasajero.typePassenger,auxPasajero.flycode,auxPasajero.statusFlight)==0){

						printf("Se pudo cargar el pasajero \n");
						flagMenu=1;
					}
					else{

						printf("No se pudo cargar el pasajero\n");
					}
				}
				break;
			case 2:

				if(flagMenu==1 || flagMenu==2){
				printPassenger(pasajeros, CANTIDAD_PASAJEROS);
				validarRetorno=pedirNumero(&idModificar, "Ingrese el ID del pasajero que desea modificar\n", "Error dato invalido", 1001, 1000000, 2);
				if(validarRetorno==0){
					modificarPasajero(pasajeros, CANTIDAD_PASAJEROS, idModificar);
				}

				}
				else{
					printf("Primero debe estar cargado algun pasajero\n");
				}
				break;
			case 3:
				if(flagMenu==1 || flagMenu==2){
					printPassenger(pasajeros, CANTIDAD_PASAJEROS);
					validarRetorno=pedirNumero(&idModificar, "Ingrese el ID del pasajero que desea dar de baja\n", "Error dato invalido", 1001, 1000000, 2);
					if(validarRetorno==0){

						if(removePassenger(pasajeros, CANTIDAD_PASAJEROS, idModificar)==0){

							printf("El pasajero pudo darse de baja, nueva lista de pasajeros\n");
							printPassenger(pasajeros, CANTIDAD_PASAJEROS);
						}
						else{
							printf("El pasajero no pudo darse de baja id invalido \n");
						}
					}
				}
				else{
					printf("Primero debe estar cargado algun pasajero\n");
				}

				break;
			case 4:
				if(flagMenu==1 || flagMenu==2){

					mostrarMenuSort();
					validarRetorno=pedirNumero(&opcionSort, "Ingrese una opcion\n", "Error! Ingrese una opcion valida: \n",1, 3, 2);
						if(validarRetorno==0){
							if(opcionSort==1 || opcionSort ==3){
								pedirNumero(&order,"Desea ordenar de manera  descendente (ingrese 0) o ascendente (ingrese 1)\n","Error orden incorrecto \n",0,1,2);

							}
						switch(opcionSort){
						case 1:
							printPassenger(pasajeros, CANTIDAD_PASAJEROS);//muestro paxs sin ordenar
							printf("\n\n");
							if(sortPassengers(pasajeros, CANTIDAD_PASAJEROS, order)==0 && ordenarPassengersPorTipo(pasajeros, CANTIDAD_PASAJEROS, order)== 0){
								printf("\n\n");
								printf("-------Pasajeros ordenados alfabeticamente y por tipo si son iguales----------- \n");
								printPassenger(pasajeros, CANTIDAD_PASAJEROS);//paxs ordenados
							}

						    break;
						case 2:
							calcularPrecioPromedio(pasajeros, CANTIDAD_PASAJEROS);
							printf("\n\n");
						    break;
						case 3:

							printPassenger(pasajeros, CANTIDAD_PASAJEROS);//muestro paxs sin ordenar
							printf("\n\n");
							if(sortPassengersByCode(pasajeros, CANTIDAD_PASAJEROS, order)==0 && ordenarPassengersPorStatusFly(pasajeros, CANTIDAD_PASAJEROS, order)== 0){
								printf("------Pasajeros ordenados por codigo de vuelo y por estado de vuelo si son iguales-------\n");
								printPassenger(pasajeros, CANTIDAD_PASAJEROS);//paxs ordenados
								printf("\n\n");
							}
							break;
						}
					}
				}
				else{
					printf("Primero debe estar cargado algun pasajero\n");
				}
				break;
			case 5:
				cargaForzadaDePax(pasajeros, CANTIDAD_PASAJEROS);
				printPassenger(pasajeros, CANTIDAD_PASAJEROS);
				flagMenu=2;
				break;
			case 6:
				validarRetorno=pedirNumero(&seguir, "Desea salis \n 1.si \n 2.no\n", "Error ingrese una Opcion valida\n", 1, 2, 2);
				if(seguir==1){
				printf("Gracias por elegir Smart Travel\n");
				}
				break;
		}
	}

	}while(seguir != 1);

	return EXIT_SUCCESS;
}

