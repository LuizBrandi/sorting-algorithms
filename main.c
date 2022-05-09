#include <stdio.h>
#include "sort.h"
#define TAM 10

int compara(const void * a, const void * b);

int main(void){
    int numeros[TAM] = {2, 8, 4, 3, 7, 1, 6, 23, 12, 20};
    quick(TAM, numeros, sizeof(int), compara);
    for(int i = 0; i < TAM; i++){
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

int compara(const void * a, const void * b){
    int c1 = *((int *) a);
    int c2 = *((int *) b);
    if(c1 > c2) return 1;
    else if(c1 < c2) return -1;
    else return 0;
}

