/*
 * cargas.c
 *
 *  Created on: 15 abr. 2022
 *      Author: pamel
 */

#include "cargas.h"


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

int pedirPrecio(float* pPrecio, char mensaje[], char error[], int minimo, int maximo, int reintentos){

	int retorno;
	float auxiliar;
	retorno=-1;

	if(pPrecio != NULL && mensaje != NULL && error != NULL && minimo <= maximo && reintentos>= 0 ){

		do{
			printf("%s", mensaje);
			scanf("%f", &auxiliar);
			reintentos--;

			if(auxiliar >= minimo && auxiliar <= maximo){
				*pPrecio= auxiliar;
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




