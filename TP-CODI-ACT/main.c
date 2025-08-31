
#include "TP.h"

//unsigned long long: 8 bytes
//char: 30
//

int main()
{
//    tEstudiante vec[60];
//    unsigned long long prueba[5];
//    unsigned long long* pp=prueba;
//    unsigned long long* pin=prueba;
//    struct tm fechabien[60];
//    struct tm* pfecha=fechabien;
//    struct tm* inif=fechabien;
//    time_t valorf;
//    tEstudiante* pvec=vec;
//    tEstudiante* ini=vec;
//    int band1=0;
    char nombre[12]="estudiantes";
    char archAMergear[19]="ListadoAlumnos.dat";
    char vecNombres[19][TAM];
//    char ruta1[]="estudiantes1.dat";
//    char ruta2[]="estudiantes2.dat";
//    char ruta3[]="estudiantes3.dat";
//    char ruta4[]="estudiantes4.dat";
//    char ruta5[]="estudiantes5.dat";
//    int reg_MAX = 10;
//    int i;
   genBinFileName(vecNombres,nombre,TAM);
   ordenarPorFecha(vecNombres,TAM,sizeof(tEstudiante),parseFechaEst);
    mergeGen(vecNombres,archAMergear,TAM,sizeof(tEstudiante),NormalizarEsts);
    /get5MejoresPromedios(archAMergear);
//    for (i = 1; i <= ce; i++)
//    {
//        fname = concatArchNum(cad, i);  //Retorna el puntero al nombre del archivo a abrir
//        printf("%s\n", fname);
//        free(fname); // Free al puntero creado en funcion
//    }
//
//    FILE* pf=fopen(ruta1,"rb");
//
//    if(!pf)
//    {
//        exit(1);
//    }
//    //printf("Archivo 1:\n");
//    while(fread(pvec,sizeof(tEstudiante),1,pf))
//    {
//        pvec->nombreYApellido[sizeof(pvec->nombreYApellido)-1]='\0';
//        if(band1==0)
//        {
//            *pp=pvec->fechaDeInscripcion;
//            pp++;
//            band1++;
//        }
//        valorf=(pvec->fechaDeInscripcion)/1000;
//        pfecha=gmtime(&valorf);
//        //printf("Anio:%d Mes:%d Dia:%d Hora:%d Min:%d\n", pfecha->tm_year+1900, pfecha->tm_mon, pfecha->tm_mday, pfecha->tm_hour, pfecha->tm_min);
//        pvec++;
//        pfecha++;
//        ce++;
//    }
//    fclose(pf);
//
//    band1=0;
//
//    pf=fopen(ruta2,"rb");
//    //printf("Archivo 2:");
//    while(fread(pvec,sizeof(tEstudiante),1,pf))
//    {
//        pvec->nombreYApellido[sizeof(pvec->nombreYApellido)-1]='\0';
//        if(band1==0)
//        {
//            *pp=pvec->fechaDeInscripcion;
//            pp++;
//            band1++;
//        }
//        valorf=(pvec->fechaDeInscripcion)/1000;
//        pfecha=gmtime(&valorf);
//        //printf("Anio:%d Mes:%d Dia:%d Hora:%d Min:%d\n", pfecha->tm_year+1900, pfecha->tm_mon, pfecha->tm_mday, pfecha->tm_hour, pfecha->tm_min);
//        pvec++;
//        pfecha++;
//        ce++;
//    }
//    fclose(pf);
//
//    band1=0;
//
//    pf=fopen(ruta3,"rb");
//   // printf("Archivo 3:");
//    while(fread(pvec,sizeof(tEstudiante),1,pf))
//    {
//        pvec->nombreYApellido[sizeof(pvec->nombreYApellido)-1]='\0';
//        if(band1==0)
//        {
//            *pp=pvec->fechaDeInscripcion;
//            pp++;
//            band1++;
//        }
//        valorf=(pvec->fechaDeInscripcion)/1000;
//        pfecha=gmtime(&valorf);
//        //printf("Anio:%d Mes:%d Dia:%d Hora:%d Min:%d\n", pfecha->tm_year+1900, pfecha->tm_mon, pfecha->tm_mday, pfecha->tm_hour, pfecha->tm_min);
//        pvec++;
//        pfecha++;
//        ce++;
//    }
//    fclose(pf);
//
//    band1=0;
//
//    pf=fopen(ruta4,"rb");
//    //printf("Archivo 4:");
//    while(fread(pvec,sizeof(tEstudiante),1,pf))
//    {
//        pvec->nombreYApellido[sizeof(pvec->nombreYApellido)-1]='\0';
//        valorf=(pvec->fechaDeInscripcion)/1000;
//        if(band1==0)
//        {
//            *pp=pvec->fechaDeInscripcion;
//            pp++;
//            band1++;
//        }
//        pfecha=gmtime(&valorf);
//        //printf("Anio:%d Mes:%d Dia:%d Hora:%d Min:%d\n", pfecha->tm_year+1900, pfecha->tm_mon, pfecha->tm_mday, pfecha->tm_hour, pfecha->tm_min);
//        pvec++;
//        pfecha++;
//        ce++;
//    }
//    fclose(pf);
//
//    band1=0;
//
//    pf=fopen(ruta5,"rb");
//    //printf("Archivo 5:");
//    while(fread(pvec,sizeof(tEstudiante),1,pf))
//    {
//        pvec->nombreYApellido[sizeof(pvec->nombreYApellido)-1]='\0';
//        if(band1==0)
//        {
//            *pp=pvec->fechaDeInscripcion;
//            pp++;
//            band1++;
//        }
//        valorf=(pvec->fechaDeInscripcion)/1000;
//        pfecha=gmtime(&valorf);
//        //printf("Anio:%d Mes:%d Dia:%d Hora:%d Min:%d\n", pfecha->tm_year+1900, pfecha->tm_mon, pfecha->tm_mday, pfecha->tm_hour, pfecha->tm_min);
//        pfecha++;
//        pvec++;
//        ce++;
//    }
//    fclose(pf);
//
//    pvec=ini;
//    pfecha=inif;
//    pp=pin;
//
//    gen_sort(pp,5,compararUnsAsc,sizeof(unsigned long long));
//
//    for(int i=0;i<5;i++)
//    {
//        valorf=(*pp)/1000;
//        pfecha=gmtime(&valorf);
//        printf("Anio:%d Mes:%d Dia:%d Hora:%d Min:%d\n", pfecha->tm_year+1900, pfecha->tm_mon, pfecha->tm_mday, pfecha->tm_hour, pfecha->tm_min);
//        pfecha++;
//        pp++;
//    }
    return 0;
}
