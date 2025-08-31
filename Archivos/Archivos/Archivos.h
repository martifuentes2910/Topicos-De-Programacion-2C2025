#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
typedef struct
{
    int dia,mes,anio;

} tFecha;
typedef struct
{
    long dni;
    char apyn[36];
    char categoria;
    tFecha fecIngreso;
    float sueldo;
} tEmpleado;
typedef struct
{
    int dni;
    char nya[30];
    float promedio;
} tEstudiante;
typedef struct{
int dni;
int legajo;
float promedio;
int edad;
char genero;
}tAlumno;

int crearArchivo(const char*,void*,unsigned,unsigned);
int recorrerArch(const char* fname,unsigned tam, void accion(void* val));
int abrirArchivo(FILE **pf, const char *nombreArch, const char *modoApertura, int mostrarError);

int crearArchivoEmp(char* nombreArchivo);
int leerYmostrarArchivo(char* nombreArchivo);
void mostrarEmpleado(const tEmpleado *emp);

int buscarPorDni(FILE *pf,tEmpleado *pe);


int crearArchivoDeTextoLV(char *nombreArchOrigen, char *nombreArchDestino);
int crearArchivoDeTextoLF(char *nombreArchOrigen, char *nombreArchDestino);

void trozarCamposLongitudVariable(tEmpleado *d,char *s);
void trozarCamposLongitudFija(tEmpleado *d,char *s);

void actualizarPorcentajeSueldo(FILE *pf, float porcentaje, int *nroRegistros);
//void mostrarEmpleado(void* val);
//void crearArchivo(const char*);

#endif // ARCHIVOS_H_INCLUDED

