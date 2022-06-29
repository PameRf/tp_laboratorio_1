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

int buscarUltimoId(Passenger* list, int len){
	int retorno=-1;

	int idMayor=0;
	int flagId=0;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			if(list[i].isEmpty==0){
				if(flagId==0 || idMayor<list[i].id){
					idMayor=list[i].id;
					retorno=idMayor;
				}
			}
		}
	}
	return retorno;
}

int generarId(Passenger* list, int len){

	 int idPasajero=0;
	 int auxId;

	 if (list != NULL && len > 0){

		 auxId=buscarUltimoId(list, len);
		 if(auxId != -1){
			 idPasajero=auxId;
			 idPasajero++;
		 }
		 else{
			 idPasajero=1000;
			 idPasajero++;

		 }
	 }

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

Passenger cargarUnPax(int* retorno){

	Passenger unPasajero;

	int flagNombre=0;
	int flagApellido=0;
	int flagrecio=0;
	int flagFliyCode=0;
	int flagTipo=0;
	int flagEstado=0;
	*retorno=-1;




			if(pedirCaracteres("Ingrese el nombre \n","Error dato invalido \n", unPasajero.name,51,3)== 0){

				flagNombre=1;
			}
			else{

				printf("Error no se pudo cargar nombre invalido\n");
			}
			if(flagNombre==1 && pedirCaracteres("Ingrese el apellido \n","Error dato invalido \n",unPasajero.lastName,51,3)== 0 ){

				flagApellido=1;
			}
			else{
				printf("Error no se pudo cargar apellido invalido\n");
			}
			if(flagApellido==1 && pedirPrecio(&unPasajero.price,"Ingrese el precio del vuelo: \n", "Error! el precio es incorrecto: \n", 9000, 4700000, 3)== 0){

				flagrecio=1;
			}
			else{
				printf("Error no se pudo cargar Precio\n");
			}
			if(flagrecio==1 &&pedirFlyCode(unPasajero.flycode, "Ingrese su codigo de vuelo: \n", 10)== 0){

				flagFliyCode=1;
			}
			else{
				printf("Error no se pudo cargar Fly code\n");
			}
			if( flagFliyCode==1 &&pedirNumero(&unPasajero.typePassenger, "Ingrese tipo de pasajero 1 (Economy), 2 (Premium Economy) y 3 (Business) \n", "Error! Tipo de pasajero invalido", 1, 3,3)== 0){

				flagTipo=1;
			}
			else{
				printf("Error no se pudo cargar tipo de pax\n");
			}
			if(flagTipo==1 && pedirNumero(&unPasajero.statusFlight, "Ingrese estado de vuelo 4 (Activo), 5 (Reprogramado) y 6 (Cancelado) \n", "Error! Estado de vuelos invalido", 4, 6,3)== 0){

				flagEstado=1;
			}
			else{
				printf("Error no se pudo cargar estado de vuelo\n");
			}

			if(flagNombre==1 && flagApellido==1 && flagrecio==1 &&flagFliyCode==1 && flagTipo==1 && flagEstado==1){

				unPasajero.isEmpty= 0;
				//unPasajero.id=generarId();
				*retorno=-0;

    	    }else{
    	    	printf("Error no se pudo cargar pasajero\n");
    	    }



	//printPassenger(unPasajero);
return unPasajero;

}


int addPassenger(Passenger list[], int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFlight){

	int retorno;
	int espacioLibre;


	retorno = -1;

	if (list != NULL && name != NULL && lastName != NULL && flycode!= NULL && len > 0){


	espacioLibre= buscarEspacioLibre(list, len);


		if (espacioLibre != -1) {



			list[espacioLibre].isEmpty = 0;

			list[espacioLibre].id= id;

			strncpy(list[espacioLibre].name, name, sizeof(list[espacioLibre].name));

			strncpy(list[espacioLibre].lastName, lastName, sizeof(list[espacioLibre].lastName));

			list[espacioLibre].price= price;

			strncpy(list[espacioLibre].flycode, flycode, sizeof(list[espacioLibre].flycode));

			list[espacioLibre].typePassenger= typePassenger;

			list[espacioLibre].statusFlight= statusFlight;

			 mostrarUnPassenger(list[espacioLibre]);

			retorno = 0;
		}
	}

	return retorno;
}

int mostrarUnPassenger(Passenger unPasajero){

	char auxiliarTipo[40];
	char auxiliarStatusFly[40];

	if (unPasajero.isEmpty == 0){

		switch(unPasajero.typePassenger){

			case ECONOMY:
			strcpy(auxiliarTipo, "ECONOMY");
			break;
			case PREMIUM_ECONOMY:
			strcpy (auxiliarTipo, "PREMIUM_ECONOMY");
			break;
			case BUSINESS:
			strcpy(auxiliarTipo, "BUSINESS");
			break;
		}
		switch(unPasajero.statusFlight){

			case ACTIVO:
			strcpy(auxiliarStatusFly, "ACTIVO");
			break;
			case REPROGRAMADO:
			strcpy (auxiliarStatusFly, "REPROGRAMADO");
			break;
			case CANCELADO:
			strcpy(auxiliarStatusFly, "CANCELADO");
			break;
		}

		printf("%-4d %-10s %-15s %-19.2f %-12s %-19s %-10s \n", unPasajero.id,  unPasajero.name, unPasajero.lastName,unPasajero.price, unPasajero.flycode, auxiliarTipo, auxiliarStatusFly);

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

	int retorno;
	retorno = -1;

	if (list != NULL && len > 0 && id > 0) {

		for (int i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == 0){

			  retorno = i;
			  return retorno;
			}
		}
	}
	return retorno;
}

int modificarPasajero(Passenger* list, int len,int id){

	int retorno;
	int indice;
	int opcion;
	retorno = -1;

	if (list != NULL && len > 0 && id > 0)
	{
		indice = findPassengerById(list, len, id);

    	if (indice != -1){

    		 mostrarUnPassenger(list[indice]);

    		 mostrarSubMenu();

    		 pedirNumero(&opcion, "Ingrese la opcion que desea modificar\n", "Error! la opcion ingresada es incorrecta \n",1, 5, 3);

    		 switch(opcion){

    		 case 1:
    			 if(pedirCaracteres("Ingrese el nuevo nombre: \n", "Error dato invalido \n", list[indice].name,51,3)== 0){

    				 printf("El nuevo nombre fue cargado correctamente \n");

    			 }
    			 else{

    				 printf("Error! no se pudo cargar nombre invalido \n");
    			 }
    		 break;
    		 case 2:
    			if(pedirCaracteres("Ingrese el nuevo apellido: \n","Error dato invalido\n",list[indice].lastName,51,3)== 0){

    				printf("El nuevo apellido fue cargado correctamente \n");
				}
				else{
					printf("Error! no se pudo cargar apellido invalido\n");
				}
    		 break;
    		 case 3:
    			if(pedirPrecio(&list[indice].price,"Ingrese el nuevo precio del vuelo: \n", "Error! el precio es incorrecto: \n", 9000, 4700000, 3)== 0){

    				printf("El nuevo precio fue cargado correctamente \n");
				}
				else{
					printf("Error! no se pudo cargar Precio");
				}
    		 break;
    		 case 4:
    			if(pedirNumero(&list[indice].typePassenger, "Ingrese nuevo tipo de pasajero 1 (Economy), 2 (Premium Economy) y 3 (Business) \n", "Error! Tipo de pasajero invalido", 1, 3,3)== 0){

					printf("El nuevo tipo de pasajero fue cargado correctamente \n");
				}
				else{
					printf("Error no se pudo cargar tipo de pasajero \n");
				}
    		 break;
    		 case 5:
    			if(pedirFlyCode(list[indice].flycode, "Ingrese su codigo de vuelo: \n", 10)== 0){

    				printf("El nuevo codigo de vuelo fue cargado correctamente \n");
				}
				else{
					printf("Error no se pudo cargar el codigo de vuelo \n");
				}
    		 break;
    		 }

    		 mostrarUnPassenger(list[indice]);

			retorno = 0;
	    }
	}
   return retorno;
}

int removePassenger(Passenger* list, int len, int id){

	int retorno;
	int indice;
	retorno = -1;

	if (list != NULL && len > 0 && id > 0) {

		indice = findPassengerById(list, len, id);

		if (indice != -1) {

			mostrarUnPassenger(list[indice]);

			list[indice].isEmpty = 1;
			retorno = 0;
		}
	}
	return retorno;
}

int sortPassengers(Passenger* list, int len, int order){

	int retorno = -1;
	int i;
	Passenger paxAux;
	int ordenado;

	if (list != NULL && len > 0) {
		do {
			ordenado = 1;
			len--;
			for (i = 0; i < len; i++) {
				if (order ==1 && stricmp(list[i].lastName, list[i + 1].lastName)>0){
					paxAux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = paxAux;
					ordenado = 0;
				}
				else if( order ==0 && stricmp(list[i].lastName, list[i + 1].lastName)<0){
					paxAux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = paxAux;
					ordenado = 0;
				}
			}
		} while (ordenado == 0);
		retorno = 0;
	}
	return retorno;
}


int ordenarPassengersPorTipo(Passenger* list, int len, int order){

	int retorno;
	int i;
	Passenger paxAux;
	int ordenado;
	retorno = -1;

	if (list != NULL && len > 0) {
		do {
			ordenado = 1;
			len--;
			for (i = 0; i < len; i++) {

				if (stricmp(list[i].lastName, list[i + 1].lastName)==0 && (list[i].typePassenger < list[i + 1].typePassenger && order ==1)){

					paxAux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = paxAux;
					ordenado = 0;
				}
				else if (stricmp(list[i].lastName, list[i + 1].lastName)==0 && (list[i].typePassenger > list[i + 1].typePassenger && order ==0)){

					paxAux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = paxAux;
					ordenado = 0;
				}

			}
		} while (ordenado == 0);
		retorno = 0;
	}
	return retorno;
}

int calcularPrecioPromedio(Passenger* list, int len){

	 int retorno;
	 float promedio;
	 float acumuladorPrecio;
	 int contadorPax;
	 int paxsMayorpromedio;

	 retorno=-1;
	 acumuladorPrecio=0;
	 contadorPax=0;

	 if (list != NULL && len > 0) {

		for (int i = 0; i < len; i++) {
			if ( list[i].isEmpty == 0){

			acumuladorPrecio+= list[i].price;
			contadorPax++;

			}
	   }
		printf("El precio total de todos los pasajes es %.2f \n", acumuladorPrecio);

		if (contadorPax !=0){

			promedio =  acumuladorPrecio / contadorPax;
			printf("El promedio  de todos los pasajes es %.2f\n", promedio);
			paxsMayorpromedio= buscarPaxSuperanPromedio(list, len, promedio);
			printf("La cantidad de pasajeros con precios que superan el promedio son: %.d\n", paxsMayorpromedio);

		}

	 	retorno=0;
	 }
 return retorno;
}

int buscarPaxSuperanPromedio(Passenger* list, int len, float promedio){

	int retorno;
	int contadorPaxMayor;
	retorno=-1;
	contadorPaxMayor=0;
	if (list != NULL && len > 0) {

		for (int i = 0; i < len; i++) {
			if (list[i].isEmpty == 0 && list[i].price > promedio){

				contadorPaxMayor++;

			}
			retorno=contadorPaxMayor;
	   }
	}
 return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order){

	int retorno = -1;
		int i;
		Passenger paxAux;
		int ordenado;

		if (list != NULL && len > 0) {
			do {
				ordenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (order ==1 && stricmp(list[i].flycode, list[i + 1].flycode)>0){
						paxAux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = paxAux;
						ordenado = 0;
					}
					else if(order ==0 && stricmp(list[i].flycode, list[i].flycode) <0){
						paxAux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = paxAux;
						ordenado = 0;

					}


				}
			} while (ordenado == 0);
			retorno = 0;
		}
		return retorno;
}

int ordenarPassengersPorStatusFly(Passenger* list, int len, int order){

	int retorno = -1;
		int i;
		Passenger paxAux;
		int ordenado;

		if (list != NULL && len > 0) {
			do {
				ordenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (order ==1 && list[i].statusFlight < list[i + 1].statusFlight){

						paxAux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = paxAux;
						ordenado = 0;
					}
					else if (order ==0 && list[i].statusFlight > list[i + 1].statusFlight){

						paxAux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = paxAux;
						ordenado = 0;


					}

				}
			} while (ordenado == 0);
			retorno = 0;
		}
	return retorno;
}

int cargaForzadaDePax(Passenger* list, int len){

	int retorno;
	int id;

	if(list != NULL && len > 0){
		id=generarId(list, len);
		if(id>0){
			Passenger paxsAuxiliares[6]={{id, "Juan", "Bustamante", 12000,"ar29",1,4, 0} ,
						{id+1, "Roberto", "Gomez", 13000,"ar33",2,4, 0},
						{id+2, "Ezequiel", "Freire", 150345, "ar33",3,5, 0},
						{id+3, "Dario", "Gomez",24000, "la69",3,6, 0},
						{id+4, "Jose", "Romano",356786, "la69",2,4, 0},
						{id+5, "Laura", "Torres", 23453, "ar29",1,5, 0}};
			retorno=-1;

			for(int i=0; i< 6; i++){

					  list[i]= paxsAuxiliares[i];
						retorno=0;

				}
			}
		}

	return retorno;
}
