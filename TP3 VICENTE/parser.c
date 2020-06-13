#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return - 1 en caso de ERROR  retorna 0 en caso de 	EXITO.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char id[128];
	char nombre[128];
	char horasTrabajadas[128];
	char sueldo[128];
	Employee* pE;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		ll_clear(pArrayListEmployee);

		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4)
			{
				pE = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if(pE!=NULL)
				{
					ll_add(pArrayListEmployee, pE);
				}
			}
		}
		while(feof(pFile)==0);

		printf("\nTOTAL DE EMPLEADOS CARGADOS:  %d", ll_len(pArrayListEmployee));
		retorno = 0;
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* empleado;
	int empleadosLeidos=0;
	int retorno = -1;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		ll_clear(pArrayListEmployee);

		do
		{
			empleado = employee_new();
			empleadosLeidos = fread(empleado,sizeof(Employee),1,pFile);
			if(empleadosLeidos==1)
			{
				ll_add(pArrayListEmployee, empleado);
			}
		}
		while(empleadosLeidos!=0);

		printf("\nTOTAL DE EMPLEADOS CARGADOS:  %d", ll_len(pArrayListEmployee));
		retorno = 0;
	}

    return retorno;
}
