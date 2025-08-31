#include "Archivos.h"

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
/// EJEMPLO ARCHIVOS BINARIOS CON T_EMPLEADOS ////////////////////////////
int crearArchivoEmp(char* nombreArchivo)
{
    tEmpleado vecEmpleados[]=
    {
        {44444444,"Persona Cuatro",'A',{1,4,2004},44000.4F},
        {22222222,"Persona Dos",'B',{1,2,2002},22000.2F},
        {33333333,"Persona Tres",'B',{1,3,2003},33000.3F},
        {55555555,"Persona Cinco",'A',{1,5,2005},55000.5F},
        {11111111,"Persona Uno",'C',{1,1,2001},111000.1F},
    };
    FILE *pf =fopen(nombreArchivo,"wb");
    if(pf)
    {
        fwrite(vecEmpleados,sizeof(tEmpleado),5,pf);
        fclose(pf);
        return 0;
    }
    return -2;

}

int buscarPorDni(FILE *pf,tEmpleado *pe)
{
    // tEmpleado aBuscar = pe->dni;
    tEmpleado emp;

    fread(&emp,sizeof(tEmpleado),1,pf);
    while(!feof(pf) && emp.dni!=pe->dni)        // CON ARCHIVO ORDENADO: && emp.dni > pe->dni
    {
        fread(&emp,sizeof(tEmpleado),1,pf);
    }
    if(emp.dni==pe->dni)
    {
        fwrite(&emp,sizeof(tEmpleado),1,pf);
//        fwrite(&emp.apyn,sizeof(emp.apyn),1,pf);
//        fwrite(&emp.categoria,sizeof(emp.categoria),1,pf);
//        fwrite(&emp.fecIngreso,sizeof(tFecha),1,pf);
//        fwrite(&emp.sueldo,sizeof(emp.sueldo),1,pf);
//        leerYmostrarArchivo("Empleados.dat");
        return 1;
    }
    return 0;

}
int leerYmostrarArchivo(char* nombreArchivo)
{
    tEmpleado emp;
    FILE *pf= fopen(nombreArchivo,"rb");
    if(!pf)
        return -1;
    mostrarEmpleado(NULL);
    fread(&emp,sizeof(tEmpleado),1,pf);
    while(!feof(pf))
    {
        mostrarEmpleado(&emp);
        fread(&emp,sizeof(tEmpleado),1,pf);
    }
    fclose(pf);
    return 0;
}
void mostrarEmpleado(const tEmpleado *emp)
{
    if(!emp)
    {
        printf("DNI      NOMBRE Y APELLIDO                  CAT FEC. ING     SUELDO    \n");
        printf("-------- ---------------------------------- --- ------------ ----------\n");
        return;
    }
    printf("%08ld %-*.*s %c  %02d/%02d/%04d %10.2f\n", emp->dni,
           (int)sizeof(emp->apyn)-1,
           (int)sizeof(emp->apyn)-1,
           emp->apyn,
           emp->categoria,
           emp->fecIngreso.dia,
           emp->fecIngreso.mes,
           emp->fecIngreso.anio,
           emp->sueldo);

}
/// EJEMPLO ARCHIVOS DE TEXTO //////////////////////
/**
    FUNCIONES PARA ARCHIVOS
    =======================
    GENERALES: fopen / fclose / remove / rewind

    BINARIOS / TEXTO
    ========   =====
    fread    | fputs
    fwrite   | fgets --> recibe cad de LONG VARIABLE
    fseek    | fprintf
    ftell    | fscanf --> ASIGNA DATOS (LOS FORMATEA) DESDE UN ARCHIVO DE TEXTO
    feof     | sprintf
    fflush   | sscanf --> recibe cad de LONG FIJA / ASIGNA DATOS (LOS FORMATEA) DESDE UN ARRAY

    FUNCIONES PARA CADENAS DE FORMATO CON ARRAYS (crear cadenas de texto a partir de variables)
    ============================================
    - sprintf: Esta función es equivalente a fprintf, excepto que el argumento cadena especifica un array en el
        cual la salida generada es para ser escrita, en vez de un stream. Un carácter nulo es escrito al final
        de los caracteres escritos; no es contado como parte de la suma retornada. El comportamiento
        acerca de copiando entre objetos que se superponen no está definido.

    - sscanf: Esta función es equivalente a fscanf, excepto que el argumento cadena especifica un array desde
        el cual la entrada es obtenida, en vez de un stream. Llegando al final de la cadena es equivalente a
        encontrar un final de fichero (EOF) en la función fscanf. El comportamiento acerca de copiando
        entre objetos que se superponen no está definido.

    FUNCIONES PARA CADENAS DE FORMATO CON ARCHIVOS DE TEXTO
    =======================================================
    - fputs: Esta función escribe la cadena apuntada por cadena al stream apuntado por stream. El
        carácter nulo no es escrito.
        EJ: fputs( "Esto es un ejemplo usando '\fputs\'\n", fichero )

    - fgets: Esta función lee como máximo uno menos que el número de caracteres indicado por n
        desde el stream apuntado por stream al array apuntado por cadena. Ningún carácter
        adicional es leído después del carácter de nueva línea (el cual es retenido) o después de
        un final de fichero (EOF). Un carácter nulo es escrito inmediatamente después del
        último carácter leído en el array.
        EJ: fgets(linea, 81, fichero)

    - fprintf: Esta función envía datos al stream apuntado por stream, bajo el control de la cadena apuntada por formato
        que especifica cómo los argumentos posteriores son convertidos para la salida.
        EJ: fprintf( fichero, "%d\t%d\t%d\t%d\n", i, i*i, i*i*i, i*i*i*i )

    - fscanf: Esta función recibe datos del stream apuntado por stream, bajo el control de la cadena apuntada por
        formato que especifica las secuencias de entrada permitadas y cómo han de ser convertidas para la
        asignación. Si hay argumentos insuficientes para el formato, el comportamiento no está definido.
        EJ: fscanf( fichero, "%d\t%d\t%d\t%d\n", &x1, &x2, &x3, &x4 );


    --------
    fseek(pf,0L,SEEK_END);
    ce = ftell(pf) / sizeof(tDato); --> Calcula la cantidad de registros de un archivo, util para cuando no sabemos cuantos tiene
    rewind(pf) --> vuelve el archivo al principio

    FUNCIONES PARA ARCHIVOS DE TEXTO
    ================================
    LECTURA:
    - char *fgets(char* cad, size_t longitud,FILE *fp): Para leer caracteres desde un flujo conectado a un arch de texto se utiliza fgets.
        La funcion lee caracteres y los guarda en cad hasta encontrar el char de NUEVA LINEA (\n) o hasta leer longitud-1 caracteres,
        lo que ocurra primero, poniendo a continuacion el ultimo leido del caracter nulo ('\0).
        !!!! SI SE LEYO EL CHAR (\n) SE GUARDA EN LA CADENA cad.
    ESCRITURA:
    - int fprintf(FILE *fp, const char *formato,...): Retorna el numero de caracteres realmente escritos.
        En caso de un error, retornara un numero negativo.

    ORGANIZACION DE LOS DATOS EN ARCHIVOS DE TEXTO
    ==============================================
    LONGITUD VARIABLE: Se separan los campos por un caracter particular el cual se determina en el momento del diseño.
    LONGITUD FIJA: La longitud de cada campo se encuentra definida con antelacion y se respeta, INCLUSO AUNQUE SOBRE ESPACIO para
    almacenar el dato. En este caso SE ADICIONARAN CARACTERES PARA COMPLETAR LA LONGITUD TOTAL DEL CAMPO
**/
void actualizarPorcentajeSueldo(FILE *pf, float porcentaje, int *nroRegistros) ///ACTUALIZA UN ARCHIVO BINARIO !!!!
{
    tEmpleado emp;

    long posIni = ftell(pf);
    *nroRegistros = 0;
    rewind(pf);

    fread(&emp,sizeof(tEmpleado),1,pf);
    while(!feof(pf))
    {
        (*nroRegistros)++;
        emp.sueldo *= porcentaje;
        fseek(pf, -(long)sizeof(tEmpleado),SEEK_CUR);
        fwrite(&emp,sizeof(tEmpleado),1,pf);
        fseek(pf,0L,SEEK_CUR);      // se mantiene la posicion actual
        fread(&emp,sizeof(tEmpleado),1,pf);
    }
    fseek(pf,posIni,SEEK_SET);
}
void trozarCamposLongitudFija(tEmpleado *d,char *s) ///LEEMOS Y TROZAMOS EL ARCH DE ATRAS PARA ADELANTE <-----
{
    char *aux = s + 8+ 35 + 1 + 8 + 9; // 1)  SUMO LA LONGITUD (CARACTERES) QUE CONTIENE LA LINEA (EN ESTE CASO 61 TOTAL)
    *aux = '\0';    // 2) LO REEMPLAZO CON EL FIN DE CADENA
    ///SUELDO
    aux -= 9; //TAM_SUELDO (LE RESTAMOS)
    sscanf(aux,"%f",&d->sueldo);
    *aux = '\0';

    ///FECHA DE INGRESO
    aux -= 8;
    sscanf(aux,"%d/%d/%d",
           &d->fecIngreso.dia,
           &d->fecIngreso.mes,
           &d->fecIngreso.anio);
   *aux = '\0';
   ///CATEGORIA
   aux -= 1;
   sscanf(aux,"%c",&d->categoria);
   *aux= '\0';

   ///NOMBRE Y APELLIDO
   aux -= 35;
   strcpy(d->apyn,aux);
   *aux= '\0';

   ///DNI
   aux -= 8;
   sscanf(aux,"%ld",&d->dni);     //LLEGAMOS AL ULTIMO CAMPO, NO HACE FALTA VOLVER A BUSCAR Y REEMPLAZAR
   *aux= '\0';

}
void trozarCamposLongitudVariable(tEmpleado *d,char *s) ///LEEMOS Y TROZAMOS EL ARCH DE ATRAS PARA ADELANTE <-----
{
    char *aux = strchr(s,'\n'); // 1)  BUSCO EL ULTIMO CARACTER (EL SALTO DE LINEA)
    *aux = '\0';    // 2) LO REEMPLAZO CON EL FIN DE CADENA
    ///SUELDO
    aux = _strrchrR(s,';');
    /**
        Utilizar una de las dos opciones
        sscanf(aux,"%;f",&d->sueldo);
    **/
    sscanf(aux+1,"%f",&d->sueldo);
    *aux = '\0';

    ///FECHA DE INGRESO
    aux = _strrchrR(s,';');
    sscanf(aux+1,"%d/%d/%d",
           &d->fecIngreso.dia,
           &d->fecIngreso.mes,
           &d->fecIngreso.anio);
   *aux = '\0';
   ///CATEGORIA
   aux = _strrchrR(s,';');
   sscanf(aux+1,"%c",&d->categoria);
   *aux= '\0';

   ///NOMBRE Y APELLIDO
   aux = _strrchrR(s,';');
   strcpy(d->apyn,aux+1);
   *aux= '\0';

   ///DNI
   sscanf(s,"%ld",&d->dni);     //LLEGAMOS AL ULTIMO CAMPO, NO HACE FALTA VOLVER A BUSCAR Y REEMPLAZAR
   //DIRECTAMENTE LEE DESDE EL INICIO DE LA LINEA (SOLO QUEDA EL PRIMER CAMPO DENTRO DE LA CADENA)
}
/// ARCH TXT LONGITUD VARIABLE
int crearArchivoDeTextoLV(char *nombreArchOrigen, char *nombreArchDestino)
{
    tEmpleado emp;
    FILE *fpBin, *fpTxtLV;

    if((fpBin=fopen(nombreArchOrigen,"rb"))==NULL)
        return -1;
    if((fpTxtLV=fopen(nombreArchDestino,"wt"))==NULL)
        return -2;
    /// CANT DE REGISTROS DEL BINARIO
    fseek(fpBin,0L,SEEK_END);
    int cr = ftell(fpBin) / sizeof(tEmpleado);
    rewind(fpBin);
    ///

    fread(&emp,sizeof(tEmpleado),1,fpBin);
    for(int i=0; i<cr; i++)
    {
        fprintf(fpTxtLV,"%ld;%s;%c;%d/%d/%d;%.2f\n",
                emp.dni,
                emp.apyn,
                emp.categoria,
                emp.fecIngreso.dia,
                emp.fecIngreso.mes,
                emp.fecIngreso.anio,
                emp.sueldo);
        fread(&emp,sizeof(tEmpleado),1,fpBin);
    }
    fclose(fpBin);
    fclose(fpTxtLV);

    return 0;

}
/// ARCH TXT LONGITUD FIJA
int crearArchivoDeTextoLF(char *nombreArchOrigen, char *nombreArchDestino)
{
    tEmpleado emp;
    FILE *fpBin, *fpTxtLV;

    if((fpBin=fopen(nombreArchOrigen,"rb"))==NULL)
        return -1;
    if((fpTxtLV=fopen(nombreArchDestino,"wt"))==NULL)
        return -2;
//    /// CANT DE REGISTROS DEL BINARIO
//    fseek(fpBin,0L,SEEK_END);
//    int cr = ftell(fpBin) / sizeof(tEmpleado);
//    rewind(fpBin);
//    ///

    fread(&emp,sizeof(tEmpleado),1,fpBin);
    while(!feof(fpBin))
    {
        fprintf(fpTxtLV,"%08ld%-*.*s%c%02d%02d%04d%9.2f\n",
                emp.dni,
                (int)sizeof(emp.apyn)-1,
                (int)sizeof(emp.apyn)-1,
                emp.apyn,
                emp.categoria,
                emp.fecIngreso.dia,
                emp.fecIngreso.mes,
                emp.fecIngreso.anio,
                emp.sueldo);
        fread(&emp,sizeof(tEmpleado),1,fpBin);
    }
    fclose(fpBin);
    fclose(fpTxtLV);

    return 0;

}
int leerYmostrarArchivoDeTexto(char *nombreArchivo)
{
    char cad[100];
    FILE *pf =fopen(nombreArchivo,"rt");
    if(!pf)
        return -1;

    while(fgets(cad,sizeof(cad),pf))    /// A DIFERENCIA DE LOS ARCHS BINARIO, NO REALIZA LECTURA PREVIA
        printf("%s\n",cad);

    fclose(pf);
    return 0;
}
/// LETS COME BACK LATER!!
//int crearArchivoEmp(const char* fname, void* emps)
//{
//    int i;
//    FILE*pf;
//
//    //void* pemps=data;
//    pf=fopen(fname, "wb");
//    if(!pf)
//    {
//        return -1;
//    }
//     for(i=0; i<sizeof(emps)/sizeof(tEmpleado); i++)
//    {
//        fwrite(emps, sizeof(*emps), 1, pf);
//        emps++;
//    }
//    fclose(pf);
//    return 1;
//}

int crearArchivo(const char* fname, void* data,unsigned tam,unsigned sizedata)
{
    int i;
    FILE*pf;

    pf=fopen(fname, "wb");
    if(!pf)
    {
        return -1;
    }

    for(i=0; i<sizedata/tam; i++)
    {
        fwrite(data,tam,1, pf);
        data+=tam;
    }
    fclose(pf);
    return 1;
}

//void mostrarEmpleado(void* val)
//{
//    tEmpleado* emp =(tEmpleado*)val;
//    printf("%d | %s | %5.2f\n",emp->dni, emp->nya, emp->sueldo);
//}
int recorrerArch(const char* fname,unsigned tam, void accion(void* val))
{
    FILE *pf;
//tEmpleado emp;
    void* buffer = malloc(tam);         //RESERVA MEMORIA PARA LEER UN DATO DEL TIPO ESPECIFICADO
    if(!buffer)                 //CHEQUEA QUE CREADO EL PUNTERO Y RESERVADO LA MEMORIA BIEN
    {
        return 3;
    }

    pf=fopen(fname,"rb"); //ABRE
    if(!pf)             //CHEQUEA QUE HAYA ABIERTO BIEN
    {
        return 2;
    }

    fread(buffer,tam,1,pf); //LEE 1ER REGISTRO
    while(!feof(pf))
    {
        accion(buffer);     //REALIZA LA ACCION REQUERIDA (CON LOS DATOS DE LECTURA)
        fread(buffer,tam,1,pf); //LEE REGISTROS HASTA EL FIN DE ARCHIVO
    }
    fclose(pf);         //CIERRA
    return 1;
}
