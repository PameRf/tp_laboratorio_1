/*
 * validacion.h
 *
 *
 */

#ifndef VALIDACION_H_
#define VALIDACION_H_

/// @fn int validarOpcion(int, int, int, int)
/// @brief valida si se ingreso en cada opcion del menu y coloca una bandera, para validar en el main
///  de que el usuario no pueda ingresar en la opcion 3 si primero no ingreso los operandos A y B,
/// y que no pueda ingresar la opcion cuatro si no ingreso todas las opciones anteriores previamente.
///
/// @param opcion  es la opcion del menu ingresada
/// @param flagnumero1 bandera del operando A
/// @param flagnumero2 bandera del operando B
/// @param flagOpcion bandera de opcion ingresada
/// @return retorna el valor de la bandera de opcion ingresada.
int validarOpcion(int opcion, int flagnumero1, int flagnumero2, int flagOpcion);


#endif /* VALIDACION_H_ */
