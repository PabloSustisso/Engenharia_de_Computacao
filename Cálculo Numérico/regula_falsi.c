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

    printf("Digite o intervalo do zero da funcao: ");
    scanf("%f %f", &a, &b);
    printf("Digite a precisao desejada: ");
    scanf("%f", &precisao);

    f_a = function(a);
    f_b = function(b);
    Xm = ((a * f_b) - (b * f_a)) / ((f_b) - (f_a));
    f_xm = function(Xm);

    if (f_xm < precisao)
        erro = fabs(f_xm);

    printf("\na\tX\tb\tf(a)\tf(X)\tf(b)\terro\n");
    printf("%2.2f\t%2.2f\t%2.2f\t%2.2f\t%2.2f\t%2.2f\t%2.6f\n", a, Xm, b, f_a, f_xm, f_b, erro);

    do
    {
        if (erro <= precisao)
        {
            break;
        }
        
        if (f_a * f_xm < 0)
        {
            b = Xm;
            f_a = function(a);
            f_b = function(b);
            Xm = ((a * f_b) - (b * f_a)) / ((f_b) - (f_a));
            f_xm = function(Xm);

            if (f_xm < precisao)
                erro = fabs(f_xm);
        }
        else
        {
            a = Xm;
            f_a = function(a);
            f_b = function(b);
            Xm = ((a * f_b) - (b * f_a)) / ((f_b) - (f_a));
            f_xm = function(Xm);

            if (f_xm < precisao)
                erro = fabs(f_xm);
        }

        printf("%2.2f\t%2.2f\t%2.2f\t%2.2f\t%2.2f\t%2.2f\t%2.6f\n", a, Xm, b, f_a, f_xm, f_b, erro);

    } while (erro >= precisao);

    return 0;
}