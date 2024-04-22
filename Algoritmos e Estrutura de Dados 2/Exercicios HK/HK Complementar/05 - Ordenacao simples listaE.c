#include <stdio.h>
#include <stdlib.h>
#include "listaE.c"

void concatenar(ListaE *l1, ListaE *l2)
{
    Cell *aux;

    if (!listaE_vazia(l1) && !listaE_vazia(l2))
    {
        aux = l1->head;

        while (aux->next != NULL)
            aux = aux->next;
        
        aux->next = l2->head;
        l2->head = NULL;
    }
}

void bubblesort(ListaE *l)
{
    int tam = tamanho_LE(l);
    Cell *auxA, *auxB;
    int vAux, i;

    while (tam > 0)
    {
        i = 0;
        auxA = l->head;
        auxB = auxA->next;

        while ((auxB != NULL) && (i < tam))
        {
            if (auxA->item > auxB->item)
            {
                vAux = auxA->item;
                auxA->item = auxB->item;
                auxB->item = vAux;
            }
            
            auxA = auxB;
            auxB = auxB->next;
            i++;
        }
        tam--;
    }
}

int main()
{
    ListaE *l = criar_listaE();
    int item = 0;

    while (item != -1)
    {
        scanf("%d", &item);

        if (item != -1)
            inserir_ultimo(item, l);
    }
    
    bubblesort(l);
    imprimir(l);
    liberar_LE(l);

    return 0;
}