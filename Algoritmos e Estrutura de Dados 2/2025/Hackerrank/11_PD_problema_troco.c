#include <stdio.h>
#include <stdlib.h>

int* criar_vetor(int n){
    int *v = (int*)malloc(n * sizeof(int));

    return v;
}

void ler_inteiros(int *v, int n){
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
}

void solve(int *moedas, int n, int troco){
    int *aux = criar_vetor(troco + 1);

    aux[0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = moedas[i]; j <= troco; j++){
            aux[j] += aux[j - moedas[i]];
        }
    }

    printf("%d", aux[troco]);

    free(aux);
}

int main(){
    int T;
    scanf("%d", &T);

    int N;
    scanf("%d", &N);

    int *moedas = criar_vetor(N);
    ler_inteiros(moedas, N);

    solve(moedas, N, T);

    free(moedas);

    return 0;
}