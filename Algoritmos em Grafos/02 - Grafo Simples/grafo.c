// =============================================================================
// ARQUIVO DE IMPLEMENTACAO DAS FUNCOES DO GRAFO
// =============================================================================

#include <stdio.h>    // Para funcoes de entrada e saida (printf).
#include <stdlib.h>   // Para alocacao de memoria (malloc, free).
#include "grafo.h"    // Inclui as definicoes das estruturas e prototipos.

// --- FUNCOES DE CRIACAO ---

// Aloca memoria para um novo grafo e o inicializa como vazio.
Grafo *criar_grafo () {
    // Aloca memoria para a estrutura Grafo.
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    // Define o inicio da lista de vertices como NULL, indicando um grafo vazio.
    g->head = NULL;
    return g;
}

// Aloca memoria para um novo no de vertice (Lista).
Lista *criar_lista (int vert) {
    // Aloca memoria para a estrutura Lista.
    Lista *l = (Lista*)malloc(sizeof(Lista));
    // Define o valor do vertice.
    l->vert = vert;
    // Inicializa os ponteiros como NULL, pois ainda nao esta conectado a nada.
    l->proximo = NULL;
    l->head = NULL;
    return l;
}

// Aloca memoria para um novo no de adjacencia (Node).
Node *criar_node (int adj) {
    // Aloca memoria para a estrutura Node.
    Node *n = (Node*)malloc(sizeof(Node));
    // Define o valor do vertice adjacente.
    n->adj = adj;
    // Inicializa o proximo como NULL.
    n->proximo = NULL;
    return n;
}

// --- FUNCOES DE BUSCA ---

// Verifica se um vertice existe no grafo.
// Retorna 1 se encontrar, 0 caso contrario.
int buscar_vertice (Grafo *g, int vert) {
    Lista *aux = g->head; // Ponteiro auxiliar para percorrer a lista de vertices.

    // Percorre a lista enquanto o ponteiro nao for nulo.
    while (aux != NULL) {
        // Se encontrar o vertice com o valor procurado...
        if (aux->vert == vert)
            return 1; // ...retorna 1 (verdadeiro).
        
        // Avanca para o proximo vertice da lista.
        aux = aux->proximo;
    }
    // Se o loop terminar, o vertice nao foi encontrado.
    return 0;
}

// Verifica se uma aresta entre dois vertices existe.
// Retorna 1 se encontrar, 0 caso contrario.
int buscar_aresta (Grafo *g, int origem, int destino) {
    // Arestas de um vertice para ele mesmo nao sao permitidas neste modelo.
    if (origem == destino) {
        return 0;
    }
    
    // So busca a aresta se ambos os vertices existirem no grafo.
    if (buscar_vertice(g, origem) && buscar_vertice(g, destino)) {
        // Encontra a lista de adjacencias do vertice de origem.
        Lista *lista_aux = g->head;
        while (lista_aux != NULL && lista_aux->vert != origem) {
            lista_aux = lista_aux->proximo;
        }

        // Se encontrou a lista de origem, percorre sua lista de adjacencias.
        if (lista_aux != NULL) {
            Node *node_aux = lista_aux->head;
            while (node_aux != NULL) {
                // Se encontrar um no de adjacencia para o destino...
                if (node_aux->adj == destino) {
                    return 1; // ...a aresta existe.
                }
                node_aux = node_aux->proximo;
            }
        }
    }
    // Se chegou aqui, a aresta nao foi encontrada.
    return 0;
}

// --- FUNCOES DE INSERCAO ---

// Insere um novo vertice na lista principal do grafo de forma ordenada.
void inserir_vertice (Grafo *g, int vert) {
    // Primeiro, verifica se o vertice ja existe para evitar duplicatas.
    if (buscar_vertice(g, vert)) {
        printf("O vertice %d ja existe no grafo!\n", vert);
        return;
    }

    Lista *novo_vertice = criar_lista(vert);

    // Caso 1 e 2: A lista esta vazia OU o novo vertice deve ser o primeiro.
    if (g->head == NULL || g->head->vert > vert) {
        novo_vertice->proximo = g->head; // O novo aponta para o antigo primeiro.
        g->head = novo_vertice;         // A cabeca do grafo agora e o novo vertice.
    }
    // Caso 3: O vertice sera inserido no meio ou no fim da lista.
    else {
        Lista *atual = g->head;
        // Avanca 'atual' ate encontrar o local certo para a insercao.
        while (atual->proximo != NULL && atual->proximo->vert < vert) {
            atual = atual->proximo;
        }
        // Realiza a insercao.
        novo_vertice->proximo = atual->proximo;
        atual->proximo = novo_vertice;
    }
    printf("Vertice %d inserido com sucesso!\n", vert);
}

// Funcao auxiliar (static) para inserir um no de adjacencia de forma ordenada.
// Sendo 'static', so pode ser usada dentro deste arquivo .c.
static void inserir_adjacencia_ordenado(Lista *vertice, int adj_valor) {
    Node *novo_node = criar_node(adj_valor);
    
    // Caso 1: A lista de adjacencias esta vazia ou o novo no e o menor.
    if (vertice->head == NULL || vertice->head->adj > adj_valor) {
        novo_node->proximo = vertice->head;
        vertice->head = novo_node;
        return;
    }
    
    // Caso 2: Insere no meio ou no fim.
    Node *atual = vertice->head;
    while (atual->proximo != NULL && atual->proximo->adj < adj_valor) {
        atual = atual->proximo;
    }
    novo_node->proximo = atual->proximo;
    atual->proximo = novo_node;
}

// Insere uma aresta entre uma origem e um destino (de forma simetrica).
void inserir_aresta (Grafo *g, int origem, int destino) {
    if (origem == destino) {
        printf("O vertice de origem precisa ser diferente do vertice de destino!\n");
        return;
    }
    if (buscar_aresta(g, origem, destino)) {
        printf("A aresta entre %d e %d ja existe!\n", origem, destino);
        return;
    }
    
    // A insercao so ocorre se ambos os vertices existirem.
    if (buscar_vertice(g, origem) && buscar_vertice(g, destino)) {
        // Encontra os ponteiros para os nos dos vertices de origem e destino.
        Lista *lista_origem = g->head;
        Lista *lista_destino = g->head;

        while (lista_origem != NULL && lista_origem->vert != origem)
            lista_origem = lista_origem->proximo;

        while (lista_destino != NULL && lista_destino->vert != destino)
            lista_destino = lista_destino->proximo;

        // Se ambos foram encontrados, insere a adjacencia em cada um.
        if (lista_origem && lista_destino) {
            inserir_adjacencia_ordenado(lista_origem, destino); // Adiciona destino aos vizinhos da origem.
            inserir_adjacencia_ordenado(lista_destino, origem); // Adiciona origem aos vizinhos do destino.
            printf("Aresta entre %d e %d inserida com sucesso!\n", origem, destino);
        }
    } else {
        printf("Um ou ambos os vertices nao existem no grafo!\n");
    }
}

// --- FUNCOES DE REMOCAO E VISUALIZACAO ---

// Imprime o grafo no formato de lista de adjacencias.
void visualizar_grafo (Grafo *g) {
    Lista *lista_aux = g->head; // Ponteiro para percorrer os vertices.
    printf("\n---------- GRAFO ----------\n");
    
    // Laco externo: percorre cada vertice.
    while (lista_aux != NULL) {
        printf("%d -> ", lista_aux->vert);
        Node *node_aux = lista_aux->head; // Ponteiro para percorrer as adjacencias.
        
        // Laco interno: percorre os vizinhos do vertice atual.
        while (node_aux != NULL) {
            printf("%d ", node_aux->adj);
            if (node_aux->proximo != NULL)
                printf("-> ");
            node_aux = node_aux->proximo;
        }
        printf("\n");
        lista_aux = lista_aux->proximo;
    }
    printf("---------------------------\n");
}

// Libera toda a memoria alocada para o grafo.
void liberar_grafo (Grafo *g) {
    Lista *lista_atual = g->head;
    
    // Laco externo: percorre e libera cada vertice.
    while (lista_atual != NULL) {
        // Guarda o ponteiro para o proximo vertice antes de liberar o atual.
        Lista *proxima_lista = lista_atual->proximo;

        Node *node_atual = lista_atual->head;
        // Laco interno: percorre e libera a lista de adjacencias do vertice atual.
        while (node_atual != NULL) {
            // Guarda o ponteiro para o proximo no antes de liberar o atual.
            Node *proximo_node = node_atual->proximo;
            free(node_atual);
            node_atual = proximo_node;
        }
        
        // Libera o no do vertice.
        free(lista_atual);
        // Avanca para o proximo vertice.
        lista_atual = proxima_lista;
    }
    // Finalmente, libera a estrutura principal do grafo.
    free(g);
}

// Funcao auxiliar para remover um no de adjacencia especifico.
void remover_adjacencia (Lista *vertice, int node_adj_remover) {
    if (vertice == NULL || vertice->head == NULL) {
        return;
    }
    Node *no_atual = vertice->head;
    Node *no_anterior = NULL;
    
    // Encontra o no e seu anterior.
    while (no_atual != NULL && no_atual->adj != node_adj_remover) {
        no_anterior = no_atual;
        no_atual = no_atual->proximo;
    }

    if (no_atual != NULL) {
        // Religa os ponteiros.
        if (no_anterior == NULL)
            vertice->head = no_atual->proximo;
        else
            no_anterior->proximo = no_atual->proximo;
        
        free(no_atual); // Libera memoria.
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
        // Para cada vertice, remove a adjacencia para 'vert', se existir.
        remover_adjacencia(lista_aux, vert);
        lista_aux = lista_aux->proximo;
    }

    // Passo 2: Remover o proprio vertice da lista principal.
    Lista *lista_remover = g->head;
    Lista *lista_anterior = NULL;
    
    // Encontra o vertice a ser removido e seu anterior.
    while (lista_remover != NULL && lista_remover->vert != vert) {
        lista_anterior = lista_remover;
        lista_remover = lista_remover->proximo;
    }

    // A propria lista de adjacencias do vertice removido ja foi limpa
    // pela chamada a remover_adjacencia(lista_remover, vert) no loop anterior.
    // Mas, por seguranca, vamos garantir que ela seja liberada caso nao tenha sido.
    Node *node_remover = lista_remover->head;
    while(node_remover != NULL) {
        Node *temp = node_remover;
        node_remover = node_remover->proximo;
        free(temp);
    }
    
    // Religa os ponteiros da lista principal.
    if (lista_anterior == NULL) // Se for o primeiro elemento.
        g->head = lista_remover->proximo;
    else // Se estiver no meio ou no fim.
        lista_anterior->proximo = lista_remover->proximo;

    free(lista_remover); // Libera a memoria do no do vertice.
    printf("Vertice %d removido com sucesso!\n", vert);
}

// Remove uma aresta entre dois vertices.
void remover_aresta (Grafo *g, int origem, int destino) {
    if (!buscar_aresta(g, origem, destino)) {
        printf("A aresta %d -> %d nao existe no grafo!\n", origem, destino);
        return;
    }
    
    // Encontra os nos dos vertices de origem e destino.
    Lista *l_origem = g->head;
    while (l_origem != NULL && l_origem->vert != origem)
        l_origem = l_origem->proximo;

    Lista *l_destino = g->head;
    while (l_destino != NULL && l_destino->vert != destino)
        l_destino = l_destino->proximo;
    
    // Remove a conexao em ambos os sentidos.
    if (l_origem != NULL)
        remover_adjacencia(l_origem, destino);
    if (l_destino != NULL)
        remover_adjacencia(l_destino, origem);

    printf("Aresta entre %d e %d removida com sucesso!\n", origem, destino);
}