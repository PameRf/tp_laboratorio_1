/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int pedirNumero(int* , char mensaje[], char error[], int minimo, int maximo, int reintentos);
int pedirPrecio(long int* pPrecio, char mensaje[], char error[], int minimo, long int maximo, int reintentos);

int main(void) {

	setbuf(stdout,NULL);

	int opcionMenu;
	int flagMenu;
	int kilometros;
	long int precioAerolineas;
	long int precioLatam;
	long int precioConTcDebitoAr;
	long int precioConTcDebitoLa;
	int validarOpcion;
	int validarPrecio;

	flagMenu=0;

	do{

		if(flagMenu==0){
			printf("1) Ingresar Kilómetros: (km=x)\n");
			printf("2) Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n"
					 "- Precio vuelo Aerolíneas: \n"
					 "- Precio vuelo Latam: \n");
			printf("3) Calcular todos los costos: \n"
					 "a) Tarjeta de débito (descuento 10%%)\n"
					 "b) Tarjeta de crédito (interés 25%%)\n"
					 "c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
					 "d) Mostrar precio por km (precio unitario)\n"
					 "e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");

			printf("4) Informar Resultados\n"
					   "Latam:\n"
					   "a) Precio con tarjeta de débito: r\n"
					   "b) Precio con tarjeta de crédito: r\n"
					   "c) Precio pagando con bitcoin : r\n"
					   "d) Precio unitario: r\n"
					   "Aerolíneas:\n"
					   "a) Precio con tarjeta de débito: r\n"
					   "b) Precio con tarjeta de crédito: r\n"
					   "c) Precio pagando con bitcoin : r\n"
					   "d) Precio unitario: r\n"
					   "La diferencia de precio es : r \n");
			printf("5) Carga forzada de datos\n");
			printf("6) Salir\n");

			validarOpcion= pedirNumero(&opcionMenu, "Ingrese una opcion:", "La opcion ingresada no es valida",1, 6,2);


		}
		else if(flagMenu==1){

			printf("1) Ingresar Kilómetros: (km=%d)\n",kilometros);
			printf("2) Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)\n"
					 "- Precio vuelo Aerolíneas: \n"
					 "- Precio vuelo Latam: \n");
			printf("3) Calcular todos los costos: \n"
					 "a) Tarjeta de débito (descuento 10%%)\n"
					 "b) Tarjeta de crédito (interés 25%%)\n"
					 "c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
					 "d) Mostrar precio por km (precio unitario)\n"
					 "e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");

			printf("4) Informar Resultados\n"
					  "Latam:\n"
					   "a) Precio con tarjeta de débito: r\n"
					   "b) Precio con tarjeta de crédito: r\n"
					   "c) Precio pagando con bitcoin : r\n"
					   "d) Precio unitario: r\n"
					   "Aerolíneas:\n"
					   "a) Precio con tarjeta de débito: r\n"
					   "b) Precio con tarjeta de crédito: r\n"
					   "c) Precio pagando con bitcoin : r\n"
					   "d) Precio unitario: r\n"
					   "La diferencia de precio es : r \n");
			printf("5) Carga forzada de datos\n");
			printf("6) Salir\n");


			validarOpcion= pedirNumero(&opcionMenu, "Ingrese una opcion: ", "La opcion ingresada no es valida\n",1, 6,2);

		}
		else if(flagMenu==2){

			printf("1) Ingresar Kilómetros: (km=%d)\n",kilometros);
			printf("2) Ingresar Precio de Vuelos: (Aerolíneas= %ld, Latam=%ld)\n"
					 "- Precio vuelo Aerolíneas: \n"
					 "- Precio vuelo Latam: \n", precioAerolineas,precioLatam);
			printf("3) Calcular todos los costos: \n"
					 "a) Tarjeta de débito (descuento 10%%)\n"
					 "b) Tarjeta de crédito (interés 25%%)\n"
					 "c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
					 "d) Mostrar precio por km (precio unitario)\n"
					 "e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");

			printf("4) Informar Resultados\n"
					  "Latam:\n"
					   "a) Precio con tarjeta de débito: r\n"
					   "b) Precio con tarjeta de crédito: r\n"
					   "c) Precio pagando con bitcoin : r\n"
					   "d) Precio unitario: r\n"
					   "Aerolíneas:\n"
					   "a) Precio con tarjeta de débito: r\n"
					   "b) Precio con tarjeta de crédito: r\n"
					   "c) Precio pagando con bitcoin : r\n"
					   "d) Precio unitario: r\n"
					   "La diferencia de precio es : r \n");
			printf("5) Carga forzada de datos\n");
			printf("6) Salir\n");


			validarOpcion= pedirNumero(&opcionMenu, "Ingrese una opcion: ", "La opcion ingresada no es valida",1, 6,2);
		}
		else if(flagMenu==3){

			printf("1) Ingresar Kilómetros: (km=%d)\n",kilometros);
			printf("2) Ingresar Precio de Vuelos: (Aerolíneas= %ld, Latam=%ld)\n"
					 "- Precio vuelo Aerolíneas: \n"
					 "- Precio vuelo Latam: \n", precioAerolineas,precioLatam);
			printf("3) Calcular todos los costos: \n"
					 "a) Tarjeta de débito (descuento 10%%)\n"
					 "b) Tarjeta de crédito (interés 25%%)\n"
					 "c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
					 "d) Mostrar precio por km (precio unitario)\n"
					 "e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");

			printf("4) Informar Resultados\n"
					  "Latam:\n"
					   "a) Precio con tarjeta de débito: r\n"
					   "b) Precio con tarjeta de crédito: r\n"
					   "c) Precio pagando con bitcoin : r\n"
					   "d) Precio unitario: r\n"
					   "Aerolíneas:\n"
					   "a) Precio con tarjeta de débito: r\n"
					   "b) Precio con tarjeta de crédito: r\n"
					   "c) Precio pagando con bitcoin : r\n"
					   "d) Precio unitario: r\n"
					   "La diferencia de precio es : r \n");
			printf("5) Carga forzada de datos\n");
			printf("6) Salir\n");



			validarOpcion= pedirNumero(&opcionMenu, "Ingrese una opcion:", "La opcion ingresada no es valida\n",1, 6,2);
				}
		if(validarOpcion== 0){
		switch(opcionMenu){
			case 1:
				if(pedirNumero(&kilometros, "Ingrese los Kilometros del vuelo:", "Los kilometros se encuentran fuera del rango \n",
						400, 13000, 2)==0){
					flagMenu=1;
				}
				break;

			case 2:
				if(flagMenu==1){
					if(pedirPrecio(&precioAerolineas, "Ingrese el precio del pasaje de Aerolineas Argentinas: ", "El precio que ingreso no es un precio valido\n"
						, 9000 , 1000000, 2)==0){
						if(pedirPrecio(&precioLatam, "Ingrese el precio del pasaje de Latam: ", "El precio que ingreso no es un precio valido\n"
												, 9000 , 1000000, 2)==0){
							flagMenu=2;
						}
					}

					break;
				}
				else{
					printf("Primero debe ingresar los Kilometros\n");
				}
				break;
			case 3:
				if(flagMenu== 2){
					validarPrecio=Calcular_PagoDebito(&precioConTcDebitoAr, kilometros, precioAerolineas);

					if(validarPrecio==0){
							printf("los resultados son: %ld",precioConTcDebitoAr);
							flagMenu=3;
							break;
					}
				}

				else{
					printf("Primero debe ingresar las opciones anteriores\n");
				}
				break;
			case 4:
				if(flagMenu==3){
					printf("Se muestran  los resultados");
				}
				else{
					printf("Primero debe ingresar las opciones anteriores\n");
				}
				break;

		}
	  }




	}while(opcionMenu != 6);



	return EXIT_SUCCESS;
}

int pedirNumero(int* pOpcion, char mensaje[], char error[], int minimo, int maximo, int reintentos){

	int retorno;
	int auxiliar;
	retorno=-1;

	if(pOpcion != NULL && mensaje != NULL && error != NULL && minimo <= maximo && reintentos>= 0 ){

		do{
		printf("%s", mensaje);
		scanf("%d", &auxiliar);
		reintentos--;

		if(auxiliar >= minimo && auxiliar <= maximo){
			*pOpcion= auxiliar;
			retorno=0;
			break;
		}
		else{
			printf("%s", error);
		}


		}while(reintentos > 0);

	}
	return retorno;
}

int pedirPrecio(long int* pPrecio, char mensaje[], char error[], int minimo, long int maximo, int reintentos){

	int retorno;
	int precioAuxiliar;
	retorno=-1;

	if(pPrecio != NULL && mensaje != NULL && error != NULL && minimo <= maximo && reintentos>= 0 ){

		do{
		printf("%s", mensaje);
		scanf("%d", &precioAuxiliar);
		reintentos--;

		if(precioAuxiliar >= minimo && precioAuxiliar <= maximo){
			*pPrecio= precioAuxiliar;
			retorno=0;
			break;
		}
		else{
			printf("%s", error);
		}


		}while(reintentos > 0);

	}
	return retorno;
}
