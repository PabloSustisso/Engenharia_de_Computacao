#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void imprimir_vetor(int vet[], int tam){
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);
}

void bubble_sort(int vet[], int tam){
    for(int i = 1; i < tam; i++){
        for(int j = 0; j < tam - 1; j++){
            if(vet[j] > vet[j+1]){
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

int metodo_guloso(int vet[], int C){
    bubble_sort(vet, TAM); //ordenar o vetor do menor pro maior arquivo
    
    int subconjunto[TAM];
    int soma = 0;

    for(int i = 0; i < TAM; i++){
        if(soma + vet[i] <= C)
            subconjunto[i] = vet[i];
        soma += vet[i];
    }

    return subconjunto;
}

int main(){
    int vet[TAM];
    int capacidade = 10, j = 0;

    for(int i = 9; i >= 0; i--){
        vet[j] = i;
        j++;
    }
    
    

    imprimir_vetor(metodo_guloso(vet, capacidade), TAM);
}