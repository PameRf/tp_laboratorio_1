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
#define CANTIDAD_PASAJEROS 6


int main(void) {

	setbuf(stdout,NULL);

	int opcionMenu;
	int validarMenu;
	//int flagMenu;
	Passenger pasajeros[CANTIDAD_PASAJEROS]={{1001, "Juan", "Carlos", 12000,"ar29",1, 0} ,
            {1002, "Roberto", "Gomez", 13000,"ar29",2, 0},
			{1003, "Ezequiel", "Jimenez", 150345, "ar45",3, 0},
            {1004, "Martin", "Hernandez",24000, "la23",1, 0},
            {1005, "Jose", "Perez",356786, "la69",2, 0},
            {1006, "Carla", "Luque", 23453, "ba23",1, 0}};

	Passenger auxPasajero;
	//int validarRetorno;
	//char respuesta='s';
	//int idPasajero;
	//int index;
	//int validaPaxCargado;



	//validarRetorno=initPassengers(pasajeros, CANTIDAD_PASAJEROS);

	//printf("Se pudo inicializar %d\n",validarRetorno);

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
			case 1:

				auxPasajero= cargarUnPax();
					//printPassenger(auxPasajero);

					if(addPassenger(pasajeros, CANTIDAD_PASAJEROS, auxPasajero.id, auxPasajero.name, auxPasajero.lastName,auxPasajero.price, auxPasajero.typePassenger,auxPasajero.flycode)==0){

						printf("Se pudo cargar el pasajero \n");
					}
					else{

						printf("No se pudo cargar el pasajero");

					}


				break;

				/*if(validaPaxCargado != 5){

					printf("Se pudo cargar el pasajero \n");
					printPassenger(auxPasajero);
				}
				else{

					printf("No se pudo cargar el pasajero");

				}*/
				//auxpasa(funcion un cagar un pasajero)
				// carga la lista addpassager
		//	printf("Esta en altas %d\n", idPasajero);

			case 2:

				modificarPasajero(pasajeros, CANTIDAD_PASAJEROS, 1003);


				//printf("el indice encontrado vacio es %d\n",index);
				break;
			case 3:
				if(removePassenger(pasajeros, CANTIDAD_PASAJEROS, 1005)==0){

					printf("El pasajero pudo darse de baja, nueva lista de pasajeros\n");
					printPassenger(pasajeros, CANTIDAD_PASAJEROS);
				}
				else{
					printf("El pasajero no pudo darse de baja id invalido \n");
				}
				//printf("Su codigo de vuelo es %s: \n",flycode);
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
