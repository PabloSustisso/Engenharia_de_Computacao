#include <stdio.h>

typedef struct
{
    int x;
    int y;
}vetor_r2;

vetor_r2 soma_vec(vetor_r2 v1, vetor_r2 v2)
{
    vetor_r2 soma;
    soma.x = v1.x + v2.x;
    soma.y = v1.y + v2.y;

    return soma;
}

int main(void)
{
    vetor_r2 v1, v2, soma;

    scanf("%d %d", &v1.x, &v1.y);
    scanf("%d %d", &v2.x, &v2.y);

    soma = soma_vec(v1, v2);

    printf("%d %d", soma.x, soma.y);
    
    return 0;
}