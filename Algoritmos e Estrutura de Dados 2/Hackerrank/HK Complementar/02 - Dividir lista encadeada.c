#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "listaE.c"

void dividir(ListaE *l1, ListaE *l2)
{
    int t;
    Cell *aux;

    if (l1 != NULL)
    {
        t = tamanho_LE(l1)/2;
        aux = l1->head;

        while (t > 1)
        {
            aux = aux->next;
            t--;
        }

        l2->head = aux->next;
        aux->next = NULL;
    }
}

int main()
{
    int aux = 0;
    ListaE *l1 = criar_listaE();
    ListaE *l2 = criar_listaE();

    while (aux != -1)
    {
        scanf("%d", &aux);

        if (aux != -1)
            inserir_ultimo(aux, l1);
    }
    
    dividir(l1, l2);

    imprimir(l1);
    imprimir(l2);

    liberar_LE(l1);
    liberar_LE(l2);

    return 0;
}