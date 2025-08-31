#ifndef TDAVECTOR_H_INCLUDED
#define TDAVECTOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    void* vec;
    int ce;
    unsigned tam;
    int maxi;

}Vector;
void m_memmove(void* a,void* b, size_t n);
int crearVector(Vector* vec,int ce,unsigned tam);
int destruirVectorEst(Vector* vec);
int destruirVectorDin(Vector* vec);
int cargarVectorOrdenado(Vector* vec, void* dato, int cmp(const void*,const void*));
int cargarVector(Vector* vec,void* dato);
void mostrarInt(const void* dato);
void recorrerVector(Vector* vec,void accion(const void*));

#endif // TDAVECTOR_H_INCLUDED
