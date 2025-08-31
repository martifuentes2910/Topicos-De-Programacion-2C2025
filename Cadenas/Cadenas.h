#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESLETRA(x) ((x>='a' && x<='z') || (x>='A' && x<='Z'))
#define AMAYUSC(x) ((x >= 'a') && (x <= 'z')? x-('a'-'A'):x)
#define AMINUSC(x) ((x >= 'A') && (x <= 'Z')? x+('a'-'A'):x)
#define ESESPACIO(x) ((x == ' '))
size_t miStrlen(const char* );
char *miStrchr(const char *, int);

int esPalindromo(const char*);      //a una letra minuscula le restas 32 y te da su MAYUSCULA
int proxPalabra(char*);
void Invertir(char*);
void Normalizar(char* cad,int* ce);
void eliminar(char* cad, int*ce);
char desplazamiento(char c, unsigned desp, const char* grupo);
void desofuscar(char *cad, const char* grupo);
#endif // CADENAS_H_INCLUDED
