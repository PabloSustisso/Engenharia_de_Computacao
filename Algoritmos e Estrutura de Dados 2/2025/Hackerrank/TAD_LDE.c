#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node *next;
    struct node *previous;
}node;

typedef struct ListaDE{
    node *head;
}ListaDE;

ListaDE* criar_listaDE(){
    ListaDE *lista = (ListaDE*)malloc(sizeof(ListaDE));
    lista->head = NULL;
    return lista;
}

node* criar_node(int key){
    node *novo = (node*)malloc(sizeof(node));
    novo->item = key;
    novo->next = NULL;
    novo->previous = NULL;
    return novo;
}

int listaDE_vazia(ListaDE *l){
    return (l == NULL) || (l->head == NULL);
}

node* buscar(ListaDE *l, int key){
    node *aux;
    if (l != NULL){
        aux = l->head;
        while (aux != NULL && aux->item != key)
            aux = aux->next;
    }
    return aux;
}

void inserir_primeiro_DE(ListaDE *l, int key){
    node *novo;
    if (l == NULL)
        criar_listaDE();
    novo = criar_node(key);
    novo->next = l->head;
    if(!listaDE_vazia(l))
        l->head->previous = novo;
    l->head = novo;
}

void inserir_ultimo(ListaDE *l, int key){
    node *novo, *aux;
    if (listaDE_vazia(l))
        inserir_primeiro_DE(l, key);
    else{
        aux = l->head;
        while (aux->next != NULL)
            aux = aux->next;
        novo = criar_node(key);
        aux->next = novo;
        novo->previous = aux;
    }
}

void imprimir_listaDE(ListaDE *l){
    node *aux;
    if (l != NULL){
        aux = l->head;
        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
    }
}

node* remover(ListaDE *l, int key){
    if (listaDE_vazia(l))
        return NULL;

    node *aux = l->head;

    if (aux->item == key) {
        l->head = aux->next;
        if (l->head != NULL)
            l->head->previous = NULL;
        return aux;
    }

    while (aux != NULL && aux->item != key) {
        aux = aux->next;
    }

    if (aux != NULL) {
        if (aux->previous != NULL)
            aux->previous->next = aux->next;

        if (aux->next != NULL)
            aux->next->previous = aux->previous;

        return aux;
    }

    return NULL;
}


int liberar_LE(ListaDE *l){
    node *auxA, *auxB;
    if(l != NULL){
        auxA = l->head;
        while(auxA != NULL){
            auxB = auxA;
            auxA = auxA->next;
            free(auxB);
        }
        free(l);
    }
    return 1;
}

void inserir_ordenado_DE(ListaDE *l, int key){
    if (listaDE_vazia(l))
        inserir_primeiro_DE(l, key);
    else{
        node *novo, *auxA;
        auxA = l->head;
        novo = criar_node(key);
        if(novo->item < auxA->item){
            novo->next = auxA;
            auxA->previous = novo;
            l->head = novo;
        }
        else{
            while(auxA != NULL && novo->item >= auxA->item){
                auxA = auxA->next;
            }
            if(auxA == NULL){
                inserir_ultimo(l, key);
                return;
            }
            novo->next = auxA;
            auxA->previous->next = novo;
            novo->previous = auxA->previous;
            auxA->previous = novo;
        }
    }
}

node* remover_primeiro(ListaDE *l){
    node *aux = NULL;
    if(!listaDE_vazia(l)){
        aux = l->head;
        l->head = l->head->next;
        l->head->previous = NULL;
        return aux;
    }
    return aux;
}

node* remover_ultimo(ListaDE *l){
    node *aux = NULL;
    if(!listaDE_vazia(l)){
        aux = l->head;
        while(aux != NULL && aux->next != NULL){
            aux = aux->next;
        }
        aux->previous->next = NULL;
        return aux;
    }
    return aux;
}