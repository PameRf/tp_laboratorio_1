/*
 * Calculos.c
 *
 *  Created on: 12 abr. 2022
 *      Author: pamel
 */

#include "calculos.h"

int Calcular_PagoDebito(long int* resultado, long int precio){

 int retorno;
 double descuento;
 long int auxiliar;
 retorno=-1;

 if(resultado!= NULL && precio>0){

	 descuento= (precio*DESCUENTO_TC)/100;
	 auxiliar= precio - descuento;
	 *resultado=auxiliar;
	 retorno=0;
 }

 return retorno;

}

int Calcular_PagoCredito(long int* resultado, long int precio){

	int retorno;
	double interes;
	long int auxiliar;
	retorno=-1;

	 if(resultado!= NULL && precio>0){

		 interes= (precio*INTERES_TC)/100;
		 auxiliar= precio + interes;
		 *resultado=auxiliar;
		 retorno=0;
	 }

	 return retorno;


}

float Calcular_PagoBitcoin(long int precio){


	float auxbitcoin;

	 	 auxbitcoin= precio/4606954.55;

	return auxbitcoin;

}

float  Calcular_PrecioUnitario(int kilometros,long int precio){

	float precioUnitario;

	if(precio> 0){
		precioUnitario=precio/kilometros;
	}

	return precioUnitario;
}

float Calcular_DiferenciaDePrecio(long int precioUno,long int precioDos){

	int resultado;

	if(precioUno> precioDos){

		resultado=precioUno- precioDos;
	}
	else if(precioDos> precioUno){

		resultado= precioDos- precioUno;
	}
	else if(precioUno== precioDos){
		 resultado=0;
	}
   return resultado;

}
