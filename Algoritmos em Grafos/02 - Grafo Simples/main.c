// =============================================================================
// ARQUIVO PRINCIPAL PARA TESTE E INTERACAO COM O GRAFO
// =============================================================================

#include "grafo.h"    // Inclui a biblioteca do grafo.
#include <stdio.h>    // Para entrada e saida (printf, scanf).
#include <stdlib.h>   // Para a funcao system("cls").

// Funcao para exibir o menu de opcoes para o usuario.
void menu () {
    printf("\n---------- MENU ----------\n");
    printf("1. Inserir Vertice\n");
    printf("2. Inserir Aresta\n");
    printf("3. Visualizar Grafo\n");
    printf("4. Remover Vertice\n");
    printf("5. Remover Aresta\n");
    printf("6. Inserir grafo predefinido do trabalho\n");
    printf("7. Sair\n");
    printf("--------------------------\n\n");
    printf("Selecione uma opcao: ");
}

// Funcao para popular o grafo com um conjunto predefinido de dados.
void grafo_exercicio (Grafo *g) {
    // Insere os vertices de 1 a 9.
    for(int i = 1; i <= 9; i++)
        inserir_vertice(g, i);

    printf("\n");
    // Insere as arestas predefinidas.
    inserir_aresta(g, 1, 2);
    inserir_aresta(g, 1, 6);
    inserir_aresta(g, 2, 4);
    inserir_aresta(g, 2, 3);
    inserir_aresta(g, 3, 5);
    inserir_aresta(g, 4, 6);
    inserir_aresta(g, 4, 5);
    inserir_aresta(g, 4, 7);
    inserir_aresta(g, 7, 8);
    inserir_aresta(g, 7, 9);
}

// Funcao principal do programa.
int main () {
    // Cria um novo grafo vazio.
    Grafo *g = criar_grafo();
    // Variaveis para controle do menu e entrada de dados.
    int qtd = 7, opc, vert, origem, destino;

    // Laco principal do menu. Continua ate o usuario escolher sair.
    do {
        menu();
        scanf("%d", &opc);

        // Limpa a tela e avisa sobre opcao invalida.
        if (opc > qtd) {
            system("cls");
            printf("\nInsira uma opcao valida!\n");
        }

        // Estrutura switch para tratar a escolha do usuario.
        switch (opc) {
            case 1: // Inserir Vertice
                printf("Informe o vertice a ser adicionado: ");
                scanf("%d", &vert);
                system("cls");
                inserir_vertice(g, vert);
                break;
            
            case 2: // Inserir Aresta
                printf("Informe o vertice de origem: ");
                scanf("%d", &origem);
                printf("informe o vertice de destino: ");
                scanf("%d", &destino);
                system("cls");
                inserir_aresta(g, origem, destino);
                break;

            case 3: // Visualizar Grafo
                system("cls");
                visualizar_grafo(g);
                break;

            case 4: // Remover Vertice
                printf("Informe o vertice a ser removido: ");
                scanf("%d", &vert);
                system("cls");
                remover_vertice(g, vert);
                break;

            case 5: // Remover Aresta
                printf("Informe o vertice de origem: ");
                scanf("%d", &origem);
                printf("informe o vertice de destino: ");
                scanf("%d", &destino);
                system("cls");
                remover_aresta(g, origem, destino);
                break;

            case 6: // Grafo Predefinido
                system("cls");
                grafo_exercicio(g);
                break;

            default: // Qualquer outra opcao (incluindo Sair).
                break;
        }

        // Condicao de saida do laco.
        if (opc == qtd) {
            system("cls");
            break;
        }

    } while (opc < qtd);

    // Funcao essencial para liberar toda a memoria alocada antes de fechar.
    liberar_grafo(g);

    return 0; // Finaliza o programa com sucesso.
}