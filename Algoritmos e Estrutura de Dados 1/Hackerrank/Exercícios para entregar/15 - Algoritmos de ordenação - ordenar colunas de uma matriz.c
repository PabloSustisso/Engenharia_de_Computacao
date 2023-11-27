#include <stdio.h>
#include <stdlib.h>

float **startMat(int l, int c)
{
    float **mat;
    mat = (float**)malloc(l * sizeof(float*));
    
    for (int i = 0; i < l; i++) // Alocando dinamicamente as colunas da matriz
    {
        mat[i] = (float*)malloc(c * sizeof(float));
    }

    return mat;
}

void scanMat(float **mat, int l, int c)
{
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            scanf("%f", &mat[i][j]);
}

void printMat(float **mat, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%.1f ", mat[i][j]);
        }
        printf("\n");
    }
}

void sortColumnMat(float **mat, int l, int c)
{
    float *v;
    int k = 0, i, j, x;

    v = (float*)malloc(l * sizeof(float));
    
    while (k < c)
    {
        // atribuir cada coluna separadamente a um vetor auxiliar
        for (i = 0; i < l; i++)
            v[i] = mat[i][k];
        
        // ordenar separadamente cada coluna utilizando bubblesort
        for (i = 0; i < l - 1; i++)
            for (j = 0; j < l - i - 1; j++)
                if (v[j] > v[j + 1]){
                    x = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = x;
                }

        // atribuir os valores ordenados para matriz em ordem decrescente
        int z = 0;
        for (i = l - 1; i >= 0; i--){
            mat[z][k] = v[i];
            z++;
        }

        k++;
    } 
    
}

int main(void)
{
    int l, c;
    float **mat;
    scanf("%d %d", &l, &c);

    mat = startMat(l, c);

    scanMat(mat, l, c);
    sortColumnMat(mat, l , c);
    printMat(mat, l , c); // matriz ja ordenada

    return 0;
}