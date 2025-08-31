#ifndef TDAFECHA_H_INCLUDED
#define TDAFECHA_H_INCLUDED
typedef struct
{
    int dia;
    int mes;
    int anio;
} tFecha


#define AN_MIN 1
#define AN_MAX 5000

#define esBisiesto( X ) ( ( ( X ) % 4 == 0 && ( X ) % 100 != 0 ) || \( X ) % 400 == 0 )

#endif // TDAFECHA_H_INCLUDED
