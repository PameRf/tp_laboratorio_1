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
		if(pedirNumero(&unPasajero.statusFlight, "Ingrese estado de vuelo 4 (Activo), 5 (Reprogramado) y 6 (Cancelado) \n", "Error! Estado de vuelos invalido", 4, 6,2)== 0 && flagCarga==5){

			flagCarga=6;
		}
		else{
			printf("Error no se pudo cargar estado de vuelo");
		}

		if(flagCarga== 6){

			unPasajero.isEmpty= 0;
			//printf("sepudo cargar valor is empty en aux %d",unPasajero.isEmpty);
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
	//printf("espacio libre %d \n", espacioLibre);

		if (espacioLibre != -1) {

		//	printf("espacio libre %d", espacioLibre);


			list[espacioLibre].isEmpty = 0;

			list[espacioLibre].id= id;

			strncpy(list[espacioLibre].name, name, sizeof(list[espacioLibre].name));

			strncpy(list[espacioLibre].lastName, lastName, sizeof(list[espacioLibre].lastName));

			list[espacioLibre].price= price;

			strncpy(list[espacioLibre].flycode, flycode, sizeof(list[espacioLibre].flycode));

			list[espacioLibre].typePassenger= typePassenger;

			list[espacioLibre].statusFlight= statusFlight;


			//printf("valor de isEmpty en add en if %d \n", list[espacioLibre].isEmpty);

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
			 // printf("Valor de i en if %d", i);
			 // printf("valor de retorno en if de find paseng by id %d \n", list[i].isEmpty);
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

    		 pedirNumero(&opcion, "Ingrese la opcion que desea modificar\n", "Error! la opcion ingresada es incorrecta \n",1, 5, 2);

    		 switch(opcion){

    		 case 1:
    			 if(pedirCaracteres(list[indice].name,"Ingrese el nuevo nombre: \n",51)== 0){

    				 printf("El nuevo nombre fue cargado correctamente \n");

    			 }
    			 else{

    				 printf("Error! no se pudo cargar nombre invalido \n");
    			 }
    		 break;
    		 case 2:
    			if(pedirCaracteres(list[indice].lastName,"Ingrese el nuevo apellido: \n",51)== 0){

    				printf("El nuevo apellido fue cargado correctamente \n");
				}
				else{
					printf("Error! no se pudo cargar apellido invalido");
				}
    		 break;
    		 case 3:
    			if(pedirPrecio(&list[indice].price,"Ingrese el nuevo precio del vuelo: \n", "Error! el precio es incorrecto: \n", 9000, 4700000, 2)== 0){

    				printf("El nuevo precio fue cargado correctamente \n");
				}
				else{
					printf("Error! no se pudo cargar Precio");
				}
    		 break;
    		 case 4:
    			if(pedirNumero(&list[indice].typePassenger, "Ingrese nuevo tipo de pasajero 1 (Economy), 2 (Premium Economy) y 3 (Business) \n", "Error! Tipo de pasajero invalido", 1, 3,2)== 0){

					printf("El nuevo tipo de pasajero fue cargado correctamente");
				}
				else{
					printf("Error no se pudo cargar tipo de pasajero");
				}
    		 break;
    		 case 5:
    			if(pedirFlyCode(list[indice].flycode, "Ingrese su codigo de vuelo: \n", 10)== 0){

    				printf("El nuevo codigo de vuelo fue cargado correctamente");
				}
				else{
					printf("Error no se pudo cargar el codigo de vuelo");
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
				if (stricmp(list[i].lastName, list[i + 1].lastName)  < order){
					paxAux = list[i];
					list[i] = list[i + 1];
					list[i + 1] = paxAux;
					ordenado = 0;
				}
				else if((list[i].lastName == list[i].lastName)){

					//printf("entra al if de apellidos iguales");
					ordenarPassengersPorTipo( list,  len);
					ordenado = 0;
				}
			}
		} while (ordenado == 0);
		retorno = 0;
	}
	return retorno;
}


int ordenarPassengersPorTipo(Passenger* list, int len){

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
				if (list[i].typePassenger < list[i + 1].typePassenger){

					//printf("entra al if de apellidos iguales");
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
					if (stricmp(list[i].flycode, list[i + 1].flycode)  < order){
						paxAux = list[i];
						list[i] = list[i + 1];
						list[i + 1] = paxAux;
						ordenado = 0;
					}
					else if(list[i].flycode == list[i].flycode){

						ordenarPassengersPorStatusFly(list,  len);
						ordenado = 0;
					}

				}
			} while (ordenado == 0);
			retorno = 0;
		}
		return retorno;
}

int ordenarPassengersPorStatusFly(Passenger* list, int len){

	int retorno = -1;
		int i;
		Passenger paxAux;
		int ordenado;

		if (list != NULL && len > 0) {
			do {
				ordenado = 1;
				len--;
				for (i = 0; i < len; i++) {
					if (list[i].statusFlight < list[i + 1].statusFlight){

						//printf("entra al if de apellidos iguales");
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

int cargaForzadaDePax(Passenger* list){

	int retorno;

	Passenger paxsAuxiliares[6]={{1001, "Juan", "Bustamante", 12000,"ar29",1,4, 0} ,
	            {1002, "Roberto", "Gomez", 13000,"ars33",2,4, 0},
				{1003, "Ezequiel", "Freire", 150345, "ar45",3,5, 0},
	            {1004, "Dario", "Gomez",24000, "la23",3,6, 0},
	            {1005, "Jose", "Romano",356786, "la69",2,4, 0},
	            {1006, "Laura", "Torres", 23453, "ar29",1,5, 0}};
	retorno=-1;

	for(int i=0; i< 6; i++){

		list[i]= paxsAuxiliares[i];
		retorno=0;
	}
	return retorno;
}
