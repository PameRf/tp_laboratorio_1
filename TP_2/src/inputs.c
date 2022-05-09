/*
 * inputs.c
 *
 *  Created on: 8 may. 2022
 *      Author: pamel
 */

#include "inputs.h"

int pedirEntero(int* pNumero){

	int retorno;
	char cadenaAuxiliar[4890];
	retorno= -1;

	fflush(stdin);
	scanf("%s", cadenaAuxiliar);

	if(esNumerica(cadenaAuxiliar)==1){
		*pNumero= atoi(cadenaAuxiliar);
		retorno= 0;

	}
	//printf("%d retorno en pedir entero  \n ",retorno);
	return retorno;
}

int esNumerica(char cadena[]){

	int retorno;
	int i;
	int longitud=strlen(cadena);
	printf("%d longitud\n",longitud);
	printf("%s cadena \n",cadena);
	retorno=1;
	i=0;


	if(cadena[0]== '-'){
		i=1;
	}

	for( ; i < longitud ; i++){

		if(cadena[i]>'9'|| cadena[i]< '0'){

				retorno=0;
				break;
			}
		}
	//printf("%d retorno en es numerica  \n ",retorno);
	return retorno;
}

int esFlotante(char cadena[]){

	int retorno;
	int i;
	int longitud=strlen(cadena);
	printf("%d longitud\n",longitud);
	printf("%s cadena \n",cadena);
	retorno=1;
	i=0;

	if(cadena[0] == '.'){
		retorno=0;
	}

	for( ; i < longitud ; i++){

		if((cadena[i]>'0'|| cadena[i]< '9') && cadena[i] == '.'){

				retorno=1;
				break;
			}
		}
	return retorno;
}


int pedirFlotante(float* pNumero){

	int retorno;
	char cadenaAuxiliar[4890];
	retorno= -1;

	fflush(stdin);
	scanf("%s", cadenaAuxiliar);

	if(esFlotante(cadenaAuxiliar)==1){
		*pNumero= atof(cadenaAuxiliar);
		retorno= 0;

	}
  return retorno;
}

int pedirNumero(int* pNumero, char mensaje[], char error[], int minimo, int maximo, int reintentos){

	int retorno;
	int auxiliar;
	retorno=-1;

	if(pNumero != NULL && mensaje != NULL && error != NULL && minimo <= maximo && reintentos>= 0 ){

		do{
			printf("%s", mensaje);
			reintentos--;

			if(pedirEntero(&auxiliar)==0 && auxiliar >= minimo && auxiliar <= maximo){
				*pNumero= auxiliar;
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

int pedirPrecio(float* pPrecio, char mensaje[], char error[], float minimo, float maximo, int reintentos){

	int retorno;
	float auxiliar;
	retorno=-1;

	if(pPrecio != NULL && mensaje != NULL && error != NULL && minimo <= maximo && reintentos>= 0 ){

		do{
			printf("%s", mensaje);
			reintentos--;

			if(pedirFlotante(&auxiliar)==0 && auxiliar >= minimo && auxiliar <= maximo){
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

int sonLetras(char cadena[]){

		int retorno=1;
		int i=0;

		if(cadena[0]== ' '){
			retorno=0;
		}


		if(cadena!=NULL)
		{
			while(cadena[i] != '\n')
			{
				if(cadena[i]<' '||(cadena[i]>' ' && cadena[i]<'A') || (cadena[i]>'Z' && cadena[i]<'a') || cadena[i]>'z'){
					retorno=0;
					break;
					printf("Ingreso al if");
				}
				i++;
			}
		}
	return retorno;
}


int pedirCaracteres(char cadena[],char mensaje[], int len){

	int retorno;
	retorno=-1;

	if( cadena != NULL && mensaje != NULL && len>= 0 ){

		printf("%s", mensaje);
		fflush(stdin);
		if(fgets(cadena,len,stdin) && sonLetras(cadena)== 1){

				cadena[strlen(cadena)-1] = '\0';
				retorno=0;
			}
	}
  return retorno;
}
