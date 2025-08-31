#ifndef CLASE9_H_INCLUDED
#define CLASE9_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

int cmpEntAsc(const void*, const void*);
int cmpEntAscChar(const void*, const void*);
void *myBSearch(const void* llave, void* vec, size_t ce, size_t tam, int comparar(const void* a, const void* b));
//void* buscarMenor(const void*, size_t, size_t, int(const void*, const void*));
//void adSeleccion(void*,size_t,size_t, int(const void*, const void*));
//void* _bsearch(const void*, const void*, size_t, size_t, int (const void*,const void*));
//void qsort(void*, size_t, size_t, int (const void*,const void*))

#endif // CLASE9_H_INCLUDED
