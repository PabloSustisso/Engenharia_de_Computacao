#include <stdio.h>
#include "esparsa.h"

int main(){
    //matriz teste do trabalho
    Matriz_Esparsa *m = criar_matriz(6, 7);
    inserir_valor(m, 0, 0, 2);
    inserir_valor(m, 1, 5, 45);
    inserir_valor(m, 1, 6, 13);
    inserir_valor(m, 2, 4, 89);
    inserir_valor(m, 3, 2, 12);
    inserir_valor(m, 5, 4, 3);

    imprime_matriz(m);

    //1) desaloca todos os elementos da matriz e libera a memoria
    apaga_matriz(m);

    return 0;
}