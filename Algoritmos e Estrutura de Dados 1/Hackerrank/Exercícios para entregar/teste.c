#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct
{
    char **lista;
    int tam;
} list;

void alocarLISTA(list *l)
{
    int cont = 0;
    (*l).lista = (char *)malloc((*l).tam * sizeof(char *));
    while (cont < (*l).tam)
    {
        (*l).lista[cont] = (char *)malloc(20 * sizeof(char *));
        cont++;
    }
}

void escanearLISTA(list *l)
{
    int cont = 0;
    while (cont < (*l).tam)
    {
        scanf("%s", (*l).lista[cont]);
        cont++;
    }
}

void imprimirSEARCH(list *l, char *s)
{
    int cont = 0, cont1 = 0, cont2 = 0, tam = 0;

    while (s[tam] != '\0')
    {
        tam++;
    }

    while (cont < (*l).tam)
    {
        while ((*l).lista[cont][cont1] != '\0')
        {
            if ((*l).lista[cont][cont1] == s[0])
            {
                while (cont2 < tam)
                {
                    if ((*l).lista[cont][cont1 + cont2] == s[cont2])
                    {
                        cont2++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (cont2 == tam)
                {
                    printf("%s\n", (*l).lista[cont]);
                }
                cont2 = 0;
            }
            cont1++;
        }
        cont1 = 0;
        cont++;
    }
}

int main()
{
    list lista;
    char search[10];

    scanf("%s", search);
    scanf("%d", &lista.tam);

    alocarLISTA(&lista);
    escanearLISTA(&lista);
    imprimirSEARCH(&lista, search);

    return 0;
}