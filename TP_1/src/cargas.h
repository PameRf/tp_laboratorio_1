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

int pedirNumero(int* , char mensaje[], char error[], int minimo, int maximo, int reintentos);
int pedirPrecio(long int* pPrecio, char mensaje[], char error[], int minimo, long int maximo, int reintentos);

#endif /* CARGAS_H_ */
