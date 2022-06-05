/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"


int Passenger_setId(Passenger* this,int id){

	int retorno;
	retorno=-1;

	if(this != NULL && id>0){
		this->id=id;
		retorno=0;
	}
	return retorno;
}

int Passenger_getId(Passenger* this,int* id){

	int retorno;
	retorno=-1;

	if(this != NULL && id!= NULL){
		*id=this->id;
		retorno=0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int retorno;
	retorno=-1;

	if(this != NULL && nombre != NULL){
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre){

	int retorno;
	retorno=-1;

	if(this != NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno=0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido){

	int retorno;
	retorno=-1;

	if(this != NULL && apellido != NULL){
		strcpy(this->apellido,apellido);
		retorno=0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido){

	int retorno;
	retorno=-1;

	if(this != NULL && apellido != NULL){
		strcpy(apellido, this->apellido);
		retorno=0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno;
	retorno=-1;

	if(this != NULL && codigoVuelo != NULL){
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno=0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){

	int retorno;
	retorno=-1;

	if(this != NULL && codigoVuelo != NULL){
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno=0;
	}
	return retorno;

}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){

	int retorno;
	retorno=-1;

	if(this != NULL && tipoPasajero > 0){
		this->tipoPasajero=tipoPasajero;
		retorno=0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){

	int retorno;
	retorno=-1;

	if(this != NULL && tipoPasajero > 0){
		*tipoPasajero= this->tipoPasajero;
		retorno=0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio){

	int retorno;
	retorno=-1;

	if(this != NULL && precio > 0){
		this->tipoPasajero=precio;
		retorno=0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio){

	int retorno;
	retorno=-1;

	if(this != NULL && precio > 0){
		*precio=this->tipoPasajero;;
		retorno=0;
	}
	return retorno;
}
