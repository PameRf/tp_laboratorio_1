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
		}
	}
	fclose(archivo);

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
	FILE* archivo;

	if(pArrayListPassenger!=NULL && path != NULL ){

		archivo=fopen(path,"r");

		if(archivo!=NULL){

			parser_PassengerFromBinary(archivo, pArrayListPassenger);
			retorno=0;
		}
	}
	fclose(archivo);

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

    	nuevoPasajero=cargarUnPax();

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

					if((validar=modificarPasajero(auxPax))== 0){
						printf("El pasajero se pudo modificar");
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
    return 1;
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
	int id;
	char nombre[200];
	char apellido[200];
	float precio;
	char codigoVuelo[200];
	int tipoPasajero;
	int estadoVuelo;
	char auxTipo[200];
	char auxEstado[200];


	if(pArrayListPassenger!=NULL){
		size=ll_len(pArrayListPassenger);

		for(int i=0;i<size;i++){
			auxPax=(Passenger*)ll_get(pArrayListPassenger, i);

			Passenger_getId(auxPax, &id);
			Passenger_getNombre(auxPax, nombre);
			Passenger_getApellido(auxPax, apellido);
			Passenger_getPrecio(auxPax, &precio);
			Passenger_getCodigoVuelo(auxPax, codigoVuelo);
			Passenger_getTipoPasajero(auxPax,&tipoPasajero);
			Passenger_getEstadoVuelo(auxPax, &estadoVuelo);

			switch(tipoPasajero){
			case 1:
				strcpy(auxTipo, "FirstClass");
				break;
			case 2:
				strcpy(auxTipo, "ExecutiveClass");
				break;
			case 3:
				strcpy(auxTipo, "EconomyClass");
				break;

			}
			switch(estadoVuelo){
			case 4:
				strcpy(auxEstado, "Aterrizado");
				break;
			case 5:
				strcpy(auxEstado, "En Horario");
				break;
			case 6:
				strcpy(auxEstado, "En Vuelo");
				break;

			}

			printf("%-4d %-10s %-15s %-19.2f %-12s %-19s %-10s \n",id, nombre, apellido, precio, codigoVuelo, auxTipo, auxEstado);
			retorno=0;
		}
	}

	return retorno;;
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
    return 1;
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
    return 1;
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
    return 1;
}

/*int controlle_buscarUltimoID(char* path , LinkedList* pArrayListPassenger){

}*/
