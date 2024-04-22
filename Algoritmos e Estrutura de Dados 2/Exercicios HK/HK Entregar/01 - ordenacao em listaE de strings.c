#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell {
    char item[100];
    Cell *next;
};

struct ListaE {
    Cell *head;
};

Cell* criar_celula(char key[]) {
    Cell *c = (Cell*) malloc(sizeof(Cell));
    strcpy(c->item, key);
    c->next = NULL;
    return c;
}

ListaE* criar_listaE() {
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));
    l->head = NULL;
    return l;
}

void inserir(ListaE *l, char key[])
{
    Cell *nova = criar_celula(key);

    if (l->head == NULL)
        l->head = nova;
    else
    {
        Cell *atual = l->head;

        while (atual->next != NULL)
            atual = atual->next;
        
        atual->next = nova;
    }
}

int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

void imprimir(ListaE *l){
    Cell *aux;
    
    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%s\n", aux->item);

            aux = aux->next;
        }
    }
}

int liberar_LE(ListaE *l){
    Cell *aux = NULL;
    
    if (l != NULL){
        while(l->head != NULL){
            aux = l->head;

            l->head = aux->next;

            free(aux);
        }

        free(l);

        return 1;
    }

    return 0;
}

void bubblesort_string(ListaE *l)
{
    int troca;
    char palavra[100];

    if (l->head == NULL)
        return;

    if (l != NULL)
    {
        Cell *aux1, *aux2 = NULL;

        do
        {
            troca = 0;
            aux1 = l->head;

            while (aux1->next != aux2)
            {
                if (strcmp(aux1->item, aux1->next->item) > 0)
                {
                    strcpy(palavra, aux1->item);
                    strcpy(aux1->item, aux1->next->item);
                    strcpy(aux1->next->item, palavra);
                    troca = 1;
                }
                aux1 = aux1->next;
            }
            aux2 = aux1;

        } while (troca);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    char palavra[100];

    ListaE *l = criar_listaE();

    while (n > 0)
    {
        scanf("%s", palavra);
        inserir(l, palavra);
        n--;
    }
    
    bubblesort_string(l);
    imprimir(l);

    liberar_LE(l);

    return 0;
}