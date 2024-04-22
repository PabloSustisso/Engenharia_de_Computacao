#include <stdio.h>
#include <stdlib.h>

int inverterArray(int v[], int n)
{
    int aux[n];

    if (n < 1)
    {
        return aux;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = n-1; j > i; i--)
            {
                aux[i] = v[j];
                return n-1;
            }
        }
    }
}

int main(void)
{
    int *vet, *vet2, n = 5;
    vet = (int*)malloc(n * sizeof(int));
    vet2 = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &vet[i]);

    vet2 = inverterArray(vet, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet2[i]);
    }
    
    return 0;
}