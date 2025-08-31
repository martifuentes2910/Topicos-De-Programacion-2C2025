#include "Recursivos.h"

int main()
{
    char cad[] ="mamma mia";
    char *pc;
    pc = rstrrchr(cad,'f');
    printf("%c",*pc);
    return 0;
}
