/*
 * inputs.h
 *
 *  Created on: 8 may. 2022
 *      Author: pamel
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"

int pedirEntero(int* pNumero);
int esNumerica(char cadena[]);
int esFlotante(char cadena[]);
int pedirFlotante(float* pNumero);
int pedirNumero(int* pNumero, char mensaje[], char error[], int minimo, int maximo, int reintentos);
int pedirPrecio(float* pPrecio, char mensaje[], char error[], float minimo, float maximo, int reintentos);
int sonLetras(char cadena[]);
int pedirCaracteres(char cadena[],char mensaje[], int len);
void mostrarSubMenu();

#endif /* INPUTS_H_ */
