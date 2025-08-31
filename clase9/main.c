#include "clase9.h"

int main()
{
    //int vector[]= {2,4,1,800,10};
    int vector2[] = {1,2,4,8,16,32,64,128,200,300,400,550,660};
    char vecChar[] = {'a','b','c','f','i','x'};
    int clave=64;
    char claveChar = 'x';
    char *elem;
    /*qsort(vector, sizeof(vector)/sizeof(int),sizeof(int), cmpEntAsc);
    for(int i=0; i<sizeof(vector)/sizeof(int); i++)
    {
        printf("\n%d", vector[i]);
    }*/

   // buscarMenor(vector, sizeof(vector)/sizeof(int),sizeof(int), cmpEntAsc);
   // qsort(vector, sizeof(vector)/sizeof(int),sizeof(int), cmpEntAsc);
    if((elem=myBSearch(&claveChar, vecChar,  sizeof(vecChar)/sizeof(char), sizeof(char), cmpEntAscChar)) != NULL)
        printf( "Encontrado: %c\n", *elem );
    else
        printf( "No encontrado: %c\n", claveChar );
    return 0;
}
