#include "Recursividad.h"

int cmpAscInt(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}
int cmpAscChar(const void* a, const void* b)
{
    return *(char*)a-*(char*)b;
}
void* _bsearchR(void* vec,const void* clave, size_t ce,size_t tam, int cmp(const void*,const void*))
{
    void* fin;
    void* pm;
    if(ce==0)
        return NULL;
    pm= vec + (ce/2)*tam;

    if(cmp(clave,pm)==0)
        return pm;
    else if(cmp(clave,pm)<0)
        return _bsearchR(vec,clave,ce/2,tam,cmp);
    else
    {
        fin=pm+tam;
        return _bsearchR(fin,clave,(ce-1)/2,tam,cmp);
    }
}
/**Ejercicio 6.1
Escriba una funci�n recursiva que:
- calcule el factorial de un n�mero entero.
- muestre el contenido de un array de char.
- �dem anterior, mostrando en orden inverso.
- �dem anterior, devolviendo la suma de los caracteres que representan d�gitos.
- muestre el contenido de un array de enteros en orden inverso, devolviendo la suma de todos los
elementos.
- �dem anterior, devolviendo la suma de los pares.
- �dem anterior, devolviendo la suma de los que est�n en posiciones pares.
- Escriba versiones recursivas de las funciones de biblioteca <strlen>, <strchr> y <strrchr>**/

void mostrarChar(const char* cad)   //MUESTRA UN STRING RECURSIVAMENTE
{
    if(*cad=='\0')
        return;
    printf("%c",*cad);
    return mostrarChar(cad+1);
}
int _strlenR(const char* cad)
{
    return *cad?1+_strlenR(cad+1):0;
}
char* _strchrR(char* cad, int c)
{
    if(!*cad)
        return NULL;
    return *cad==(char)c?cad:_strchrR(cad+1,c);
}

char* _strrchrR(char *cad, int c){
    char *ret;

    if(cad == NULL)
        return NULL;

    if(*cad=='\0')
        return (c == '\0') ? (char*)cad : NULL;

    if((ret = _strrchrR(cad + 1, c)))
        return ret;

    if(*cad == c)
        return (char*)cad;

    return NULL;
}
//char* _strrchrR(char* cad, int c)       ///revisar
//{
//    if(!*cad)
//        return NULL;
//
//    if(_strrchrR(cad+1, c)!=NULL)       //SI ENCONTRAMOS EL CARACTER RETORNA EL RES
//        return _strrchrR(cad+1, c);
//
//    return *cad == (char)c? cad: NULL;
//
//}
int factorial(int n)
{
    return n==0? 1:n*factorial(n-1);
}
int combinacion(int n,int k)
{
    return (factorial(n))/(factorial(k)*factorial(n-k));
}
//int comb(int n,int m)
//{
// return((n==0) || (n==m))? 1: comb(n-1,m-1) + comb(n-1,m);
//}
unsigned short comb(unsigned short* n,int m)
{

    unsigned short res = ((*n==0) || (*n==m))? 1: comb(n+1,m-1) + comb(n+1,m);
    printf("%d ",res);
    return res;
}
