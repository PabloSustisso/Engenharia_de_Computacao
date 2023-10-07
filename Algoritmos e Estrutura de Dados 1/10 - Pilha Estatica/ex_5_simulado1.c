#include <stdio.h>
#include "pilha.h"
#include "pilha.c"

Pilha *reorganizar(Pilha *p)
{
    Pilha *a1 = criar_pilha();
    Pilha *a2 = criar_pilha();

    while (!pilha_vazia(p))
    {
        empilhar(a1, desempilhar(p));

        if ((!pilha_vazia(p)) && (acessar_valor_topo(p) > acessar_valor_topo(a1)))
        {
            empilhar(a2, desempilhar(p));
            empilhar(a2, desempilhar(a1));
        }
        else
            empilhar(a2, desempilhar(a1));
    }

    p = a2;

    return p;
}

int main(void)
{
    Pilha *p = criar_pilha();

    for (int i = 1; i <= 16; i = i*2)
    {
        empilhar(p, i);
    }

    imprimir_pilha(p);

    printf("\n");
    p = reorganizar(p);

    imprimir_pilha(p);

    return 0;
}