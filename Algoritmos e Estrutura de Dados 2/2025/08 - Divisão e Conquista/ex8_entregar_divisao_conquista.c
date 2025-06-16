#include <stdio.h>
#include <stdlib.h>

//Exercício 8 lista 2 - Divisão e Conquista

// Respondendo as questões do exercício 8:
/*
    A estratégia de divisão e conquista não é eficiente para esse tipo de problema,
    pois se fizermos uma análise da complexidade chegaremos a um resultado de O(n).

    ----------- ANÁLISE DA COMPLEXIDADE -----------
    A divisão e conquista tem como estratégia principal dividir o problema ao meio
    até que se torne um subproblema de n-n+1, onde a solução é obvia.
    Como a função é recursiva, teremos uma função T(n) que descreve uma recorrência:

        Casos base: 0, se n = 0
                    1, se n = 1
        para as atribuições e comparações irei considerar O(1), portanto:
            dividir ao meio = O(1)
            retornar a função com a metade de n = T(n/2)
            retornar a função com a metade de n = T(n/2)
            portanto, temos que T(n) = 2*T(n/2) + O(1)
            Verificando o teorema mestre caímos no caso 1
                Se f(n) pertence a O(n^((log(a) na base b) - e)) para alguma constante e > 0
                então T(n) pertence theta(n^(log(a) na base b)

                Prova:
                O(n^(log(2-e) na base 2)) com e = 1
                O(n^((log(2) na base 2)-1))
                O(n^(1-1)) = O(n^0) = O(1)

                como nosso f(n) = O(1), então f(n) pertence O(n^((log(a) na base b) - e)), e > 0
                e, portanto, a complexidade de T(n) é theta(n^1) = O(n)

    Ta mas porque não é eficiente?
    -> Existe uma fórmula matemática que calcula o n-ésimo termo de uma progressão aritmética
    -> Sn = (n*(n+1))/2
    -> ou seja, uma forma de calcular o mesmo problema com complexidade constante O(1)
    sem a necessidade de recursão ou loops iterativos.
*/

//funcao que retorna a soma de 0 ate n
int somaDivisaoConquista(int inicio, int fim){
    //casos base
    if(inicio > fim)
        return 0;
    if(inicio == fim)
        return inicio;
    
    //dividir o problema no meio
    int meio = inicio + (fim - inicio)/2;

    //conquistar
    int somaMetade1 = somaDivisaoConquista(inicio, meio);
    int somaMetade2 = somaDivisaoConquista(meio+1, fim);

    return somaMetade1 + somaMetade2;
}

int soma(int n){
    somaDivisaoConquista(0, n);
}

int main(){
    int n = 5;
    int resultado = soma(n);
    system("cls");
    printf("A soma de 0 ate %d = %d\n", n, resultado);

    return 0;
}