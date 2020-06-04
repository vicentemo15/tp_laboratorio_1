/*
 ============================================================================
 Name        : bibliteca.c
 Author      : Vicente Montilla
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "utn.h"

#define QUANTITY_EMPLOYEES 1000

int main(void) {
	setbuf(stdout, NULL);
	Employee arrayEmployees[QUANTITY_EMPLOYEES];
	int option;
	int auxiliaryIndex;
	int auxiliaryIdEmployees = 0;
	int auxiliaryId;
	int optionInf;
	int auxiliarySalaryT;
	float auxiliarySalaryPro;
	int auxiliaryQuantity;

	if(initEmployees(arrayEmployees,QUANTITY_EMPLOYEES) == 0)
	{
		printf("Array initialized. \n\n");
	}

	do
	{
		if(!utn_getNumero(	&option,
				"\n\n1.Add Employee"
				"\n2.Modify Employee"
				"\n3.Remove Employee"
				"\n4.Report"
				"\n5.Exit\n\n",
				"\nError Invalid option",1,5,2) )
		{
			switch(option)
			{
			case 1:
				auxiliaryIndex = emp_positionAvailable(arrayEmployees,QUANTITY_EMPLOYEES);
				if(auxiliaryIndex >= 0)
				{
					if(addEmployees(arrayEmployees,QUANTITY_EMPLOYEES,auxiliaryIndex, &auxiliaryIdEmployees) == 0)
					{
						printf("\n Successful added\n");
					}
				}
				else
				{
					printf("\nNot enough space");
				}

				break;
			case 2:
				if (chequeoAlta(arrayEmployees,QUANTITY_EMPLOYEES) == 0)
				{
					printEmpleyees(arrayEmployees,QUANTITY_EMPLOYEES);
					if(utn_getNumero(&auxiliaryId,"\nID to modify \n","\nID ERROR",0,10000,1) == 0)
					{
						auxiliaryIndex = buscarId(arrayEmployees,QUANTITY_EMPLOYEES,auxiliaryId);
						if(	auxiliaryIndex >= 0 && empModificarArray(arrayEmployees,QUANTITY_EMPLOYEES,auxiliaryIndex) == 0)
						{
							printf("\nMODIFIED\n");
						}
					}
				}
				else
				{
					printf("Must register an employee");
				}
				break;
			case 3:
				if (chequeoAlta(arrayEmployees,QUANTITY_EMPLOYEES) == 0)
				{
					printEmpleyees(arrayEmployees,QUANTITY_EMPLOYEES);
					if(utn_getNumero(&auxiliaryId,"\nID to remove \n","\nID ERROR",0,auxiliaryIdEmployees,0)==0)
					{
						auxiliaryIndex =buscarId(arrayEmployees,QUANTITY_EMPLOYEES,auxiliaryId);
						if(	auxiliaryIndex >= 0 && removeEmployee(arrayEmployees,QUANTITY_EMPLOYEES,auxiliaryIndex)== 0)
						{
							printf("\n Removed\n");
						}
					}
				}
				else
				{
					printf("Must register an employee");
				}
				break;
			case 4:
				if (chequeoAlta(arrayEmployees,QUANTITY_EMPLOYEES) == 0)
				{
					do
					{
						if(!utn_getNumero( &optionInf,
								"\n\n1.List of employees"
								"\n2.Salary information"
								"\n3.Return",
								"\nError",1,3,2) )
						{
							switch (optionInf)
							{
							case 1:
								if (sortEmployees(arrayEmployees,QUANTITY_EMPLOYEES)!= -1)
								{
									printEmpleyees (arrayEmployees,QUANTITY_EMPLOYEES);
								}
								break;
							case 2:
								if (salarioInforme(arrayEmployees,QUANTITY_EMPLOYEES,&auxiliarySalaryT,&auxiliarySalaryPro,&auxiliaryQuantity)!= -1)
								{
									printf("\n-Total salary: %d \n-Average: %.2f \n-Number of employees over average : %d",auxiliarySalaryT,auxiliarySalaryPro,auxiliaryQuantity);
								}
								break;
							}
						}
					} while (optionInf != 3);
				}
				else
				{
					printf("Must register an employee");
				}
				break;
			}
		}
	} while(option != 5);

	return EXIT_SUCCESS;
}
