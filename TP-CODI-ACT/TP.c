#include "TP.h"
int compEntAsc(void* a, void* b)
{
    return *(int*)a-*(int*)b;
}
int cmpEstProm(void *a, void *b)
{
    float promA = ((tEstudiante*)a)->promedio;
    float promB = ((tEstudiante*)b)->promedio;
    return (promA < promB) - (promA > promB);
}
int compFlotAsc(void* a, void* b)
{
    if((*(float*)a-*(float*)b)>0)
        return 1;
    else if((*(float*)a-*(float*)b<0))
        return -1;
    return 0;

}
int compFlotDesc(void* a, void* b)
{
    if((*(float*)a-*(float*)b)>0)
        return -1;
    else if((*(float*)a-*(float*)b<0))
        return 1;
    return 0;

}

void* leerArchivo(FILE* pf, void* vec, size_t tam)
{
    fread(vec,tam,1,pf);
    return vec;
}
int abrirArchivo(FILE **pf, const char *nombreArch, const char *modoApertura, int mostrarError)
{

    *pf =fopen(nombreArch,modoApertura);
    if(!pf)
    {
        if(mostrarError== 1)
            fprintf(stderr,"Error en la apertura");
        return 0;
    }
    return 1;

}
void eliminar(char* cad, int*ce)
{
    char* fin=cad+(*ce);
    while(cad<fin)
    {
        *cad=*(cad+1);
        cad++;
    }
    *ce-=1;
}
void Normalizar(char* cad,int* ce)
{
    char* fin = cad+(*ce);
    char* ini = cad;

    while(cad<fin)
    {
        if(cad==ini)//SI EL PRIMER CARACTER DE LA CADENA NO ES ESPACIO
        {
            if(!ESESPACIO(*cad))
                *cad = AMAYUSC(*cad);
            else
            {
                eliminar(cad,ce);
                cad--;
                fin--;
            }
        }
        else if(ESLETRA(*cad)&&(!ESESPACIO(*(cad-1))))   //SI EL CARACTER ES UNA LETRA Y EL ANTERIOR NO ES UN ESPACIO
            *cad=AMINUSC(*cad);

        else if(ESESPACIO(*cad)) //SI EL CARACTER ES UN ESPACIO
        {
            if(ESESPACIO(*(cad+1)) || ((cad+1)==fin)) //SI HAY ESPACIO Y EL SIGUIENTE NO ES LETRA O FIN DE CADENA (ES ESPACIO)
            {
                eliminar(cad,ce);
                cad--;
                fin--;
            }
            else if(ESLETRA(*(cad+1)))  //SI EL CARACTER ES UN ESPACIO Y EL SIGUIENTE ES UNA LETRA
                *(cad+1)=AMAYUSC(*(cad+1));
        }

        cad++;
    }

    cad=ini;    // VUELTA AL INICIO
}

///NORMALIZAR DENTRO DEL MERGE PASANDOLE ESTA FUNCION COMO PARAMETRO
void NormalizarEsts(void* data)
{
    tEstudiante* estp=(tEstudiante*)data;
    int ce=strlen(estp->nombreYApellido);

    Normalizar(estp->nombreYApellido,&ce);
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
int compararFechaAsc(void* a, void* b)
{
    tOrden *aa=(tOrden*)a;
    tOrden *bb=(tOrden*)b;
    if((aa->fecha - bb->fecha)>0)
        return 1;
    else if((aa->fecha - bb->fecha)<0)
        return -1;
    return 0;
}
int compararUnsAsc(void* a, void* b)
{
    if(*(long long*)a-*(long long*)b>0)
        return 1;
    else if(*(long long*)a-*(long long*)b<0)
        return -1;
    return 0;
}
void genBinFileName(char* fnames, const char* cad, int cmerge)
{
    char numStr[2]; //string para el char de int + \0
    size_t newSize;
    char* fname;
    int i;
    for(i=1; i<=cmerge; i++)
    {
        sprintf(numStr, "%d", i); // Convert integer to string

        // Mem dinamica para cada nueva cadena creada
        newSize = strlen(cad) + strlen(numStr) + 5; // Base string 11 + char de numeracion (1) + ".dat\0" (5 bits mas)
        fname = (char*)malloc(newSize);
        if (fname == NULL)
        {
            fprintf(stderr, "Error en la asignacion de memoria. \n");
            exit(1);
        }
        strcpy(fname, cad);
        strcat(fname, numStr);
        strcat(fname, ".dat");

        strcpy(fnames,fname);

    }
    free(fname);
}

long long parseFechaEst(void* data)
{
   // long long fecha;
    tEstudiante *ests =(tEstudiante*)data;
    return (long long)ests->fechaDeInscripcion;

}
void mostrarEstudianteYFecha(void* val)
{
    struct tm* pfecha;
    time_t valorf;
    tEstudiante* ests = (tEstudiante*) val;
    valorf=(ests->fechaDeInscripcion)/1000;
    pfecha=gmtime(&valorf);
    printf("%I64u ",ests->dni);
    printf("Anio:%d Mes:%d Dia:%d Hora:%d Min:%d", pfecha->tm_year+1900, pfecha->tm_mon, pfecha->tm_mday, pfecha->tm_hour, pfecha->tm_min);
    printf(" %s  %.2f \n",ests->nombreYApellido, ests->promedio);
}

void gen_sort(void* vec, int n, size_t tam, int cmp(void*a,void*b)) ///PODRIA FUNCIONAR AL REVES? (DESCENDENTE EN VEZ DE ASCENDENTE)
{
    void* pe=vec;
    void* pl=vec;
    void* fin=vec+(tam*n);
    int i, j, k=n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<k; j++)
        {
            if((pl<=fin)&&(cmp(pe,pl)>0))
            {
                intercambio(pe,pl,tam);
            }
            pl+=tam;
        }
        k--;
        pe+=tam;
        pl=pe;
    }

}

void exportarMejores5PromCsv(tEstudiante* datos,unsigned cr)
{
    FILE* pf;
    int i;
    struct tm* pfecha;
    time_t valorf;
    char timeStr[17];

    if(!abrirArchivo(&pf,"MejoresAlumnos.csv","wt",1))
        exit(1);

    fprintf(pf,"DNI;FECHA DE INSC.;NOMBRE Y APELLIDO;PROMEDIO\n");

    for(i=0; i<cr; i++)
    {
        valorf=(datos->fechaDeInscripcion)/1000;
        pfecha=gmtime(&valorf);
        strftime(timeStr, sizeof(timeStr), "%d-%m-%Y %H:%M", pfecha);
        fprintf(pf,"%I64u;%s;%s;%.2f\n",
                datos->dni,
                timeStr,
                datos->nombreYApellido,
                datos->promedio);
        datos++;
    }
    fprintf(stdout, "Los datos fueron guardados en el fichero\n");
    fclose(pf);

}
void get5MejoresPromedios(const char* fname)
{
    FILE* pf;
    tEstudiante est;
    tEstudiante* mejores5Prom=(tEstudiante*)malloc(sizeof(tEstudiante)*5);
    tEstudiante *pMp = mejores5Prom;
    tEstudiante *pIni= mejores5Prom;
    tEstudiante *pFin= mejores5Prom+4;
    int i,cont=0;

    if(!abrirArchivo(&pf,fname,"rb",1))
    {
        free(mejores5Prom);
        exit(1);
    }

    while (fread(&est, sizeof(tEstudiante), 1, pf) == 1)
    {
        if(cont<5)
        {
            *pMp = est;
            pMp++;
            cont++;
        }
        else
        {
            pMp=pIni;
            gen_sort(pMp, 5, sizeof(tEstudiante), cmpEstProm);
            if (est.promedio > pFin->promedio)
                *pFin = est;
        }
    }

    fclose(pf);
    pMp=pIni;
    // Imprime los 5 alumnos con mejores promedios
    exportarMejores5PromCsv(pMp,5);

    printf("Top 5 alumnos con mejores promedios:\n");
    for (i = 0; i < 5; i++)
    {
        mostrarEstudianteYFecha(pMp);
        pMp++;

    }
    free(mejores5Prom);

}
void ordenarPorFecha(char* archNombres,unsigned cmerge,unsigned tam,long long parseFecha(void*))
{

    FILE* pf;
    tOrden* orderToOpen=(tOrden*)malloc(((int)cmerge)*sizeof(tOrden));
    tOrden* pOrd = orderToOpen;
    char* pini_nombres=archNombres;
    tOrden* pini_orden=orderToOpen;


    long long fecha;
    int i,j;
    void *data = malloc(tam);   ///GEN O NO?

    if(!orderToOpen)
        exit(1);
    /// CICLO PARA ORDENAR N CANTIDAD DE ARCHIVOS

    for(i=1; i<=cmerge; i++)
    {

        if(!abrirArchivo(&pf,archNombres,"rb",1))
        {
            free(data);
            exit(1);
        }

        fread(data, tam, 1, pf);        ///CARGA EL REGISTRO

        fecha=parseFecha(data);
        pOrd->fecha=fecha;
        strcpy(pOrd->fname, archNombres);

        /// ORDENA EL VECTOR DE ORDEN
        gen_sort(orderToOpen,i,sizeof(tOrden),compararFechaAsc);   /// AÑADIR LA FUNC DE COMPARACION A LA FUNCION


        pOrd++;
        archNombres++;
        fclose(pf);
    }

    pOrd=pini_orden;
    archNombres=pini_nombres;

    for(j=0;j<cmerge;i++)
    {
        strcpy(archNombres,pOrd->fname);
        pOrd++;
        archNombres++;
    }

    free(data);
    free(orderToOpen);
}

void mergeGen(char* archNombres,const char* archMerge,unsigned cmerge, unsigned tam, void accion(void* val)) ///ORDENAMIENTO Y MERGE. 1 SOLO arch binario con los 5 archivos dentro.
{
    ///PUEDE TENER UN PARAMETRO PARA LA CANT DE ARCHIVOS A MERGEAR
    int i;
    FILE *pf;
    FILE *p_merge;
    void *data = malloc(tam);


    ///ESCRIBIR TODO DE UNA
    if(!abrirArchivo(&p_merge,archMerge,"wb",1)) /// REEMPLAZAR POR archMerge
    {
        free(data);
        exit(1);
    }
    for(i=0; i<cmerge; i++)
    {
        if(!abrirArchivo(&pf,archNombres,"rb",1))
        {
            free(data);
            exit(1);
        }
        printf("%s\n", archNombres);

        fread(data, tam, 1, pf);
        while(!feof(pf))
        {
            accion(data);
            fwrite(data,tam,1,p_merge);
            mostrarEstudianteYFecha(data);       ///MUESTRA
            fread(data, tam, 1, pf);
        }

        archNombres++;
        fclose(pf);
    }

    fclose(p_merge);
    free(data);

}
