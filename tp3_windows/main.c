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

					if(controller_loadFromText("Archivoprueba.txt",listaPasajeros)==0){
						printf("Se cargo el archivo de pasajeros\n");
					}
					else{
						printf("No se pudo cargar el archivo \n");
					}
					break;
				case 2:
					if(controller_loadFromBinary("Archivoprueba.bin",listaPasajeros)==0){
						printf("Se cargo el archivo en binario\n");
					}
					else{
						printf("No se pudo cargar el archivo en binario\n");
					}
					break;
				case 3:
					controller_addPassenger(listaPasajeros);

					printf("opcion3\n");
					break;
				case 4:
					if(controller_editPassenger(listaPasajeros)==0){
						printf("El pasajero se modifico correctamente\n");
					}
					else{
						printf("El pasajero no se modifico\n");
					}
					break;
				case 5:
					if(controller_removePassenger(listaPasajeros)==0){

						printf("El pasajero se dio de baja correctamente\n");
					}
					else{
						printf("El pasajero no se pudo dar de baja\n");
					}
					break;
				case 6:
					if(listaPasajeros != NULL){
					controller_ListPassenger(listaPasajeros);
					}
					else{
						printf("Debe cargar el archivo primero\n");
					}
					break;
				case 7:
					if(controller_sortPassenger(listaPasajeros)==0){
						printf("Pasajeros ordenados\n");
						controller_ListPassenger(listaPasajeros);
					}
					break;
				case 8:
					if(controller_saveAsText("Archivoprueba.txt",listaPasajeros)==0){
						printf("El archivo se guardo exitosamente\n");
					}
					else{
						printf("No se pudo guard\n");
					}
					break;
				case 9:
					controller_saveAsBinary("Archivoprueba.bin", listaPasajeros);
					printf("opcion9\n");
					break;

			}
    	}
    }while(option != 10);
    return 0;
}

