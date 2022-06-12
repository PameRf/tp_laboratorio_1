/*
 * inputs.c
 *
 *  Created on: 5 jun. 2022
 *      Author: pamel
 */

#include "inputs.h"

int myGets(char cadena[], int len){
	int retorno;
	char cadenaAux[5070];
	retorno=-1;

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);

		if(fgets(cadenaAux,sizeof(cadenaAux),stdin) != NULL)
		{
			if(cadenaAux[strnlen(cadenaAux,sizeof(cadenaAux))-1] == '\n'){

			 cadenaAux[strlen(cadenaAux)-1] = '\0';
			 strncpy(cadena,cadenaAux,len);
			 retorno=0;
			 }
		}
	}
	return retorno;
}



int pedirEntero(int* pNumero){

	int retorno;
	char cadenaAuxiliar[4890];
	retorno= -1;

	fflush(stdin);

	if(myGets(cadenaAuxiliar,sizeof cadenaAuxiliar)==0 && esNumerica(cadenaAuxiliar)==1){
		*pNumero= atoi(cadenaAuxiliar);
		retorno= 0;

	}
	return retorno;
}

int esNumerica(char cadena[]){

	int retorno;
	int i;
	int longitud=strlen(cadena);

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

	if(myGets(cadenaAuxiliar,sizeof(cadenaAuxiliar))==0 &&esFlotante(cadenaAuxiliar)==1){
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
					//printf("Ingreso al if");
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

void mostrarSubMenu(){

	printf("Elija la opcion que desea mofificar: \n"
			"1. Nombre \n"
			"2. Apellido \n"
			"3. Precio \n"
			"4. Tipo de pasajero\n"
			"5. Codigo de vuelo \n"
			"6. Estado de vuelo\n");

}

int pedirLetrasYnumeros(char cadena[], char mensaje[], int len){

	int retorno;

	retorno= -1;

	if(cadena != NULL && mensaje  != NULL &&  len> 0){

		printf("%s", mensaje);
		fflush(stdin);
		if(fgets(cadena,len,stdin)){

			cadena[strlen(cadena)-1] = '\0';
			retorno=0;
		}
	}
	return retorno;
}

