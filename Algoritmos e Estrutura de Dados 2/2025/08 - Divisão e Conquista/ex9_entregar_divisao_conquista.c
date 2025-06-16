#include <stdio.h>
#include <stdlib.h>

//Exercício 9 lista 2 - Divisão e Conquista

/*
----------- ANÁLISE DA COMPLEXIDADE -----------
    A divisão e conquista tem como estratégia principal dividir o problema ao meio
    até que se torne um subproblema de n-n+1, onde a solução é obvia.
    Como a função é recursiva, teremos uma função T(n) que descreve uma recorrência:

        Caso base: vetor[0], se o vetor tiver apenas um elemento
        para as atribuições e comparações irei considerar O(1), portanto:
            dividir ao meio = O(1)
            retornar a função com a metade do vetor = T(n/2)
            retornar a função com a metade do vetor = T(n/2)
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
*/

// Função que soma os elementos de um vetor em um dado intervalo de índices
int somaVetorDivisaoConquista(int vetor[], int inicio, int fim) {
    //casos base
    if (inicio == fim) 
        return vetor[inicio];
    
    if (inicio > fim) 
        return 0;
    

    //dividir o problema no meio
    int meio = inicio + (fim - inicio) / 2;

    //conquistar
    int somaEsquerda = somaVetorDivisaoConquista(vetor, inicio, meio);
    int somaDireita = somaVetorDivisaoConquista(vetor, meio + 1, fim);

    return somaEsquerda + somaDireita;
}

int somarVetor(int vet[], int tam){
    somaVetorDivisaoConquista(vet, 0, tam - 1);
}

int main() {
    int vet[] = {10, 5, 2, 8, 15, 7};
    int tam = sizeof(vet) / sizeof(vet[0]); //tamanho do vetor, já que a linguagem C n tem uma função pra isso

    int resultado = somarVetor(vet, tam);

    system("cls");
    printf("A soma dos elementos do vetor = %d\n", resultado);

    return 0;
}