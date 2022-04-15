/*
 * Calculos.h
 *
 *  Created on: 12 abr. 2022
 *      Author: pamel
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
#include <stdio.h>
#include <stdlib.h>
#define DESCUENTO_TC 10
#define INTERES_TC 25


int Calcular_PagoDebito(long int* resultado, long int precio);
int Calcular_PagoCredito(long int* resultado, long int precio);
float Calcular_PagoBitcoin(long int precio);
float Calcular_PrecioUnitario(int kilometros,long int precio);
float Calcular_DiferenciaDePrecio(long int precioUno,long int precioDos);
#endif /* CALCULOS_H_ */
