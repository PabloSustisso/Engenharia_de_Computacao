#include <stdio.h>
#include <stdlib.h>

int *iniciar(int l, int c)
{
    int **mat;
    mat = (int**)malloc(l * sizeof(int*));
    
    for (int i = 0; i < l; i++) // Alocando dinamicamente as colunas da matriz
    {
        mat[i] = (int*)malloc(c * sizeof(int));
    }

    return mat;
}

int main(void)
{
    int **mat, l, c;
    scanf("%d %d", &l, &c);

    mat = iniciar(l, c);

    return 0;
}