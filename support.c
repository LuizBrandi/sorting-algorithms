#include "sort.h"

extern void * access(void * v, int i, int typeSize){
    char * t = (char *) v;
    t += typeSize * i;
    return (void *) t;
}

extern void swap(void * a, void * b, int typeSize){
    int i;
    char * c1 = (char *) a;
    char * c2 = (char *) b;

    for(i = 0; i < typeSize; i++){
        char temp = c1[i];
        c1[i] = c2[i];
        c2[i] = temp;
    }
}
