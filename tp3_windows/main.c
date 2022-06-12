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
    int flagMenu=0;


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
    	printf("10. Eliminar lista\n");
    	printf("11. Salir\n");

    	validarMenu=pedirNumero(&option, "Ingrese una opcion \n","Error! opcion invalida\n", 1, 11,2);

    	if(validarMenu==0){
			switch(option)
			{
				case 1:
				    if(flagMenu==0){
						if(controller_loadFromText("data.csv",listaPasajeros)==0){
							printf("Se cargo el archivo de pasajeros\n");
							flagMenu=1;
						}
						else{
							printf("No se pudo cargar el archivo \n");
						}
				    }
				    else{
							printf("No puede cargar dos veces la lista\n");
						}
					break;
				case 2:
					if(flagMenu==3){
						if(controller_loadFromBinary("data.bin",listaPasajeros)==0){
							printf("Se cargo el archivo en binario\n");
							flagMenu=2;
						}
						else{
							printf("No se pudo cargar el archivo en binario\n");
						}
					}
				  else{
						   printf("No puede cargar dos veces la lista\n");
					  }
					break;
				case 3:
					if(controller_addPassenger(listaPasajeros)==0){
						printf("El pasajero se cargo correctamente\n");
						flagMenu=1;
					}
					else{

						printf("No se pudo cargar pasajero\n");
					}
					break;
				case 4:
					if(flagMenu ==1||flagMenu==2 ){
						if(controller_editPassenger(listaPasajeros)==0){
							printf("El pasajero se modifico correctamente\n");
							flagMenu=1;
						}
						else{
							printf("El pasajero no se modifico\n");
						}
					}
					else{
						printf("Primero debe cargar la lista o un pasajero\n");
					}
					break;
				case 5:
					if(flagMenu ==1||flagMenu==2 ){
						if(controller_removePassenger(listaPasajeros)==0){

							printf("El pasajero se dio de baja correctamente\n");
							flagMenu=1;
						}
						else{
							printf("El pasajero no se pudo dar de baja\n");
						}
					}
					else{
							printf("Primero debe cargar la lista o un pasajero\n");
						}
					break;
				case 6:
					if(flagMenu >0 ){
						if(listaPasajeros != NULL){
						controller_ListPassenger(listaPasajeros);
						}
						else{
							printf("Debe cargar el archivo primero\n");
							flagMenu=1;
						}
					}
					else{
							printf("Primero debe cargar la lista o un pasajero\n");
						}
					break;
				case 7:
					if(flagMenu ==1||flagMenu==2 ){
						if(controller_sortPassenger(listaPasajeros)==0){
							printf("Pasajeros ordenados\n");
							controller_ListPassenger(listaPasajeros);
							flagMenu=1;
						}
						else{
							printf("No se pudo ordenar los pasajeros\n");
						}
					}
					else{
							printf("Primero debe cargar la lista o un pasajero\n");
						}
					break;
				case 8:
					if(flagMenu==1){
						if(controller_saveAsText("data.csv",listaPasajeros)==0){
							printf("El archivo se guardo exitosamente\n");
							flagMenu=1;
						}
						else{
							printf("No se pudo guard\n");
						}
					}
					else{
						printf("Primero debe cargar la lista o un pasajero\n");

					}
					break;
				case 9:
					if(flagMenu== 1){
						if(controller_saveAsBinary("data.bin", listaPasajeros)==0){
							printf("El archivo se guardo en binario correctamente\n");
							flagMenu=3;
						}
						else{
							printf("No se pudo cargar el archivo \n");
						}
					}
					break;
				case 10:
					if(flagMenu== 1){
					if(controller_removeList(listaPasajeros)==0){
						printf("Se borro la lista \n");
					}
					else{
						printf("No se pudo borrar la lista \n");
					}
					}
					else{
						printf("primero debe tener una lista\n");
					}
					break;

			}
    	}
    }while(option != 11);
    return 0;
}

