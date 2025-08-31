#include "Matrices.h"

/*Ejercicio 1.20
    Se dispone de una matriz cuadrada de enteros de orden N, donde cada elemento [i][j] representa la
    cantidad de puntos que obtuvo el equipo i frente al equipo j al fin de un torneo de fútbol (partidos
    de ida y vuelta) en el que participaron N equipos. El sistema de puntuación es: 3 puntos para el
    ganador del partido y ninguno para el perdedor; 1 punto para cada equipo en caso de empate.
    Desarrollar una función que determine si la matriz está correctamente generada.
    Desarrollar una función que genere un arreglo de N elementos tal que cada elemento V[k] contenga
    la cantidad de puntos obtenidos por el equipo k.
*/
void matrizTriangularSup(int mat[][TAM_F1],int orden)
{
    int aux;
    int i, j, tol=0;
    int mitf=((orden%2==0)?(orden/2):(orden/2+1)); // divide la matriz por la mitad, dependiendo de si es cuadrada de lados impar o par
    for(i=0;i<=mitf;i++)    //va hasta la mitad
    {
        for(j=tol;j<orden;j++)       //recorre las colunm
        {
            printf("%d ",mat[i][j]);

        }
        tol++;
    }

}
void DiagonalPrincipal(int mat[][TAM_F1],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d",mat[i][i]);
    }
}
void DiagonalSecundaria(int mat[][TAM_F1],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d",mat[n-i-1][i]);
    }
}
int buscarPosPA(int* pv, int num, int ce)
{
    int pos_encontrado = -1;
    int i;
    for(i=0; i<ce; i++)
    {
        if(*(pv+i) == num)
        {
            pos_encontrado = i;
            break;
        }
    }
    return pos_encontrado;

}
int verificarPuntajes(int tabla[][TAM_CUADRADO])
{
//tabla de puntajes y contrapuntajes
    int reflex[2][6]= {{0,1,2,3,4,6}
        ,{6,4,2,3,1,0}
    };
    int j,i,pos;
// revisa el triangulo superior derecho sin incluir la diagonal
    for(i=0; i<TAM_CUADRADO; i++)
    {
        for(j=i+1; j<TAM_CUADRADO; j++)
        {
            pos= buscarPosPA(reflex[0],tabla[i][j],(sizeof(reflex)/sizeof(int))/2);
            if(pos<0 || (tabla[j][i]!= reflex[1][pos]))
                return 0;
        }

    }
    return 1;
}
/*Ejercicio 1.12
Desarrollar una función para que, dada una matriz cuadrada de reales de orden N, obtenga la
sumatoria de los elementos que están por encima de la diagonal principal (excluida ésta). Lo mismo
para la diagonal secundaria. Lo mismo incluyendo la diagonal. Lo mismo, con los que están por
debajo de la diagonal.
*/

int SumaMatriz(int* mat,int f,int c)
{
    int i,j,cont=0,suma=0;
    for(i=0; i<f-1; i++)
    {
        for(j=1; j<c-i; j++)
        {
            suma+=*(mat+N*i+j+cont);
        }
        cont++;
    }
    return suma;
}
/*Ejercicio 1.19
Desarrollar una función para obtener la matriz producto entre dos matrices de enteros.*/

void MultiplicarMatriz(int m1[][TAM_C1],int m2[][TAM_C2], int f1,int c1,int f2,int c2)
{
    int i,j,k,suma;
    if(f1<1 || f2<1 ||c1<1 ||c2<1 || c1!=f2)
    {
        printf("No se pueden multiplicar estas matrices");
    }
    else
    {

        int R[f1][c2];
        for(i=0; i<f1; i++) //Filas
        {
            for(j=0; j<c2; j++)//Columnas
            {
                R[i][j]=0;
            }
        }

        for (i = 0; i < f1; i++)
        {
            //se itera através de cada fila de matriz1
            for (j = 0; j < c2; j++)  //se itera através de cada columna de matriz2
            {
                suma = 0;//es donde se almacenará el valor final
                for (k = 0; k < c1; k++)
                {
                    suma += m1[i][k] * m2[k][j];//se acumula en suma
                }
                R[i][j] = suma;
            }
        }

        for (i = 0; i < f1; i++)
        {
            printf("[");
            for (j = 0; j < c2; j++)
            {
                printf("%d\t",R[i][j]);
            }
            printf("]\n");
        }
    }
}
