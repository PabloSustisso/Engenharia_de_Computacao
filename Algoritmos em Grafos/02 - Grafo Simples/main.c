#include <stdio.h>
#include "grafo.h"

int main(){
    ListaE *grafo_1 = criar_listaE();
    inserir_vertice(grafo_1, 1);
    inserir_vertice(grafo_1, 2);
    inserir_vertice(grafo_1, 3);
    inserir_vertice(grafo_1, 4);
    inserir_vertice(grafo_1, 5);
    imprimir_vertices(grafo_1);

    return 0;
}