#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int busca_binaria_iterativa(int x, int v[], int ini, int fim)
{
    int meio;

    do
    {
        meio = (ini + fim) / 2;

        if (x == v[meio])
            return meio;
        else if (x < v[meio])
            fim = meio - 1;
        else
            ini = meio + 1;
    } while (ini <= fim);

    return -1;
}

int main(void)
{
    int n, nc, posicao;
    
    scanf("%d", &n); // tamanho do vetor
    int *v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &nc); // numero de chaves a ser procurado
    int *x = (int*)malloc(nc * sizeof(int));
    for (int i = 0; i < nc; i++)
    {
        scanf("%d", &x[i]);
        posicao = busca_binaria_iterativa(x[i], v, 0, n-1);
        printf("%d\n", posicao);
    }
       
    free(v);
    free(x);

    return 0;
}