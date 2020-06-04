#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"



/**
 * \brief chequea que al menos exista en alta.
 * \param array: Array de employees.
 * \param limite: Limite del array de employees.
 * \return Retorna el incice de la posicion  y -1 (ERROR)
 *
 */
int chequeoAlta(Employee* array,int len)
{
	int answer = -1;
	int i;

	if(array != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty == 0)
			{
				answer = 0;
				break;
			}
		}
	}

	return answer;
}

/**
 * \brief Buscar primer posicion vacia.
 * \param array: Array de employees.
 * \param limite: Limite del array de employees.
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */

int emp_positionAvailable(Employee* array,int len)
{
	int answer = -1;
	int i;

	if(array != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].isEmpty == 1)
			{
				answer = i;
				break;
			}
		}
	}

	return answer;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra.
 * \param array Employee Array de Employee
 * \param limite int Tamaño del array
 * \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
 * \return int Return (-1) si no encuentra el valor buscado , retorna posicion donde se encuentra.
 *
 */

int buscarId(Employee* array, int len, int valorBuscado)
{
	int respuesta = -1;
	int i;

	if(array != NULL && len > 0 && valorBuscado >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}

	return respuesta;
}

/**
 * \brief Imprime un solo empleado.
 * \param array: Array de employees.
 * \param limite: Limite del array de employees.
 * \return Retorna 0 (exito) y -1 (ERROR)
 *
 */

int printData(Employee* pElemento)
{
	int retorno=-1;

	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - %s - %s - %.2f  -SECTOR: %d",pElemento->id,pElemento->lastName,pElemento->name,pElemento->salary,pElemento->sector);
	}

	return retorno;
}

/**
 * \brief Imprime el array de Employee
 * \param array Array de Employee a ser actualizado
 * \param limite Limite del array de Employee
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int printEmpleyees(Employee* array,int len)
{
	int answer = -1;
	int i;

	if(array != NULL && len > 0)
	{
		answer = 0;
		for(i=0;i<len;i++)
		{
			printData(&array[i]);
		}
	}

	return answer;
}

/**
 * \brief Inicializa el array
 * \param array Array de Employee a ser actualizado
 * \param limite Limite del array de Employee
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int initEmployees(Employee* array,int len)
{
	int answer = -1;
	int i;

	if(array != NULL && len > 0)
	{
		answer = 0;
		for(i=0;i<len;i++)
		{
			array[i].isEmpty = 1;
		}
	}

	return answer;
}

/**
 * \brief Actualiza los datos de un Employee en una posicion del array
 * \param array: Array de Employee a ser actualizado.
 * \param limite: Limite del array de Employee.
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int empModificarArray(Employee* array,int limite, int indice)
{
	int respuesta = -1;
	int option;
	Employee bufferEmployee;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if (utn_getNumero(&option,"\n\n1-Name \n2-LastName \n3-Salary \n4-Sector \n5-Return","\nERROR",1,5,2)==0)
		{
			switch (option)
			{
			case 1:
				if(	utn_getNombre(bufferEmployee.name,NAME_LEN,"\nName?\n","\nERROR\n",2) == 0)
				{
					strncpy(array[indice].name,bufferEmployee.name,sizeof (NAME_LEN));
					respuesta = 0;
				}
				break;
			case 2:
				if (utn_getNombre(bufferEmployee.lastName,LASTNAME_LEN,"\nLast Name?\n","\nERROR\n",2) == 0)
				{
					strncpy(array[indice].lastName,bufferEmployee.lastName,sizeof (LASTNAME_LEN));
					respuesta = 0;
				}
				break;
			case 3:
				if (utn_getNumeroFlotante(&bufferEmployee.salary,"\nsalary?\n","\nERROR\n",0,50000,2) == 0)
				{
					array[indice].salary = bufferEmployee.salary;
					respuesta = 0;
				}
				break;
			case 4:
				if (utn_getNumero(&bufferEmployee.sector,"\nSector?","\nError",1,100,2)==0)
				{
					array[indice].sector = bufferEmployee.sector;
					respuesta = 0;
				}
				break;
			}
		}
	}

	return respuesta;
}

/**
 * \brief Da de alta un Employee en una posicion del array.
 * \param array: Array de Employee a ser actualizado.
 * \param limite: Limite del array de Employee.
 * \param indice: Posicion a ser actualizada
 * \param id: Identificador a ser asignado al Employee.
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int addEmployees(Employee* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Employee bufferEmployee;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferEmployee.name,NAME_LEN,"\nName?\n","\nERROR\n",2) == 0 &&
				utn_getNombre(bufferEmployee.lastName,LASTNAME_LEN,"\nLast Name?\n","\nERROR\n",2) == 0 &&
				utn_getNumeroFlotante(&bufferEmployee.salary,"\nsalary?\n","\nERROR\n",0,50000,2) == 0 &&
				utn_getNumero(&bufferEmployee.sector,"\nSector","\nError",1,100,2)==0)
		{
			respuesta = 0;
			bufferEmployee.id = *id;
			bufferEmployee.isEmpty = 0;
			array[indice] = bufferEmployee;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de Employee a ser actualizado
 * \param limite Limite del array de Employee
 * \param indice Posicion a ser Employee
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

int removeEmployee(Employee* array,int len, int id)
{
	int answer = -1;

	if(array != NULL && len > 0 && id  >= 0 && array[id].isEmpty == 0)
	{
		array[id].isEmpty = 1;
		answer = 0;
	}

	return answer;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
 * \param array Employee Array de Employee
 * \param limite int Tamaño del array
 * \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
 * \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
 *
 */

int findEmployeeById(Employee* array, int len, int id)
{
	int answer = -1;
	int i;

	if(array != NULL && len > 0 && id >= 0)
	{
		answer = 0;
		for(i=0;i<len;i++)
		{
			if(array[i].id == id)
			{
				answer = i;
				break;
			}
		}
	}

	return answer;
}

/**
 * \brief Ordenar el array de Employee por apellido y sector
 * \param array Array de Employee
 * \param limite Limite del array de Employee
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 *
 */

int sortEmployees(Employee* array,int len)
{
	int answer = -1;
	int flagSwap;
	int i;
	Employee buffer;
	int auxiliarCmp;

	if(array != NULL && len > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<len-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(array[i].lastName,array[i+1].lastName,NAME_LEN);
				if(	 auxiliarCmp > 0 || (auxiliarCmp == 0 && array[i].sector > array[i+1].sector) )
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}

			len--;
			answer =0;
		} while(flagSwap);
	}

	return answer;
}

/**
 * \brief calcula total salario, promedio,  y cantidad de empleados con mas del promedio
 * \param array Array de Employee
 * \param limite Limite del array de Employee
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 *
 */

int salarioInforme(Employee* array,int len,int * total,float * promedio,int * cantidad)
{
	int answer = -1;
	int i;
	int totalSalario=0;
	int cantidadSalario = 0;

	if (array != NULL && len > 0 && total != NULL && promedio != NULL && cantidad != NULL)
	{
		for (i = 0; i < len; i++)
		{
			if (array [i].isEmpty == 0)
			{
				totalSalario= totalSalario + array [i].salary;
				cantidadSalario ++;
			}
		}

		*promedio = totalSalario / cantidadSalario;
		*cantidad  = cantidadSuperaSalarioPromedio(array,len,*promedio);
		*total = totalSalario;
		answer = 0;
	}

	return answer;
}

/**
 * \brief calcula  cantidad de empleados con mas del promedio
 * \param array Array de Employee
 * \param limite Limite del array de Employee
 * \param Promedio de salario
 * \return Retorna cantidad de empleados  y -1 (ERROR)
 *
 */

int cantidadSuperaSalarioPromedio( Employee* array,int len,float promedio)
{
	int respuesta = -1;
	int i;
	int cantidadEmpleados= 0;

	if(array != NULL && len > 0 && promedio>=0)
	{
		for(i=0;i<len;i++)
		{
			if (array[i].isEmpty == 0 && array[i].salary > promedio)
			{
				cantidadEmpleados++;
			}
		}

		respuesta = cantidadEmpleados;
	}

	return respuesta;
}
