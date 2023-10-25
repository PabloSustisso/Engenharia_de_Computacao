#include <stdio.h>

int somatorio_Vetor(int v[], int tam)
{
    if (tam < 1)
        return 0;
    else 
        return v[tam-1] + somatorio_Vetor(v, tam-1);
}

int main(void)
{
    int tam;
    scanf("%d", &tam);
    int vet[tam];

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vet[i]);
    }
    printf("%d", somatorio_Vetor(vet, tam));
    

    return 0;
}