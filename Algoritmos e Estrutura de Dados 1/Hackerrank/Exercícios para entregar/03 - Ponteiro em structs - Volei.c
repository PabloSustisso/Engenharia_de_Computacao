#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    char nome[255];
    int saquesTotal;
    int bloqueiosTotal;
    int ataquesTotal;
    int saquesSucesso;
    int bloqueiosSucesso;
    int ataquesSucesso;
}Jogador;

void sucesso(int n, Jogador j[])
{
    int saqueT = 0, bloqueioT = 0, ataqueT = 0;
    int saqueS = 0, bloqueioS = 0, ataqueS = 0;
    float porcSaque = 0, porcBloqueio = 0, porcAtaque = 0;
    int i;
   
    for (i = 0; i < n; i++)
    {
        saqueT = saqueT + j[i].saquesTotal;
        bloqueioT = bloqueioT + j[i].bloqueiosTotal;
        ataqueT = ataqueT + j[i].ataquesTotal;
        saqueS = saqueS + j[i].saquesSucesso;
        bloqueioS = bloqueioS + j[i].bloqueiosSucesso;
        ataqueS = ataqueS + j[i].ataquesSucesso;
    }

    porcSaque = (saqueS * 100.0/ saqueT) ;
    porcBloqueio = (bloqueioS * 100.0/ bloqueioT) ;
    porcAtaque = (ataqueS * 100.0/ ataqueT) ;

    printf("Pontos de Saque: %.2f%%\nPontos de Bloqueio: %.2f%%\nPontos de Ataque: %.2f%%", porcSaque, porcBloqueio, porcAtaque);
    
}

int main()
{
    int n, i;

    scanf("%d", &n);
    Jogador j[n];

    for (i = 0; i < n; i++)
    {
        scanf("%s", j[i].nome);
        scanf("%d %d %d", &j[i].saquesTotal, &j[i].bloqueiosTotal, &j[i].ataquesTotal);
        scanf("%d %d %d", &j[i].saquesSucesso, &j[i].bloqueiosSucesso, &j[i].ataquesSucesso);
    }
    
    sucesso(n, j);

    return 0;
}
