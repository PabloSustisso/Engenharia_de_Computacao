#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int **create_matrix(int n)
{
    int i;
    int **mat;

    mat = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
        
    return mat;
}

int main(void)
{
    int i, j;
    int **matriz;
    int n = 10;
    int num = 50;

    int contr = n;

    matriz = create_matrix(n);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 0;
            }
            else if (j == contr-1)
            {
                matriz[i][j] = 0;
                contr--;
            }
            else matriz[i][j] = num;
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}