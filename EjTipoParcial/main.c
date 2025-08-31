#include <stdio.h>
#include <stdlib.h>
#include "TipoParcial.h"
/*
Cifrado c�sar conson�ntico
En el siguiente ejercicio utilizaremos el cifrado cesar "conson�ntico". El cifrado Cesar es un
tipo de cifrado por sustituci�n en el que una letra en el texto original es reemplazada por
otra letra que se encuentra un n�mero fijo de posiciones m�s adelante en el alfabeto.
�Conson�ntico� se refiere a que solo las consonantes ser�n reemplazadas en el alfabeto
sin las vocales. Por ejemplo, con un desplazamiento de 3, la B ser�a sustituida por la F (
situada 3 lugares a la derecha sin contar la E).

Escriba una funci�n que lea un archivo de texto que contenga el desplazamiento y la frase
a cifrar separados por una coma, y luego escriba un nuevo archivo con el desplazamiento y
la frase cifrada.

Ejemplo de entrada:
3, Arriba la birra.
Ejemplo de salida:
3, Avvifa pa fivva.
NOTAS:
� Tenga en cuenta el correcto uso de punteros y memoria.
� Tenga en cuenta el correcto uso de funciones.
� Tenga en cuenta que el alfabeto no incluye "�", "LL" ni "CH".
*/
/**Matrices Z
Realice una funci�n que reciba por par�metro una matriz (m�ximo 100 Filas y 100
columnas), la cantidad de filas y columnas reales y que realice lo siguiente:
-Recorra y muestre los elementos que conformar�an la "Z" de la matriz.
Ejemplo 1:
Mat1:
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
Mostrar�a por pantalla: 1 2 3 4 5 4 3 2 1 2 3 4 5
Ejemplo 2:
Mat2
1 2 3 4
1 2 3 4
1 2 3 4
Mostrar�a por pantalla: 1 2 3 4 3 1 2 3 4
NOTAS:
-Las matrices pueden ser N*N, o (N-1)*N o N*(N-1)**/


int main()
{

    //char cad[]="3,Azziba la birra";
    int mat[100][100]= {{1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5}
    };

    int cf=4,cc=5;
    char cadconsonantes[]="bcdfghjklmnpqrstvwxyz";
    char nombreArch[]="CifradoCesar.txt";
    //crearArchivoCadTxt(nombreArch,cad);

    //leerArchivo(nombreArch,cadconsonantes);
    // MatrizZ(mat,cf,cc);
int vecInt[] = {1,2,4,8,16,32,64,128,200,300,400,550,660};
    char vecChar[] = {'a','b','c','f','i','x'};
    char a[7]="abcdefg";
    char *ptr;
    int clave=400;
    char claveChar = 'x';
    int *elem;

    if((elem=_bsearch(&clave, vecInt,  sizeof(vecInt)/sizeof(int), sizeof(int), cmpAscInt)) != NULL)
        printf( "Encontrado: %d\n", *elem );
    else
        printf( "No encontrado: %d\n", clave );

    return 0;
}
