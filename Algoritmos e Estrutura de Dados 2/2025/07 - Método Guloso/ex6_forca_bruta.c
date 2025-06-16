#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para INT_MAX
#include <string.h> // Para a função memcpy

//Exercício 6 lista 2 - Prova por força bruta
//OBS: o gemini fez esse código, pois não tive capacidade cerebral o suficiente para pensar por mim mesmo, porém, entendi o conceito
//OBS2: o resultado encontrado pela força bruta não é o mesmo encontrado pelo método guloso
//portanto, a solução pelo método guloso não foi ótima

#define N 10

// Declaração da função recursiva (protótipo) para que forca_bruta a conheça
void gerar_permutacoes(int matriz[N][N], int percurso_atual[], int visitadas[], int nivel,
                         int melhor_percurso[], int *menor_distancia_global);

// Função "controladora" que inicia o processo de força bruta
void forca_bruta(int matriz[N][N], int percurso_final[], int *distancia_total) {
    // ---- 1. INICIALIZAÇÃO ----

    // Inicializa a menor distância encontrada com um valor "infinito"
    *distancia_total = INT_MAX;

    // Vetor para construir cada permutação durante a recursão
    int percurso_atual[N];
    // Vetor para marcar cidades visitadas em cada permutação
    int visitadas[N] = {0};

    // ---- 2. CONFIGURANDO O PONTO DE PARTIDA ----

    // Fixamos a cidade inicial como 0 para evitar calcular ciclos duplicados
    percurso_atual[0] = 0;
    visitadas[0] = 1;

    // ---- 3. INICIANDO A RECURSÃO ----

    // Chama a função recursiva para gerar todos os caminhos a partir do nível 1
    // (já que o nível 0, a cidade inicial, já foi definido)
    gerar_permutacoes(matriz, percurso_atual, visitadas, 1,
                      percurso_final, distancia_total);
}

/**
 * Função recursiva que gera todas as permutações de caminhos (o coração da força bruta).
 * @param nivel - A profundidade atual na árvore de recursão (quantas cidades no percurso_atual).
 * @param menor_distancia_global - Ponteiro para a menor distância encontrada em TODAS as chamadas.
 * @param melhor_percurso - Ponteiro para o vetor que guarda o melhor caminho encontrado.
 */
void gerar_permutacoes(int matriz[N][N], int percurso_atual[], int visitadas[], int nivel,
                         int melhor_percurso[], int *menor_distancia_global) {

    // ---- CASO BASE: Um caminho completo foi formado ----
    if (nivel == N) {
        int distancia_deste_percurso = 0;

        // Calcula a distância do caminho recém-formado
        for (int i = 0; i < N - 1; i++) {
            distancia_deste_percurso += matriz[percurso_atual[i]][percurso_atual[i + 1]];
        }
        // Adiciona a distância de volta para a cidade inicial
        distancia_deste_percurso += matriz[percurso_atual[N - 1]][percurso_atual[0]];

        // Verifica se este caminho é melhor que o melhor encontrado até agora
        if (distancia_deste_percurso < *menor_distancia_global) {
            *menor_distancia_global = distancia_deste_percurso;
            // Copia o percurso atual para o melhor percurso
            memcpy(melhor_percurso, percurso_atual, N * sizeof(int));
        }
        return; // Finaliza esta chamada recursiva
    }

    // ---- PASSO RECURSIVO: Tentar todas as próximas cidades possíveis ----
    for (int i = 0; i < N; i++) {
        // Se a cidade 'i' ainda não foi visitada neste caminho
        if (visitadas[i] == 0) {
            // 1. "ESCOLHA" -> Adiciona a cidade 'i' ao caminho atual
            visitadas[i] = 1;
            percurso_atual[nivel] = i;

            // 2. "EXPLORE" -> Chama a função para o próximo nível
            gerar_permutacoes(matriz, percurso_atual, visitadas, nivel + 1,
                              melhor_percurso, menor_distancia_global);

            // 3. "DESFAÇA A ESCOLHA" (BACKTRACK) -> Essencial para testar outras possibilidades
            visitadas[i] = 0;
        }
    }
}


int main() {
    int matriz[N][N] = {
        {  0, 12, 10, 19,  8, 15, 14, 20, 18, 11 },
        { 12,  0,  7,  9, 13, 16, 11, 10, 14, 17 },
        { 10,  7,  0,  5,  9, 12, 18, 14, 11, 13 },
        { 19,  9,  5,  0,  6, 10, 17, 13, 12, 15 },
        {  8, 13,  9,  6,  0, 11, 15,  9,  7, 10 },
        { 15, 16, 12, 10, 11,  0,  6, 13, 14, 12 },
        { 14, 11, 18, 17, 15,  6,  0,  8, 10,  9 },
        { 20, 10, 14, 13,  9, 13,  8,  0,  6,  7 },
        { 18, 14, 11, 12,  7, 14, 10,  6,  0,  5 },
        { 11, 17, 13, 15, 10, 12,  9,  7,  5,  0 }
    };

    int percurso_otimo[N + 1];
    int distancia_otima = 0;

    printf("Executando a forca bruta... (Isso pode levar alguns segundos)\n");
    forca_bruta(matriz, percurso_otimo, &distancia_otima);

    // Adiciona a volta para casa no final do vetor para impressão
    percurso_otimo[N] = percurso_otimo[0];

    printf("\nSolucao pela FORCA BRUTA (Resultado Otimo Garantido):\n");
    printf("----------------------------------------------------------\n");
    printf("Distancia otima encontrada: %d\n", distancia_otima);
    printf("Percurso otimo: ");
    for (int i = 0; i <= N; i++) {
        printf("C%d", percurso_otimo[i] + 1);
        if (i < N) {
            printf(" -> ");
        }
    }
    printf("\n");

    return 0;
}