/*
 * calculadora.h
 *
 *
 *
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/// @fn float SumarOperandos(float, float)
/// @brief Recibe y suma los operandos A y B
///
/// @param numero1 es el operando A (ingresado en la opcion 1)
/// @param numero2 es el operando B (ingresado en la opcion 2)
/// @return retorna el resultado de la suma.
float SumarOperandos(float numero1, float numero2);

/// @fn float RestarOperandos(float, float)
/// @brief Recibe y resta los operandos A y B
///
/// @param numero1  es el operando A (ingresado en la opcion 1)
/// @param numero2  es el operando B (ingresado en la opcion 2)
/// @return retorna el resultado de la resta.
float RestarOperandos(float numero1, float numero2);

/// @fn float DividirOperandos(float, float)
/// @brief Recibe y divide los operandos A y B
/// valida si alguno de los operandos es 0, un mensaje de que no es posible dividir
/// @param numero1  es el operando A (ingresado en la opcion 1)
/// @param numero2  es el operando B (ingresado en la opcion 2)
/// @return retorna el resultado de la division, o el mensaje que no es posible dividir por 0.
float DividirOperandos(float numero1, float numero2);

/// @fn float MultiplicarOperandos(float, float)
/// @brief  Recibe y multiplica los operandos A y B
///
/// @param numero1  es el operando A (ingresado en la opcion 1)
/// @param numero2  es el operando B (ingresado en la opcion 2)
/// @return retorna el resultado de la multiplicacion.
float MultiplicarOperandos(float numero1, float numero2);

/// @fn float FactoriarOperando(float)
/// @brief recibe el operando A y calcula su factorial
///
/// @param numero1  es el operando A (ingresado en la opcion 1)
/// @return retorna el resultado factorial del operando A
float FactoriarOperando (float numero1);

#endif /* CALCULADORA_H_ */
