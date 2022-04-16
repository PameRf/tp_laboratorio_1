/*
 * cargas.h
 *
 *  Created on: 15 abr. 2022
 *      Author: pamel
 */

#ifndef CARGAS_H_
#define CARGAS_H_
#include <stdio.h>
#include <stdlib.h>
/// @brief La funcion pide un numero al usuario de un rango minimo y maximo,
/// valida el rango y muestra un mensaje de error si el numero ingresado se
/// encuentra fuera del mismo, y vuelve a solicitarlo. Se utiliza en la opcion del menu, los kilometros y los precios.
///
///@param int* se pasa a que direccion de memoria debe escribir el valor del numero ingresado si finaliza con exito.
/// @param mensaje Pide el numero al usuario, se carga en la llamada.
/// @param error Muestra el mensaje de numero incorrecto, se carga en la llamada.
/// @param minimo numero minimo que puede ingresar.
/// @param maximo numero maximo que puede ingresar.
/// @param reintentos se brinda la cantidad de reintentos que puede hacer la carga y se van descontando.
/// @return retorna 0 si la funcion finaliza con exito y -1 si no se pudo obtener el numero.
int pedirNumero(int* , char mensaje[], char error[], int minimo, int maximo, int reintentos);


#endif /* CARGAS_H_ */
