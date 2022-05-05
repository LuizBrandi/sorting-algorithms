#include <stdio.h>
#include "sort.h"

/*void * access(void * v, int i, int typeSize){
    char * t = (char *) v;
    t += typeSize * i;
    return (void *) t;
}
void swap(void * a, void * b, int typeSize){
    int i;
    char * c1 = (char *) a;
    char * c2 = (char *) b;

    for(i = 0; i < typeSize; i++){
        char temp = c1[i];
        c1[i] = c2[i];
        c2[i] = temp;
    }
}*/

void bubble(void * v, int vSize, int typeSize, int (* cmp)(void *, void *)){
    int i, end, swapped;

    for(end = vSize - 1; end > 0; end--){
        swapped = 0;
        for(i = 0; i < end; i++){

            void * b1 = access(v, i, typeSize);
            void * b2 = access(v, i+1, typeSize);

            if(cmp(b1, b2)){
                swap(b1, b2, typeSize);
                swapped = 1;
            }

        }
        if(!swapped) return;
    }
}