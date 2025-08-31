
#include "prueba.h"
#define MAX 5
int main()
{
//    char cad[12] = "estudiantes";
//    int ce = 5;
//    int i;
//    char *fname;
//
//    for (i = 1; i <= ce; i++)
//    {
//        fname = concatArchNum(cad, i);  //Retorna el puntero al nombre del archivo a abrir
//        printf("%s\n", fname);
//        free(fname); // Free al puntero creado en funcion
//    }
//
//    tPersona p[7]=
//    {
//        {146,67,"Enrique"},
//        {246,46,"Raul"},
//        {346,34,"Pablo"},
//        {446,20,"Juan"},
//        {448,19,"Fran"},
//        {500,17,"Martin"},
//
//    };
//    tPersona dato= {447,19,"Facundo"};
//    int capacidad = 7, ce=6,i;
//
//    int dev= insertarOrdenado(p,&dato,&ce,sizeof(tPersona),capacidad,cmpDniPersona);
//    for(i=0; i<ce; i++)
//        printf("DNI: %d EDAD: %d NOMBRE: %s\n",p[i].dni,p[i].edad,p[i].nombre);
//    printf("%d",dev);
    //return 0;


//int vec[MAX]={3,6,9,12,16};
//int vec2[MAX]={16,12,9,6,3};
int vec3[MAX]={4,2,5,1,3};
ordenarInsercionGenCod(vec3,MAX,sizeof(int),cmpAscInt);
for(int i=0;i<MAX;i++)
    printf("%d ",vec3[i]);

//int val=5;
//int cev, i;
//cev=5;
//int dev=insertarOrdenado(vec2,&val,&cev,sizeof(int),MAX,cmpDescInt);
//for(i=0;i<cev;i++)
//    printf("%d ",vec2[i]);
//printf("\n%d",dev);
}
