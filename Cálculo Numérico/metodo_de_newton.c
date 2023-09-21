#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
    float f;

    f = x - sqrt(2);

    return f;
}

float fd(float x)
{
    float fd;

    fd = x;

    return fd;
}

int main(void)
{
    float x0, x_novo, erro, precisao;

    printf("Informe um valor aproximado para X0: ");
    scanf("%f", &x0);
    printf("Informe a precisao desejada: ");
    scanf("%f", &precisao);

    x_novo = x0 - ((f(x0)) / (fd(x0)));
    erro = fabs(x_novo - x0);
    printf("X0 = %f\nX_novo: %f\n", x0, x_novo);

    while (erro > precisao)
    {
        x0 = x_novo;
        x_novo = x0 - ((f(x0)) / (fd(x0)));
        erro = fabs(x_novo - x0);
        printf("X0 = %f\nX_novo: %f\n", x0, x_novo);
    }

    return 0;
}