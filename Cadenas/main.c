#include "Cadenas.h"
int main()
{
    char cadena[]="arriba la birra";
    char cadena2[]="HoLa, todo el; mundo";
    char cadena3[]="Nj qemh v ljs kraenkqbres; lj oqe qemh es oqevorme sgn ellhs --Istqt Asdmg";
    char cadena8[]="Hola y adios hola. Hola";
    char pal[]="hola";
    char grupo[] = "abcdghijkoqtuv";
    char *ini=cadena2;
    char *c=cadena2;
    int ce=sizeof(cadena3);


char s[] = "  a  Hola   tonotos, como estas   ?    ";
//char *sp =s;
//int ca =miStrlen(s);
// printf( "s=%s\n", s );
// printf( "strlen(s) = %d\n", miStrlen( cadena3 ) );
// printf( "%d\n", (1-7+14)%14);
//Normalizar(sp,&ca);
// printf("%sa",sp);
//    if (esPalindromo(cadena)==1)
//        printf("La cadena es un palindromo.\n");
//    else
//        printf("La cadena NO es un palindromo.\n");
   // printf("num apariciones: %d",CuentaPalabra(cadena8,pal));
   // Invertir(c);
   //desofuscar(cadena3,grupo,ce);

  desofuscar(cadena3,grupo);
  //printf("%s",cadena3);
    return 0;
}
