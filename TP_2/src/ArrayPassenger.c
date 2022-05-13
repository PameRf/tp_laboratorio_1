/*
 * ArrayPassenger.c
 *
 *  Created on: 9 may. 2022
 *      Author: pamel
 */
#include "ArrayPassenger.h"

int initPassengers(Passenger* list, int len){

	int retorno;
	retorno=-1;

		if (list != NULL && len > 0) {
			for (int i = 0; i < len; i++) {
				list[i].isEmpty = 1;
				retorno=0;
			}
		}
	return retorno;
}

int generarId(){

	static int idPasajero = 1000;

	idPasajero++;

	return idPasajero;

}

int buscarEspacioLibre(Passenger* list, int len){

	int retorno;
	retorno = -1;

		if(list != NULL && len > 0){
			for(int i = 0; i < len; i++){
				if(list[i].isEmpty == 1){
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}

int pedirFlyCode(char cadena[], char mensaje[], int len){

	int retorno;

	retorno= -1;

	if(cadena != NULL && mensaje  != NULL &&  len> 0){

		printf("%s", mensaje);
		fflush(stdin);
		if(fgets(cadena,len,stdin)){

			cadena[strlen(cadena)-1] = '\0';
			retorno=0;
		}
	}
	return retorno;
}

Passenger cargarUnPax(){

	Passenger unPasajero;

	/*char nombreAux[51];
	char apellidoAux[51];
	float precioAux;
	char codigoAux[10];
	int tipoAux;*/
	int flagCarga;
	flagCarga=0;


	    unPasajero.id=generarId();

		if(pedirCaracteres(unPasajero.name,"Ingrese el nombre: \n",51)== 0){

			flagCarga=1;
		}
		else{

			printf("Error no se pudo cargar nombre invalido");
		}
		if(pedirCaracteres(unPasajero.lastName,"Ingrese el apellido: \n",51)== 0 && flagCarga==1){

			flagCarga=2;
		}
		else{
			printf("Error no se pudo cargar apellido invalido");
		}
		if(pedirPrecio(&unPasajero.price,"Ingrese el precio del vuelo: \n", "Error! el precio es incorrecto: \n", 9000, 4700000, 2)== 0 && flagCarga==2){

			flagCarga=3;
		}
		else{
			printf("Error no se pudo cargar Precio");
		}
		if(pedirFlyCode(unPasajero.flycode, "Ingrese su codigo de vuelo: \n", 10)== 0  && flagCarga==3){

			flagCarga=4;
		}
		else{
			printf("Error no se pudo cargar Fly code");
		}
		if(pedirNumero(&unPasajero.typePassenger, "Ingrese tipo de pasajero 1 (Economy), 2 (Premium Economy) y 3 (Business) \n", "Error! Tipo de pasajero invalido", 1, 3,2)== 0 && flagCarga==4){

			flagCarga=5;
		}
		else{
			printf("Error no se pudo cargar tipo de pax");
		}

		if(flagCarga== 5){

			//printPassenger(unPasajero);
			printf("sepudo cargar");
      }

	//printPassenger(unPasajero);
return unPasajero;

}




int addPassenger(Passenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]){

	int retorno;
	int espacioLibre;

	printf("entro a la funcion \n");

	retorno = -1;

	if (list != NULL && name != NULL && lastName != NULL && flycode!= NULL && len > 0){

		printf("entro al primer if \n");

	espacioLibre= buscarEspacioLibre(list, len);
	printf("espacio libre %d \n", espacioLibre);

		if (espacioLibre != -1) {

			printf("espacio libre %d", espacioLibre);

			printf("entro al segundo if \n");

			list[espacioLibre].id= id;

			strncpy(list[espacioLibre].name, name, sizeof(list[espacioLibre].name));

			strncpy(list[espacioLibre].lastName, lastName, sizeof(list[espacioLibre].lastName));

			list[espacioLibre].price= price;

			strncpy(list[espacioLibre].flycode, flycode, sizeof(list[espacioLibre].flycode));

			list[espacioLibre].typePassenger= typePassenger;

			list[espacioLibre].isEmpty = 0;

			 mostrarUnPassenger(list[espacioLibre]);

			retorno = 0;
			printf("valor de retorno en if %d \n", retorno);
		}
	}
	printf("valor de retorno fuera if %d \n", retorno);
	return retorno;
}

int mostrarUnPassenger(Passenger unPasajero){


	if (unPasajero.isEmpty == 0){
		printf(" ID de pasajero %d \n", unPasajero.id);
		printf(" nombre de pasajero %s \n", unPasajero.name);
		printf(" apellido de pasajero %s \n", unPasajero.lastName);
		printf(" precio %f \n", unPasajero.price);
		printf(" codigo vuelo %s \n", unPasajero.flycode);
		printf(" tipo de pasajero %d \n", unPasajero.typePassenger);
		//todo lo que quiero mostrar
	}
return 0;
}

int printPassenger(Passenger list[], int length){

	int retorno;
	retorno=-1;

	if (list != NULL && length > 0){


		for(int i = 0; i < length; i++){

			mostrarUnPassenger(list[i]);
		}
		retorno=0;

	}

return retorno;
}

int findPassengerById(Passenger* list, int len,int id){
	int retorno = -1;
		if (list != NULL && len > 0 && id > 0) {

			for (int i = 0; i < len; i++) {
				if (list[i].id == id && list[i].isEmpty == 0) {
					retorno = i;
					break;
				}
			}
		}
	return retorno;
}