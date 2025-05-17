#include <stdio.h>
#include <stdlib.h>
#include "TAD_LE.c"

/*
Implemente uma função que receba duas listas encadeadas. 
A função deverá retornar uma lista encadeada com elementos 
em comum entre as listas de entrada.
*/

void ler_int(ListaE *l){
    int num;

    do{
        scanf("%d", &num);
        if(num == -1)
            break;
        inserir_ordenado(l, num);
    } while (num != -1);
}

ListaE* intersecao_LE(ListaE *l1, ListaE *l2){
    ListaE *l3 = criar_listaE(); // lista auxiliar

    node *auxL1, *auxL2; // ponteiros para andar nas listas

    if(!listaE_vazia(l1) && !listaE_vazia(l2)){
        auxL1 = l1->head;
        auxL2 = l2->head;

        while(auxL1 != NULL){
            while(auxL2 != NULL){
                if(auxL2->item == auxL1->item)
                    inserir_ordenado(l3, auxL2->item);
                auxL2 = auxL2->next;
            }
            auxL2 = l2->head;
            auxL1 = auxL1->next;
        }        
    }
    return l3;
}

int main(){

    ListaE *l1 = criar_listaE();
    ListaE *l2 = criar_listaE();
    ListaE *l3;

    ler_int(l1);
    ler_int(l2);

    l3 = intersecao_LE(l1, l2);

    imprimir_listaE(l3);
    liberar_LE(l1);
    liberar_LE(l2);
    liberar_LE(l3);

    return 0;
}