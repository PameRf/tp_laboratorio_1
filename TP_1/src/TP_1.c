/*
 ============================================================================
 Name        : TP_1.c
 Author      : Pamela Romina Freire
 Division    : 1E
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"
#include "cargas.h"
#define BITCOIN 4606954.55


int main(void) {

	setbuf(stdout,NULL);

	int opcionMenu;
	int flagMenu;
	int kilometros=0;
	float precioAerolineas=0;
	float precioLatam=0;
	float precioConTcDebitoAr;
	float precioConTcDebitoLa;
	float precioConTcCreditoAr;
	float precioConTcCreditoLa;
	float precioBitcoinAr;
	float precioBitcoinLa;
	int validarOpcion;
	float precioUnitarioAr;
	float precioUnitarioLa;
	float diferenciaPrecios;
	int salir;




	flagMenu=0;

	do{

			printf("1) Ingresar Kilómetros: (km=%d)\n",kilometros);
			printf("2) Ingresar Precio de Vuelos: (Aerolíneas= %.2f, Latam=%.2f)\n"
					 "- Precio vuelo Aerolíneas: \n"
					 "- Precio vuelo Latam: \n", precioAerolineas,precioLatam);
			printf("3) Calcular todos los costos: \n"
					 "a) Tarjeta de débito (descuento 10%%)\n"
					 "b) Tarjeta de crédito (interés 25%%)\n"
					 "c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
					 "d) Mostrar precio por km (precio unitario)\n"
					 "e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
			printf("4) Informar Resultados\n");
			printf("5) Carga forzada de datos\n");
			printf("6) Salir\n");



		validarOpcion= pedirNumero(&opcionMenu, "Ingrese una opcion: ", "La opcion ingresada no es valida",1, 6,2);

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
							precioBitcoinAr=Calcular_PrecioBitcoinOunitario(precioAerolineas, BITCOIN);
							precioBitcoinLa=Calcular_PrecioBitcoinOunitario(precioLatam,BITCOIN);
							if(kilometros != 0){
							precioUnitarioAr=Calcular_PrecioBitcoinOunitario(precioAerolineas,kilometros);
							precioUnitarioLa=Calcular_PrecioBitcoinOunitario(precioLatam,kilometros);
							}
							else{
								printf("No se puede dividir por 0");
							}
							diferenciaPrecios=Calcular_DiferenciaDePrecio(precioAerolineas,precioLatam);
							printf("Los calculos se realizaron exitosamente");
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
						printf("Los resultados son:\n"
								  "Latam:\n"
								  "a) Precio con tarjeta de débito:%.2f\n"
								  "b) Precio con tarjeta de crédito:%.2f\n"
								  "c) Precio pagando con bitcoin : %.9lf\n"
								  "d) Precio unitario:%.2f\n"
								  "Aerolíneas:\n"
								  "a) Precio con tarjeta de débito:%.2f\n"
								  "b) Precio con tarjeta de crédito:%.2f\n"
								  "c) Precio pagando con bitcoin : %.9lf\n"
								  "d) Precio unitario:%.2f\n"
								  "La diferencia de precio es: %.2f\n",precioConTcDebitoLa, precioConTcCreditoLa, precioBitcoinLa,precioUnitarioLa,
								   precioConTcDebitoAr, precioConTcCreditoAr, precioBitcoinAr, precioUnitarioAr, diferenciaPrecios);
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
					   precioBitcoinAr=Calcular_PrecioBitcoinOunitario(precioAerolineas, BITCOIN);
					   precioBitcoinLa=Calcular_PrecioBitcoinOunitario(precioLatam,BITCOIN);
					   precioUnitarioAr=Calcular_PrecioBitcoinOunitario(precioAerolineas,kilometros);
					   precioUnitarioLa=Calcular_PrecioBitcoinOunitario(precioLatam,kilometros);
					   diferenciaPrecios=Calcular_DiferenciaDePrecio(precioAerolineas,precioLatam);
					   printf("Los resultados de la carga forzada son:\n"
							  "Latam:\n"
							  "a) Precio con tarjeta de débito:%.2f\n"
							  "b) Precio con tarjeta de crédito:%.2f\n"
							  "c) Precio pagando con bitcoin : %.9lf\n"
							  "d) Precio unitario:%.2f\n"
							  "Aerolíneas:\n"
							  "a) Precio con tarjeta de débito:%.2f\n"
							  "b) Precio con tarjeta de crédito:%.2f\n"
							  "c) Precio pagando con bitcoin : %.9lf\n"
							  "d) Precio unitario:%.2f\n"
							  "La diferencia de precio es: %.2f\n",precioConTcDebitoLa, precioConTcCreditoLa, precioBitcoinLa,precioUnitarioLa,
							   precioConTcDebitoAr, precioConTcCreditoAr, precioBitcoinAr, precioUnitarioAr, diferenciaPrecios);
					   flagMenu=5;
					break;
				case 6:
					 pedirNumero(&salir, "Desea salir del menu: \n 1.si \n 2. no \n", "Error opcion invalida \n", 1, 2, 2);
					 if(salir == 1){
						 printf("Gracias por elegir Smart trips");
					 }
					 break;
			}
	  }

   }while(salir != 1);



	return EXIT_SUCCESS;
}

