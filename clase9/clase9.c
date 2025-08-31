#include "clase9.h"

int cmpEntAsc(const void*a, const void*b)
{
    return *((int*)a)-*((int*)b);
}
int cmpEntAscChar(const void*a, const void*b)
{
    return *((char*)a)-*((char*)b);
}

void qsort(void*, size_t, size_t, int (const void*,const void*))


void* buscarMenor(const void*vec, size_t ce, size_t tam, int cmpEntAsc(const void*a, const void*b))
{
    void*menor=(void*)vec;
    while(ce/tam)
    {
        if(cmpEntAsc(menor, vec)<0)
        {
            menor=(void*)vec;
        }
        vec+=tam;
    }

    return menor;
}

void ordenaSeleccion(void*vec,size_t ce,size_t tam, int cmp(const void*a, const void*b))//trae el menor y lo fija al inicio
{
    void*finfin=vec+(tam*(ce-1));
    void* menor = buscarMenor(vec, ce, tam, cmpEntAsc);
    while(vec<finfin)
    {

    }
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void *myBSearch(const void* llave, void* vec, size_t ce, size_t tam, int comparar(const void* a, const void* b))
{
    /** A PARTIR DE ACA TENEMOS 3 SITUACIONES
        -   SI EL PUNTO MEDIO ES IGUAL AL DATO BUSCADO
        -   SI EL PUNTO MEDIO ES > MAYOR AL DATO BUSCADO
        -   SI EL PUNTO MEDIO ES < MENOR AL DATO BUSCADO
    **/
      //low = vec | high = fin
    void* fin=vec+(ce-1)*tam;
    void*pm; //PUNTO MEDIO

    while(vec<=fin)
    {
            pm = vec + ((fin - vec) / (2 * tam)) * tam;
            if(comparar(pm, llave)==0)
            {
                return pm;
            }
            else if(comparar(pm,llave)<0) // clave es mayor al punto medio.
            {
                vec=pm + tam;
            }
            else // clave es menor al punto medio.
            {
               fin = pm - tam;
            }

    }

    return NULL;
}
