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



int main(void) {

	setbuf(stdout,NULL);

	int opcionMenu;
	int flagMenu;
	int kilometros;
	long int precioAerolineas;
	long int precioLatam;

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
			printf("5) Carga forzada de datos");
			printf("6) Salir");
			printf("Ingrese opcion: ");
			scanf("%d", &opcionMenu);


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
			printf("5) Carga forzada de datos");
			printf("6) Salir");


			printf("Ingrese opcion: ");
			scanf("%d",&opcionMenu);

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
			printf("5) Carga forzada de datos");
			printf("6) Salir");


			printf("Ingrese opcion: ");
			scanf("%d",&opcionMenu);
		}
		switch(opcionMenu){
		case 1:
			printf("Ingrese los Kilometros");
			scanf("%d",&kilometros);
			flagMenu=1;
			break;
		case 2:
			if(flagMenu==1){
				//armar logica y cambiar flag//
				printf("Ingresar Precio vuelo Aerolíneas: \n");
				printf("Ingresar Precio vuelo Aerolíneas: \n");
			}
			else{
				printf("Primero debe ingresar los Kilometros");
			}
		}



	}while(opcionMenu != 6);



	return EXIT_SUCCESS;
}
