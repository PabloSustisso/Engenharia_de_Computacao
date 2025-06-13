#include <stdio.h>
#include <stdlib.h>

// Definimos um N maior para testar o limite
#define N 48

// Usamos 'long long int' para armazenar números grandes
long long int F[N + 1];

long long int fib_recursivo_top_down(int n);

long long int fib_top_down(int n) {
    for (int i = 2; i <= n; i++) {
        F[i] = -1;
    }

    F[0] = 0;
    F[1] = 1;

    return fib_recursivo_top_down(n);
}

long long int fib_recursivo_top_down(int n) {
    if (F[n] != -1) {
        return F[n];
    }

    F[n] = fib_recursivo_top_down(n - 1) + fib_recursivo_top_down(n - 2);
    
    return F[n];
}

int main() {
    // Usamos %lld para imprimir um 'long long int'
    // A saída agora será a correta: 4807526976
    printf("Fibonacci(%d) = %lld\n", N, fib_top_down(N));

    return 0;
}