/*
 * Employee.h
 *
 *  Created on: 18 jun. 2020
 *      Author: vicente
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NOMBRE_LEN 128
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[NOMBRE_LEN];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_getNextId(LinkedList* pArrayListEmployee);
int employee_comparadorNombre(void* a, void* b);

int employee_CaluloSueldo(void*pElement);
int employee_MayorHorasTrabajo(void*pElement);
int employee_compararSueldoMayor(void*pElement,int valor, int index);
int employee_compararSueldoMenor(void*pElement,int valor, int index);
int employee_compararSueldoPagar(void*pElement,int valor, int index);
int employee_compararSueldoMayorDos(LinkedList* pArrayListEmployee);
#endif // employee_H_INCLUDED


#endif /* EMPLOYEE_H_ */
