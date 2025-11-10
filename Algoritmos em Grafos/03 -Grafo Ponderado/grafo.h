// =============================================================================
// ARQUIVO DE CABECALHO (HEADER) PARA A ESTRUTURA DE GRAFO
// =============================================================================

// Estas diretivas (include guards) evitam que o conteudo deste arquivo
// seja incluido mais de uma vez durante a compilacao, o que causaria erros.
#ifndef GRAFO_H
#define GRAFO_H

// --- DEFINICAO DAS ESTRUTURAS DE DADOS ---

// Estrutura 'Node' (No de Adjacencia)
// Representa uma conexao (aresta) de um vertice para outro.
typedef struct Node {
    int adj;                // Armazena o valor do vertice adjacente (o vizinho).
    int peso;               // NOVO: Armazena o peso da aresta.
    struct Node *proximo;   // Ponteiro para o proximo no na lista de adjacencias.
} Node;

// Estrutura 'Lista' (No de Vertice)
// Representa um vertice na lista principal do grafo.
typedef struct Lista {
    int vert;               // Armazena o valor do proprio vertice.
    struct Lista *proximo;  // Ponteiro para o proximo vertice na lista principal do grafo.
    struct Node *head;      // Ponteiro para o inicio da sua lista de adjacencias (seus vizinhos).
} Lista;

// Estrutura 'Grafo'
// E a estrutura principal que contem todo o grafo.
typedef struct Grafo {
    struct Lista *head;     // Ponteiro para o inicio da lista de vertices.
} Grafo;


// --- PROTOTIPOS DAS FUNCOES (EXISTENTES E MODIFICADAS) ---

// Funcao para alocar memoria e inicializar um novo grafo.
Grafo *criar_grafo ();

// Funcao para inserir um novo vertice no grafo de forma ordenada.
void inserir_vertice (Grafo *g, int vert);

// Funcao para inserir uma nova aresta ponderada entre dois vertices existentes.
void inserir_aresta (Grafo *g, int origem, int destino, int peso);

// Funcao para imprimir a lista de adjacencias do grafo (agora com pesos).
void visualizar_grafo (Grafo *g);

// Funcao para liberar toda a memoria alocada pelo grafo.
void liberar_grafo (Grafo *g);

// Funcao para remover um vertice e todas as arestas conectadas a ele.
void remover_vertice (Grafo *g, int vert);

// Funcao para remover uma aresta entre dois vertices.
void remover_aresta (Grafo *g, int origem, int destino);


// --- PROTOTIPOS DAS NOVAS FUNCOES DE ANALISE ---

// Informa o grau de um vertice especifico.
int grau_vertice(Grafo *g, int vert);

// Informa se o grafo e conexo e, caso contrario, quantas componentes possui.
void verificar_conectividade(Grafo *g);

// Informa se o grafo e Euleriano.
void verificar_euleriano(Grafo *g);

// Informa se o grafo possui ciclos e quantos ciclos fundamentais por componente.
void verificar_ciclos(Grafo *g);


#endif //GRAFO_H