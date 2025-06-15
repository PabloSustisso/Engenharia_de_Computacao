#include <stdio.h>
#include <stdlib.h>

//Exercício 4 lista 2 - Método Guloso

// ----------- ANÁLISE DE COMPLEXIDADE -----------
/*
    Irei analisar apenas a função de resolução do exercício:
    Começa com o bubblesort que tem complexidade O(n²), o que vai dominar a complexidade do código.
    Variáveis criadas e adicionadas irei considerar O(1).

    Primeiro FOR: itera n+1 vezes, sendo n = tamanho do vetor
        as verificações e atribuições dentro do for são O(1)*n vezes
    
    MALLOC é uma função muito rápida, portanto, O(1)

    Segundo FOR: itera k+1 vezes, sendo k = tamanho do subvetor
        que no pior caso k = n, portanto, itera n+1 vezes
        faz n atribuições no pior caso

    RETURN é constante O(1)

    PORTANTO: O(n²) + O(n) + O(n) = O(n²) (Acredito que não preciso provar isso)
    CONCLUSÃO: A complexidade do algoritmo vai depender do método de ordenação utilizado
        O melhor a se utilizar visando a menor complexidade possível seria o MergeSort ou TimSort por exemplo
            que possuem complexidade (n*Log(n))
*/

#define TAM 10

void imprimir_vetor(int vet[], int tam){
    for(int i = 0; i < tam; i++)
        printf("%d ", vet[i]);
}

void bubble_sort(int vet[], int tam){
    for(int i = 1; i < tam; i++){
        for(int j = 0; j < tam - 1; j++){
            if(vet[j] > vet[j+1]){
                int aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;
            }
        }
    }
}

int* metodo_guloso(int A[], int C, int *k_resultado, int *soma_resultado){
    bubble_sort(A, TAM); //ordenar o vetor do menor pro maior arquivo
    //isso garante uma solução ótima para esse caso

    *k_resultado = 0; //fiz dessa forma para poder reutilizar os valores na main
    *soma_resultado = 0;

    //verificação para capacidade
    for(int i = 0; i < TAM; i++){
        if(*soma_resultado + A[i] <= C){
            *soma_resultado += A[i];
            (*k_resultado)++; //calculando o tamanho do subvetor
        }
    }

    int *sub = (int*)malloc(*k_resultado * sizeof(int));
    //transferindo os valores para o subvetor
    for(int i = 0; i < *k_resultado; i++)
        sub[i] = A[i];

    return sub;
}

int main(){
    int A[TAM]; //lista com o tamanho dos arquivos
    int C = 35; //capacidade
    int y = 0; //variavel de controle

    //preenchendo o vetor de TAM até 1
    for(int i = TAM; i > 0; i--){
        A[y] = i;
        y++;
    }

    int k = 0, soma = 0;

    int *sub = metodo_guloso(A, C, &k, &soma); //subvetor solução

    printf("Capacidade: %d\n", C);
    imprimir_vetor(A, TAM);
    printf("\n");
    imprimir_vetor(sub, k);
    printf("  soma: %d", soma);
    free(sub);

    return 0;
}