#ifndef TIPOPARCIAL_H_INCLUDED
#define TIPOPARCIAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

#define ESLETRA(x)((x >= 'a' && x <= 'z')||(x >= 'A' && x <= 'Z'))
#define ESVOCAL(x) ((x=='a' || x == 'A') || (x=='e' || x == 'E') ||(x=='i' || x == 'I') || (x=='o' || x == 'O') || (x=='u' || x == 'U'))
#define ESESPACIO(x) ((x ==' '))
#define ESNUMERO(x) ((x >= 48 && x <= 57))

#define AMAYUSCULA(x) ((x >= 'a') && (x <= 'z')? x=x-('a'-'A'):x)

#define AMINUSCULA(x) ((x >= 'A') && (x <= 'Z')? x+('a'-'A'):x)
size_t miStrlen(const char* );
char *miStrchr(const char *, int);
void *_bsearch(const void* clave, void* vec, size_t ce, size_t tam, int comparar(const void* a, const void* b));
void qsort(void *base, size_t nmemb, size_t tamanyo, int (*comparar)(const void *, const void *));

int cmpAscInt(const void* a,const void* b);
void MatrizZ(int mat[][100], int cf, int cc);
int crearArchivoCadTxt(const char*fname, void* data);
int leerArchivoTxt(char *fname);
void leerArchivo( char* fname,char*);
void CifradoCesarConsonantico(char*, char*);
char desplazamiento( char c, unsigned desp, char* grupo);
#endif // TIPOPARCIAL_H_INCLUDED
