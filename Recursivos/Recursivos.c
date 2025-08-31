#include "Recursivos.h"
//unsigned rstrlen(const char* cad)
//{
//
//}
////
//char* rstrrchr(const char* cad, char c)
//{
//    if(*cad){
//            if(*cad == c){
//                rstrrchr(cad,c);
//            }
//        return rstrrchr((cad+1),c);
//    }
//    else{
//        if(cad != pc)
//            return rstrrchr((cad-1),c);
//        else return pc;
//    }
//
//}
char *_rstrrchr(const char *s, int c, char *find){
    if(s==NULL) return NULL;
    if(*s == '\0') return (c == '\0') ? (char*)s : find;
    return StrrchrR(s + 1, c, *s == c ? (char*)s : find);
}

char *rstrrchr(const char *s, int c){
    return _rstrrchr(s, c, NULL);
}
unsigned rfact(unsigned n)
{
    return (n==0)?1:n*rfact(n-1);
}
