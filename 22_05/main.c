#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
char* concatArchNum(const char* cad, int i);
void* m_memmove(void *s1, const void *s2, size_t n)
{
    unsigned char temp[n];


    for (size_t i = 0; i < n; i++)
    {
        temp[i] = ((unsigned char *)s2)[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        ((unsigned char *)s1)[i] = temp[i];
    }

    return s1;
}

void* m_memcpy(void *s1, const void *s2, size_t n)
{
    unsigned char *d = s1;
    const unsigned char *s = s2;

    for (size_t i = 0; i < n; i++)
    {
        d[i] = s[i];
    }

    return s1;
}

void intercambio(void *a, void *b, size_t size)
{
    unsigned char temp[size];
    m_memcpy(temp, a, size);
    m_memcpy(a, b, size);
    m_memcpy(b, temp, size);
}

void mostrarEntero(void *d)
{
    printf("%d\n",*(int*)d);
}

void mostrarFlotante(void *d)
{
    printf("%f\n",*(float*)d);
}

void duplicarEntero(void* d)
{
    int * val = (int*)d;
    (*val) = (*val) * 2;
}

void* recorrervector(void* vec,unsigned ce,unsigned tam,void accion(void*))//map
{
    int i=0;
    void* ini = vec;
    for(i=0; i<ce; i++)
    {
        accion(vec);
        vec+=tam;
    }

    return ini;
}

void* map(void* vec,unsigned ce,unsigned tam,void accion(void*))//map
{
    int i=0;
    void * ini = vec;
    for(i=0; i<ce; i++)
    {
        accion(vec);
        vec+=tam;
    }
    return ini;
}

bool mayorque3(void *d)
{
    return ((*(int*)d > 3) ? true : false );

}
bool distintode3(void *d)
{
    return ((*(int*)d != 3) ? true : false );

}
void* filter(void* vec,int* ce,unsigned tam,bool ffiltro(void*))//map
{

    void * pl = vec;
    void * pe = vec;
    int i=0;
    unsigned ceInterna=0;

    for(i=0; i<*ce; i++)
    {

        if(ffiltro(pl))
        {
            if(pe!=pl)
            {
                m_memcpy(pe,pl,tam);
            }
            pe+=tam;
            ceInterna++;
        }
        pl+=tam;
    }

    *ce=ceInterna;

    return vec;
}

int cmpEntAsc(const void *a, const void *b)
{
    return (*((int*)a) - *((int*)b));
}

void* buscarmenor(const void* vec,size_t ce,size_t tam,int (cmp) (const void *a, const void *b))
{
    int i=0,r=0;
    void* menor = (void*)vec;

    for(i=0; i<ce; i++)
    {
        vec+=tam;
        if(cmpEntAsc(menor,vec)>0)
        {
            menor = (void*)vec;
        }
    }
    return menor;
}

void adseleccion(void* vec, size_t ce, size_t tam,int (cmp)(const void *a, const void *b))
{
    void* menor;
    int i=0;

    for(i=0; i<ce-1; i++)
    {
        menor = buscarmenor(vec,ce-i,tam,cmpEntAsc);

        if(menor!=vec)
        {
            intercambio(vec,menor,tam);
        }
        vec+=tam;
    }
}

char* concatArchNum(const char* cad, int i)
{
    char numStr[2]; //string para el char de int + \0
    sprintf(numStr, "%d", i); // Convert integer to string

    // Mem dinamica para cada nueva cadena creada
    size_t newSize = strlen(cad) + strlen(numStr) + 5; // Base string 11 + char de numeracion (1) + ".dat\0" (5 bits mas)
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


int main()
{
    char cad[12] = "estudiantes";
    int ce = 5;
    int i;
    char *fname;

    for (i = 1; i <= ce; i++)
    {
        fname = concatArchNum(cad, i);  //Retorna el puntero al nombre del archivo a abrir
        printf("%s\n", fname);

    }
 free(fname); // Free al puntero creado en funcion
    return 0;
    /*Clase 7
    char mat[6]="ho2a";
    char mat2[6];

    m_memcpy(mat2,mat,6);

    printf("%s\n",mat);
    printf("%s",mat2);

    // int mat[6]= {1,3,3,4,3,6};
    //Uso de la funcion map
    //  map(mat,6, sizeof(float),duplicarEntero);
    //  map(mat,6, sizeof(float),mostrarEntero);

    // int ce=6;

    // int* pv = filter(mat,&ce,sizeof(int),distintode3);

    //map(pv,ce,sizeof(int),mostrarEntero);
    */

//    int mat[6]= {3,5,4,16,8,7};
//
//  //qsort(mat,6,sizeof(int),cmpEntAsc);
//   adseleccion(mat,6,sizeof(int),cmpEntAsc);
//   map(mat,6,sizeof(int),mostrarEntero);


}
