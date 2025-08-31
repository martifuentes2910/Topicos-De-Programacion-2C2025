#ifndef GENERICOS_H_INCLUDED
#define GENERICOS_H_INCLUDED
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define TAM 7
void* _map(void* vec, unsigned ce, unsigned tam,int accion(void*) );
int mostrarFlotante(void* info);
int raizCuadrada(void* info);
unsigned rfact(unsigned n);
#endif // GENERICOS_H_INCLUDED
