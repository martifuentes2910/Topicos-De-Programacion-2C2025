#include "Matematicas.h"

long factorial(unsigned val)
{
    unsigned long long res=1;
    int i;
    for(i=1; i<=val; i++)
    {
        res*=i;
    }
    return res;
}

int combinatorio(int m, int n)
{
    int res;
    int fm=factorial(m);
    int fn=factorial(n);
    int fd=factorial(m-n);

    if((m>=n)&&(n>=0))
    {
        res = ( fm / ( fn * fd ) );
    }

    return res;
}

float potencia(float val, float pot)
{
    int i;
    float res=val;
    for(i=0; i<pot; i++)
    {
        res=res*val;
    }
    return res;

}

float euler (float* val, float tol)
{
    float i=1;
    float res=1,valor;
    float valori=*val;
    do
    {
        valori=potencia(*val,i);
        valor =valori/(float)factorial(i);
        res+=valor;
        i++;
    }
    while(valor>=tol);
    return res;
}
/*Ejercicio 9
Dados dos números naturales A y B, desarrollar una función para obtener el cociente entero A/B y el
resto. (A puede ser 0; B, no).*/
void cociente(int a, int b)
{
    int res,cos;
    if(b!=0)
    {
        res = a/b;
        cos = a%b;
    }
    printf("El cociente de la division entre %d y %d es %d, y el resto es %d",a,b,cos,res);
}


/*Ejercicio 7
Un número natural es perfecto, deficiente o abundante según que la suma de sus divisores positivos
menores que él sea igual, menor o mayor que él. Por ejemplo:
Número Divisores positivos menores que él Suma de los divisores Clasificación
6 1, 2, 3 6 PERFECTO
10 1, 2, 5 8 DEFICIENTE
12 1, 2, 3, 4, 6 16 ABUNDANTE
Desarrollar una función que determine si un número natural es perfecto, deficiente o abundante*/





