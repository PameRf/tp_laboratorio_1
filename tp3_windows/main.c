#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int validarMenu;
    FILE* file;

    LinkedList* listaPasajeros = ll_newLinkedList();


    do{
    	printf(".............................MENU.............................................\n");
    	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n ");
    	printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
    	printf("3. Alta de pasajero\n");
    	printf("4. Modificar datos de pasajero\n");
    	printf("5. Baja de pasajero\n");
    	printf("6. Listar pasajeros\n");
    	printf("7. Ordenar pasajeros\n");
    	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
    	printf("10. Salir\n");

    	validarMenu=pedirNumero(&option, "Ingrese una opcion \n","Error! opcion invalida\n", 1, 10,2);

    	if(validarMenu==0){
			switch(option)
			{
				case 1:

					if(controller_loadFromText("data.csv",listaPasajeros)==0){
						printf("Se cargo la lista de pasajeros\n");
					}
					else{
						printf("No se pudo cargar la lista\n");
					}


					break;
				case 2:
					printf("Pedir\n");
					break;
				case 3:
					file=fopen("Archivoprueba.txt","w");
					if(file != NULL){
						controller_addPassenger(listaPasajeros);
					}
					fclose(file);
					printf("opcion3\n");
					break;
				case 4:
					printf("opcion4\n");
					break;
				case 5:
					printf("opcion5\n");
					break;
				case 6:
					controller_ListPassenger(listaPasajeros);
					break;
				case 7:
					printf("opcion8\n");
					break;
				case 8:
					printf("opcion8\n");
					break;
				case 9:
					printf("opcion9\n");
					break;

			}
    	}
    }while(option != 10);
    return 0;
}

