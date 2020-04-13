/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
 *      Author: sebam
 */
#include <stdio.h>
#include <stdlib.h>
int dividir (float* pResultado,int operador1, int operador2)
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
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%f",&bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
int factorial (int operador1,long int* pResultado)
{

	int retorno = -1;
	long int factorial =1;

	if(pResultado != NULL && operador1 >=0)
	{
		for (int i=operador1;i>0;i--)
		{
			factorial=factorial * i;
		}
		*pResultado = factorial;
		retorno = 0;
	}
	return retorno;}

int printArray(int* array, int limite)
{
	int retorno = -1;
	if(array !=NULL && limite >=0)
	{
		for(int  i = 0; i< limite; i++)
		{
			printf("INDICE: %d , VALOR : %d\n",i,array[i]);

		}

		printf ("\n\n");
		retorno = 0;
	}

 return retorno;
}


int descendenteArray(int* array,int limite)
{
  int retorno= -1;
  int buffer;
  int flagSwap;


  if (array!=NULL && limite>=0)
  {
	  do
	  {
		  flagSwap = 0;
		  for(int i=0;i<limite-1;i++)
		  {
			  if(array[i] < array[i+1])
			  {
				  buffer = array[i];
				  array[i]=array[i+1];
				  array[i+1] = buffer;
				  flagSwap = 1;
			  }
		  }
	  } while (flagSwap);

	  retorno=0;
  }

  return retorno;
}
