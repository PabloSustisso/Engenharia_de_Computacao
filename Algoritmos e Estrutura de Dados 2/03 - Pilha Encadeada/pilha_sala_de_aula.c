#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "pilha_sala_de_aula.h"

typedef struct CellP CellP;

struct CellP
{
    int key;
    CellP *next;
};

typedef struct PilhaE PilhaE;

struct PilhaE
{
    CellP *topo;
};

CellP *criar_celulaP(int key)
{
    CellP *c = malloc(sizeof(CellP));

    c->key = key;

    c->next = NULL;

    return c;
}

PilhaE *criar_pilha()
{
    PilhaE *p = malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}

int pilha_vazia(PilhaE *p)
{
    return (p == NULL) || (p->topo == NULL);
}

void empilhar(int key, PilhaE *p)
{
    CellP *c = criar_celulaP(key);

    if (p == NULL)
        p = criar_pilha();

    c->next = p->topo;

    p->topo = c;
}

int desempilhar(PilhaE *p)
{
    int t = INT_MIN;
    CellP *aux;

    if (!pilha_vazia(p))
    {
        aux = p->topo;
        p->topo = aux->next;
        t = aux->key;
        free(aux);
    }
    
    return t;
}

int valor_topo(PilhaE *p)
{
    int t = INT_MIN;

    if (!pilha_vazia(p))
    {
        t = p->topo->key;
    }
    
    return t;
}