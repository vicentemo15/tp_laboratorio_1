/*
 ============================================================================
 Name        : tp5.c
 Author      : Vicente Montilla.
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

#define DATA_CSV "src\\data.csv"
#define DATA_BIN "src\\data.bin"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir..
*****************************************************/

int main()
{

	setbuf(stdout, NULL);
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int auxlia;
    Employee* pE = NULL;

    do{
    	if(utn_getNumero(&option,"\n\nMENU:\n 01-CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.CSV (MODO TEXTO)"
    			"\n 02-CARGAR LOS DATOS DE LOS EMPLEADOS DESDE EL ARCHIVO DATA.BIN (MODO BINARIO)"
    			"\n 03-ALTA DE EMPLEADOS"
    			"\n 04-MODIFICAR DATOS DE EMPLEADOS"
    			"\n 05-BAJA DE EMPLEADO"
    			"\n 06-LISTAR EMPLEADOS"
    			"\n 07-ORDENAR EMPLEADOS"
    			"\n 08-GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATA.CSV (MODO TEXTO)"
    			"\n 09-GUARDAR LOS DATOS DE LOS EMPLEADOS EN EL ARCHIVO DATA.BIN (MODO BINARIO)"
    			"\n 10-prueba ll_map"
    			"\n 11-prueba ll_filter"
    			"\n 12-prueba ll_reduce"
    			"\n 13-SALIR\n" ,"ERROR",1,13,2)==0)
    	{
    		switch(option)
    		{
    		case 1:
    			controller_loadFromText(DATA_CSV,listaEmpleados);
    			break;
    		case 2:
    			controller_loadFromBinary(DATA_BIN,listaEmpleados);
    			break;
    		case 3:
    			controller_addEmployee(listaEmpleados);
    		   break;
    		case 4:
    			 controller_editEmployee(listaEmpleados);
    		    break;
    		case 5:
    			controller_removeEmployee(listaEmpleados);
    		    break;
    		case 6:
    			controller_ListEmployee(listaEmpleados);
    		    break;
    		case 7:
    			controller_sortEmployee(listaEmpleados);
    		    break;
    		case 8:
    			controller_saveAsText(DATA_CSV, listaEmpleados);
    		    break;
    		case 9:
    			controller_saveAsBinary(DATA_BIN, listaEmpleados);
    		    break;
    		case 10:
    			ll_map(listaEmpleados,employee_CaluloSueldo);
    			break;
    		case 11:
    			controller_ListEmployee( ll_filter(listaEmpleados,employee_MayorHorasTrabajo));
    			break;
    		case 12:
    			auxlia = ll_reduce(listaEmpleados, employee_compararSueldoPagar);
    			printf ("\ntotal a pagar: %d",auxlia);
    			pE = ll_reduceDos(listaEmpleados, employee_compararSueldoMayorDos);
    			if(pE != NULL)
    			{
    				printf("\n Mayor sueldo:\nID: %d -NOMBRE: %s -HORAS TRABAJADAS: %d - SUELDO: %d ",pE->id,pE->nombre,pE->horasTrabajadas,pE->sueldo);
    			}
    			break;
    		}
    	}
    }while(option != 13);

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
