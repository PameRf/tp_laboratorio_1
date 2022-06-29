/*
 * ArrayPassenger.h
 *
 *  Created on: 9 may. 2022
 *      Author: pamel
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#define ECONOMY 1
#define PREMIUM_ECONOMY 2
#define BUSINESS 3
#define ACTIVO 4
#define REPROGRAMADO 5
#define CANCELADO 6


typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} Passenger;
/// @brief la funcion inicializa la estructura de pasajeros poniendo es isEmpty en 1(indicando que esta vacio)
///
/// @param list se pasa la lista de pasajeros
/// @param len y la cantidad de los mismo
/// @return retorna -1 sino pudo inicializarse o 0 si pudo realizarse la funcion.
int initPassengers(Passenger* list, int len);
int buscarUltimoId(Passenger* list, int len);
///
/// @brief la funcion incrementa el numero de id en uno cada vez q se la llama guardando el id anterior (no se repite)
/// no recibe parametros
/// @return retorna el numero de id
int generarId(Passenger* list, int len);
/// @brief recorre la lista de pasajeros y si encuentra un espacio libre isEmpty en 1
/// ///
/// @param list  se pasa la lista de pasajeros
/// @param len  y la cantidad de los mismo
/// @return retorna -1 sino encontro espacio libre o el indice donde encontro el espacio libre
int buscarEspacioLibre(Passenger* list, int len);
/// @brief utilizo un pax auxiliar cargo todos los datos de la estructura y llamo a las diferentes fuciones para la carga del mismo
///
/// @return un pasajero
Passenger cargarUnPax(int* retorno);
/// @brief  paso los datos del pasajero auxiliar para que se cargue en una posicion libre de la lista de pax
///
/// datos de la estructura se pasan como referencia
/// @param list
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flycode
/// @param statusFlight
/// @return -1 sino pudo cargar el pasajero o 0 si lo cargo
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[], int statusFlight);
/// @brief solicito el codigo de vuelo puede ser alfanumerico
///
/// @param cadena paso cadena como referencia
/// @param mensaje igreso el mensaje para solicitar el dato
/// @param len tamanio a escribir
/// @return retorna -1 sino pudo devolver el dato o 0 si lo pudo cargar
int pedirFlyCode(char cadena[], char mensaje[], int len);
/// @brief Muestra un solo pasajero cargado
/// utilizo dos auxiliares para typePassenger y flycode para que muestre el nombre y no el numero del dato
///
/// @param unPasajero se pasa el pasajero a mostrar
/// @return 0
int mostrarUnPassenger(Passenger unPasajero);
/// @brief muestro la lista de pasajeros cargados  utilizo en for la funcion mostrar un pasajero
///
/// @param list de pasajeros
/// @param length tamanio
/// @return -1 sino lo pudo mostrar o 0 si pudo realizarlo
int printPassenger(Passenger list[], int length);
/// @brief paso el id a buscar en la lista si lo encuentra devuelve el indice donde se encuentra
///
/// @param list de pasajeros
/// @param len tamanio
/// @param id a buscar
/// @return -1 sino lo encontro o el indice si lo encontro
int findPassengerById(Passenger* list, int len,int id);
/// @brief  paso el numero de id del pasajero llamo a la fucion findPassengerById para q devuelva el indice del pax a modificar
/// si lo encuentra llamo a un submenu para  que el usuario elija que dato desea moodificar, muestra el pasajero modificado
/// @param list de pasajeros
/// @param len tamanio
/// @param id a buscar
/// @return retorna -1 sino pudo modificarlos o 0 si lo pudo hacer
int modificarPasajero(Passenger* list, int len,int id);
/// @brief  paso el numero de id del pasajero llamo a la fucion findPassengerById para q devuelva el indice del pax si lo encuentra pongo isEmpty en uno
///
/// @param list de pasajeros
/// @param len tamanio
/// @param id a buscar
/// @return retorna -1 sino pudo darlo de baja o 0 si pudo
int removePassenger(Passenger* list, int len, int id);
/// @brief ordena a los pasajeros por apellido de panera desencente si encuentra dos apellidos iguales lo ordena desecendete pero por tipo de pasajero
///
/// @param list de pasajeros
/// @param len tamanio
/// @param order 0
/// @return -1 sino lo pudo ordenar o 0 si lo pudo hacer
int sortPassengers(Passenger* list, int len, int order);
/// @brief ordena a los pasajeros por tipo de pasajero de maner desendente
///
/// @param list de pasajeros
/// @param len tamanio
/// @return devuelve 0 si se pudo ordenar o -1 sino lo pudo hacer
int ordenarPassengersPorTipo(Passenger* list, int len,int order);
/// @brief recorre la lista y si el lugar esta ocupado acumula el precio del vuelo y cuenta los pax, luego calcula el promedio dividiendo el precio acumulado con la cantidad
/// de pasajeros, llamo a fusion buscarPaxSuperanPromedio pasandole la lista tamanio y el promedio obternido// muestro por pantalla el promedio y la cantidad de
///  pasajeros con precios de vuelos que superan el precio promedio
/// @param list de pasajeros
/// @param len tamanio
/// @return -1 sino pudo calcularlo o 0 si pudo hacerlo
int calcularPrecioPromedio(Passenger* list, int len);
/// @brief recorre la lista de pax y si el precio del vuelo es mayor al promedio que se paso como referencia los cuenta
///
/// @param list de pasajeros
/// @param len tamanio
/// @param promedio
/// @return -1 sino encontro precios mayores al promedio o la cantidad de pasajeros del contador
int buscarPaxSuperanPromedio(Passenger* list, int len, float promedio);
/// @brief ordena de manera desecente los codigos de vuelo y llama a funcion ordenarPassengersPorStatusFly si dos codigos son iguales para ordenar por  estado de vuelo
///
/// @param list de pasajeros
/// @param len tamanio
/// @param order 0
/// @return -1 sino lo pudo ordenar y 0 si lo pudo hacer
int sortPassengersByCode(Passenger* list, int len, int order);
/// @brief  ordena por estado de vuelo mostrando primero los vuelos activos
///
/// @param list de pasajeros
/// @param len tamanio
/// @return -1 sino lo pudo ordenar y 0 si lo pudo hacer
int ordenarPassengersPorStatusFly(Passenger* list, int len, int order);
/// @brief en una variable de pax auciliar harcodeo datos y se los paso a la lista de pasajeros
///
/// @param list de pasajeros
/// @return -1 sino lo pudo cargar y 0 si lo pudo hacer
int cargaForzadaDePax(Passenger* list, int len);
#endif /* ARRAYPASSENGER_H_ */
