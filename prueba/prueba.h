#ifndef PRUEBA_H_INCLUDED
#define PRUEBA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
int dni;
int edad;
char nombre[15];

}tPersona;

int cmpDniPersona(const void*a,const void* b);
int cmpAscInt (const void* a, const void* b);
int cmpDescInt(const void* a, const void* b);
char* concatArchNum(const char* cad, int i);
int insertarOrdenado(void* vec, void* val, int* ce, unsigned tam, unsigned max_elem, int cmp(const void*, const void*));

#endif // PRUEBA_H_INCLUDED
