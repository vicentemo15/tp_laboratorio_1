/*
 ============================================================================
 Name        : bibliteca.c
 Author      : vicente
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



	int main(void)
	{
		setbuf(stdout,NULL);
		int edad;
		int peso;
		char letra;
		int respuesta;

		respuesta = utn_getCaracter(&letra,"Letra?\n","Error la letra debe ser desde A a J\n",'A','J',1);
		if(respuesta == 0)
		{
			printf("\nLa letra es %c\n",letra);
		}
		else
		{
			printf("\nERROR");
		}


		respuesta = utn_getNumero(&edad,"Edad?\n","Error la edad debe ser desde 0 a 199\n",0,199,2);
		if(respuesta == 0)
		{
			printf("La edad es: %d \n",edad);
		}
		else
		{
			printf("\nERROR");
		}

		respuesta = utn_getNumero(&peso,"Peso?\n","Error peso debe ser desde 0 a 500\n",0,500,3);
		if(respuesta == 0)
		{
			printf("El peso es: %d \n",peso);
		}
		else
		{
			printf("\nERROR");
		}




		return EXIT_SUCCESS;
	}

