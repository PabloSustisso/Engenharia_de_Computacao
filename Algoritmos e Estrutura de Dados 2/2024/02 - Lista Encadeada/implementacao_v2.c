#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "listaE.c"
#include "listaDE.c"

static Cell* inserir_ordenado_rec(Cell *c, int item)
{
    Cell *nova;

    if (c == NULL)
        c = criar_celula(item);

    else if (item < c->item)
    {
        nova = criar_celula(item);
        nova->next = c;
        c = nova;
    }
    else
        c->next = inserir_ordenado_rec(c->next, item);

    return c;
}

void inserir_ordenado2(int key, ListaE *l)
{
    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else
    {
        l->head = inserir_ordenado_rec(l->head, key);
    }
}

int procurar_key(int key, ListaDE *l)
{
    CellDE *aux; // celula auxiliar para não perder a lista

    if (l != NULL)
    {
        aux = l->head; // iniciar a celular auxiliar com a cabeca da lista

        while (aux != NULL) // percorrer a lista
        {
            if (aux->item == key) // se a chave for encontrada, retorna 1
                return 1;

            aux = aux->next; // se não, avanca para o proximo da lista
        }
    }
    
    return 0; // caso a chave não pertenca a lista, retorna 0
}

void inserir_ultimo(int key, ListaDE *l)
{
    CellDE *aux, *novo; // nova celula para insersao

    if (l == NULL) // verificar se existe uma lista, se nao, criar uma nova
        l = criar_ListaDE();

    if (!listaDE_vazia())
        inserir_primeiro(key, l);
    else
    {
        aux = l->head; // atribuir a cabeca ao auxiliar para percorrer a lista
    }

    while (aux != NULL) // percorrer a lista
    {
        if (aux->next == NULL) // achar o final da lista
        {
            novo->item = key; // atribuir a chave na ultima posicao
            novo->previous = aux->next;
            novo->next = NULL;
        }

        aux = aux->next; // atualizar o aux para percorrer a lista
    }
}

int main()
{
    

    return 0;
}

