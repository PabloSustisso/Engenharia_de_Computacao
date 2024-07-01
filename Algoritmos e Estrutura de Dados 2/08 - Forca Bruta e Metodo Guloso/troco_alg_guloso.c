#include <stdio.h>
#include <stdlib.h>

// Algoritmos gulosos sao tipicamente usados para resolver problemas de otimizacao
// Objetivo: maximizar ou minimizar

// Um dos segredos dos algoritmos gulosos eh a forma de ordenacao/organizacao
// do conjunto de entrada

// Alg gulosos sao utilziados para resovler problemas de otimizacao que funcionem
// atraves de uma sequencia de passos

// Exemplos: problema do troco, problema da mochila, selecao de atividades
/*---------------------------------------------------------------------------------*/

// Problema do troco:
// Seja E = {e1, e2, ..., en}, e M, um valor positivo que representa o troco
// Supondo que E esteja ordenado de forma decrescente:
    // No passo i, escolher r(i) = j, tal que e(j) <= M e e(j-1) > M
    // Dividir M por e(j)
    // No proximo passo, utilizar o resto da divisao (M % e(j))
    // Aplicar esse processo ate o troco ser zerado (resto da divisao for zero)
    // ou todas as moedas terem sido percorridas
// Algoritmo:
    // Ordene o valor das moedas de forma decrescente
    // Comencando com a primeira moeda (i = 0), divida o valor do troco pelo valor
    // da moeda i (caso o valor do troco seja maior que o da moeda)
        // Adicione a parte inteira da divisao no conjunto da solucao
        // Utilize o resto da divisao na proxima iteracao

// Minimizar o numero de moedas
int qtd_moedas(int moedas[], int n, int troco)
{
    int i, n_moedas = 0;

    for (i = 0; i < n && troco > 0; i++)
    {
        // atualizar o valor do troco faltante
        n_moedas += troco / moedas[i];
        // atualizar o valor do troco faltante
        troco = troco % moedas[i];
    }
    if (troco == 0)
        return n_moedas; // solucao encontrada
    else
        return -1; // solucao nao encontrada
}

// Adaptado para retornar o vetor com as moedas utilizadas
int* qtd_moedas2(int moedas[], int n, int troco, int* tamanho)
{
    int i, j = 0;
    int* moedas_utilizadas = (int*)malloc(sizeof(int) * troco); // Alocando o pior caso possível

    for (i = 0; i < n && troco > 0; i++)
    {
        while (troco >= moedas[i])
        {
            troco -= moedas[i];
            moedas_utilizadas[j++] = moedas[i];
        }
    }

    if (troco > 0)
    {
        free(moedas_utilizadas);
        return NULL; // solucao nao encontrada
    }
    else
    {
        *tamanho = j;
        return moedas_utilizadas; // solucao encontrada
    }
}

int main()
{
    int moedas[4] = {300, 250, 100, 1};
    int tamanho, i;

    int* r = qtd_moedas2(moedas, 4, 450, &tamanho);
    if (r != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            printf("%d ", r[i]);
        }
        free(r);
    }
    else
    {
        printf("Solução não encontrada\n");
    }

    return 0;
}