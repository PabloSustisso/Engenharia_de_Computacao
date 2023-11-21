#include <stdio.h>
#include <stdlib.h>

static int busca_bin(int x, int v[], int ini, int fim){
    int meio;

    
    if ((ini == fim) && (x == v[ini]))
        return ini;
    
    else if (ini < fim){
        
        meio = (ini + fim) / 2;

        if (x == v[meio])
            return meio;
        
        else if (x < v[meio])
            return busca_bin(x, v, ini, meio - 1);
        
        else
            return busca_bin(x, v, meio + 1, fim);
    }else
        return -1;
}

int busca_binaria(int x, int v[], int n){
    return busca_bin(x, v, 0, n - 1);
}

int busca_sequencial(int x, int v[], int n){
    int i;

    for (i = 0; i < n; i++)
        if (x == v[i])
            return i;

    return -1;
}

int busca_seq_bin(int x, int v[], int n, int m)
{
    int i = 0;

    if (v[m] < x)
        return busca_binaria(x, v, n);

    else if (v[m] >= x)
    {
        return busca_sequencial(x, v, n);
    }

    else
        return -1;
}

int main(void)
{
    int num, tam_vet, m;
    scanf("%d", &num);
    scanf("%d", &tam_vet);

    int vet[tam_vet];
    for (int i = 0; i < tam_vet; i++)
    {
        scanf("%d", &num);
        vet[i] = num;
    }
    
    scanf("%d", &m); // tamanho minimo da particao

    busca_seq_bin(num, vet, tam_vet, m);
}