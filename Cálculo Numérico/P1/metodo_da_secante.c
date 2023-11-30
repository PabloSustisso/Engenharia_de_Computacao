#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define e 2.718281828459045235360287
#define pi 3.14159265359

float f(float x)
{
    float f;

    f = pow(e, x) - (2*x) - 2;

    return f;
}

int main(void)
{
    float x0, x1, x_novo, erro, precisao;

    printf("Digite dois numeros inciciais: ");
    scanf("%f %f", &x0, &x1);
    printf("Informe a precicao: ");
    scanf("%f", &precisao);

    do
    {
        x_novo = x1 - ((f(x1))/((f(x1)-f(x0))/(x1 - x0)));
        erro = fabs(x_novo - x1);
        printf("\nX novo: %.7f", x_novo);
        printf("\nErro: %.7f", erro);
        x0 = x1;
        x1 = x_novo;
    } while (erro > fabs(x_novo - x1));
    
    return 0;
}