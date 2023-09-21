#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "TAD_lista_est_HR.h"

int main(void)
{
    Lista* L1 = criar_lista();
    Lista* L2 = criar_lista();

    inserir(L1, -90);
    inserir(L2, 10);

    imprimir_lista(L1);

    return 0;
}