#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct 
{
    int numerador;
    int denominador;
}Racional;

Racional divisao (Racional n1, Racional n2)
{
    Racional n3;

    n3.numerador = n2.denominador * n1.numerador;
    n3.denominador = n1.denominador * n2.numerador;

    return n3;
}

int main()
{
    Racional n[2], p;
    int i;

    for (i = 0; i < 2; i++)
    {
        scanf("%d %d", &n[i].numerador, &n[i].denominador);
    }
    
    p = divisao(n[0], n[1]);
    
    printf("%d %d", p.numerador, p.denominador);

    return 0;
}
