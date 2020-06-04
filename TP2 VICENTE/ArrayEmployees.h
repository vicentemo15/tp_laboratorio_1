#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define NAME_LEN 51
#define LASTNAME_LEN 51

typedef struct
{
	char name[NAME_LEN];
	char lastName[LASTNAME_LEN];
	float salary;
	int isEmpty;
	int id;
	int sector;
}Employee;

int emp_positionAvailable(Employee* array,int len);
int chequeoAlta(Employee* array,int len);
int buscarId(Employee* array, int len, int valorBuscado);
int printData(Employee* auxProducto);
int initEmployees(Employee* array,int len);
int empModificarArray(Employee* array,int limite, int indice);
int addEmployees(Employee* array,int limite, int indice, int* id);
int printEmpleyees(Employee* array,int len);
int findEmployeeById(Employee* array, int len, int id);
int removeEmployee(Employee* array,int len, int id);
int sortEmployees(Employee* array,int len);
int salarioInforme(Employee* array,int len,int * total,float * promedio,int * cantidad);
int cantidadSuperaSalarioPromedio( Employee* array,int len,float promedio);

#endif /* ARRAYEMPLOYEES_H_ */
