#include <stdio.h>

#define N 48

long long int F[N+1];

long long int fib_recursivo_top_down(int n);

long long int fib_top_down(int n){
    F[0] = 0;
    F[1] = 1;

    for(int i = 2; i <= n; i++)
        F[i] = -1;
    
    return fib_recursivo_top_down(n);
}

long long int fib_recursivo_top_down(int n){
    if(F[n] == -1)
        F[n] = fib_recursivo_top_down(n-1) + fib_recursivo_top_down(n-2);
    
    return F[n];
}

int main(){
    printf("%lld", fib_top_down(N));

    return 0;
}