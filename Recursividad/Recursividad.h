#ifndef RECURSIVIDAD_H_INCLUDED
#define RECURSIVIDAD_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* _strchrR(char* cad, int c);
char* _strrchrR(char* cad, int c);
void mostrarChar(const char* cad);
int _strlenR(const char* cad);
int cmpAscInt(const void* a, const void* b);
int cmpAscChar(const void* a, const void* b);
void* _bsearchR(void* vec,const void* clave, size_t ce,size_t tam, int cmp(const void*,const void*));
#endif // RECURSIVIDAD_H_INCLUDED
