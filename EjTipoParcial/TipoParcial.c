#include "TipoParcial.h"

int _strcmp(const char* cad1, const char* cad2){
while(*cad1 && *cad1 == *cad2)
{
    cad1++;
    cad2++;
}
return *(unsigned char*)cad1 - *(unsigned char*)cad2;
}

void *mem_cpy(void *dest,const void*orig,size_t cant)
{
    void *ini=dest;
    while(cant--)
    {
        *((char *)dest) = *((char *)orig);
        dest++;
        orig++;
    }
    return ini;
}

void *mem_move(void *dest, const void *orig,size_t cant){

 void * ini=dest;
    if(orig >= dest){

        while(cant--)
        {
            *((char *)dest) = *((char *)orig);
            dest++;
        orig++;
        }

    }
    else{

        dest +=cant -1;
        orig +=cant -1;
        while(cant--)
        {
            *((char *)dest) = *((char *)orig);
            dest--;
            orig--;
        }

    }
    return ini;
}

int cmpAscInt(const void* a,const void* b)
{

    return *((int*)a) - *((int*)b);

}
char cmpAscChar(const void* a,const void* b)
{

    return *((char*)a) - *((char*)b);

}


void *_bsearch(const void* clave,
               void* vec,
               size_t ce,
               size_t tam,
               int comparar(const void* a, const void* b))
{

    /** A PARTIR DE ACA TENEMOS 3 SITUACIONES
            -   SI EL PUNTO MEDIO ES IGUAL AL DATO BUSCADO
            -   SI EL PUNTO MEDIO ES > MAYOR AL DATO BUSCADO
            -   SI EL PUNTO MEDIO ES < MENOR AL DATO BUSCADO
        **/
    void *high = vec+(ce-1)*tam;
    void *pm;
    while(vec<=high)
    {
        pm= vec + ((high-vec) /(2*tam)) *tam;
        if(comparar(pm,clave)==0)
            return (void*)pm;

        else if(comparar(pm,clave)<0)
            vec = pm + tam;         // clave es mayor al punto medio.

        else
            high= pm - tam;         // clave es menor al punto medio.

    }
    return (void*)NULL;
}


void MatrizZ(int mat[][100], int cf, int cc)
{
/// i MUEVE LA FILA. j MUEVE LA COLUMNA
    if((cf-1)!=cc && (cc-1)!=cf && cc!=cf)
        printf("Matriz invalida");
    else
    {
        int i=0,j=0;
        for(j=0; j<cc; j++)
        {
            printf("%d ",mat[0][j]);

        }
        int minDim = cf < cc ? cf : cc;         /// ELIJE CUAL SERA EL TOPE DE LA DIAGONAL
        for (i = 1; i < minDim - 1; i++)
        {
            printf("%d ",mat[i][cc-i-1]);   /// ULTIMA COL (5) - i (1,2..) -1 (por el indice de matriz)
        }
        if (cf > 1)         ///HACER ESTE PASO SOLO SI HAY MAS DE UNA FILA
        {
            for(j=0; j<cc; j++)
            {
                printf("%d ",mat[cf-1][j]); ///LA ULTIMA FILA (5) - 1 (indice matriz) ---> se reinicia j a 0 y comienza de nuevo a sumar

            }
        }
    }


}


int proxPal(char* cad)
{
    char *ini=cad;
    int le=0, esp=0;


    while(ESLETRA(*cad))
    {
        le++;
        cad++;
    }
    while(ESESPACIO(*cad)&&(*cad!='\0'))
    {
        esp++;
        cad++;
    }
    cad=ini;
    return le+esp;

}
char *mystrchr(const char* grupo, int c)
{
    while(*grupo && *(char*)grupo!=(char)c)
        grupo++;

    return *(char*)grupo == (char)c? (char*)grupo:(char*)NULL;
}
size_t mystrlen(const char* cad)
{
    int len=0;
    while(*cad++)
        len++;

    return len;
}

char desplazamiento(char c, unsigned desp, char* grupo)
{
    char minus=c;
    char* pc=strchr(grupo,AMINUSCULA(minus)); ///PUNTERO A LA CONSONANTE DENTRO DEL GRUPO
    int len=strlen(grupo);
    char* fin=grupo+len;    ///FIN DEL GRUPO



    if(!pc)      /// DE CASUALIDAD NO ENCUENTRA LA CONSONANTE EN EL GRUPO
        return c;
    else
    {
        while(desp>0)
        {
            pc+=1;          ///EL PUNTERO DE CONSONANTES AL GRUPO SE VA MOVIENDO DE A +1
            desp--;         ///DISMINUYE EL DESPLAZAMIENTO (FUNCIONA COMO EL I EN LA ITERACION)
            if(pc==fin)
                pc=grupo;        ///SI P YA ES z SE SITUA EL PUNTERO AL COMIENZO DEL GRUPO

        }
        if((c >= 'A') && (c <= 'Z'))  ///SI C ES MAYUSCULA
            AMAYUSCULA(*pc);

        return *pc;         ///DEVUELVO EL VALOR DEL PUNTERO DE CONSONANTES (OSEA, LA CONSONANTE NUEVA) PARA SU REEMPLAZO EN LA FUNCION
    }
}
void CifradoCesarConsonantico(char* cad, char *cadconsonantes)
{
    char* ini=cad;
    int desp=0;
    desp=(int)(*cad-'0');        /// EL PRIMER CHAR ES EL NUMERO DE DESP. LO CASTEAMOS A INT Y ALMACENAMOS
    printf("%c\n", *cad);

    while(*cad)
    {
        if(ESLETRA(*cad) && !ESVOCAL(*cad))
        {
            *cad=desplazamiento(*cad,desp,cadconsonantes);
            cad++;
        }
        else
            cad++;
    }
    cad=ini;
    printf("%s", cad);

}
void leerArchivo(char* fname, char* cadconsonantes)
{
    /// ALMACENAMOS EL DESP EN INT

    //char* fin;
    char receptor[100];
    char*cad=receptor;

    char ruta2[]="parcialofus.txt";

    FILE* pf;
    FILE* pf2;

    pf=fopen(fname,"rt");
    if(!pf)
    {
        exit(1);
    }
    pf2=fopen(ruta2,"wt");
    if(!pf2)
    {
        exit(1);
    }

    fgets(cad,50,pf);           /// LEE UN REGISTRO DEL ARCHIVO DONDE ESTA LA CADENA (ES SOLO 1 REGISTRO)
    CifradoCesarConsonantico(cad,cadconsonantes);
    fputs(cad,pf2);     ///ESCRIBO EN EL NUEVO ARCHIVO LA CADENA RESULTANTE

    fclose(pf);
    fclose(pf2);

}
