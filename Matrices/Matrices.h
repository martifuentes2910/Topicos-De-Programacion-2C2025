#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define TAM_F 3
#define TAM_C 3

#define TAM_F1 50
#define TAM_C1 50

#define TAM_F2 50
#define TAM_C2 50

#define N 3
#define TAM_CUADRADO 3

int SumaMatriz(int* ,int ,int );
void MultiplicarMatriz(int m1[][TAM_C1],int m2[][TAM_C2], int f1,int c1,int f2,int c2);
int buscarPosPA(int* pv, int num, int ce);
int verificarPuntajes(int tabla[][TAM_CUADRADO]);
#endif // MATRICES_H_INCLUDED
