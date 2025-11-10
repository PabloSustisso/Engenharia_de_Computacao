// =============================================================================
// ARQUIVO DE IMPLEMENTACAO DAS FUNCOES DO GRAFO
// =============================================================================

#include <stdio.h>    // Para funcoes de entrada e saida (printf).
#include <stdlib.h>   // Para alocacao de memoria (malloc, free, calloc).
#include "grafo.h"    // Inclui as definicoes das estruturas e prototipos.

// --- FUNCOES DE CRIACAO ---

// Aloca memoria para um novo grafo e o inicializa como vazio.
Grafo *criar_grafo () {
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    g->head = NULL;
    return g;
}

// Aloca memoria para um novo no de vertice (Lista).
Lista *criar_lista (int vert) {
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->vert = vert;
    l->proximo = NULL;
    l->head = NULL;
    return l;
}

// Aloca memoria para um novo no de adjacencia (Node).
// (MODIFICADO: agora recebe o peso)
Node *criar_node (int adj, int peso) {
    Node *n = (Node*)malloc(sizeof(Node));
    n->adj = adj;
    n->peso = peso; // Armazena o peso
    n->proximo = NULL;
    return n;
}

// --- FUNCOES DE BUSCA E AUXILIARES ---

// Verifica se um vertice existe no grafo.
// Retorna 1 se encontrar, 0 caso contrario.
int buscar_vertice (Grafo *g, int vert) {
    Lista *aux = g->head;
    while (aux != NULL) {
        if (aux->vert == vert)
            return 1;
        aux = aux->proximo;
    }
    return 0;
}

// Verifica se uma aresta entre dois vertices existe.
// Retorna 1 se encontrar, 0 caso contrario.
int buscar_aresta (Grafo *g, int origem, int destino) {
    if (origem == destino) {
        return 0;
    }
    
    if (buscar_vertice(g, origem) && buscar_vertice(g, destino)) {
        Lista *lista_aux = g->head;
        while (lista_aux != NULL && lista_aux->vert != origem) {
            lista_aux = lista_aux->proximo;
        }

        if (lista_aux != NULL) {
            Node *node_aux = lista_aux->head;
            while (node_aux != NULL) {
                if (node_aux->adj == destino) {
                    return 1;
                }
                node_aux = node_aux->proximo;
            }
        }
    }
    return 0;
}

// (NOVO) Funcao auxiliar para encontrar o ponteiro do no de um vertice.
// Retorna o ponteiro para o 'Lista' ou NULL se nao encontrar.
Lista *obter_no_lista(Grafo *g, int vert_id) {
    Lista *aux = g->head;
    while (aux != NULL) {
        if (aux->vert == vert_id) {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

// (NOVO) Funcao auxiliar para encontrar o maior ID de vertice no grafo.
// Util para alocar arrays de 'visitados'.
int obter_max_vertice(Grafo *g) {
    int max_id = 0;
    Lista *aux = g->head;
    while (aux != NULL) {
        if (aux->vert > max_id) {
            max_id = aux->vert;
        }
        aux = aux->proximo;
    }
    return max_id;
}


// --- FUNCOES DE INSERCAO ---

// Insere um novo vertice na lista principal do grafo de forma ordenada.
void inserir_vertice (Grafo *g, int vert) {
    if (buscar_vertice(g, vert)) {
        printf("O vertice %d ja existe no grafo!\n", vert);
        return;
    }

    Lista *novo_vertice = criar_lista(vert);

    if (g->head == NULL || g->head->vert > vert) {
        novo_vertice->proximo = g->head;
        g->head = novo_vertice;
    }
    else {
        Lista *atual = g->head;
        while (atual->proximo != NULL && atual->proximo->vert < vert) {
            atual = atual->proximo;
        }
        novo_vertice->proximo = atual->proximo;
        atual->proximo = novo_vertice;
    }
    printf("Vertice %d inserido com sucesso!\n", vert);
}

// Funcao auxiliar (static) para inserir um no de adjacencia de forma ordenada.
// (MODIFICADO: agora recebe o peso)
static void inserir_adjacencia_ordenado(Lista *vertice, int adj_valor, int peso) {
    Node *novo_node = criar_node(adj_valor, peso);
    
    if (vertice->head == NULL || vertice->head->adj > adj_valor) {
        novo_node->proximo = vertice->head;
        vertice->head = novo_node;
        return;
    }
    
    Node *atual = vertice->head;
    while (atual->proximo != NULL && atual->proximo->adj < adj_valor) {
        atual = atual->proximo;
    }
    novo_node->proximo = atual->proximo;
    atual->proximo = novo_node;
}

// Insere uma aresta entre uma origem e um destino (de forma simetrica).
// (MODIFICADO: agora recebe o peso)
void inserir_aresta (Grafo *g, int origem, int destino, int peso) {
    if (origem == destino) {
        printf("O vertice de origem precisa ser diferente do vertice de destino!\n");
        return;
    }
    if (buscar_aresta(g, origem, destino)) {
        printf("A aresta entre %d e %d ja existe!\n", origem, destino);
        return;
    }
    
    // A insercao so ocorre se ambos os vertices existirem.
    Lista *lista_origem = obter_no_lista(g, origem);
    Lista *lista_destino = obter_no_lista(g, destino);

    if (lista_origem && lista_destino) {
        // Insere a adjacencia em ambos os sentidos com o mesmo peso.
        inserir_adjacencia_ordenado(lista_origem, destino, peso);
        inserir_adjacencia_ordenado(lista_destino, origem, peso);
        printf("Aresta entre %d e %d (Peso: %d) inserida com sucesso!\n", origem, destino, peso);
    } else {
        printf("Um ou ambos os vertices (%d, %d) nao existem no grafo!\n", origem, destino);
    }
}

// --- FUNCOES DE REMOCAO E VISUALIZACAO ---

// Imprime o grafo no formato de lista de adjacencias.
// (MODIFICADO: agora exibe o peso)
void visualizar_grafo (Grafo *g) {
    Lista *lista_aux = g->head;
    printf("\n---------- GRAFO (Vertices: Vizinho(Peso)) ----------\n");
    
    if (lista_aux == NULL) {
        printf("Grafo vazio.\n");
    }

    while (lista_aux != NULL) {
        printf("%d -> ", lista_aux->vert);
        Node *node_aux = lista_aux->head;
        
        if (node_aux == NULL) {
            printf("(Nenhum vizinho)");
        }
        
        while (node_aux != NULL) {
            // Exibe o vizinho e o peso da aresta
            printf("%d(p:%d) ", node_aux->adj, node_aux->peso);
            if (node_aux->proximo != NULL)
                printf("-> ");
            node_aux = node_aux->proximo;
        }
        printf("\n");
        lista_aux = lista_aux->proximo;
    }
    printf("-----------------------------------------------------\n");
}

// Libera toda a memoria alocada para o grafo.
void liberar_grafo (Grafo *g) {
    Lista *lista_atual = g->head;
    
    while (lista_atual != NULL) {
        Lista *proxima_lista = lista_atual->proximo;
        Node *node_atual = lista_atual->head;

        while (node_atual != NULL) {
            Node *proximo_node = node_atual->proximo;
            free(node_atual);
            node_atual = proximo_node;
        }
        free(lista_atual);
        lista_atual = proxima_lista;
    }
    free(g);
}

// Funcao auxiliar para remover um no de adjacencia especifico.
void remover_adjacencia (Lista *vertice, int node_adj_remover) {
    if (vertice == NULL || vertice->head == NULL) {
        return;
    }
    Node *no_atual = vertice->head;
    Node *no_anterior = NULL;
    
    while (no_atual != NULL && no_atual->adj != node_adj_remover) {
        no_anterior = no_atual;
        no_atual = no_atual->proximo;
    }

    if (no_atual != NULL) {
        if (no_anterior == NULL)
            vertice->head = no_atual->proximo;
        else
            no_anterior->proximo = no_atual->proximo;
        
        free(no_atual);
    }
}

// Remove um vertice e todas as arestas conectadas a ele.
void remover_vertice (Grafo *g, int vert) {
    if (!buscar_vertice(g, vert)) {
        printf("O vertice %d nao existe no grafo!\n", vert);
        return;
    }

    // Passo 1: Remover todas as arestas que chegam em 'vert'.
    Lista *lista_aux = g->head;
    while (lista_aux != NULL) {
        if (lista_aux->vert != vert) {
             remover_adjacencia(lista_aux, vert);
        }
        lista_aux = lista_aux->proximo;
    }

    // Passo 2: Remover o proprio vertice da lista principal.
    Lista *lista_remover = g->head;
    Lista *lista_anterior = NULL;
    
    while (lista_remover != NULL && lista_remover->vert != vert) {
        lista_anterior = lista_remover;
        lista_remover = lista_remover->proximo;
    }

    // Libera a lista de adjacencias do vertice removido.
    Node *node_remover = lista_remover->head;
    while(node_remover != NULL) {
        Node *temp = node_remover;
        node_remover = node_remover->proximo;
        free(temp);
    }
    
    // Religa os ponteiros da lista principal.
    if (lista_anterior == NULL)
        g->head = lista_remover->proximo;
    else
        lista_anterior->proximo = lista_remover->proximo;

    free(lista_remover);
    printf("Vertice %d removido com sucesso!\n", vert);
}

// Remove uma aresta entre dois vertices.
void remover_aresta (Grafo *g, int origem, int destino) {
    if (!buscar_aresta(g, origem, destino)) {
        printf("A aresta %d -> %d nao existe no grafo!\n", origem, destino);
        return;
    }
    
    Lista *l_origem = obter_no_lista(g, origem);
    Lista *l_destino = obter_no_lista(g, destino);
    
    if (l_origem != NULL)
        remover_adjacencia(l_origem, destino);
    if (l_destino != NULL)
        remover_adjacencia(l_destino, origem);

    printf("Aresta entre %d e %d removida com sucesso!\n", origem, destino);
}


// --- NOVAS FUNCOES DE ANALISE ---

// (NOVO) Informa o grau de um vertice especifico.
int grau_vertice(Grafo *g, int vert) {
    Lista *no_vertice = obter_no_lista(g, vert);
    if (no_vertice == NULL) {
        printf("Vertice %d nao encontrado!\n", vert);
        return -1; // Retorna -1 para indicar erro
    }

    int grau = 0;
    Node *vizinho = no_vertice->head;
    while (vizinho != NULL) {
        grau++;
        vizinho = vizinho->proximo;
    }
    
    printf("O grau do vertice %d e: %d\n", vert, grau);
    return grau;
}

// (NOVO) Funcao auxiliar recursiva (DFS) para visitar componentes conexas.
static void dfs_visita(Grafo *g, int vert_id, int *visitados) {
    // Marca o vertice atual como visitado
    visitados[vert_id] = 1;

    // Obtem o no da lista principal para o vertice atual
    Lista *no_vertice = obter_no_lista(g, vert_id);
    if (no_vertice == NULL) return; // Protecao

    // Percorre todos os vizinhos
    Node *vizinho = no_vertice->head;
    while (vizinho != NULL) {
        // Se o vizinho ainda nao foi visitado, visita recursivamente
        if (visitados[vizinho->adj] == 0) {
            dfs_visita(g, vizinho->adj, visitados);
        }
        vizinho = vizinho->proximo;
    }
}

// (NOVO) Conta o numero de componentes conexas do grafo.
// Retorna o numero de componentes.
static int contar_componentes_conexas(Grafo *g) {
    if (g->head == NULL) {
        return 0; // Grafo vazio, 0 componentes
    }

    // Encontra o maior ID para alocar o array de visitados
    int max_vert = obter_max_vertice(g);
    // calloc inicializa todos os elementos com 0 (nao visitado)
    int *visitados = (int*)calloc(max_vert + 1, sizeof(int));
    if (visitados == NULL) {
        printf("Erro de alocacao de memoria para 'visitados'.\n");
        return -1;
    }

    int componentes = 0;
    Lista *atual = g->head;

    // Percorre todos os vertices da lista principal
    while (atual != NULL) {
        // Se o vertice 'atual' ainda nao foi visitado...
        if (visitados[atual->vert] == 0) {
            // ... encontramos o inicio de uma nova componente.
            componentes++;
            // Inicia a DFS a partir dele para marcar todos os alcancaveis.
            dfs_visita(g, atual->vert, visitados);
        }
        atual = atual->proximo;
    }

    free(visitados); // Libera o array auxiliar
    return componentes;
}

// (NOVO) Funcao principal para verificar a conectividade.
void verificar_conectividade(Grafo *g) {
    int componentes = contar_componentes_conexas(g);
    
    if (componentes == 0) {
        printf("O grafo esta vazio.\n");
    } else if (componentes == 1) {
        printf("O grafo E CONEXO (possui 1 componente).\n");
    } else {
        printf("O grafo NAO E CONEXO (possui %d componentes).\n", componentes);
    }
}

// (NOVO) Funcao auxiliar para contar componentes que possuem arestas.
// (Necessaria para a definicao correta de Grafo Euleriano)
static int contar_componentes_nao_nulas(Grafo *g) {
     if (g->head == NULL) return 0;

    int max_vert = obter_max_vertice(g);
    int *visitados = (int*)calloc(max_vert + 1, sizeof(int));
    if (visitados == NULL) return -1; // Erro de memoria

    int componentes_reais = 0;
    Lista *atual = g->head;

    while (atual != NULL) {
        // So inicia a busca se o vertice nao foi visitado E tem grau > 0
        if (visitados[atual->vert] == 0 && atual->head != NULL) { 
            componentes_reais++;
            dfs_visita(g, atual->vert, visitados);
        }
        atual = atual->proximo;
    }

    free(visitados);
    return componentes_reais;
}

// (NOVO) Informa se o grafo e Euleriano.
void verificar_euleriano(Grafo *g) {
    printf("\n--- Analise de Grafo Euleriano ---\n");
    if (g->head == NULL) {
        printf("O grafo esta vazio. Nao e Euleriano.\n");
        return;
    }

    // 1. Verifica os graus de todos os vertices
    int vertices_impares = 0;
    Lista *atual = g->head;
    while (atual != NULL) {
        int grau = 0;
        Node *vizinho = atual->head;
        while (vizinho != NULL) {
            grau++;
            vizinho = vizinho->proximo;
        }
        
        if (grau % 2 != 0) {
            vertices_impares++;
            printf("Vertice %d possui grau impar (%d).\n", atual->vert, grau);
        }
        atual = atual->proximo;
    }

    if (vertices_impares > 0) {
        printf("NAO E EULERIANO: Possui %d vertices de grau impar.\n", vertices_impares);
        printf("(Um grafo so e Euleriano se TODOS os vertices tem grau par).\n");
        return;
    }

    printf("Todos os vertices possuem grau par.\n");

    // 2. Verifica a conectividade (considerando apenas vertices com arestas)
    int componentes = contar_componentes_nao_nulas(g);
    
    if (componentes == 0) {
        printf("O grafo nao possui arestas. E trivialmente Euleriano.\n");
    } else if (componentes == 1) {
        printf("Todos os vertices de grau > 0 estao em uma unica componente.\n");
        printf("CONCLUSAO: O grafo E EULERIANO.\n");
    } else {
        printf("NAO E EULERIANO: Possui %d componentes conexas com arestas.\n", componentes);
    }
}


// (NOVO) Funcao auxiliar (DFS) para contar Vertices (V) e Arestas (E) de UMA componente.
static void dfs_ciclos(Grafo *g, int vert_id, int *visitados, int *v_comp, int *e_comp_soma_graus) {
    visitados[vert_id] = 1;
    (*v_comp)++; // Incrementa a contagem de vertices desta componente

    Lista *no_vertice = obter_no_lista(g, vert_id);
    if (no_vertice == NULL) return;

    Node *vizinho = no_vertice->head;
    while (vizinho != NULL) {
        (*e_comp_soma_graus)++; // Adiciona 1 para cada ponta de aresta

        if (visitados[vizinho->adj] == 0) {
            dfs_ciclos(g, vizinho->adj, visitados, v_comp, e_comp_soma_graus);
        }
        vizinho = vizinho->proximo;
    }
}

// (NOVO) Informa se o grafo possui ciclos (Formula da Ciclomaticidade).
void verificar_ciclos(Grafo *g) {
    printf("\n--- Analise de Ciclos (C = E - V + P) ---\n");
    if (g->head == NULL) {
        printf("O grafo esta vazio.\n");
        return;
    }

    int max_vert = obter_max_vertice(g);
    int *visitados = (int*)calloc(max_vert + 1, sizeof(int));
    if (visitados == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }

    int componente_id = 0;
    int total_ciclos = 0;
    Lista *atual = g->head;

    // Itera por todas as possiveis componentes
    while (atual != NULL) {
        if (visitados[atual->vert] == 0) {
            componente_id++;
            int v_comp = 0; // Vertices na componente
            int e_comp_soma_graus = 0; // Soma dos graus na componente

            // Roda a DFS para contar V e E da componente
            dfs_ciclos(g, atual->vert, visitados, &v_comp, &e_comp_soma_graus);

            // Num grafo nao direcionado, E = (Soma dos Graus) / 2
            int e_comp = e_comp_soma_graus / 2;
            
            // Formula da Ciclomaticidade para uma componente (P=1)
            // C = E - V + 1
            int ciclos_comp = e_comp - v_comp + 1;
            
            printf("Componente %d:\n", componente_id);
            printf("  - Vertices (V): %d\n", v_comp);
            printf("  - Arestas (E): %d\n", e_comp);
            printf("  - Ciclos Fundamentais (C = E-V+1): %d\n", ciclos_comp);

            total_ciclos += ciclos_comp;
        }
        atual = atual->proximo;
    }
    
    printf("-------------------------------------------\n");
    if (total_ciclos == 0) {
        printf("O grafo E ACICLICO (nao possui ciclos).\n");
    } else {
        printf("O grafo POSSUI CICLOS (Total de %d ciclos fundamentais).\n", total_ciclos);
    }

    free(visitados);
}