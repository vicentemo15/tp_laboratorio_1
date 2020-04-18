/*
 * calculadora.h
 *
 *  Created on: 10 abr. 2020
 *      Author: Vicente Montilla
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef CALCULADORA_H_
#define CALCULADORA_H_

int dividir (float* pResultado,int operador1, int operador2);
int multiplicacion (int operador1, int operador2);
int resta (int operador1, int operador2);
int suma (int operador1, int operador2);
int factorial (int operador1,long int* pResultado);

#endif /* CALCULADORA_H_ */
