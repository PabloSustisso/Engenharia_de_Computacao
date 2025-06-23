#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
Seja um arranjo composto por números inteiros, podendo ser positivos e/ou negativos. 
A subsequência máxima é aquela que tem o maior valor de soma entre todos os os seus elementos.
Implemente, utilizando a estratégia força-bruta, uma função que retorne o somatório da subsequência máxima.
*/

int soma_subsequencia_max(int vet[], int tam){
    int soma_max = INT_MIN;

    for(int i = 0; i < tam; i++){
        int soma_atual = 0;

        for(int j = i; j < tam; j++){
            soma_atual += vet[j];

            if(soma_atual > soma_max)
                soma_max = soma_atual;
        }
    }

    return soma_max;
}

int* ler_vetor_int(int n){
    int *vet = (int*)malloc(n * sizeof(int));
    int num, i = 0;
    
    while(n > 0){
        scanf("%d", &num);

        vet[i] = num;
        i++;
        n--;
    }

    return vet;
}

int main(){
    int n;
    scanf("%d", &n);

    int *vet = ler_vetor_int(n);
    int resultado = soma_subsequencia_max(vet, n);
    printf("%d", resultado);

    free(vet);

    return 0;
}