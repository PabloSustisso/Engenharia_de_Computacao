#include <stdio.h>

int soma_incrementos(int a, int b)
{
    if (b == 0)
        return a; // Condicao de parada
    else
        return soma_incrementos(a+1, b-1);
}

int main(void)
{
    int a, b, n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", soma_incrementos(a, b));
    }
    
    return 0;
}