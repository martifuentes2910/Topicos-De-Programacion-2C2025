#include "prueba.h"
void ordenarInsercion(int* v,int ce)
{
    int i, j, elemAIns;
    for(i=1; i<ce; i++)
    {
        elemAIns=v[i];
        j=i-1;
        while(j>=0 && elemAIns <v[j])
        {
            v[j+i]=v[j];
            j--;
        }
        v[j+1]=elemAIns;
    }
}
void trasponerMatrizCuadrada(int mat[][MAX_COL], unsigned lado){
    int aux;
    int i=0, j, tol=0;
    int mitf=((lado%2==0)?(lado/2):(lado/2+1)); // divide la matriz por la mitad, dependiendo de si es cuadrada de lados impar o par
//    printf("%d", *pmat+i*lado+j);
    for(i=i;i<=mitf;i++)    //va hasta la mitad
    {
        for(j=tol;j<lado;j++)       //recorre las colunm
        {
            aux=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=aux;
        }
        tol++;
    }
    return;
}
void intercambio(void* a, void* b, unsigned tam)
{
    char aux;
    for(int i=0; i<tam; i++)
    {
        aux=*(char*)a;
        *(char*)a=*(char*)b;
        *(char*)b=aux;
        a++;
        b++;
    }
}
void ordenarInsercionGenCod(void* vec, int ce, unsigned tam, int cmp(void*,void*))
{
    void* pe=vec;
    void* pl=vec;
    //void* fin=vec+(tam*ce);
    int i, j, k=ce;
    for(i=0; i<ce; i++)
    {
        for(j=0; j<k; j++)
        {
            if((pe!=pl)&&(cmp(pe,pl)>0))
                intercambio(pe,pl,tam);

            pl+=tam;
        }
        k--;
        pe+=tam;
        pl=pe;
    }

}
void ordenarInsercionGen(void * vec, unsigned ce,unsigned tam,int cmp(const void*,const void*))
{
    void* aux;
    void* fin=vec+(ce-1)*tam;

    while(vec<fin)
    {
        //while( j>=0 && aux < )
            memcpy(vec,vec+tam,tam);
        vec+=tam;
    }
}
char* concatArchNum(const char* cad, int i)
{
    char numStr[2]; //string para el char de int + \0
    sprintf(numStr, "%d", i); // Convert integer to string

    // Mem dinamica para cada nueva cadena creada
    size_t newSize = strlen(cad) + strlen(numStr) + 5; // Base string 12 + char de numeracion (2) + ".dat\0" (5 bits mas)
    char *fname = (char*)malloc(newSize);
    if (fname == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(fname, cad);
    strcat(fname, numStr);
    strcat(fname, ".dat");

    return fname;
}
/*Ejercicio 3.17
Desarrolle una función genérica que permita insertar de forma ordenada un elemento en un vector.
Puede ayudarse, usando como patrón, la versión no genérica desarrollada y probada de la práctica 1
y con las funciones de biblioteca memcpy y memmove.*/

//Implemente insertar ordenado segun consigna
//vec: Vector donde insertar
//val: Elemento a insertar
//ce: Cantidad de elementos presentes en el vector
//tam: tamanio de cada elemento
//max_elem: cantidad maxima de elementos que tolera el vector
//cmp: funcion de comparacion
int insertarOrdenado(void* vec, void* val, int* ce, unsigned tam, unsigned max_elem, int cmp(const void*, const void*))
{
    void* ini=vec;
    void* fin=vec+(*ce-1)*tam;

    if(*ce==max_elem && cmp(val,fin)>0)  // VAL ES MAS GRANDE/CHICO QUE EL ULTIMO
        return 0;

    vec=fin+tam;
    while(ini<vec && cmp(val,vec-tam)<0)
    {
        memcpy(vec,vec-tam,tam);
        vec-=tam;
    }
    memcpy(vec,val,tam);
    if(*ce == max_elem)
        return 0;
    (*ce)++;

    return 1;
}
int cmpAscInt (const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}
int cmpDescInt(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

int cmpAscChar (const void* a, const void* b)
{

    return *(char*)a - *(char*)b;
}
int cmpDniPersona(const void*a,const void* b)
{
    return ((tPersona*)a)->dni - ((tPersona*)b)->dni;
}
