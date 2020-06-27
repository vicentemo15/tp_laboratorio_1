/*
 * Employee.c
 *
 *  Created on: 18 jun. 2020
 *      Author: vicente
 */

#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"
#include <string.h>

static int isValidNombre(char* cadena,int longitud);

/** \brief Crea un nuevo empleado.

 * \ retorna Nuevo empleado.
 *
 */
Employee* employee_new(void)
{
	Employee* auxiliarE = NULL;
	auxiliarE = (Employee*) malloc(sizeof(Employee));
	return auxiliarE;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	int flagOk=0;
	Employee* punteroEmployee = NULL;
	punteroEmployee = employee_new();
	if(punteroEmployee != NULL)
	{
		if(employee_setId(punteroEmployee,atoi(idStr))==0)
		{
			if(employee_setNombre(punteroEmployee,nombreStr)==0)
			{
				if(employee_setHorasTrabajadas(punteroEmployee,atoi(horasTrabajadasStr))==0)
				{
					if(employee_setSueldo(punteroEmployee,atoi(sueldoStr))==0)
					{
						flagOk=1;
					}
				}
			}
		}
		if(flagOk==0)
		{
			printf("Error al leer:  %s\n", idStr);
			employee_delete(punteroEmployee);
			punteroEmployee=NULL;
		}
	}
	return punteroEmployee;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}


int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,NOMBRE_LEN))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,NOMBRE_LEN);
		}
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,NOMBRE_LEN);
	}
	return retorno;
}

int employee_comparadorNombre(void* a, void* b)
{
	int retorno = -1;
	Employee* aux1 = (Employee*)a;
	Employee* aux2 = (Employee*)b;

	if(a != NULL && b != NULL)
	{
	      if (strncmp(aux1->nombre,aux2->nombre,NOMBRE_LEN) > 0)
	      {
	    	  retorno = 1;
	      }
	      else
	      {
	    	  retorno = -1;
	      }
	}

	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas > 0)
	{
		retorno = 0;
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo > 0)
	{
		retorno = 0;
		this->sueldo = sueldo;
	}
	return retorno;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}

int employee_getNextId(LinkedList* pArrayListEmployee)
{
	int retorno= -1;
	Employee* pE = NULL;
	int maxId = 0;
	int i;

	for (i=0;i <ll_len(pArrayListEmployee);i++)
	{
		pE = ll_get(pArrayListEmployee, i);
		if (pE != NULL)
		{
			if (pE->id > maxId)
			{
				maxId= pE->id;
			}
		}
	}

	retorno= maxId + 1;
	return retorno;
}
int employee_CaluloSueldo(void*pElement)
{
	int retorno= -1;
	Employee* auxiliar = (Employee*) pElement;

	if(auxiliar != NULL)
	{
		if (auxiliar->horasTrabajadas >= 100)
		{

			auxiliar->sueldo = auxiliar->horasTrabajadas * 50 * 25;
		}else
		{
			auxiliar->sueldo = auxiliar->horasTrabajadas * 30 * 25;
		}
		retorno = 0;
	}
	return retorno;
}

int employee_MayorHorasTrabajo(void*pElement)
{
	int retorno= -1;
	Employee* auxiliar = (Employee*) pElement;

	if(auxiliar != NULL)
	{
		if (auxiliar->horasTrabajadas >= 100)
		{
			retorno = 0;
		}else
		{
			retorno = 1;
		}

	}
	return retorno;
}

int employee_compararSueldoMayor(void*pElement,int valor, int index)
{

	Employee* auxiliar = (Employee*) pElement;

	if(index == 0)
	{
		valor = auxiliar->sueldo;

	}
	else
	{
		if (auxiliar->sueldo > valor)
		{
			valor = auxiliar->sueldo;

		}
	}
	return valor;
}
int employee_compararSueldoMenor(void*pElement,int valor, int index)
{

	Employee* auxiliar = (Employee*) pElement;

	if(index == 0)
	{
		valor = auxiliar->sueldo;

	}
	else
	{
		if (auxiliar->sueldo < valor)
		{
			valor = auxiliar->sueldo;

		}
	}
	return valor;
}

int employee_compararSueldoPagar(void*pElement,int valor, int index)
{

	Employee* auxiliar = (Employee*) pElement;

		valor = valor + auxiliar->sueldo;


	return valor;
}


int employee_compararSueldoMayorDos(LinkedList* pArrayListEmployee)
{
	Employee* auxiliar = NULL;
	int i;
	int valor = 0;
	int index;

	if ( pArrayListEmployee != NULL )
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			auxiliar = ll_get(pArrayListEmployee,i);
			if(i == 0)
			{
				valor = auxiliar->sueldo;

			}
			else
			{
				if (auxiliar->sueldo > valor)
				{
					valor = auxiliar->sueldo;
					index = i;
				}
			}
		}
	}
	return index;
}
