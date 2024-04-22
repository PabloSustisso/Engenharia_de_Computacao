#include <stdio.h>
#include <stdlib.h>

typedef struct PilhaE PilhaE;

PilhaE criar_pilha();

int pilha_vazia(PilhaE *p);

void empilhar(int key, PilhaE *p);

int desempilhar(PilhaE *p);

int valor_topo(PilhaE *p);