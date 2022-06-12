#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "inputs.h"
#include "parser.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{

	int retorno=-1;
	FILE* archivo;

	if(pArrayListPassenger!=NULL && path != NULL ){

		archivo=fopen(path,"r");

		if(archivo!=NULL){
			parser_PassengerFromText(archivo, pArrayListPassenger);
			retorno=0;
			fclose(archivo);
		}
	}


 return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* archivoBinario;

	if(pArrayListPassenger!=NULL && path != NULL ){

		archivoBinario=fopen(path,"rb");

		if(archivoBinario!=NULL){
			printf("Entra al if de controler\n");
			retorno=parser_PassengerFromBinary(archivoBinario, pArrayListPassenger);
			fclose(archivoBinario);
		}
	}

 return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int retorno= -1;
    Passenger* nuevoPasajero;

    if(pArrayListPassenger != NULL){

    	nuevoPasajero=cargarUnPax(pArrayListPassenger);

    	if(nuevoPasajero != NULL){
    		ll_add(pArrayListPassenger, nuevoPasajero);
    		retorno=0;
    	}
    }
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int idAbuscar;
	int validar;
	int indiceEncontrado;
	Passenger* auxPax;
	auxPax=NULL;

	if(pArrayListPassenger != NULL){

		validar=pedirNumero(&idAbuscar, "Ingrese el numero de id del pasajero a modifica \n", "Error! dato invalido", 1, 1000, 2);
		if(validar==0){

			indiceEncontrado=findPassengerById(pArrayListPassenger,idAbuscar);

			if(indiceEncontrado != -1){
				auxPax=(Passenger*)ll_get(pArrayListPassenger, indiceEncontrado);

				if(auxPax != NULL){

					mostrarUnPax(auxPax);

					if((validar=modificarPasajero(auxPax)) !=-1){
						printf("El pasajero se pudo modificar\n");
						mostrarUnPax(auxPax);
						retorno=0;
					}
				}
			}
		}
	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int idBuscar;
	int indiceEncontrado;
	Passenger * auxPax;
	int validar;

	if(pArrayListPassenger !=NULL){

		validar=pedirNumero(&idBuscar, "Ingrese el ID del pasajero a eliminar \n", "Error! dato invalido",1,10000000,2);
		if(validar==0){
			indiceEncontrado= findPassengerById(pArrayListPassenger,idBuscar);
			if(indiceEncontrado != -1){
				auxPax=(Passenger*)ll_get(pArrayListPassenger, indiceEncontrado);

				if(auxPax != NULL){

					mostrarUnPax(auxPax);
					ll_remove(pArrayListPassenger,indiceEncontrado);
					Passenger_delete(auxPax);
					retorno=0;
			}
		  }
    	}
    }
	return retorno;
}

int controller_removeList(LinkedList* pArrayListPassenger){

	int retorno=-1;
	int validar;
	int opcion;
	if(pArrayListPassenger != NULL){

		validar= pedirNumero(&opcion, "Esta seguro que desea eliminar la lista: indique 1(Si) o 2(No)", "Error!opcion invalida", 1, 2, 2);
		if(validar==0 && opcion ==1){
			Passenger_BorrarLista(pArrayListPassenger);
			retorno=0;
		}
	}
	return retorno;
}
/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger){

	int retorno=-1;
	Passenger* auxPax;
	int size;


	if(pArrayListPassenger!=NULL){
		size=ll_len(pArrayListPassenger);

		for(int i=0;i<size;i++){
			auxPax=(Passenger*)ll_get(pArrayListPassenger, i);
			mostrarUnPax(auxPax);

			retorno=0;
		}
	}

	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int opcion;
	int validar;
	int orden;

	if(pArrayListPassenger != NULL){
	menuSort();
	validar= pedirNumero(&opcion,"Ingrese la opcion\n","Error opcion incorrecta \n",1,5,2);
	if(validar==0){

		pedirNumero(&orden,"Desea ordenar de manera  descendente (ingrese 0) o ascendente (ingrese 1)\n","Error orden incorrecto \n",0,1,2);

		switch(opcion)
		{
			case 1:
				ll_sort(pArrayListPassenger, Passenger_compararXNombre, orden);
				retorno=0;
				break;
			case 2:
				ll_sort(pArrayListPassenger, Passenger_compararXapellido, orden);
				retorno=0;
				break;
			case 3:
				ll_sort(pArrayListPassenger, Passenger_compararXPrecio, orden);
				retorno=0;
				break;
			case 4:
				ll_sort(pArrayListPassenger, Passenger_compararXtipo, orden);
				retorno=0;
				break;
			case 5:
				ll_sort(pArrayListPassenger, Passenger_compararXtipo, orden);
				retorno=0;
				break;
		}
	  }
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* auxPax;
	FILE* archivo;
	int size;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[7];
	int tipoPasajero;
	int estadoVuelo;

	if(path != NULL && pArrayListPassenger!= NULL){

		size=ll_len(pArrayListPassenger);

		archivo=fopen(path,"w");
		if(archivo !=NULL){

			fprintf(archivo,"id,Nombre,apellido,precio,codigo de vuelo,tipo de pasajero,estado de vuelo\n");

			for(int i=0;i<size;i++){

				auxPax=(Passenger*)ll_get(pArrayListPassenger, i);
				Passenger_getId(auxPax, &id);
				Passenger_getNombre(auxPax,nombre);
				Passenger_getApellido(auxPax, apellido);
				Passenger_getPrecio(auxPax, &precio);
				Passenger_getCodigoVuelo(auxPax, codigoVuelo);
				Passenger_getTipoPasajero(auxPax, &tipoPasajero);
				Passenger_getEstadoVuelo(auxPax,&estadoVuelo);

				 fprintf(archivo,"%d,%s,%s,%f,%s,%d,%d\n",id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
				retorno=0;

			   }
			}
		}fclose(archivo);
   return retorno;
}



/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* auxPax;
	FILE* archivo;
	int size;

	if(path != NULL && pArrayListPassenger!= NULL){

		size=ll_len(pArrayListPassenger);

		archivo=fopen(path,"wb");
		if(archivo != NULL){

			for(int i=0;i<size;i++){

			auxPax=(Passenger*)ll_get(pArrayListPassenger, i);
			fwrite(auxPax,sizeof(Passenger),1,archivo);
			retorno=0;

			}
			fclose(archivo);
		}
	}
    return retorno;
}


