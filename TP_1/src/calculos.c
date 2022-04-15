/*
 * Calculos.c
 *
 *  Created on: 12 abr. 2022
 *      Author: pamel
 */

#include "calculos.h"

int Calcular_PagoDebito(long int* resultado,int kilometros, long int precio){

 int retorno;
 double descuento;
 long int auxiliar;
 retorno=-1;

 if(resultado!= NULL && kilometros> 0 && precio>0){

	 descuento= (precio*DESCUENTO_TC)/100;
	 auxiliar= precio - descuento;
	 *resultado=auxiliar;
	 retorno=0;
 }

 return retorno;

}
