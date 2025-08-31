include <stdio.h>
#include <stdlib.h>
/// 20/04/2024
typedef struct {
char* cursor;
bool finsec;
} SecuenciaPal;

typedef struct {
char vecPal[TAM_PAL];
} Palabra;

int main()
{
    // aritmetica de punteros
    // la \ indica que lo que viene a continuacion es un codigo
    char cad[TAM]="*#hoLa\tcAdEnA/*";
    char var = 'a'; // 97 ascii- 1byte

    printf("Hello world!\n");
    return 0;
}

/// TAREA: es palindomo contemplando espacios y espalindromo key sensitive
bool esCapicua(const char *p) {
    const char *q = p;
    while(*q){
        q++;
    }
    q--;

    while(p<q){
        if(*p != *q)
            return false;
        p++;
        q--;
    }
}

char* normalizar(char* norm, const char* aNorm){
    SecuenciaPal secL, secE;
    Palabra pal;

    secPalCrear(&secL, aNorm);
    secPalCrear(&secE, norm);
    leerPalabra(&secL, &pal)

    while(!finSecLec(&secL)){
        aTitulo(&pal);
        escribirPalabra(&secE, &pal);
        if(leerPalabra(&secL, &pal))
            escribirCaracter(&secE. '');
    }
    secPalCerrar(&secE);
    return norm;
}

void secPalCrear(SecuenciaPal* sec, const char* cad)
{
    sec->cursor = (char*)cad;
    sec->finSec = false;
}

bool finSec(const SecuenciaPal* sec)
{
    return sec->finsec;
}

bool leerPalabra(SecuenciaPal *sec, Palabra *pal)
{
    // *(sec->cursor) falso cuando apunta al caracter nulo (0 = falso)
    while(*(sec->cursor) && !esLetra(*(sec->cursor)))
        sec->cursor++;

    if(!*(sec->cursor))
    {
        sec->finsec = true;
        return false;
    }

    char* actPal= pal->vecPal;
    while(*(sec->cursor)&&esLetra(*(sec->cursor)))
    {
        *actPal=*(sec->cursor);
        actPal++;
        sec->cursor++;
    }
    *actPal='\0';
    return true;
}

void escribirPalabra(SecuenciaPal* sec, const Palabra* pal)
{
    char* actPal = pal->vecPal;

    while(*actPal)
    {
        *(sec->cursor) = *actPal;
        sec->cursor++;
        actPal++;
    }
}

void aTitulo(Palabra* pal)
{
    char* actPal= pal->vecPal;
    *actPal = toupper(*actPal);
    actPal++;
    while(*actPal)
    {
        *actPal=tolower(*actPal);
        actPal++;
    }
}

/// 18/05/2024

// punteros a funcion - funciones genericas - punteros  a void
// memcpy(dirD, dirO, cant_bytes)

void vectorOrdenarSelección(Vector* vector)
{
    int* ult = vector->vec + vector->ce-1;
    for(int* i = vector->vec; i<ult; i++) {
        {
            m = buscarMenor(i, ult);
            intercambiar(m, i);
        }
    }
}

int* buscarMenor(int* ini, imt* fin)
{
    int* m = ini;
    for(int* j = ini+1; j++)
    {
        if(*j<*m)
            m=j;
    }
    return m;
}
