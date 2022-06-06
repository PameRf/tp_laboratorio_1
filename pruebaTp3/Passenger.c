/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include "Passenger.h"

Passenger* Passenger_new(){

	Passenger* espacioParaPasajero;

		espacioParaPasajero=(Passenger*) malloc(sizeof(Passenger));

		if (espacioParaPasajero != NULL){
			Passenger_setId(espacioParaPasajero, 0);
			Passenger_setNombre(espacioParaPasajero, " ");
			Passenger_setApellido(espacioParaPasajero, " ");
			Passenger_setPrecio(espacioParaPasajero, 0);
			Passenger_setCodigoVuelo(espacioParaPasajero, " ");
			Passenger_setTipoPasajero(espacioParaPasajero, 0);
			Passenger_setEstadoVuelo(espacioParaPasajero, 0);

		}
		return espacioParaPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr){

	Passenger* nuevoPasajero;
	nuevoPasajero= Passenger_new();

	if(idStr !=NULL && nombreStr !=NULL && apellidoStr !=NULL && precioStr!=NULL && tipoPasajeroStr !=NULL && codigoVueloStr !=NULL && estadoVueloStr !=NULL){
		if(nuevoPasajero!=NULL){
			Passenger_setId(nuevoPasajero,atoi(idStr));
			Passenger_setNombre(nuevoPasajero,nombreStr);
			Passenger_setApellido(nuevoPasajero,apellidoStr);
			Passenger_setPrecio(nuevoPasajero,atof(precioStr));
			Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr);
			Passenger_setTipoPasajero(nuevoPasajero, atoi(tipoPasajeroStr));
			Passenger_setEstadoVuelo(nuevoPasajero, atoi(estadoVueloStr));

		}
	}
	return nuevoPasajero;
}

void Passenger_delete(Passenger* this){

	if(this!=NULL){
			free(this);
	}
}
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

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo){

	int retorno;
	retorno=-1;

	if(this != NULL && estadoVuelo > 0){
		this->estadoVuelo=estadoVuelo;
		retorno=0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo){

	int retorno;
	retorno=-1;

	if(this != NULL && estadoVuelo != NULL){
		*estadoVuelo= this->estadoVuelo;
		retorno=0;
	}
	return retorno;
}
