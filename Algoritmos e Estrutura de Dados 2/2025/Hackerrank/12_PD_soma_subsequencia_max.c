#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    return (a > b) ? a : b;
}

int* criar_vetor(int n){
    int *v = (int*)malloc(n * sizeof(int));

    if(v == NULL)
        return NULL;

    return v;
}

void ler_dados(int *v, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}

int solve(int *v, int n){
    if(n <= 0)
        return 0;

    int max_global = v[0];
    int max_atual = v[0];

    for(int i = 1; i < n; i++){
        max_atual = max(v[i], max_atual + v[i]);
        max_global = max(max_global, max_atual);
    }

    return max_global;
}

int main(){
    int n;
    scanf("%d", &n);

    int *v = criar_vetor(n);
    ler_dados(v, n);

    int r = solve(v, n);
    printf("%d", r);

    free(v);

    return 0;
}