#include <stdio.h>
#include <stdlib.h>
#include "listaDE.h"

// Definindo a estrutura da lista encadeada
struct ListaDE{
    node *head;
};

// Definindo a estrutura do nó da lista encadeada
struct node{
    int item;
    struct node *next;
    struct node *previous;
};

// Função para criar uma nova lista encadeada
ListaDE* criar_listaDE(){
    ListaDE *lista = (ListaDE*)malloc(sizeof(ListaDE)); // Alocando memória para a lista
    lista->head = NULL; // Inicializando o ponteiro head como NULL
    return lista; // Retornando o ponteiro da lista criada
}

// Função para criar um novo nó
node* criar_node(int key){
    node *novo = (node*)malloc(sizeof(node));
    novo->item = key;
    novo->next = NULL;
    novo->previous = NULL;
    return novo;
}

// Função para verificar se a lista está vazia
int listaDE_vazia(ListaDE *l){
    return (l == NULL) || (l->head == NULL);
}

// Função para buscar uma chave na lista
node* buscar(ListaDE *l, int key){
    node *aux; // Auxiliar para não perder a head da lista

    if (l != NULL){
        aux = l->head;

        // Enquanto a chave não for encontrada e o NULL não for alcançado, percorre cada nó
        while (aux != NULL && aux->item != key)
            aux = aux->next;
    }
    return aux;
}

// Função para inserir uma key na primeira posição da lista
void inserir_primeiro_DE(ListaDE *l, int key){
    node *novo; // nó a ser inserido

    // Se a lista for nula então cria-se uma
    if (l == NULL)
        criar_listaDE();

    novo = criar_node(key); // cria-se o nó
    novo->next = l->head; // primeiro o novo aponta para a cabeça
    if(!listaDE_vazia(l))
        l->head->previous = novo; 
    l->head = novo; // depois a cabeça aponta para o novo
}

// Função para inserir uma key na última posição da lista
void inserir_ultimo(ListaDE *l, int key){
    node *novo, *aux; // nó a ser inserido e aux para percorrer

    // Se a lista estiver vazia ele insere primeiro (head)
    if (listaDE_vazia(l))
        inserir_primeiro_DE(l, key);

    // Se não, ele percorre toda a lista até achar next->NULL (último elemento da lista)
    else{
        aux = l->head;

        while (aux->next != NULL)
            aux = aux->next;

        novo = criar_node(key); // Cria o novo nó
        aux->next = novo; // Atribui o novo nó para o NULL encontrado
        novo->previous = aux;
    }
}


// Função para imprimir toda a lista
void imprimir_listaDE(ListaDE *l){
    node *aux;

    if (l != NULL){
        aux = l->head;

        // Percorre toda a lista até achar um next->NULL
        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
    }
}

// Função para remover um nó
node* remover(ListaDE *l, int key){
    // um nó para avançar na lista e outro para guardar o nó anterior
    node *auxA = NULL;

    if (!listaDE_vazia(l)){
        auxA = l->head;

        // se a key estiver na cabeça, atualiza a cabeça somente
        if (auxA->item == key){
            l->head = l->head->next;
        }

        else{
            // Enquanto a chave não for encontrada e o NULL não for alcançado, percorre cada nó
            while (auxA != NULL && auxA->item != key){
                auxA = auxA->next;
            }
        }
        // Se a chave foi encontrada, auxA vai ser != NULL
        if (auxA != NULL){
            if(auxA->previous != NULL){
                auxA->previous->next = auxA->next; // o anterior irá apontar para o sucessor do nó removido
                auxA->next->previous = auxA->previous;
            }
            return auxA; // Operação bem-sucedida
        }
    }
    return auxA;
}

// Função para liberar a lista
int liberar_LE(ListaDE *l){
    node *auxA, *auxB;

    if(l != NULL){
        auxA = l->head;

        // Percorre a lista e vai liberando os nós
        while(auxA != NULL){
            auxB = auxA;
            auxA = auxA->next;
            free(auxB); // libera cada nó anterior
        }

        free(l); // libera a lista depois de liberar todos os nós
    }
    return 1;
}

// Função para inserir ordenado
void inserir_ordenado_DE(ListaDE *l, int key){

    // Se a lista for vazia insere primeiro (head)
    if (listaDE_vazia(l))
        inserir_primeiro_DE(l, key);
    else{
        node *novo, *auxA;

        auxA = l->head;
        novo = criar_node(key);

        // se o novo for menor que o head, ele se torna o head
        if(novo->item < auxA->item){
            novo->next = auxA;
            auxA->previous = novo;
            l->head = novo;
        }
        else{
            // enquanto o novo > nó atual(auxA) ele percorre
            while(auxA != NULL && novo->item >= auxA->item){
                auxA = auxA->next; // nó atual
            }
            
            if(auxA == NULL){
                inserir_ultimo(l, key);
                return;
            }

            novo->next = auxA; // o sucessor do novo acessa o nó atual
            auxA->previous->next = novo; // o antecessor do nó atual acessa o novo
            novo->previous = auxA->previous;
            auxA->previous = novo;
        }
    }
}

// função para remover o primeiro elemento da lista
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

// Função para remover o último elemento da lista
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