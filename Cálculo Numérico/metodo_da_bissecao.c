#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
    float precisao;
    float a, b, Xm, f_a, f_b, f_xm, erro;

    printf("Digite o intervalo do zero da funcao: ");
    scanf("%f %f", &a, &b);
    printf("Digite a precisao desejada: ");
    scanf("%f", &precisao);

    Xm = (a+b)/2;
    f_a = pow(a, 3) - (9*a) + 3;
    f_b = pow(b, 3) - (9*b) + 3;
    f_xm = pow(Xm, 3) - (9*Xm) + 3;
    erro = b-a;

    printf("\na\tXm\tb\tf(a)\tf(Xm)\tf(b)\terro\n");
    printf("%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", a, Xm, b, f_a, f_xm, f_b, erro);
    
    while ((b-a) > precisao)
    {
        if ((b-a) <= precisao)
        {
            break;
        }
        if ((f_a*f_xm) < 0)
        {
            b = Xm;
        }
        else if ((f_xm*f_b) < 0)
        {
            a = Xm;
        }
        
        Xm = (a+b)/2;
        f_a = pow(a, 3) - (9*a) + 3;
        f_b = pow(b, 3) - (9*b) + 3;
        f_xm = pow(Xm, 3) - (9*Xm) + 3;
        erro = erro/2;

        printf("%.2f\t%.4f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", a, Xm, b, f_a, f_xm, f_b, erro);
    }
    
    return 0;
}