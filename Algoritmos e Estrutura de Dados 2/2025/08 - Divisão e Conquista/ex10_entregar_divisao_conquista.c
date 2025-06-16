#include <stdio.h>
#include <stdlib.h>

//Exercício 10 lista 2 - Divisão e Conquista

int multiplicaDivisaoConquista(int n, int vezes){
    //casos base
    if(vezes == 0)
        return 0;
    if(vezes == 1)
        return 1;

    //dividir na metade
    int metade1 = vezes/2;
    int metade2 = vezes - metade1;

    //conquistar
    int resultado1 = multiplicaDivisaoConquista(n, metade1);
    int resultado2 = multiplicaDivisaoConquista(n, metade2);
}

int main(){


    return 0;
}