#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node *next;
}node;

typedef struct ListaE{
    node *head;
}ListaE;

ListaE* criar_listaE(){
    ListaE *lista = (ListaE*)malloc(sizeof(ListaE));
    lista->head = NULL;
    return lista;
}

node* criar_node(int key){
    node *novo = (node*)malloc(sizeof(node));
    novo->item = key;
    novo->next = NULL;
    return novo;
}

int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

node* buscar(ListaE *l, int key){
    node *aux = NULL;
    if (l != NULL){
        aux = l->head;
        while (aux != NULL && aux->item != key)
            aux = aux->next;
    }
    return aux;
}

void inserir_primeiro(ListaE *l, int key){
    node *novo;
    if (l == NULL)
        criar_listaE();
    novo = criar_node(key);
    novo->next = l->head;
    l->head = novo;
}

void inserir_ultimo(ListaE *l, int key){
    node *novo, *aux;
    if (listaE_vazia(l))
        inserir_primeiro(l, key);
    else{
        aux = l->head;
        while (aux->next != NULL)
            aux = aux->next;
        novo = criar_node(key);
        aux->next = novo;
    }
}

void imprimir_listaE(ListaE *l){
    node *aux;
    if (l != NULL){
        aux = l->head;
        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
    }
}

node* remover(ListaE *l, int key){
    node *auxA = NULL, *auxP = NULL;
    if (!listaE_vazia(l)){
        auxA = l->head;
        if (auxA->item == key){
            l->head = l->head->next;
        } else {
            auxP = auxA;
            while (auxA != NULL && auxA->item != key){
                auxP = auxA;
                auxA = auxA->next;
            }
        }
        if (auxA != NULL){
            if(auxP != NULL)
                auxP->next = auxA->next;
            return auxA;
        }
    }
    return auxA;
}

int liberar_LE(ListaE *l){
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

void inserir_ordenado(ListaE *l, int key){
    if (listaE_vazia(l))
        inserir_primeiro(l, key);
    else{
        node *novo, *auxA;
        auxA = l->head;
        novo = criar_node(key);
        if(novo->item < auxA->item){
            novo->next = auxA;
            l->head = novo;
        } else {
            node *auxB = auxA;
            while(auxA != NULL && novo->item >= auxA->item){
                auxB = auxA;
                auxA = auxA->next;
            }
            novo->next = auxA;
            auxB->next = novo;
        }
    }
}

node* remover_primeiro(ListaE *l){
    node *aux = NULL;
    if(!listaE_vazia(l)){
        aux = l->head;
        l->head = l->head->next;
        return aux;
    }
    return aux;
}

node* remover_ultimo(ListaE *l){
    node *aux = NULL;
    if(!listaE_vazia(l)){
        aux = l->head;
        node *auxB = aux;
        while(aux != NULL && aux->next != NULL){
            auxB = aux;
            aux = aux->next;
        }
        auxB->next = NULL;
        return aux;
    }
    return aux;
}
