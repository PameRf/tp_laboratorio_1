/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */


#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "inputs.h"
#define FIRST_CLASS "1"
#define EXECUTIVE_CLASS "2"
#define ECONOMY_CLASS "3"
#define ATERRIZADO "4"
#define EN_HORARIO "5"
#define EN_VUELO "6"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[4];
	int tipoPasajero;
	int estadoVuelo;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);
Passenger* Passenger_newParametrosUsuario(int idStr, char *nombreStr,char *apellidoStr, float precioStr, char* codigoVueloStr,int tipoPasajeroStr, int estadoVueloStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

int convertirTipoAentero(char* tipoPasajero);
int convertirEstadoAentero(char* estadoVuelo);

int generarId();
Passenger* cargarUnPax();
int findPassengerById(LinkedList* pArrayListPassenger,int id);
int modificarPasajero(Passenger* pPasajero);
void mostrarUnPax(Passenger* pPasajero);


#endif /* PASSENGER_H_ */
