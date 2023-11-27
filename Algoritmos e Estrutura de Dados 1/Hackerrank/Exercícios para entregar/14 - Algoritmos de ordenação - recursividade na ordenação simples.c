#include <stdio.h>
#include <stdlib.h>

void bubblesort(int v[], int n, int j)
{
    int x;
    for (int i = 0; i < n - 1; i++)
    {
        if (v[j] > v[j + 1]){
            x = v[j];
            v[j] = v[j + 1];
            v[j + 1] = x;
        }
        else
            bubblesort(v, n-1, j+1);
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int *v = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);

    bubblesort(v, n, 0);
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);

    free(v);
    
    return 0;
}