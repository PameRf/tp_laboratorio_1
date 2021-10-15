/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include <string.h>
#include "ArrayEmployees.h"

int main(void) {

	int opcion;
	int respuesta;
	int flagEmpleado=0;
	Employee listaEmpleados[ELEMENTS];

	respuesta= initEmployees(listaEmpleados, ELEMENTS);

	do
		{

			printf("\n1.Cargar un Empleado\n");
		    printf("2.Modificar Empleado\n");
		    printf("3.Eliminar Empleado\n");
		    printf("4.Listar\n"
		    		" A)Los empleados ordenados alfabeticamente por Apellido y Sector\n"
		    		" B)Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
		    printf("5.Salir\n");

		opcion= getInt("Ingrese una opcion: \n", "Error ingrese una opcion valida \n",-1,5);

		switch(opcion)
					 {
						 case 1:


						 break;
						 case 2:
							 printf("%d", opcion);
						 break;
						 case 3:
							 printf("%d", opcion);
						 break;
						 case 4:
							 printf("%d", opcion);
						 break;
						 case 5:
						 break;

					 }


		 }while(opcion!= 5);

	return 0;
}
