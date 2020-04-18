/*
 * calcuadora.c
 *
 *  Created on: 10 abr. 2020
 *      Author: Vicente Montilla
 */
#include <stdio.h>
#include <stdlib.h>

int resta (int operador1, int operador2)
{
	int resultado;
	resultado = operador1 - operador2;

    return resultado;
}

int suma (int operador1, int operador2)
{
	int resultado;
	resultado = operador1 + operador2;

    return resultado;
}

int multiplicacion (int operador1, int operador2)
{
	int resultado;
	resultado = operador1 * operador2;

    return resultado;
}


int dividir (float* pResultado, int operador1, int operador2)
{
	float resultado;
	int retorno = -1;
	if(pResultado != NULL &&operador2 != 0)
	{
		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}

	return retorno;
}

int factorial (int operador1, long int* pResultado)
{

	int retorno = -1;
	long int factorial =1;

	if(pResultado != NULL && operador1 >= 0)
	{
		for (int i=operador1; i > 0; i--)
		{
			factorial=factorial * i;
		}
		*pResultado = factorial;
		retorno = 0;
	}

	return retorno;
}
