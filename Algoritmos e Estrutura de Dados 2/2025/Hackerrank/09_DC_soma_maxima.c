#include <stdio.h>
#include <stdlib.h>

int* criar_vetor(int n){
    int *vet = (int*)malloc(n * sizeof(int));

    return vet;
}

void ler_vetor(int *vet, int n){
    int num;

    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        vet[i] = num;
    }
}

int somaDivisaoConquista(int *vet, int i, int f){
    if(i == f){
        if(vet[i] >= 0)
            return vet[i];
        else
            return 0;
    }
    
    int meio = i + (f - i) / 2;

    int se = somaDivisaoConquista(vet, i, meio);
    int sd = somaDivisaoConquista(vet, meio + 1, f);

    return se + sd;
}

int solve(int *v, int n){
    if(n == 0)
        return 0;
    return somaDivisaoConquista(v, 0, n - 1);
}

int main(){
    int n;
    scanf("%d", &n);

    int *v = criar_vetor(n);
    ler_vetor(v, n);

    int r = solve(v, n);
    printf("%d", r);

    free(v);

    return 0;
}