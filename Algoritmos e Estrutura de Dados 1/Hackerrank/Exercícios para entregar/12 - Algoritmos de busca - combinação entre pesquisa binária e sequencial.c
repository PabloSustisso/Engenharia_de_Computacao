#include <stdio.h>
#include <stdlib.h>

int busca_seq_bin(int x, int v[], int n, int m)
{
    int direito = n-1, esquerdo = 0, meio;

    while (direito - esquerdo + 1 > m) // busca binaria atualizando os limites esq e dir
    {
        meio = (direito+esquerdo)/2;

        if (v[meio] == x)
            return meio;
        else if (x < v[meio])
            direito = meio - 1;
        else
            esquerdo = meio + 1;
    }

    for (int i = esquerdo; i <= direito; i++) // mostrar o subvetor da busca sequencial
        printf("%d ", v[i]);
    
    printf("\n");
    for (int i = esquerdo; i <= direito; i++) // busca sequencial a partir do subvetor gerado
        if (v[i] == x)
            return i;
    
    return -1;
}

int main(void)
{
    int x, n, m;
    scanf("%d", &x); // numero a ser procurado
    scanf("%d", &n); // tamanho do vetor

    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    
    scanf("%d", &m); // tamanho da particao

    int posicao = busca_seq_bin(x, v, n, m);
    printf("%d", posicao);

    return 0;
}   