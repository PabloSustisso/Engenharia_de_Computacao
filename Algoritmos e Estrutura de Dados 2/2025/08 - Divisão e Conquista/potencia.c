#include <stdio.h>
#include <stdlib.h>

int potencia(int a, int n){
    if(n == 0)
        return 1;

    int p;
    p = potencia(a, n/2);
    p = p*p;

    if(n % 2 != 0)
        p = a*p;

    return p;
}

int main(){
    int a = 2;
    int n = 10;

    system("cls");
    printf("Calculando %d elevado a %d:\n", a, n);
    printf("----------------------------\n");
    printf("%d elevado a %d = %d\n", a, n, potencia(a, n));

    return 0;
}