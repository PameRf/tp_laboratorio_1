/*
 ============================================================================
 Name        : TP_1.c
 Author      : Freire Pamela Romina

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

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




	do
	{
		if(flag==0){
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
		else if(flag==1){

		printf("1. Ingrese primer operando A=  %f \n", operandoA);
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

		printf("1. Ingrese primer operando A=  %f \n", operandoA);
		printf("2. Ingrese segundo operando B= %f \n", operandoB);
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



		switch(opcionSeleccionada)
		{
			case 1:
				printf("Ingrese primer operando A: ");
				scanf("%f",&operandoA);
			break;
			case 2:
				printf("Ingrese segundo operando B: ");
				scanf("%f",&operandoB);
			break;
			case 3:
				 resultadoSuma= SumarOperandos(operandoA, operandoB);
				 resultadoResta= RestarOperandos(operandoA, operandoB);
				 resultadoDivision= DividirOperandos(operandoA, operandoB);
				 resultadoMultiplicacion= MultiplicarOperandos(operandoA, operandoB);

			break;
			case 4:
				printf("El resultada de la suma es %f: \n",resultadoSuma);
				printf("El resultada de la resta es %f: \n",resultadoResta);
				printf("El resultada de la division es %f: \n",resultadoDivision);
				printf("El resultada de la division es %f: \n",resultadoMultiplicacion);
			break;
			case 5:
				printf("Gracias por usar la calculadora\n");
			break;
		}

	}while(opcionSeleccionada!= 5);




	return 0;
}
