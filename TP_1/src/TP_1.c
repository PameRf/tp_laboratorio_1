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
#include "cargas.h"


int main(void) {

	setbuf(stdout,NULL);

	int opcionMenu;
	int flagMenu;
	int kilometros;
	long int precioAerolineas;
	long int precioLatam;
	long int precioConTcDebitoAr;
	long int precioConTcDebitoLa;
	long int precioConTcCreditoAr;
	long int precioConTcCreditoLa;
	float precioBitcoinAr;
	float precioBitcoinLa;
	int validarOpcion;
	float precioUnitarioAr;
	float precioUnitarioLa;
	float diferenciaPrecios;


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
		else if(flagMenu==2||flagMenu==3){

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
		else if(flagMenu==4){
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
					   "a) Precio con tarjeta de débito:%ld\n"
					   "b) Precio con tarjeta de crédito:%ld\n"
					   "c) Precio pagando con bitcoin : %.9lf\n"
					   "d) Precio unitario:%.2f\n"
					   "Aerolíneas:\n"
					   "a) Precio con tarjeta de débito:%ld\n"
					   "b) Precio con tarjeta de crédito:%ld\n"
					   "c) Precio pagando con bitcoin : %.9lf\n"
					   "d) Precio unitario:%.2f\n"
					   "La diferencia de precio es: %.2f\n",precioConTcDebitoLa, precioConTcCreditoLa, precioBitcoinLa,precioUnitarioLa,
					   precioConTcDebitoAr, precioConTcCreditoAr, precioBitcoinAr, precioUnitarioAr, diferenciaPrecios);
			printf("5) Carga forzada de datos\n");
						printf("6) Salir\n");


			validarOpcion= pedirNumero(&opcionMenu, "Ingrese una opcion: ", "La opcion ingresada no es valida",1, 6,2);

		}
		else if(flagMenu==5){
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
					  "a) Precio con tarjeta de débito:%ld\n"
					  "b) Precio con tarjeta de crédito:%ld\n"
					  "c) Precio pagando con bitcoin : %.9lf\n"
					  "d) Precio unitario:%.2f\n"
					  "Aerolíneas:\n"
					  "a) Precio con tarjeta de débito:%ld\n"
					  "b) Precio con tarjeta de crédito:%ld\n"
					  "c) Precio pagando con bitcoin : %.9lf\n"
					  "d) Precio unitario:%.2f\n"
					  "La diferencia de precio es: %.2f\n",precioConTcDebitoLa, precioConTcCreditoLa, precioBitcoinLa,precioUnitarioLa,
					   precioConTcDebitoAr, precioConTcCreditoAr, precioBitcoinAr, precioUnitarioAr, diferenciaPrecios);

			printf("5) Carga forzada de datos\n");
			printf("6) Salir\n");

			validarOpcion= pedirNumero(&opcionMenu, "Ingrese una opcion: ", "La opcion ingresada no es valida",1, 6,2);



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
						, 9000 , 1500000, 2)==0){
						if(pedirPrecio(&precioLatam, "Ingrese el precio del pasaje de Latam: ", "El precio que ingreso no es un precio valido\n"
							, 9000 , 1500000, 2)==0){
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
					if(Calcular_PagoDebito(&precioConTcDebitoAr, precioAerolineas)==0 && Calcular_PagoDebito(&precioConTcDebitoLa, precioLatam)==0 &&
					Calcular_PagoCredito(&precioConTcCreditoAr,precioAerolineas)==0 && Calcular_PagoCredito(&precioConTcCreditoLa, precioLatam)==0){
						precioBitcoinAr=Calcular_PagoBitcoin(precioAerolineas);
						precioBitcoinLa=Calcular_PagoBitcoin(precioLatam);
						precioUnitarioAr=Calcular_PrecioUnitario(kilometros,precioAerolineas);
						precioUnitarioLa=Calcular_PrecioUnitario(kilometros,precioLatam);
						diferenciaPrecios=Calcular_DiferenciaDePrecio(precioAerolineas,precioLatam);
						printf("Se estan realizando los calculos por medio de pago");
						flagMenu=3;

					}

					break;

				}


				else{
					printf("Primero debe ingresar las opciones anteriores\n");
				}
				break;
			case 4:

				if(flagMenu==3){
					printf("Los resultados son: \n");
					flagMenu=4;
					break;
				}

				else{
					printf("Primero debe ingresar las opciones anteriores\n");
				}


				break;
			case 5:


				   kilometros= 7090;
				   precioAerolineas= 162965;
				   precioLatam= 159339;

				   Calcular_PagoDebito(&precioConTcDebitoAr, precioAerolineas);
				   Calcular_PagoDebito(&precioConTcDebitoLa, precioLatam);
				   Calcular_PagoCredito(&precioConTcCreditoAr,precioAerolineas);
				   Calcular_PagoCredito(&precioConTcCreditoLa, precioLatam);
				   precioBitcoinAr=Calcular_PagoBitcoin(precioAerolineas);
				   precioBitcoinLa=Calcular_PagoBitcoin(precioLatam);
				   precioUnitarioAr=Calcular_PrecioUnitario(kilometros,precioAerolineas);
				   precioUnitarioLa=Calcular_PrecioUnitario(kilometros,precioLatam);
				   diferenciaPrecios=Calcular_DiferenciaDePrecio(precioAerolineas,precioLatam);
				   printf("Se estan realizando los calculos por medio de pago\n");
				   flagMenu=5;


				break;
			case 6:

				 printf("Gracias por elegi Smart trips");

				 break;


		}
	  }




	}while(opcionMenu != 6);



	return EXIT_SUCCESS;
}

