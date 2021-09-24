/*
 * calculadora.c
 *
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"


float SumarOperandos(float numero1, float numero2){

	float resultadoSuma;

	resultadoSuma= numero1 + numero2;

	return resultadoSuma;
}


float RestarOperandos(float numero1, float numero2){

	float resultadoResta;

	resultadoResta= numero1 - numero2;

	return resultadoResta;
}

float DividirOperandos(float numero1, float numero2){

	float resultadoDivision;
	if(numero1 != 0 && numero2 != 0){

	resultadoDivision= (int)numero1 / numero2;
	}
	else{
		printf("No es posible dividir por 0");
	}

	return resultadoDivision;

}

float MultiplicarOperandos(float numero1, float numero2){

	float resultadoMultiplicacion;

	resultadoMultiplicacion= numero1 * numero2;

	return  resultadoMultiplicacion;
}


float FactoriarOperando (float numero1){

	    int i;
	    int numeroFactoriado=1;

	    for (i=numero1;i >1 ; i--)
	    {
	        numeroFactoriado=numeroFactoriado*i;
	    }

	    return numeroFactoriado;
}



