/*
 * validacion.c
 *
 *
 */
#include "validacion.h"
#include <stdio.h>
#include <stdlib.h>

int validarOpcion(int opcion, int flagnumero1, int flagnumero2, int flagOpcion){

	  if (opcion==1)
	    {
		  flagOpcion=1;
	    }
	    else if(opcion==2)
	    {
	    	flagOpcion=2;
	    }
	    else if(flagnumero1==1 && flagnumero2==1 &&opcion==3)
	    {
	    	flagOpcion=3;
	    }
	    else if(flagnumero1==1 &&flagnumero2==1 && flagOpcion==3 && opcion==4)
	    {
	    	flagOpcion=4;
	    }

	    return flagOpcion;

	}

int ErrorDeOpcion(int opcion){

	int retorno= -1;
	if(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5){

		retorno=0;
	}

	return retorno;
}
