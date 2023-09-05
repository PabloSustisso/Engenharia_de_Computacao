#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct personagem
{
    char nome[20];
    int energia, defesa, forca;

} Personagem;

void batalhinhazinha(Personagem p1, Personagem p2, int rodadas)
{
    int dano_p1, dano_p2;

    while ((p1.energia >= 0 && p2.energia >= 0) && rodadas > 0)
    {
        dano_p1 = p1.forca - p2.defesa;
        if (dano_p1 <= 0)
        {
            dano_p1 = 1;
        }

        dano_p2 = p2.forca - p1.defesa;
        if (dano_p2 <= 0)
        {
            dano_p2 = 1;
        }

        p2.energia = p2.energia - dano_p1;
        
        if (p2.energia <= 0)
        {
            p2.energia = 0;
            break;
        }
        
        p1.energia = p1.energia - dano_p2;
        
        if (p1.energia <= 0)
        {
            p1.energia = 0;
            break;
        }
       
        else if (p2.energia <= 0)
        {
            p2.energia = 0;
            break;
        }

        rodadas--;
    }

    printf("%s %d\n%s %d\n", p1.nome, p1.energia, p2.nome, p2.energia);
    
    if (p1.energia > p2.energia)
    {
        printf("%s", p1.nome);
    }
    else if (p2.energia > p1.energia)
    {
        printf("%s", p2.nome);
    }
    else
    {
        printf("empate");
    }
}

int main()
{
    Personagem p1, p2;
    int rodadas;

    scanf("%s %d %d %d", p1.nome, &p1.energia, &p1.defesa, &p1.forca);
    scanf("%s %d %d %d", p2.nome, &p2.energia, &p2.defesa, &p2.forca);
    scanf("%d", &rodadas);

    batalhinhazinha(p1, p2, rodadas);

    return 0;
}