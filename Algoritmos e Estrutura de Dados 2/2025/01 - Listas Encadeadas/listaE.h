#ifndef LISTAE_H
#define LISTAE_H

typedef struct node node; // Definindo a estrutura do nó

typedef struct ListaE ListaE; // Definindo a estrutura da lista encadeada

ListaE* criar_listaE(); // Função para criar uma nova lista encadeada

node* criar_node(int key); // Função para criar um novo nó

int listaE_vazia(ListaE *l); // Função para verificar se a lista está vazia

node* buscar(ListaE *l, int key); // Função para buscar uma key na lista

void inserir_primeiro(ListaE *l, int key); // Função para inserir uma key na primeira posição da lista

void inserir_ultimo(ListaE *l, int key); // Função para inserir uma key na última posição da lista

void imprimir_listaE(ListaE *l); // Função para imprimir toda a lista

node* remover(ListaE *l, int key); // Função para remover uma key (nó)

int liberar_LE(ListaE *l); // Função para liberar a lista

void inserir_ordenado(ListaE *l, int key); // Função para inserir ordenado

node* remover_primeiro(ListaE *l); // função para remover o primeiro elemento da lista

node* remover_ultimo(ListaE *l); // Função para remover o último elemento da lista

void split(ListaE *l1, ListaE *l2, ListaE *l3); // divide a lista 1 em duas lista l2 e l3

void concatenar(ListaE *l1, ListaE *l2); // a lista l2 vai ser concatenada em l1

ListaE* merge(ListaE *l1, ListaE *l2); // as listas l1 e l2 devem ser intercaladas em uma nova

int tamanho(ListaE *l); // retorna o tamanho da lista

#endif // LISTAE_H