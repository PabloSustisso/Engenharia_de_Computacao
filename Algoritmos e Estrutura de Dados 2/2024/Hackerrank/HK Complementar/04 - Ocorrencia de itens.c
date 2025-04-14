#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "listaE.c"

int ocorrencias(int item, ListaE *l)
{
    int contador = 0;
    Cell *aux;

    if (l != NULL)
    {
        aux = l->head;

        while (aux != NULL)
        {
            if (item == aux->item)
                contador++;

            aux = aux->next;
        }
    }

    return contador;
}

int main()
{
    int aux = 0;
    ListaE *l = criar_listaE();

    while (aux != -1)
    {
        scanf("%d", &aux);

        if (aux != -1)
            inserir_ultimo(aux, l);
    }
    
    scanf("%d", &aux);
    printf("o item %d aparece %d vez(es)", aux, ocorrencias(aux, l));

    return 0;
}