#include "TDAVector.h"

/**Ejercicio 4.7
Implemente un TDA Vector. Debe desarrollar una versión con memoria estática y otra con memoria
dinámica. Debe implementar las primitivas:
- crear vector
- vector lleno
- vector vacío
- insertar elemento en orden
- eliminar elemento
- destruir vector
Tenga en cuenta que la primitiva ‘destruir’ debe, según sea el caso, liberar la memoria reservada, o
poner la cantidad de elementos en cero.**/
int main()
{
    Vector vecInt;
    int vec[]= {1,2,3,4,5,6,7};
    crearVector(&vecInt,7,sizeof(int));

    for(int i=0; i<7; i++)
        cargarVector(&vecInt,&vec[i]);
    recorrerVector(&vecInt,mostrarInt);
    destruirVectorDin(&vecInt);



    return 0;
}
