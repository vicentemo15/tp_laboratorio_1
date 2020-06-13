#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* fp = fopen(path,"r");
	parser_EmployeeFromText(fp, pArrayListEmployee);
	fclose(fp);
	return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* fp = fopen(path,"rb");
	parser_EmployeeFromBinary(fp, pArrayListEmployee);
	fclose(fp);
	return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pE;
	int id;
	char nombre[NOMBRE_LEN];
	int horasTrabajadas;
	int sueldo;

	id= employee_getNextId(pArrayListEmployee);
	if(utn_getNombre(nombre,NOMBRE_LEN,"\n INGRESE EL NOMBRE: \n","ERROR",2)==0 &&
			utn_getNumero(&horasTrabajadas,"\nINGRESE LAS HORAS TRABAJADAS:  \n","ERROR",0,10000,2)==0 &&
			utn_getNumero(&sueldo,"\nINGRESE EL SUELDO:  \n","ERROR",0,100000,2)==0)
	{
		pE= employee_new();
		employee_setId(pE,id);
		employee_setNombre(pE,nombre);
		employee_setHorasTrabajadas(pE,horasTrabajadas);
		employee_setSueldo(pE,sueldo);

		ll_add(pArrayListEmployee, pE);
		retorno = 0;
	}

	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idEmployee;
	int i;
	Employee* pE= NULL;
	int opcion;

	if(utn_getNumero(&idEmployee,"\nINGRESE EL ID DEL EMPLEADO A MODIFICAR: ","ERROR",1,employee_getNextId(pArrayListEmployee)-1,2)==0)
	{
		for (i=0; i<ll_len(pArrayListEmployee);i++)
		{
			pE= ll_get(pArrayListEmployee,i);
			if(pE != NULL && pE->id==idEmployee)
			{
				printf("\nID: %d -NOMBRE: %s -HORAS TRABAJADAS: %d - SUELDO: %d\n\n",pE->id,pE->nombre,pE->horasTrabajadas,pE->sueldo);
				do
				{
					if (utn_getNumero(&opcion,"MODIFICAR: \n 1-NOMBRE\n 2-HORAS EXTRAS\n 3-SUELDO\n 4-VOLVER\n","ERROR",1,4,2)==0)
					{
						switch (opcion) {
						case 1:
							if(utn_getNombre(pE->nombre,NOMBRE_LEN,"\n INGRESE EL NOMBRE: \n","ERROR",2)==0)
							{
								ll_set(pArrayListEmployee,i,pE);
								printf("NOMBRE MODIFICADO CORRECTAMENTE\n\n");
							}
							break;
						case 2:
							if(utn_getNumero(&pE->horasTrabajadas,"\nINGRESE LAS HORAS TRABAJADAS:  \n","ERROR",0,10000,2)==0)
							{
								ll_set(pArrayListEmployee,i,pE);
								printf("HORAS MODIFICADO CORRECTAMENTE\n\n");
							}
							break;
						case 3:
							if(utn_getNumero(&pE->sueldo,"\nINGRESE EL SUELDO:\n","ERROR",0,100000,2)==0)
							{
								ll_set(pArrayListEmployee,i,pE);
								printf("SUELDO MODIFICADO CORRECTAMENTE\n\n");
							}
							break;
						}
					}
				} while (opcion!=4);

				return 0;
			}
		}

		printf("EMPLEADO NO ENCONTRADO!\n");
	}

	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int idEmployee;
	int i;
	Employee* pE= NULL;

	if(utn_getNumero(&idEmployee,"\nINGRESE EL ID DEL EMPLEADO A ELIMINAR: ","ERROR",1,employee_getNextId(pArrayListEmployee)-1,2)==0)
	{
		for (i=0; i<ll_len(pArrayListEmployee);i++)
		{
			pE= ll_get(pArrayListEmployee,i);
			if(pE!= NULL && pE->id==idEmployee)
			{
				ll_remove(pArrayListEmployee,i);
				employee_delete(pE);
				printf("EMPLEADO ELIMINADO CORRECTAMENTE\n");
				return 0;
			}
		}

		printf("EMPLEADO NO ENCONTRADO!\n");
	}

    return -1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	Employee* pE = NULL;

	if (pArrayListEmployee!= NULL)
	{
		for (i = 0;i< ll_len(pArrayListEmployee);i++)
		{
			pE = ll_get(pArrayListEmployee, i);

			if(pE != NULL)
			{
				printf("\nID: %d -NOMBRE: %s -HORAS TRABAJADAS: %d - SUELDO: %d ",pE->id,pE->nombre,pE->horasTrabajadas,pE->sueldo);
			}
		}
		retorno = 0;
	}

	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int (*fun_ptr)(void*, void*) = &employee_comparadorNombre;

	printf("\nORDENANDO EMPLEADOS POR NOMBRE ...");
	ll_sort(pArrayListEmployee, fun_ptr, 1);
	printf("\nEMPLEADOS ORDENADOS OK!");

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	Employee* pE = NULL;
	FILE* fp = fopen(path,"w");
	int i;
	int result = 0;
	int total = 0;

	if (fp != NULL && pArrayListEmployee != NULL)
	{
		for(i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pE = ll_get(pArrayListEmployee, i);
			if(pE != NULL)
			{
				result = fprintf(fp,"%d,%s,%d,%d\n",pE->id, pE->nombre, pE->horasTrabajadas, pE->sueldo);
				if(result > 0)
				{
				  total++;
				}
			}
		}
	}

	printf("\nTOTAL DE EMPLEADOS GUARDADOS:  %d", total);
	fclose(fp);
	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	Employee* pE = NULL;
	FILE* fp = fopen(path,"wb");
	int i;
	int result = 0;
	int total = 0;

	if (fp != NULL && pArrayListEmployee != NULL)
	{
		for(i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pE = ll_get(pArrayListEmployee, i);
			if(pE != NULL)
			{
				result = fwrite(pE,sizeof(Employee),1,fp);
				if(result == 1)
				{
				  total++;
				}
			}
		}
	}

	printf("\nTOTAL DE EMPLEADOS GUARDADOS:  %d", total);
	fclose(fp);
	return 1;
}

