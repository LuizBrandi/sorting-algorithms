#include <stdio.h>

void bubble(void * v, int vSize, int typeSize, int (* cmp)(void *, void *)){
    int i, end, swapped;

    for(end = vSize - 1; end > 0; end--){
        swapped = 0;
        for(i = 0; i < end; i++){

            void * b1 = access(v, i, typeSize);
            void * b2 = access(v, i, typeSize);

            if(cmp(b1, b2)){
                swap(b1, b2, typeSize);
                swapped = 1;
            }

        }
        if(!swapped) return;
    }
}