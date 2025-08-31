#include "Cadenas.h"

/// FUNCIONES DE BIBLIOTECA "STRING.H"
//miStrCpy
char *miStrchr(const char *pc, int car)
{   //EXISTE LA CADENA Y EL CAR ACTUAL DEL PUNTERO NO ES IGUAL AL CAR BUSCADO
    while(*pc && *(char*)pc != (char)car)
        pc++;
    return *(char*)pc ==(char)car ? (char * )pc :(char *) NULL;
    //SI AL FINAL ENCONTRO EL CARACTER, LO DEVUELVE. SINO, DEVUELVE NULL

}
//miStrCmp
size_t miStrlen(const char* cad)
{
    size_t len =0;
    while(*(char *)cad++)
        len++;

    return len;
}

/// EJERCICIOS DE MANEJO DE CADENAS
int esPalindromo(const char*frase)
{
    char *pi =(char*)frase;
    char *pf =(char*)frase+strlen(frase)-1;
    while(pi < pf)
    {
        while (!ESLETRA(*pi) && pi < pf)
            pi++;
        while (!ESLETRA(*pf) && pi < pf)
            pf--;
        if (AMAYUSC(*pi) != AMAYUSC(*pf))
            return 0;

        pi++;
        pf--;

    }
    return 1;
}
int proxPalabra(char* cad)
{
    char* ini=cad;
    int le=0, es=0;
    while(ESLETRA(*cad))
    {
        le++;
        cad++;
    }
    while(!ESLETRA(*cad)&&(*cad!='\0'))
    {
        cad++;
        es++;
    }

    cad=ini;
    return le+es;
}

/// Ejercicio 1.10
/*
La siguiente línea “Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmgj” ha
sido ofuscada para impedir su lectura desplazando desplazado hacia atrás dentro del grupo
"abcdghijkoqtuv" tantos caracteres como posición tiene en la palabra.
Ejemplo, si la palabra es “hola”
    ● "h":un lugar atrás porque es la primera letra de la palabra, queda "g"
    ● "o":dos lugares atrás, queda "j"
    ● "l":No figura en grupo, no se modifica, queda "l"
    ● "a":cuatro lugares hacia atrás, queda "q", antes de la “a” está la “v”.
Quedando una vez ofuscada como “gjlq”.
    ● No considere ningún carácter que no figura dentro del grupo
    ● Una palabra es todo conjunto de uno o mas caracteres que responden a la función isalpha
    ● La frase desofuscada esta en Español.
*/
//void desofuscar(char* cad, char* grupo, int ce)
//{
//    int lengrupo = miStrlen(grupo);
//    char *newletrapos, *newletra;
//    char *desofuscada;
//    char *pos;
//    desofuscada=strcpy(desofuscada,cad);
//    char* ini= cad;
//    int iniproxpal = proxPalabra(cad,ini);
//
//    while(*cad)
//    {
//        if(ESLETRA(*cad))
//        {
//
//            pos =(char*)strchr(grupo, *cad); //posicion de la letra en el grupo
//            if(pos!=NULL)
//            {
//                newletrapos = pos - cad + 1;
//                newletra = grupo + (cad - newletrapos + lengrupo) %lengrupo; //
//                *desofuscada = *newletra;
//            }
//
//        }
//        cad++;
//        desofuscada++;
//    }
//}
void desofuscar(char *cad, const char* grupo)
{
    int i;
    char* ini=cad;
    int cant=proxPalabra(cad);
    while(cant>0)
    {
        i=1;
        //invertir(pcad, pcad);
        while(i<=cant)
        {
            *cad=desplazamiento(*cad,i,grupo);
            i++;
            cad++;
        }
        cant=proxPalabra(cad);
    }
    cad=ini;
    printf("%s", cad);
}
char desplazamiento(char c, unsigned desp, const char* grupo)
{
    char* p=miStrchr(grupo,c);
    if(!p)
        return c;
    else
        return *(grupo+(((p-grupo)+desp)%strlen(grupo)));

}

void invertir(char* cad, char* ini)
{
    int ce=0;
    char* fin;
    char aux;
    /*while(!ESLETRA(*cad))
    {
      cad++;
    }*/


    while(ESLETRA(*cad))
    {
        cad++;
        ce++;
    }
    cad=ini;
    fin=ini+ce-1;
    while(cad<fin)
    {
        aux=*cad;
        *cad=*fin;
        *fin=aux;
        cad++;
        fin--;
    }
    cad=ini;
    printf("%s", cad);
}
//void desofuscar(char* cad,char* grupo, int ce)
//{
//    char len = strlen(cad);
//
//
//    while(*cad)
//    {
//        if(ESLETRA(*cad))
//        {
//
//            char *pos = strchr(grupo, *cad);
//
//            if (indice >= 0 && indice < len)   // si la letra está en el alfabeto
//            {
//                int desplazamiento = indice + 1; // desplazamiento según la posición de la letra
//                char *nueva_letra = alfabeto + (indice - desplazamiento + len) % len; // calcula la nueva letra desplazada
//                *cadena = *nueva_letra; // reemplaza la letra en la cadena original
//            }
//        }
//
//
//
//        // Si el caracter está en el grupo, realizar el desplazamiento
//        if (pos != NULL)
//        {
//            // Calcular el desplazamiento
//            int desplazamiento = pos - grupo + 1;
//
//            // Aplicar el desplazamiento
//            int nueva_posicion = (i - desplazamiento) % len;
//            if (nueva_posicion < 0)
//                nueva_posicion += len;
//
//            // Asignar el nuevo caracter a la cadena
//            cadena[i] = cadena[nueva_posicion];
//        }
//
//        cad++;
//    }
//}
/// Ejercicio 1.8
/*
Desarrollar una función que cuente el número de apariciones de una palabra dentro de una cadena
de texto. Para ello la función recibe como parámetros dos punteros a char. El primero corresponde al
texto, el segundo corresponde a la cadena buscada. La función debe retornar el número de
ocurrencias. Contemple las condiciones de borde y haga un listado de éstas.
*/

int CuentaPalabra(char* cad, char* pal)
{
    int cont=0;
    char *ini=cad;
    int lencad = strlen(cad);
    int lenpal = strlen(pal);

    while(*cad)
        //for (int i = 0; i <= lencad - lenpal; i++)
    {
        // Verificar si la palabra buscada aparece en esta posición del texto
        if (strncmp(cad, pal, lenpal) == 0)
            cont++;
        cad++;
    }

    return cont;
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

///Ejercicio 1.9 DONE
/*Desarrollar una función que normalice la cadena de texto que se le pasa como argumento. En este
caso, la cadena se encontrará normalizada cuando la primera letra de cada palabra sea mayúscula y
las siguientes minúsculas. La cadena normalizada no deberá contener espacios o tabulaciones al
inicio o al final. En el caso de que las palabras de la cadena se encuentren separadas por más de un
espacio o tabulación, se deberán eliminar los excedentes. Se debe modificar la cadena pasada como
argumento. No puede realizar una o más copias locales de la cadena original. Contemple las
condiciones de borde y haga un listado de éstas.
*/
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
