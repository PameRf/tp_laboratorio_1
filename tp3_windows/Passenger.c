/*
 * Passenger.c
 *
 *  Created on: 9 jun. 2022
 *      Author: pamel
 */

#include "Passenger.h"

Passenger* Passenger_new() {

	Passenger *espacioParaPasajero;

	espacioParaPasajero = (Passenger*) malloc(sizeof(Passenger));

	if (espacioParaPasajero != NULL) {
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

Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *apellidoStr, char *precioStr, char *codigoVueloStr,
		char *tipoPasajeroStr, char *estadoVueloStr) {

	Passenger *nuevoPasajero;

	nuevoPasajero = Passenger_new();
	int validarretorno;

	if (idStr != NULL && nombreStr != NULL && apellidoStr != NULL
			&& precioStr != NULL && tipoPasajeroStr != NULL
			&& codigoVueloStr != NULL && estadoVueloStr != NULL) {
		if (nuevoPasajero != NULL) {
			Passenger_setId(nuevoPasajero, atoi(idStr));
			Passenger_setNombre(nuevoPasajero, nombreStr);
			Passenger_setApellido(nuevoPasajero, apellidoStr);
			Passenger_setPrecio(nuevoPasajero, atof(precioStr));
			Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr);
			validarretorno = convertirTipoAentero(tipoPasajeroStr);
			if (validarretorno == 0) {
				Passenger_setTipoPasajero(nuevoPasajero, atoi(tipoPasajeroStr));
			}
			validarretorno = convertirEstadoAentero(estadoVueloStr);
			if (validarretorno == 0) {
				Passenger_setEstadoVuelo(nuevoPasajero, atoi(estadoVueloStr));
			}
		}
	}
	return nuevoPasajero;
}

Passenger* Passenger_newParametrosUsuario(int idStr, char *nombreStr,
		char *apellidoStr, float precioStr, char *codigoVueloStr,
		int tipoPasajeroStr, int estadoVueloStr){

	Passenger *nuevoPasajero;

	nuevoPasajero = Passenger_new();

	if (idStr >0 && nombreStr != NULL && apellidoStr != NULL
			&& precioStr >0 && tipoPasajeroStr >0
			&& codigoVueloStr != NULL && estadoVueloStr >0){
		if (nuevoPasajero != NULL) {
			Passenger_setId(nuevoPasajero, idStr);
			Passenger_setNombre(nuevoPasajero, nombreStr);
			Passenger_setApellido(nuevoPasajero, apellidoStr);
			Passenger_setPrecio(nuevoPasajero, precioStr);
			Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr);
			Passenger_setTipoPasajero(nuevoPasajero, tipoPasajeroStr);
			Passenger_setEstadoVuelo(nuevoPasajero, estadoVueloStr);
			}
	}
	return nuevoPasajero;
}
void Passenger_delete(Passenger *this) {

	if (this != NULL) {
		free(this);
	}
}
int Passenger_setId(Passenger *this, int id) {

	int retorno;
	retorno = -1;

	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getId(Passenger *this, int *id) {

	int retorno;
	retorno = -1;

	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setNombre(Passenger *this, char *nombre) {
	int retorno;
	retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger *this, char *nombre) {

	int retorno;
	retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger *this, char *apellido) {

	int retorno;
	retorno = -1;

	if (this != NULL && apellido != NULL) {
		strcpy(this->apellido, apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger *this, char *apellido) {

	int retorno;
	retorno = -1;

	if (this != NULL && apellido != NULL) {
		strcpy(apellido, this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {

	int retorno;
	retorno = -1;

	if (this != NULL && codigoVuelo != NULL) {
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {

	int retorno;
	retorno = -1;

	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;

}

int Passenger_setTipoPasajero(Passenger *this, int tipoPasajero) {

	int retorno;
	retorno = -1;

	if (this != NULL && tipoPasajero > 0) {
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger *this, int *tipoPasajero) {

	int retorno;
	retorno = -1;

	if (this != NULL && tipoPasajero > 0) {
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger *this, float precio) {

	int retorno;
	retorno = -1;

	if (this != NULL && precio > 0) {
		this->tipoPasajero = precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger *this, float *precio) {

	int retorno;
	retorno = -1;

	if (this != NULL && precio > 0) {
		*precio = this->tipoPasajero;
		;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger *this, int estadoVuelo) {

	int retorno;
	retorno = -1;

	if (this != NULL && estadoVuelo > 0) {
		this->estadoVuelo = estadoVuelo;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger *this, int *estadoVuelo) {

	int retorno;
	retorno = -1;

	if (this != NULL && estadoVuelo != NULL) {
		*estadoVuelo = this->estadoVuelo;
		retorno = 0;
	}
	return retorno;
}

int convertirTipoAentero(char *tipoPasajero) {

	int retorno = -1;
	if (tipoPasajero != NULL) {

		if (strcmp(tipoPasajero, "FirstClass") == 0) {

			strcpy(tipoPasajero, FIRST_CLASS);
		}
		if (strcmp(tipoPasajero, "ExecutiveClass") == 0) {
			strcpy(tipoPasajero, EXECUTIVE_CLASS);
		}
		if (strcmp(tipoPasajero, "EconomyClass") == 0) {
			strcpy(tipoPasajero, ECONOMY_CLASS);
		}
		retorno = 0;
	}
	return retorno;
}
int convertirEstadoAentero(char *estadoVuelo) {

	int retorno = -1;
	if (estadoVuelo != NULL) {

		if (strcmp(estadoVuelo, "Aterrizado") == 0) {
			strcpy(estadoVuelo, ATERRIZADO);
			retorno = 0;
		}
		if (strcmp(estadoVuelo, "En Horario") == 0) {
			strcpy(estadoVuelo, EN_HORARIO);
			retorno = 0;
		}
		if (strcmp(estadoVuelo, "En Vuelo") == 0) {
			strcpy(estadoVuelo, EN_VUELO);
			retorno = 0;
		}
	}
	return retorno;
}

int generarId(){

	static int idPasajero = 1000;

	idPasajero++;

	return idPasajero;

}

Passenger* cargarUnPax(){

	Passenger* unPasajero;
	int id;
	char nombre[200];
	char apellido[200];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	int estadoVuelo;

	int flagCarga;
	flagCarga=0;
	unPasajero=NULL;

	  id=generarId();

		if(pedirCaracteres(nombre,"Ingrese el nombre: \n",200)== 0){

			flagCarga=1;
		}
		else{

			printf("Error no se pudo cargar nombre invalido");
		}
		if(pedirCaracteres(apellido,"Ingrese el apellido: \n",200)== 0 && flagCarga==1){

			flagCarga=2;
		}
		else{
			printf("Error no se pudo cargar apellido invalido");
		}
		if(pedirPrecio(&precio,"Ingrese el precio del vuelo: \n", "Error! el precio es incorrecto: \n", 9000, 4700000, 2)== 0 && flagCarga==2){

			flagCarga=3;
		}
		else{
			printf("Error no se pudo cargar Precio");
		}
		if(pedirLetrasYnumeros(codigoVuelo, "Ingrese su codigo de vuelo: \n", 50)== 0  && flagCarga==3){

			flagCarga=4;
		}
		else{
			printf("Error no se pudo cargar Fly code");
		}
		if(pedirNumero(&tipoPasajero, "Ingrese tipo de pasajero 1 (FirstClass), 2 (ExecutiveClass) y 3 (EconomyClass) \n", "Error! Tipo de pasajero invalido", 1, 3,2)== 0 && flagCarga==4){

			flagCarga=5;
		}
		else{
			printf("Error no se pudo cargar tipo de pax");
		}
		if(pedirNumero(&estadoVuelo, "Ingrese estado de vuelo 4 (Aterrizado), 5 (En Horario) y 6 (En Vuelo) \n", "Error! Estado de vuelos invalido", 4, 6,2)== 0 && flagCarga==5){

			flagCarga=6;
		}
		else{
			printf("Error no se pudo cargar estado de vuelo");
		}

		if(flagCarga== 6){


			unPasajero=Passenger_newParametrosUsuario(id,nombre,
				apellido, precio, codigoVuelo,tipoPasajero,estadoVuelo);
      }


return unPasajero;

}

int modificarPasajero(Passenger* pPasajero){

	int retorno=-1;
	char nombre[200];
	char apellido[200];
	float precio;
	char codigoVuelo[50];
	int tipoPasajero;
	int estadoVuelo;
	int opcion;


	if (pPasajero != NULL){


	 mostrarSubMenu();

	 pedirNumero(&opcion, "Ingrese la opcion que desea modificar\n", "Error! la opcion ingresada es incorrecta \n",1, 6, 2);

		 switch(opcion){

		 case 1:
			 if(pedirCaracteres(nombre,"Ingrese el nuevo nombre: \n",200)== 0){

				 Passenger_setNombre(pPasajero,nombre);
				 retorno=1;

			 }
			 else{

				 printf("Error! no se pudo cargar nombre invalido \n");
			 }
		 break;
		 case 2:
			if(pedirCaracteres(apellido,"Ingrese el nuevo apellido: \n",200)== 0){

				Passenger_setApellido(pPasajero, apellido);
				retorno=2;
			}
			else{
				printf("Error! no se pudo cargar apellido invalido");
			}
		 break;
		 case 3:
			if(pedirPrecio(&precio,"Ingrese el nuevo precio del vuelo: \n", "Error! el precio es incorrecto: \n", 9000, 4700000, 2)== 0){

				Passenger_setPrecio(pPasajero,precio);
				retorno=3;
			}
			else{
				printf("Error! no se pudo cargar Precio");
			}
		 break;
		 case 4:
			if(pedirNumero(&tipoPasajero, "Ingrese nuevo tipo de pasajero 1 (FirstClass), 2 (ExecutiveClass) y 3 (EconomyClass) \n", "Error! Tipo de pasajero invalido", 1, 3,2)== 0){

				Passenger_setTipoPasajero(pPasajero,tipoPasajero);
				retorno=4;
			}
			else{
				printf("Error no se pudo cargar tipo de pasajero");
			}
		 break;
		 case 5:
			if(pedirLetrasYnumeros(codigoVuelo, "Ingrese su codigo de vuelo: \n", 10)== 0){

				Passenger_setCodigoVuelo(pPasajero,codigoVuelo);
				retorno=5;
			}
			else{
				printf("Error no se pudo cargar el codigo de vuelo");
			}
		 break;
		 case 6:
			if(pedirNumero(&estadoVuelo, "Ingrese Ingrese estado de vuelo 4 (Aterrizado), 5 (En Horario) y 6 (En Vuelo) \n","Error estado invalido",4,6,2)== 0){

				Passenger_setEstadoVuelo(pPasajero,estadoVuelo);
				retorno=6;
			}
			else{
				printf("Error no se pudo cargar el codigo de vuelo");
			}
		 break;
		 }
	}
 return retorno;
}





int findPassengerById(LinkedList* pArrayListPassenger,int id){

	int retorno=-1;
	int size;
	Passenger* auxPasajero;
	int idAux;


	if (pArrayListPassenger != NULL && id > 0){

		size=ll_len(pArrayListPassenger);

		for (int i = 0; i < size; i++){

			auxPasajero= (Passenger*)ll_get(pArrayListPassenger, i);

			if (Passenger_getId(auxPasajero,&idAux)== id){

			  retorno = i;

			}
		}
	}
	return retorno;
}
