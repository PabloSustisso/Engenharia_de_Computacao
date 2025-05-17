#include <stdio.h>
#include "listaE.c"

int main(){
    ListaE *l = criar_listaE();
    //ListaE *l2 = criar_listaE();
    //ListaE *l3 = criar_listaE();

    for (int i = 10; i > 0; i--)
    {
        inserir_ordenado(l, i);
    }
    
    imprimir_listaE(l);
    inserir_ordenado(l,11);
    printf("\n");
    imprimir_listaE(l);


    return 0;
}