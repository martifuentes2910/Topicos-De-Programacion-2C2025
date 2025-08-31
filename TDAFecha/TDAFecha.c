#include "TDAFecha.h
/*Ejercicio 4.1
Desarrollar una función que determine si una fecha es formalmente correcta*/
int esFechaValida(const tFecha *fec)
{
    static const char dias[][12] =
    {
        { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    };


    return fec->me > 0 && fec->me <= 12 &&
           fec->an >= AN_MIN && fec->an <= AN_MAX &&
           fec->di > 0 && fec->di <= dias[esBisiesto(fec->an)][fec->me - 1];
}

/*Ejercicio 4.7
Implemente un TDA Vector. Debe desarrollar una versión con memoria estática y otra con memoria
dinámica. Debe implementar las primitivas:
- crear vector
- vector lleno
- vector vacío
- insertar elemento en orden
- eliminar elemento
- destruir vector
Tenga en cuenta que la primitiva ‘destruir’ debe, según sea el caso, liberar la memoria reservada, o
poner la cantidad de elementos en cero.*/



int ingresarFechaDMA(tFecha *fec, const char *mensajeOpcional)
{
    if(mensajeOpcional)
        printf("%s", mensajeOpcional);
    else
        printf("Fecha (dd/mm/aaaa - 0=No Ingresa): ");
    fec->di = 0;
    fec->me = 0;
    fec->an = 0;
    fflush(stdin);
    scanf("%d/%d/%d", &fec->di, &fec->me, &fec->an);
    return fec->di && fec->me && fec->an;
}
