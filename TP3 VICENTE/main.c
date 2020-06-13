#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

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
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

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
    			"\n 10-SALIR\n" ,"ERROR",1,10,2)==0)
    	{
    		switch(option)
    		{
    		case 1:
    			controller_loadFromText("data.csv",listaEmpleados);
    			break;
    		case 2:
    			controller_loadFromBinary("data.bin",listaEmpleados);
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
    			controller_saveAsText("data.csv", listaEmpleados);
    		    break;
    		case 9:
    			controller_saveAsBinary("data.bin", listaEmpleados);
    		    break;
    		}
    	}
    }while(option != 10);

    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

