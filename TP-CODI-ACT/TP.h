#ifndef TP_H_INCLUDED
#define TP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <time.h>

#define TAM 5

#define ESLETRA(x) ((x>='a' && x<='z') || (x>='A' && x<='Z'))
#define AMAYUSC(x) ((x >= 'a') && (x <= 'z')? x-('a'-'A'):x)
#define AMINUSC(x) ((x >= 'A') && (x <= 'Z')? x+('a'-'A'):x)
#define ESESPACIO(x) ((x == ' '))

typedef struct
{
    unsigned long long dni;
    unsigned long long fechaDeInscripcion;
    char nombreYApellido[30];
    float promedio;
}tEstudiante;

typedef struct{

    long long fecha;
    char fname[20];
}tOrden;

void* leerArchivo(FILE* pf, void* vec, size_t tam);

void intercambio(void*, void*, unsigned tam);

int compFlotAsc(void* a, void* b);

void gen_sort(void* vec, int n, size_t tam, int cmp(void*a,void*b));

int compEntAsc(void* a, void* b);

int compararUnsAsc(void* a, void* b);

void genBinFileName(char fnames[][TAM], const char* cad, int cmerge);

long long parseFechaEst(void* data);

void ordenarPorFecha(char fnames[][TAM],unsigned cmerge,unsigned tam,long long parseFecha(void*));

void NormalizarEsts(void* data);

void mergeGen(char fnames[][TAM],const char* archMerge,unsigned cmerge, unsigned tam, void accion(void* val));

void get5MejoresPromedios(const char* fname);


#endif // TP_H_INCLUDED
