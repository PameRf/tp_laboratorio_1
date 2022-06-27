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


/// @brief La funcion calcula el precio resultado del 10% de decuento por pago con debito. Utilizo regla de tres simple,
/// luego al precio le resto el descuento obtenido.
///
/// @param resultado se pasa la direccion de memoria donde va a escribir el precio con descuento obtenido.
/// @param precio recibe el precio a calcular (pasaje por valor).
/// @return retorna 0 si la funcion finaliza con exito y -1 si no se pudo obtener el resultado.
int Calcular_PagoDebito(float* resultado, int precio);
/// @brief  La funcion calcula el precio resultado del 25% de decuento por pago con credito. Utilizo regla de tres simple,
/// luego al precio le sumo el interes obtenido.
///
/// @param resultado se pasa la direccion de memoria donde va a escribir el precio con el interes obtenido.
/// @param precio recibe el precio a calcular (pasaje por valor).
/// @return retorna 0 si la funcion finaliza con exito y -1 si no se pudo obtener el resultado.
int Calcular_PagoCredito(float* resultado, int precio);
/// @brief La funcion calcula el precio resultado  dividiendo el precio con BITCOIN o por kilometros
/// @param division
/// @param precio
/// @return el resultado obtenido.
float Calcular_PrecioBitcoinOunitario(int precio,int division);
/// @brief  La funcion recibe los dos precios ingresados, compara cual es el precio mayor entre ambos, al precio mayor resto el menor
/// y brindo el resultado obtenido si ambos precios son iguales retorna 0 diferencia
///
/// @param precioUno recibe el primer precio a calcular (pasaje por valor).
/// @param precioDos recibe el segundo a calcular (pasaje por valor).
/// @return la diferencia obtenida o 0 si ambos precios son iguales.
float Calcular_DiferenciaDePrecio( int precioUno, int precioDos);
#endif /* CALCULOS_H_ */
