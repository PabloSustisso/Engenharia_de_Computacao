#include <stdio.h>
#include <math.h>

// Implementacao recursiva da funcao fatorial
int fatorial(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fatorial(n-1);
}

// Somatorio em vetor
int somatorio(int v[], int n)
{
    if (n < 1)
        return 0;
    else
        return v[n-1] + somatorio(v, n-1);
}

// Torre de Hanoi
void hanoi(char de, char para, char via, int n)
{
    if (n >= 1)
    {
        hanoi(de, via, para, n-1);
        printf("disco %d de %c para %c\n", n, de, para);
        hanoi(via, para, de, n-1);
    }   
}

// Pessima aplicabilidade de recursao, pois exige muito processamento
int fibonacci(int n)
{
    if(n <= 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

// Utilizando recursao para calcular o Maximo Divisor Comum entre dois numeros
int MDC(int a, int b)
{
    if (b == 0)
        return a;
    else
        return MDC(b, a%b);
}

int main(void)
{
    //int n = 2, vet[5] = {10, 1, 1, 1, 1};

    //printf("O somatorio da posicao [%d] ate [0] eh: %d", n, somatorio(vet, n));
    
    //hanoi('A', 'C', 'B', 5);

    //printf("%d\n", fibonacci(6));

    printf("MDC: %d", MDC(252, 105));
    
    return 0;
}