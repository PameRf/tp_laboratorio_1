/*
 ============================================================================
 Name        : TP_1.c
 Author      : Freire Pamela Romina
Enunciado: Hacer una calculadora.
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"
#include "validacion.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcionSeleccionada;
	float operandoA;
	float operandoB;
	int flag=0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoFactorial;
	int flagOperandoA=0;
	int flagOperandoB=0;
	int flagOpcion=0;
	int respuestaDeopcion;


	do
	{
		if( flag == 0 || respuestaDeopcion == 0 ){
			printf("1. Ingrese primer operando A= x \n");
			printf("2. Ingrese segundo operando B= y \n");
			printf("3. Calcular todas las operaciones\n"
					"    a) Calcular la suma (A+B) \n"
					"    b) Calcular la resta (A-B) \n"
					"    c) Calcular la division (A/B)\n"
					"    d) Calcular la multiplicacion (A*B)\n"
					"    e) Calcular el factorial (A!)\n");
			printf("4. Informar resultados\n"
					);
			printf("5. Salir\n");

			printf("Ingrese una opcion: ");
			scanf("%d", &opcionSeleccionada);


			flag=1;
		}
		else if( flag == 1 || respuestaDeopcion == 0){
			printf("1. Ingrese primer operando A=  %.2f \n", operandoA);
			printf("2. Ingrese segundo operando B= x \n");
			printf("3. Calcular todas las operaciones\n"
					"    a) Calcular la suma (A+B) \n"
					"    b) Calcular la resta (A-B) \n"
					"    c) Calcular la division (A/B)\n"
					"    d) Calcular la multiplicacion (A*B)\n"
					"    e) Calcular el factorial (A!)\n");
			printf("4. Informar resultados\n"
					);
			printf("5. Salir\n");

			printf("Ingrese una opcion: ");
			scanf("%d", &opcionSeleccionada);
			flag=2;
		}
		else {
			printf("1. Ingrese primer operando A=  %.2f \n", operandoA);
			printf("2. Ingrese segundo operando B= %.2f \n", operandoB);
			printf("3. Calcular todas las operaciones\n"
					"    a) Calcular la suma (A+B) \n"
					"    b) Calcular la resta (A-B) \n"
					"    c) Calcular la division (A/B)\n"
					"    d) Calcular la multiplicacion (A*B)\n"
					"    e) Calcular el factorial (A!)\n");
			printf("4. Informar resultados\n");
			printf("5. Salir\n");

			printf("Ingrese una opcion: ");
			scanf("%d", &opcionSeleccionada);
		}

		flagOpcion= validarOpcion(opcionSeleccionada, flagOperandoA, flagOperandoB, flagOpcion);

		respuestaDeopcion=ErrorDeOpcion(opcionSeleccionada);

		if(respuestaDeopcion == 0){
			printf("Debe ingresar una opcion valida\n");
		}

		switch(opcionSeleccionada)
		{
			case 1:
				printf("Ingrese primer operando A: ");
				scanf("%f",&operandoA);
				flagOperandoA=1;
				break;
			case 2:
				printf("Ingrese segundo operando B: ");
				scanf("%f",&operandoB);
				flagOperandoB=1;
				break;
			case 3:
				if(flagOpcion == 3){
					resultadoSuma= SumarOperandos(operandoA, operandoB);
					resultadoResta= RestarOperandos(operandoA, operandoB);
					resultadoDivision= DividirOperandos(operandoA, operandoB);
					resultadoMultiplicacion= MultiplicarOperandos(operandoA, operandoB);
					resultadoFactorial= FactoriarOperando(operandoA);
					printf("Se estan calculando las operaciones. Ingrese la opcion 4 para mostras los resultados\n");
				}
				else{
					printf("Para realizar la operacion debe Ingresar el operando que falta\n");
				}

				break;
			case 4:
				if(flagOpcion == 4){
					printf("El resultado de la suma es %.2f: \n",resultadoSuma);
					printf("El resultado de la resta es %.2f: \n",resultadoResta);
					printf("El resultado de la division es %.2f: \n",resultadoDivision);
					printf("El resultado de la multiplicacion es %.2f: \n",resultadoMultiplicacion);
					if(resultadoFactorial > 0){
						printf("El resultado del factorial del operando A es %.2f: \n",resultadoFactorial);
					}
					else{
						printf("No se puede sacar el factorial de un negativo\n");
					}
				}
				else{
					printf("Debe ingresar las opciones anteriores antes de mostrar resultados \n");
				}
				break;
			case 5:
				printf("Gracias por usar la calculadora\n");
				break;
		}
	}while(opcionSeleccionada!= 5);

	return 0;
}
