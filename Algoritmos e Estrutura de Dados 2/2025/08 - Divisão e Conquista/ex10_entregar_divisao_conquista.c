#include <stdio.h>
#include <stdlib.h>

//Exercício 10 lista 2 - Divisão e Conquista

//------------- ANÁLISE DE COMPLEXIDADE ----------------
/*
    Casos base: O(1)
    resultado_metade = T(n/2), onde n é o número de 'vezes' e há apenas uma chamada recursiva
    Verificações: O(1)
    Returns: O(1)

    Portanto, temos: T(n) = T(n/2) + O(1), onde n é o número de 'vezes'
    caímos no teorema 2 do método mestre, onde:
    Se f(n) pertence a theta(n^(log(a) na base b)), então T(n) pertence
    a theta(n^(log(a) na base b) * (log (n)) na base 2)

    Conferindo:
        f(n) = O(1), a = 1, b = 2+
        theta(n^(log(1) na base 2)) = n^0 = 1
        f(n) pertence a theta(1)
        portanto:
            T(n) é theta(n^(log(1) na base 2) * (log (n)) na base 2)
            -> T(n) é theta(n^(0) * (log (n)) na base 2)
            -> T(n) é theta(1 * (log (n)) na base 2)
            -> T(n) é theta(log (n) na base 2), onde n é o número de vezes
            -> T(n) é O(log n)
*/

int multiplicaDivisaoConquista(int n, int vezes){
    //casos base
    if(vezes == 0)
        return 0;
    if(vezes == 1)
        return n;

    //dividir/conquistar
    int resultado_metade = multiplicaDivisaoConquista(n, vezes/2);

    // se vezes for par
    if(vezes % 2 == 0)
        return resultado_metade + resultado_metade;
    // se for impar
    else
        return n + resultado_metade + resultado_metade;
}

int main(){
    system("cls");

    int n = 3;
    int vezes = 4;
    int resultado = multiplicaDivisaoConquista(n, vezes);

    printf("Resultado de %d x %d = %d\n", n, vezes, resultado);

    return 0;
}