#include "Recursividad.h"

int main()
{
    int vec[]= {1,2,4,8,16,32,64,128,254}; //ORDENADOS DE MENOR A MAYOR
    int vec2[]= {254,128,64,32,16,8,4,2,1}; //ORDENADOS DE MAYOR A MENOR
    int vec3[]= {'a','b','c','d','e'};
     char clave='a';
    char *pe;
    if((pe=(char*)_bsearchR(vec3,&clave,5,sizeof(char),cmpAscChar))!=NULL)
        printf("%c",*pe);
    else
        printf("No se encontro el elemento.");
//    int clave=32;
//    int *pe;
//    if((pe=(int*)_bsearchR(vec2,&clave,sizeof(vec)/sizeof(int),sizeof(int),cmpAscInt))!=NULL)
//        printf("%d",*pe);
//    else
//        printf("No se encontro el elemento.");
//    char cad[]="abcdefgh";
   // char cad3[]="abcafa";
//    char cad2[]= {'a','b','c','d'};

//mostrarChar(cad2);
//int len=_strlenR(cad);
//printf("Tamanio: %d",len);
//char* pc;

//    if((pc=_strchrR(cad,'i'))!=NULL)
//        printf("%c",*pc);
//    else
//        printf("No se encontro el caracter");
///
//    if((pc=_strrchrR(cad3,'b'))!=NULL)
//        printf("%c",*pc);
//    else
//        printf("No se encontro el caracter");


///// EJ 6.2 TRIANGULO DE TARTAGLIA REVISAAAAARRRRRRRRRR
//    unsigned short ents[19]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
//   // comb(&ents[19],19);
//    return 0;
}
