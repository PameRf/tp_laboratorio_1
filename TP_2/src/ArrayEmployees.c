#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include <string.h>
#include "ArrayEmployees.h"

int initEmployees(Employee list[], int len)
{
	int retorno=-1;

	    for(int i=0; i<len; i++)
	    {
	       list[i].isEmpty=TRUE;
	       retorno= 0;
	    }
 return retorno;
}

