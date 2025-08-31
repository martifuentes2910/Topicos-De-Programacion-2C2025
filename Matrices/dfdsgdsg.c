#include <stdio.h>
#include <stdlib.h>

int EstaDentroDelRango(int, int, int);
int LeerYValidar(int,int);

int main()
{
    int sum= 0,conta = 0,contb = 0, contc= 0,num=0;

    num = LeerYValidar(100, 2000);
    printf("%d", EstaDentroDelRango(100, num, 500));
    while(num=! 99)
    {

        if( EstaDentroDelRango(100, num, 500) == 1)
            conta++;
        if( EstaDentroDelRango(500, num, 1200) == 1)
            contb++;
        if( EstaDentroDelRango(1200, num, 2000) == 1)
        {
            contc++;
            sum += num;
        }

        num = LeerYValidar(100, 2000);

    }

    printf("%d %d %d",conta,contb,sum/contc);
    return 0;
}

int LeerYValidar(int min, int max)
{
    int num,vali=0, compara;
    do
    {
        printf("Ingrese un numero entre 100 y 2000: ");
        scanf("%d", &num);
    }
    while( EstaDentroDelRango(min, num, max) == 0);

    return num;
}

int EstaDentroDelRango(int min, int num, int max)
{
    if((num > min && num < max) || (num == 99))
        return 1;
    else
        return 0;

}
