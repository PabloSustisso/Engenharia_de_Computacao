#include <stdio.h>
#include <stdlib.h>
#include "TAD_LDE.c"

/*
Implemente uma função que receba uma lista duplamente encadeada. 
A função deverá remover todos os elementos repetidos.
*/

void remover_node(ListaDE *l, node *n) {
    if (n == NULL) return;

    if (n->previous != NULL)
        n->previous->next = n->next;
    else
        l->head = n->next;

    if (n->next != NULL)
        n->next->previous = n->previous;

    free(n);
}

// assumindo que a lista nao esteja ordenada
void remover_repetidos(ListaDE *l){
    node *aux1 = l->head;

    // valor a ser comparado com todos os outros
    while(aux1 != NULL){
        // percorrer toda a lista
        node *aux2 = aux1->next;
        while(aux2 != NULL){
            if(aux2->item == aux1->item){
                node *duplicado = aux2;
                aux2 = aux2->next;
                remover_node(l, duplicado);
                // nao avanca aux
            }
            else{
                aux2 = aux2->next;
            }
        }
        aux1 = aux1->next;
    }
}

int main(){
    ListaDE *l = criar_listaDE();
    int num;

    do{
        scanf("%d", &num);
        if(num == -1)
            break;
        inserir_ultimo(l, num);
    } while(num != -1);

    remover_repetidos(l);
    imprimir_listaDE(l);
    liberar_LE(l);

    return 0;
}