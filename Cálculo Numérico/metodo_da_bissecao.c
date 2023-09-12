#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define e 2.718281828459045235360287

int main(void)
{
    float precisao;
    float a, b, Xm, f_a, f_b, f_xm, erro;
    int n_iteracoes;

    printf("Digite o intervalo do zero da funcao: ");
    scanf("%f %f", &a, &b);
    printf("Digite a precisao desejada: ");
    scanf("%f", &precisao);

    // Xm = (a + b) / 2;
    // f_a = 70 * (pow(e, (-1.5 * a))) + 2.5 * (pow(e, (-0.075 * a))) - 9;
    // f_b = 70 * (pow(e, (-1.5 * b))) + 2.5 * (pow(e, (-0.075 * b))) - 9;
    // f_xm = 70 * (pow(e, (-1.5 * Xm))) + 2.5 * (pow(e, (-0.075 * Xm))) - 9;
    // erro = b - a;

    Xm = (a + b) / 2;
    f_a = a * log10(a) - 1;
    f_b = b * log10(b) - 1;
    f_xm = Xm * log10(Xm) - 1;
    erro = (b - a);

    n_iteracoes = ceil((log10(b - a) - log10(precisao)) / (log10(2)));
    printf("\nNumero de iteracoes: %d\n", n_iteracoes);

    printf("\na\tXm\tb\tf(a)\tf(Xm)\tf(b)\terro\n");
    printf("%.2f\t%.4f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", a, Xm, b, f_a, f_xm, f_b, erro);

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

        // Xm = (a + b) / 2;
        // f_a = 70 * (pow(e, (-1.5 * a))) + 2.5 * (pow(e, (-0.075 * a))) - 9;
        // f_b = 70 * (pow(e, (-1.5 * b))) + 2.5 * (pow(e, (-0.075 * b))) - 9;
        // f_xm = 70 * (pow(e, (-1.5 * Xm))) + 2.5 * (pow(e, (-0.075 * Xm))) - 9;
        // erro = b - a;

        Xm = (a + b) / 2;
        f_a = a * log10(a) - 1;
        f_b = b * log10(b) - 1;
        f_xm = Xm * log10(Xm) - 1;
        erro = (b - a);

        printf("%.2f\t%.4f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", a, Xm, b, f_a, f_xm, f_b, erro);
    }

    return 0;
}