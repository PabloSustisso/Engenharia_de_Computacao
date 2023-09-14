#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int * prog_arit(int n, int r)
{
    int *vet;
    vet = (int*)malloc(n * sizeof(int));

    int i;

    for (i = 0; i < n; i++)
    {
        vet[i] = 0 + r*i;
    }
    
    return vet;
}

void mostraVetor(int vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vet[i]);
    }
}

int main(void)
{   
    int tam_vetor, razao, *vet;

    scanf("%d %d", &tam_vetor, &razao);

    vet = prog_arit(tam_vetor, razao);
    mostraVetor(vet, tam_vetor);

    free(vet);

    return 0;
}
