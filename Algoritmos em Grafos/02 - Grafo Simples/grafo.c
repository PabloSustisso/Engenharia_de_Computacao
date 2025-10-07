#include "grafo.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item;
    struct Node *proximo;
};

struct ListaE {
    Node *head;
    struct ListaE *proximo;
};

ListaE *criar_listaE() {
    ListaE *lista = (ListaE *)malloc(sizeof(ListaE));

    if (lista == NULL) {
        printf("Nao foi possivel alocar a memoria para a lista!\n");
        return NULL;
    }

    lista->head = NULL;
    lista->proximo = NULL;

    return lista;
}

Node *criar_node(int valor) {
    Node *novo = (Node *)malloc(sizeof(Node));

    if (novo == NULL) {
        printf("Nao foi possivel alocar a memoria para o node!\n");
        return NULL;
    }

    novo->item = valor;
    novo->proximo = NULL;

    return novo;
}

int listaE_vazia(ListaE *lista) {
    return (lista == NULL) || (lista->head == NULL);
}

void inserir_vertice(ListaE *grafo, int vertice) {
    if (grafo == NULL)
        grafo = criar_listaE();

    // Se a lista ainda nao possui nenhum vertice
    if (grafo->head == NULL) {
        Node *novo = criar_node(vertice);
        novo->proximo = grafo->head;
        grafo->head = novo;
    } else {
        ListaE *aux_lista = grafo;

        while (aux_lista->head != NULL)
            aux_lista = aux_lista->proximo;

        Node *novo = criar_node(vertice);
        novo->proximo = aux_lista->head;
        aux_lista->head = novo;
    }
}

void imprimir_vertices(ListaE *grafo) {
    if (grafo == NULL) {
        printf("O grafo nao existe na memoria!\n");
        return;
    }

    ListaE *aux_lista = grafo;

    printf("---------- GRAFO ----------");
    while (aux_lista->head != NULL) {
        printf("%d ->\n", aux_lista->head->item);
        aux_lista = aux_lista->proximo;
    }
    printf("------ FIM DO GRAFO -------");
}