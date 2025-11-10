// =============================================================================
// ARQUIVO PRINCIPAL PARA TESTE E INTERACAO COM O GRAFO
// =============================================================================

#include "grafo.h"    // Inclui a biblioteca do grafo.
#include <stdio.h>    // Para entrada e saida (printf, scanf).
#include <stdlib.h>   // Para a funcao system("cls").

// Funcao para exibir o menu de opcoes para o usuario.
void menu () {
    printf("\n---------- MENU (GRAFOS PONDERADOS) ----------\n");
    printf("1. Inserir Vertice\n");
    printf("2. Inserir Aresta (Ponderada)\n");
    printf("3. Visualizar Grafo\n");
    printf("4. Remover Vertice\n");
    printf("5. Remover Aresta\n");
    printf("6. Inserir grafo predefinido do trabalho\n");
    printf("----------------------------------------------\n");
    printf("7. Informar Grau de um Vertice\n");
    printf("8. Verificar Conectividade (Componentes)\n");
    printf("9. Verificar se e Euleriano\n");
    printf("10. Verificar Ciclos (por Componente)\n");
    printf("----------------------------------------------\n");
    printf("11. Sair\n");
    printf("----------------------------------------------\n\n");
    printf("Selecione uma opcao: ");
}

// Funcao para popular o grafo com um conjunto predefinido de dados.
// (MODIFICADO: agora insere pesos nas arestas)
void grafo_exercicio (Grafo *g) {
    // Insere os vertices de 1 a 9.
    for(int i = 1; i <= 9; i++)
        inserir_vertice(g, i);

    printf("\n");
    // Insere as arestas predefinidas com pesos arbitrarios.
    inserir_aresta(g, 1, 2, 5);  // Peso 5
    inserir_aresta(g, 1, 6, 2);  // Peso 2
    inserir_aresta(g, 2, 4, 10); // Peso 10
    inserir_aresta(g, 2, 3, 3);  // Peso 3
    inserir_aresta(g, 3, 5, 1);  // Peso 1
    inserir_aresta(g, 4, 6, 8);  // Peso 8
    inserir_aresta(g, 4, 5, 4);  // Peso 4
    inserir_aresta(g, 4, 7, 7);  // Peso 7
    inserir_aresta(g, 7, 8, 6);  // Peso 6
    inserir_aresta(g, 7, 9, 9);  // Peso 9
}

// Funcao principal do programa.
int main () {
    // Cria um novo grafo vazio.
    Grafo *g = criar_grafo();
    // Variaveis para controle do menu e entrada de dados.
    int qtd_opcoes = 11, opc, vert, origem, destino, peso; // Adicionado 'peso'

    // Laco principal do menu. Continua ate o usuario escolher sair.
    do {
        menu();
        scanf("%d", &opc);

        // Limpa a tela e avisa sobre opcao invalida.
        if (opc > qtd_opcoes || opc < 1) {
            system("cls");
            if (opc != qtd_opcoes) { // Nao mostra "opcao invalida" se for "Sair"
                printf("\nInsira uma opcao valida (1 a %d)!\n", qtd_opcoes);
            }
        }

        // Estrutura switch para tratar a escolha do usuario.
        switch (opc) {
            case 1: // Inserir Vertice
                printf("Informe o vertice a ser adicionado: ");
                scanf("%d", &vert);
                system("cls");
                inserir_vertice(g, vert);
                break;
            
            case 2: // Inserir Aresta (MODIFICADO)
                printf("Informe o vertice de origem: ");
                scanf("%d", &origem);
                printf("Informe o vertice de destino: ");
                scanf("%d", &destino);
                printf("Informe o PESO da aresta: "); // Pede o peso
                scanf("%d", &peso);
                system("cls");
                inserir_aresta(g, origem, destino, peso);
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
                printf("Informe o vertice de destino: ");
                scanf("%d", &destino);
                system("cls");
                remover_aresta(g, origem, destino);
                break;

            case 6: // Grafo Predefinido
                system("cls");
                grafo_exercicio(g);
                break;

            case 7: // (NOVO) Grau do Vertice
                printf("Informe o vertice para verificar o grau: ");
                scanf("%d", &vert);
                system("cls");
                grau_vertice(g, vert);
                break;

            case 8: // (NOVO) Verificar Conectividade
                system("cls");
                verificar_conectividade(g);
                break;

            case 9: // (NOVO) Verificar Euleriano
                system("cls");
                verificar_euleriano(g);
                break;
                
            case 10: // (NOVO) Verificar Ciclos
                system("cls");
                verificar_ciclos(g);
                break;

            case 11: // Sair
                system("cls");
                printf("Encerrando o programa e liberando a memoria...\n");
                break;

            default: // Opcao invalida (ja tratada acima)
                break;
        }

    } while (opc != qtd_opcoes);

    // Funcao essencial para liberar toda a memoria alocada antes de fechar.
    liberar_grafo(g);
    printf("Memoria liberada. Ate logo!\n");

    return 0; // Finaliza o programa com sucesso.
}