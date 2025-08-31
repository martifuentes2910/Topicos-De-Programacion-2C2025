#include "TDAVector.h"

/// TDA VECTOR CON MEM DINAMICA
int estaLleno(Vector* vec)      // 0/false si no esta lleno, 1/true si esta lleno (ce==max)
{
    return vec->ce==vec->maxi;

}
int estaVacio(Vector* vec)      // 0/false si tiene algun elemento, 1/true si esta vacio (ce==0)
{
    return vec->ce==0;
}
void m_memmove(void* a,void* b, size_t n)
{
    char aux;
    for(int i=0;i<n;i++)
    {
        aux=*(char*)a;
        *(char*)a=*(char*)b;
        *(char*)b=aux;
        a++;
        b++;
    }
}


int crearVector(Vector* vec,int ce,unsigned tam)    /// ES UN CONSTRUCTOR
{
    vec->vec = malloc(ce*tam);
    if(!vec->vec)
        return 0;
    vec->maxi = ce;
    vec->ce=0;
    vec->tam=tam;

    return 1;

}
int destruirVectorEst(Vector* vec)
{
    vec->vec=NULL;
    vec->ce=0;
    vec->maxi=0;
    return 1;

}
int destruirVectorDin(Vector* vec)
{
    // vec->vec=NULL;
    free(vec->vec);
    return 1;
}

int cargarVectorOrdenado(Vector* vec, void* dato, int cmp(const void*,const void*))
{
    void* ini=vec->vec;
    void* fin=vec->vec+(vec->ce-1)*vec->tam;

    if(vec->ce == vec->maxi && cmp(dato,fin)>0)
        return 0;

    while(ini <=fin && cmp(dato,ini)>0)
        ini+=vec->tam;

    memmove(ini+vec->tam,ini,(fin - ini) + vec->tam);
    memcpy(ini,dato,vec->tam);
    vec->ce++;
    return 1;
}
int eliminarElemento(Vector* vec, void* elemento,int cmp(const void*, const void*))
{
    int j = 0;
    void* ini;
    void* pvec = vec->vec;
    void* fin=vec->vec + (vec->ce * vec->tam);

    if(vec->ce == 0)
        return 0;

    for (ini=vec->vec; ini < fin; ini+=vec->tam)
    {
        if (cmp(ini,elemento)==0)       //mientras no sea igual al elemento todo sigue su curso normal
        {
            memcpy(pvec,ini,vec->tam);
            pvec+=vec->tam;                        //cuando el elemento es el buscado, la proxima vez que el elemento
            j++;                //no es el buscado se reasigna a la posicion de j que quedo guardada de la ultima vez
        }                       //que se cumplio la condicion
    }

    vec->ce = j;
    return 1;
}
int cargarVector(Vector* vec,void* dato)
{
    void* ultPos = vec->vec + (vec->ce * vec->tam);
    if(vec->maxi == vec->ce)
        return 0;
    memcpy(ultPos,dato,vec->tam);
    vec->ce++;
    return 1;
}
void mostrarInt(const void* dato)
{
    printf("%d\n",*(int*)dato);
}
void recorrerVector(Vector* vec,void accion(const void*))
{
    void* ini = vec->vec;
    void* fin = vec->vec + (vec->ce * vec->tam);

    while(ini<fin)
    {
        accion(ini);
        ini+=vec->tam;
    }
    //otra forma mas piola
    //    for(ini=vec->vec;ini<fin;ini+=vec->tam)
//        accion(ini);

}
