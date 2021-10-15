#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include <string.h>

int getInt(char mensaje[], char mensajeError[], int min, int max)
{
	 	 char bufferString[4589];
	 	 int numero;
	 	 int validacion;
	    printf("%s",mensaje);

	    validacion=isNumber(bufferString,sizeof bufferString);
	    numero=atoi(bufferString);

	    while(validacion== 0 || numero < min || numero > max)
	    {
	    printf("%s",mensajeError);

	    validacion=isNumber(bufferString,sizeof bufferString);

	    numero=atoi(bufferString);
	    }

	    numero=atoi(bufferString);

	return numero;
}

int isNumber(char cadena[], int tam)
{
	int retorno= 1;
	 fflush(stdin);
	 gets(cadena);
	int i=0;

	  if(i==0 && (cadena[i]=='-'||cadena[i]=='+'))
	    {
	        i=1;
	    }
	    for(; i<tam; i++)
	    {
	        if(cadena[i]> '9' && cadena[i]< '0')
	        {
	        	retorno=0;
	            printf("Error solo igrese numeros\n");

	        }

	        retorno=1;
	    }
 return retorno;
}





