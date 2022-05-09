#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#define TAM 4

typedef struct{
    char * nome;
    float salario;
} Funcionario;

Funcionario ** vetorDePonteiros(int tamanho, Funcionario * vetor);
void imprimeVetor(int tamanho, Funcionario ** vetor);
int comparador(const void * c1, const void * c2);

int main(void){
    Funcionario programadores[TAM] = {{"Luiz", 2500},
                                      {"Ana", 4000},
                                      {"Lucas", 2300},
                                      {"Joao", 3000}
    };

    Funcionario ** ordemSalario = vetorDePonteiros(TAM, programadores);  
    //bubble(TAM, ordemSalario, sizeof(Funcionario *), comparador);
    quick(TAM, ordemSalario, sizeof(Funcionario *), comparador);
    //qsort(ordemSalario, TAM, sizeof(Funcionario *), comparador);
    imprimeVetor(TAM, ordemSalario);
}

Funcionario ** vetorDePonteiros(int tamanho, Funcionario * vetor){
    Funcionario ** novo = (Funcionario **) malloc(sizeof(Funcionario) * TAM);
    int i;

    for(i = 0; i < TAM; i++){
        novo[i] = &vetor[i];
    }

    return novo;
}

void imprimeVetor(int tamanho, Funcionario ** vetor){
    int i;
    for(i = 0; i < TAM; i++){
        printf("Nome: %s\n", vetor[i]->nome);
        printf("Salário: %.2f\n", vetor[i]->salario);
        printf("\n");
    }
}

int comparador(const void * c1, const void * c2){
    Funcionario ** f1 = (Funcionario **) c1;
    Funcionario ** f2 = (Funcionario **) c2;

    /*if((*f1)->salario > (*f2)->salario) return 1;
    else if((*f1)->salario < (*f2)->salario) return -1;
    else return 0;*/
    int comp = strcmp((*f1)->nome, (*f2)->nome);
    
    if(comp > 0) return 1;
    else if(comp < 0) return -1;
    else return 0;
}