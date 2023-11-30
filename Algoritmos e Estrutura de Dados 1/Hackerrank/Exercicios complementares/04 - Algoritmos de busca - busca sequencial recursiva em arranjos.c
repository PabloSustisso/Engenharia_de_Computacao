#include <stdio.h>

// Busca sequencial com arranjo utilizando recursao
int buscaSequencial(int chave, int vet[], int n)
{
    // caso base
    if (n < 0)
        return -1;
    else
    {
        if (chave == vet[n])
            return n;
        else
            return buscaSequencial(chave, vet, n-1); // chamada recursiva para posicao n-1 no vetor
    }
}

int main(void)
{
    int tam, casos_teste, chaves;
    scanf("%d", &tam);

    int vet[tam];
    for (int i = 0; i < tam; i++)
        scanf("%d", &vet[i]);
    
    scanf("%d", &casos_teste);
    for (int i = 0; i < casos_teste; i++)
    {    
        scanf("%d", &chaves);
        printf("%d\n", buscaSequencial(chaves, vet, tam-1));
    }
    
    return 0;
}