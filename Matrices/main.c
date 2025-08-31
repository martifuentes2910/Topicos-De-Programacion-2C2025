#include "Matrices.h"

int main()
{
    int mat[5][5]=
    {
        {0,1,2,3,0},
        {4,0,4,6,3},
        {2,1,0,1,2},
        {3,3,1,0,6},
        {6,2,0,0,0},
    };
    int matJuego20[TAM_CUADRADO][TAM_CUADRADO]={{0,2,3},
                                                {2,0,6},
                                                {3,0,0}};
    int mat2[TAM_F1][TAM_C1]=
    {
        {6,1,2},
        {4,5,4},
        {2,1,7}
    };
     int mat3[TAM_F2][TAM_C2]=
    {
        {0,1},
        {4,0},
        {2,1}
    };
    matrizTriangularSup(mat,5);
//    DiagonalPrincipal(mat2,3);
//    DiagonalSecundaria(mat2,3);
//    int seVerifica= verificarPuntajes(matJuego20);
//    if(seVerifica)
//        printf("Se verifica!!");
//    else
//        printf("No se verifica.");
//MultiplicarMatriz(mat2,mat3,3,3,3,2);
//    int sum=SumaMatriz(&mat2[0][0],N,N);
//    printf("La suma es: %d",sum);
    return 0;
}
