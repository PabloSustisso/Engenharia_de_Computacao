#include <stdio.h>
#include <stdlib.h>
#include "listaE.h"

// Definindo a estrutura da lista encadeada
struct ListaE{
    node *head;
};

// Definindo a estrutura do nó da lista encadeada
struct node{
    int item;
    struct node *next;
};

// Função para criar uma nova lista encadeada
ListaE* criar_listaE(){
    ListaE *lista = (ListaE*)malloc(sizeof(ListaE)); // Alocando memória para a lista
    lista->head = NULL; // Inicializando o ponteiro head como NULL
    return lista; // Retornando o ponteiro da lista criada
}

// Função para criar um novo nó
node* criar_node(int key){
    node *novo = (node*)malloc(sizeof(node));
    novo->item = key;
    novo->next = NULL;
    return novo;
}

// Função para verificar se a lista está vazia
int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

// Função para buscar uma chave na lista
node* buscar(ListaE *l, int key){
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
void inserir_primeiro(ListaE *l, int key){
    node *novo; // nó a ser inserido

    // Se a lista for nula então cria-se uma
    if (l == NULL)
        criar_listaE();

    novo = criar_node(key); // cria-se o nó
    novo->next = l->head; // primeiro o novo aponta para a cabeça
    l->head = novo; // depois a cabeça aponta para o novo
}

// Função para inserir uma key na última posição da lista
void inserir_ultimo(ListaE *l, int key){
    node *novo, *aux; // nó a ser inserido e aux para percorrer

    // Se a lista estiver vazia ele insere primeiro (head)
    if (listaE_vazia(l))
        inserir_primeiro(l, key);

    // Se não, ele percorre toda a lista até achar next->NULL (último elemento da lista)
    else{
        aux = l->head;

        while (aux->next != NULL)
            aux = aux->next;

        novo = criar_node(key); // Cria o novo nó
        aux->next = novo; // Atribui o novo nó para o NULL encontrado
    }
}


// Função para imprimir toda a lista
void imprimir_listaE(ListaE *l){
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
node* remover(ListaE *l, int key){
    // um nó para avançar na lista e outro para guardar o nó anterior
    node *auxA = NULL, *auxP = NULL;

    if (!listaE_vazia(l)){
        auxA = l->head;

        // se a key estiver na cabeça, atualiza a cabeça somente
        if (auxA->item == key){
            l->head = l->head->next;
        }

        else{
            auxP = auxA;
            // Enquanto a chave não for encontrada e o NULL não for alcançado, percorre cada nó
            while (auxA != NULL && auxA->item != key){
                auxP = auxA; // nó anterior
                auxA = auxA->next;
            }
        }
        // Se a chave foi encontrada, auxA vai ser != NULL
        if (auxA != NULL){
            if(auxP != NULL)
                auxP->next = auxA->next; // o anterior irá apontar para o sucessor do nó removido
            return auxA; // Operação bem-sucedida
        }
    }
    return auxA;
}

// Função para liberar a lista
int liberar_LE(ListaE *l){
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
void inserir_ordenado(ListaE *l, int key){

    // Se a lista for vazia insere primeiro (head)
    if (listaE_vazia(l))
        inserir_primeiro(l, key);
    else{
        node *novo, *auxA;

        auxA = l->head;
        novo = criar_node(key);

        // se o novo for menor que o head, ele se torna o head
        if(novo->item < auxA->item){
            novo->next = auxA;
            l->head = novo;
        }
        else{
            node *auxB = auxA;

            // enquanto o novo > nó atual(auxA) ele percorre
            while(auxA != NULL && novo->item >= auxA->item){
                auxB = auxA; // nó anterior
                auxA = auxA->next; // nó atual
            }

            novo->next = auxA; // o sucessor do novo acessa o nó atual
            auxB->next = novo; // o antecessor do nó atual acessa o novo
        }
    }
}

// função para remover o primeiro elemento da lista
node* remover_primeiro(ListaE *l){
    node *aux = NULL;

    if(!listaE_vazia(l)){
        aux = l->head;

        l->head = l->head->next;

        return aux;
    }
    return aux;
}

// Função para remover o último elemento da lista
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

// retorna o tamanho da lista
int tamanho(ListaE *l){
    node *aux = l->head;
    int count = 0;

    while(aux != NULL){
        aux = aux->next;
        count++;
    }
    return count;
}

// divide a lista 1 em duas listas l2 e l3
void split(ListaE *l1, ListaE *l2, ListaE *l3){
    int tam = tamanho(l1);
    int split = tam/2; // arredonda para baixo
    int count = 0;

    node *aux = l1->head;

    while(aux != NULL){
        if(count < split){
            inserir_ordenado(l2, aux->item);
            count++;
        }
        else{
            inserir_ordenado(l3, aux->item);
        }
        aux = aux->next;
    }
}

// a lista l2 vai ser concatenada em l1
void concatenar(ListaE *l1, ListaE *l2){
    node *aux = l2->head;

    while(aux != NULL){
        inserir_ultimo(l1, aux->item);
        aux = aux->next;
    }
}

ListaE* merge(ListaE *l1, ListaE *l2); // as listas l1 e l2 devem ser intercaladas em uma nova