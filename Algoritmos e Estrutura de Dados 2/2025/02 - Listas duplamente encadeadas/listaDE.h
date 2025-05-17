#ifndef LISTADE_H
#define LISTADE_H

typedef struct node node; // Definindo a estrutura do nó

typedef struct ListaDE ListaDE; // Definindo a estrutura da lista duplamente encadeada

ListaDE* criar_listaDE(); // Função para criar uma nova lista duplamente encadeada

node* criar_node(int key); // Função para criar um novo nó

int listaDE_vazia(ListaDE *l); // Função para verificar se a lista está vazia

node* buscar(ListaDE *l, int key); // Função para buscar uma key na lista

void inserir_primeiro_DE(ListaDE *l, int key); // Função para inserir uma key na primeira posição da lista

void inserir_ultimo(ListaDE *l, int key); // Função para inserir uma key na última posição da lista

void imprimir_listaDE(ListaDE *l); // Função para imprimir toda a lista

node* remover(ListaDE *l, int key); // Função para remover uma key (nó)

int liberar_LE(ListaDE *l); // Função para liberar a lista

void inserir_ordenado_DE(ListaDE *l, int key); // Função para inserir ordenado

node* remover_primeiro(ListaDE *l); // função para remover o primeiro elemento da lista

node* remover_ultimo(ListaDE *l); // Função para remover o último elemento da lista

#endif // LISTADE_H