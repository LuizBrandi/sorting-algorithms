#include <stdio.h>
#include "sort.h"
#define TAM 10

int compara(void * a, void * b){
    int c1 = *((int *) a);
    int c2 = *((int *) b);
    if(c1 > c2) return 1;
    else return 0;
}


int main(void){
    printf("teste\n");
    int numeros[TAM] = {2, 8, 4, 3, 7, 1, 6, 23, 12, 20};
    bubble(numeros, TAM, sizeof(int), compara);
    for(int i = 0; i < TAM; i++){
        printf("%d ", numeros[i]);
    }
    printf("\n");
}