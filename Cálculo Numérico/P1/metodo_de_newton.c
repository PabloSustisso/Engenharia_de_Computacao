#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define e 2.718281828459045235360287

float f(float x)
{
    float f;

    f = pow(e, x) - (2*x) - 2;

    return f;
}

float fd(float x)
{
    float fd;

    fd = pow(e, x) - 2;

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
    printf("\nErro: %.7f\n", erro);

    while (erro > precisao)
    {
        x0 = x_novo;
        x_novo = x0 - ((f(x0)) / (fd(x0)));
        erro = fabs(x_novo - x0);
        printf("X0 = %f\nX_novo: %f\n", x0, x_novo);
        printf("\nErro: %.7f\n", erro);
    }

    return 0;
}