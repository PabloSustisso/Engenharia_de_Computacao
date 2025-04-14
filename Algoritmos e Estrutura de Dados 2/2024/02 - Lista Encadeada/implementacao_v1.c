#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Cell Cell;

// Estrutura para uma lista encadeada.
struct Cell
{
    int item;
    Cell *next; // Aponta para o endereco do proximo item da lista.
};

int main()
{
    Cell *c1 = malloc(sizeof(Cell));
    c1->item = 10;
    c1->next = NULL;

    Cell *c2 = malloc(sizeof(Cell));
    c2->item = 20;
    c2->next = NULL;
    c1->next = c2;

    Cell *c3 = malloc(sizeof(Cell));
    c3->item = 25;
    c3->next = NULL;
    c2->next = c3;

    printf("%d\n", c1->item);
    printf("%d\n", c2->item); // Ou printf("%d\n", c1->next->item);
    printf("%d\n", c3->item); // Ou printf("%d\n", c1->next->next->item);

    return 0;
}

