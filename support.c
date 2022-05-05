#include <stdlib.h>

void * access(void * v, int i, int typeSize){
    void * t = (char *) v;
    t += typeSize * i;
    return (void *) t;
}

void swap(void * a, void * b, int typeSize){
    int i;
    char c1 = (char *) a;
    char c2 = (char *) b;

    for(i = 0; i < typeSize){
        char temp = c1[i];
        c1[i] = c2[i];
        c2[i] = temp;
    }
}
