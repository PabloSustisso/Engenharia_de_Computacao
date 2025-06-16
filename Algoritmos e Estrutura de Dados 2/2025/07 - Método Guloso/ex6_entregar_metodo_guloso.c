#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Exercício 6 lista 2 - Método Guloso

#define N 10 // numero de cidades

// funcao que retorna um vetor com o percurso encontrado
// e tambem a distancia percorrida
void solve(int matriz[N][N], int percurso[], int *distancia_total){
    //vetor flag para marcar as cidades ja visitadas
    int visitadas[N] = {0};

    // vou definir como ponto de partida a cidade 0 (C1)
    int cidade_atual = 0;
    *distancia_total = 0; // inicializando a distancia
    int cidades_visitadas_contador = 0; // contador que vai ate N-1

    // como irei comecar pela C1 ela ja estara visitada
    percurso[cidades_visitadas_contador] = cidade_atual;
    visitadas[cidade_atual] = 1;
    cidades_visitadas_contador++;

    // aplicando o loop para visitar as demais cidades
    while(cidades_visitadas_contador < N){
        int proxima_cidade = -1;
        int menor_distancia = INT_MAX; // isso ajuda a comparar com valores menores que ele

        // aqui ele vai iterar sobre a linha atual, procurando o menor valor
        for(int i = 0; i < N; i++){
            // verificacoes: 
            // a cidade 'i' ainda nao foi visitada?
            // a distancia da cidade atual ate 'i' eh a menor que temos na linha?
            if(visitadas[i] == 0 && matriz[cidade_atual][i] < menor_distancia){
                menor_distancia = matriz[cidade_atual][i];
                proxima_cidade = i;
            }
        }

        // se encontrarmos uma proxima cidade valida
        if(proxima_cidade != -1){
            *distancia_total += menor_distancia;
            cidade_atual = proxima_cidade;

            percurso[cidades_visitadas_contador] = cidade_atual;
            visitadas[cidade_atual] = 1;
            cidades_visitadas_contador++;
        }
    }

    // volta para fechar o ciclo
    // adiciona a distancia da ultima cidade de volta para a primeira
    *distancia_total += matriz[cidade_atual][percurso[0]];
    percurso[N] = percurso[0];
}

int main(){
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

    int percurso[N+1]; // vetor para guardar o percurso
    int distancia_total = 0;

    solve(matriz, percurso, &distancia_total);

    system("cls");
    printf("Solucao pelo metodo guloso (vizinho mais proximo):\n");
    printf("---------------------------------------------------\n");
    printf("Distancia total percorrida: %d\n", distancia_total);
    printf("Percurso: ");
    for (int i = 0; i <= N; i++) {
        // imprime C1, C2, etc., em vez de 0, 1...
        printf("C%d", percurso[i] + 1); 
        if (i < N) {
            printf(" -> ");
        }
    }
    printf("\n");

    return 0;
}