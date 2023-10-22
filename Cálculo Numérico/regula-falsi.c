#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x) {
    return exp(x) - 2*x - 2 ;
}

int main(void) {
    float epsilon = 0.0001;
    float a, b, raiz, fa, fb, fx, erro;

    printf("Informe o limite inferior do intervalo: ");
    scanf("%f", &a);
    do{
        printf("Informe o limite superior do intervalo: ");
        scanf("%f", &b);
    }while(a >= b);

    fa = f(a);
    fb = f(b);
    raiz = (a * fb - b * fa) / (fb - fa);
    fx = f(raiz);
    erro = fx;

    if (fa * fb > 0) {
        printf("\nA funcao nao possui raiz no intervalo fornecido.\n");
        return 1;
    }

    printf("\na\tXm\tb\tf(a)\tf(Xm)\tf(b)\terro\n");
    printf("%.7f\t%.7f\t%.7f\t%.7f\t%.7f\t%.7f\t%.7f\n", a, raiz, b, fa, fx, fb, erro);
    int i = 0;
    while(i < 2){
        if (fa * fx < 0) {
            b = raiz;
        }
        else {
            a = raiz;
        }

        fa = f(a);
        fb = f(b);
        raiz = (a * fb - b * fa) / (fb - fa);;
        fx = f(raiz);
        erro = fx;
        i++;

        printf("%.7f\t%.7f\t%.7f\t%.7f\t%.7f\t%.7f\t%.7f\n", a, raiz, b, fa, fx, fb, erro);
    }

    printf("\nA raiz aproximada da funcao eh: %.7f\n", raiz);

    return 0;
}
