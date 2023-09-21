//Método da Bisseção

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define e 2.718281828459045235360287
#define pi 3.14159265359

float function(float x)
{
    float f;

    f = (275 * log((1850) / (1850 - (27 * x)))) + (9.8 * x) - 150;

    return f;
}

int main(void)
{
    float precisao;
    float a, b, Xm, f_a, f_b, f_xm, erro;
    int n_iteracoes;

    printf("Digite o intervalo do zero da funcao: ");
    scanf("%f %f", &a, &b);
    printf("Digite a precisao desejada: ");
    scanf("%f", &precisao);

    Xm = (a + b) / 2;
    f_a = function(a);
    f_b = function(b);
    f_xm = function(Xm);
    erro = ((b) - (a));

    if (erro < 0)
    {
        erro *= (-1);
    }

    n_iteracoes = ceil((log10(b - a) - log10(precisao)) / (log10(2)));
    printf("\nNumero de iteracoes: %d\n", n_iteracoes);

    printf("\na\tXm\tb\tf(a)\tf(Xm)\tf(b)\terro\n");
    printf("%2.4f\t%2.4f\t%2.4f\t%2.4f\t%2.2f\t%2.2f\t%2.6f\n", a, Xm, b, f_a, f_xm, f_b, erro);

    while (erro > precisao)
    {
        if (erro <= precisao)
        {
            break;
        }
        if ((f_a * f_xm) < 0)
        {
            b = Xm;
        }
        else if ((f_xm * f_b) < 0)
        {
            a = Xm;
        }

        Xm = (a + b) / 2;
        f_a = function(a);
        f_b = function(b);
        f_xm = function(Xm);
        erro = ((b) - (a));

        if (erro < 0)
        {
            erro *= (-1);
        }

        printf("%2.4f\t%2.4f\t%2.4f\t%2.4f\t%2.2f\t%2.2f\t%2.6f\n", a, Xm, b, f_a, f_xm, f_b, erro);
    }

    return 0;
}