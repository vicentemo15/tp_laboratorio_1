/*
 ============================================================================
 Name        : TP1.c
 Author      : VICENTE
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

int main(void)
{
	int numero1;
	int numero2;
	int opciones;
	int rSuma;
	int rResta;
	int rMulti;
	float rDividir;
	long int rFactorial;
	long int rFactorial2;
	int rError;
	int rErrorDivi;

	  do
	{
		printf("\n\n INGRESE UNA OPCION\n");
		printf("1: SUMAR\n");
		printf("2: RESTAR\n");
		printf("3: MULTIPLICAR\n");
		printf("4: DIVIDIR\n");
		printf("5: FACTORIAL\n");
		printf("6: TODAS LAS OPERACIONES\n");
		printf ("7: SALIR\n");
		scanf("%d",&opciones);

		if (opciones !=7)
		  {
			printf("INGRESE 1ER NUMERO\n");
			scanf ("%d",&numero1);
			printf("INGRESE 2DO NUMERO\n");
			scanf ("%d",&numero2);
		  }

		switch (opciones)
		  {
		case 1:
			rSuma=suma(numero1,numero2);
			printf ("LA SUMA DE %d y %d\n es igual a :%d",numero1, numero2,rSuma);

			break;
		case 2 :
			rResta=resta(numero1,numero2);
			printf ("LA RESTA DE %d y %d\n es igual a :%d",numero1, numero2,rResta);
			break;
		case 3 :
			rMulti=multiplicacion(numero1,numero2);
			printf ("LA MULTIPLICACION DE %d y %d\n es igual a :%d",numero1, numero2,rMulti);
			break;
		case 4 :
			rErrorDivi = dividir(&rDividir,numero1,numero2);
			if (rErrorDivi==0)
			  {
				printf ("LA DIVISION DE %d y %d\n es igual a :%.2f",numero1, numero2,rDividir);
			  }
			else { printf("EL SEGUNDO NUMERO DEBE SER DIFERENTE DE 0");}
			break;

		case 5:

			rError = factorial(numero1,&rFactorial);
			if (rError==0)
			  {
				printf ("EL FACTORIAL DE %d ES: %ld\n",numero1,rFactorial);
			  }
			else {printf("EL NUMERO INGRESADO DEBE SER MAYOR O IGUAL 0\n");}
			rError = factorial(numero2,&rFactorial2);
			if (rError==0)
			  {
				printf ("EL FACTORIAL DE %d ES: %ld\n",numero2,rFactorial2);
			  }
			else {printf("EL NUMERO INGRESADO DEBE SER MAYOR O IGUAL 0\n");}
			break;
		case 6:
			rSuma=suma(numero1,numero2);
			rResta=resta(numero1,numero2);
			rMulti=multiplicacion(numero1,numero2);
			rErrorDivi = dividir(&rDividir,numero1,numero2);
			int rError1 = factorial(numero1,&rFactorial);
			rError = factorial(numero2,&rFactorial2);
			printf ("LA SUMA DE %d + %d = %d\n",numero1, numero2,rSuma);
			printf ("LA RESTA DE %d - %d = %d\n",numero1, numero2,rResta);
			printf ("LA MULTIPLICACION DE %d * %d = %d\n",numero1, numero2,rMulti);
			if (rErrorDivi==0)
			   {
				printf ("LA DIVISION DE %d / %d = %.2f\n",numero1, numero2,rDividir);
			   }
			else { printf("EL SEGUNDO NUMERO DEBE SER DIFERENTE DE 0\n");}
			if (rError1==0)
			   {
				printf ("EL FACTORIAL DE %d ES: %ld\n",numero1,rFactorial);
			   }
			else {printf("EL NUMERO INGRESADO DEBE SER MAYOR O IGUAL 0\n");}
			if (rError==0)
			   {
				printf ("EL FACTORIAL DE %d ES: %ld\n",numero2,rFactorial2);
			   }
			else {printf("EL NUMERO INGRESADO DEBE SER MAYOR O IGUAL 0\n");}
			break;
		    }

	 } while (opciones!=7);


	return EXIT_SUCCESS;
}
