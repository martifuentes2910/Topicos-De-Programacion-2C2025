/// MAP FILTER REDUCE
void *mem_cpy(void *dest,const void*orig,size_t cant)
{
    void * aux=dest;
    while(cant--)
    {
        *dest++ = *(orig)++
    }
    return aux;
}

void *mem_move(void *dest, const void *orig,size_t cant){

 void * aux=dest;
    if(orig >= dest){

        while(cant--)
            *dest++= *orig++;

    }
    else{

        *dest +=cant -1;
        *orig +=cant -1;
        while(cant--)
            *dest--= *orig--;
    }
}

void _filter(void*vec,unsigned ce,unsigned tam, accion(void*))
{
    int i=0;
    void* pe=vec;
    void ini=vec;
    unsigned int ceinterna=*ce;
    for(i=0; i<*ce; i++)
    {
        if(accion(vec))
        {
            if(pe!=vec)
                memcpy(pe,vec,tam);
            pe+=tam;
        }
        else
            ceinterna--;

        vec+=tam

    }
    vec=ini;
    *ce=ceinterna;
    return vec;

}
/*MAP NO MUEVE A OTRO VECTOR. TRANSFORMA EL MISMO VECTOR EN OTRO DESPUES DE EFECTUAR UNA ACCION*/
//          VEC   CANT ELEM  TAMAÑO SIZEOF DEL TIPO DE DATO
void* _map(void* vec, unsigned ce, unsigned tam,int accion(void*) ) //ESTA FUNCION SE PUEDE HACER BIEN GENERICA CON VOID ACCION(*VOID)
{
    int i;
    void* ini=vec;
    for(i=0; i<ce; i++)
    {

        accion(vec);
        vec+=tam; //DESPLAZAMIENTO POR BYTES EN EL PUNTERO (GRACIAS AL SIZEOF).
        // ES LA UNICA MANERA DE DESPLAZAR UN PUNTERO VOID
    }
    //TIL PRINTF DEVUELVE INT
    return ini;
}
//void multiplicarpor2(void* val)
//{
//    *(int*)val=*(int*)val*2;
//}
int raizCuadrada(void* info)
{
    float* pinfo=(float*)info;
    *pinfo= sqrt(*pinfo);
    return 1;
}
int mostrarFlotante(void* info)
{
    return printf("%5.2f", *(float*)info);
}
