#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell{
    int item;
    
    Cell *next;
};

struct ListaE{
    Cell *head;
};

Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}

int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

int procurar(int key, ListaE *l){
    Cell *aux;
    
    if (l != NULL){
        aux = l->head;

        while (aux != NULL){
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
}

void inserir_primeiro(int key, ListaE *l){
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}

void inserir_ultimo(int key, ListaE *l){
    Cell *aux, *novo;
    
    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}


int remover(int key, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (!listaE_vazia(l)){
        auxA = l->head;

        if(auxA->item == key){
            l->head = l->head->next;
        }else{
            auxP = auxA;

            while((auxA != NULL) && (auxA->item != key)){
                    auxP = auxA;

                auxA = auxA->next;
            }
        }

        if (auxA != NULL){
            if (auxP != NULL)
                auxP->next = auxA->next;

            free(auxA);

            return 1;
        }

    }

    return 0;
}


void imprimir(ListaE *l){
    Cell *aux;
    
    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
    }
}


int liberar_LE(ListaE *l){
    Cell *aux = NULL;
    
    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}

void remover_elementos(ListaE *l1, ListaE *l2) {
    Cell *aux;
    int max = INT_MIN;
    int min = INT_MAX;

    if (!listaE_vazia(l1)) {
        aux = l1->head;
        while (aux != NULL) {
            if (aux->item > max)
                max = aux->item;
            aux = aux->next;
        }

        remover(max, l1);
    }

    if (!listaE_vazia(l2)) {
        aux = l2->head;
        while (aux != NULL) {
            if (aux->item < min)
                min = aux->item;
            aux = aux->next;
        }

        remover(min, l2);
    }
}

int main() {
    int aux, n;
    ListaE *l1 = criar_listaE();
    ListaE *l2 = criar_listaE();

    scanf("%d", &n);
    while (n > 0) {
        n--;
        scanf("%d", &aux);
        inserir_ultimo(aux, l1);
    }

    scanf("%d", &n);
    while (n > 0) {
        n--;
        scanf("%d", &aux);
        inserir_ultimo(aux, l2);
    }

    remover_elementos(l1, l2);

    imprimir(l1);
    imprimir(l2);

    liberar_LE(l1);
    liberar_LE(l2);

    return 0;
}