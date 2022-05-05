#include <stdio.h>
#include "sort.h"

int compara(void * a, void * b){
    int c1 = *((int *) a);
    int c2 = *((int *) b);
    if(c1 > c2) return 1;
    else return 0;
}


int main(void){
    printf("teste\n");
    int numeros[5] = {2, 8, 4, 3, 7};
    bubble(numeros, 5, sizeof(int), compara);
    for(int i = 0; i < 5; i++){
        printf("%d ", numeros[i]);
    }
    printf("\n");
}