#include <stdio.h>
void * access(void * v, int i, int typeSize){
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
}

void bubble(int vSize, void * v, int typeSize, int (* cmp)(const void * a, const void * b)){
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
        if(!swapped) break;
    }
}

void quick(int size, void * v, int typeSize, int (* cmp)(const void * a, const void * b)){
    if(size > 1){
        int i = 0, a = 1, b = size - 1;
        
        void * pivot = access(v, i, typeSize);
        void * vA = access(v, a, typeSize);
        void * vB = access(v, b, typeSize);

        do{

            while(a < size && cmp(vA, pivot) <= 0){
                a++;
                vA = access(v, a, typeSize);
            }

            while(cmp(vB, pivot) == 1){
                b--;
                vB = access(v, b, typeSize);
            } 
            
            if(a < b){
                swap(vA, vB, typeSize);
                a++;
                b--;
                vA = access(v, a, typeSize);
                vB = access(v, b, typeSize);
            }

        }while(a <= b);

        swap(pivot, vB, typeSize);

        quick(b, v, typeSize, cmp);
        quick(size - a, vA, typeSize, cmp);
    }
}