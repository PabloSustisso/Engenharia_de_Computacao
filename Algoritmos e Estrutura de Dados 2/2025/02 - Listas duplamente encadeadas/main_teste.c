#include <stdio.h>
#include <stdlib.h>
#include "listaDE.c"

int main(){
    ListaDE *l = criar_listaDE();

    inserir_primeiro_DE(l, 1);
    inserir_primeiro_DE(l, 2);
    inserir_ultimo(l, 4);
    imprimir_listaDE(l);
    printf("\n");
    remover_ultimo(l);
    imprimir_listaDE(l);

    return 0;
}