#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Cell Cell;

typedef struct PilhaE PilhaE;

struct Cell{
    char item;
    Cell *next;
};


struct PilhaE{
    Cell *topo;
};


Cell* criar_celula(char key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}


int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}


void empilhar(char key, PilhaE *p){
    Cell *aux;

    if (p == NULL)
        p = criar_pilhaE();

    aux = criar_celula(key);

    aux->next = p->topo;

    p->topo = aux;
}


char desempilhar(PilhaE *p){
    Cell *aux;
    char item = ' ';

    if (!pilhaE_vazia(p)){
        aux = p->topo;
        
        item = aux->item;

        p->topo = aux->next;

        free(aux);
    }

    return item;
}


void imprimir_pilha(PilhaE *p){
    Cell *aux;

    if (!pilhaE_vazia(p)){
        aux = p->topo;

        while (aux != NULL){
            printf("%d\n", aux->item);

            aux = aux->next;
        }
    }
}


int liberar_pilha(PilhaE *p){
    if (p != NULL){
        while (!pilhaE_vazia(p))
            desempilhar(p);

        free(p);

        return 1;
    }

    return 0;
}

int contar_parenteses(char string[])
{
    PilhaE *p = criar_pilhaE();
    int i = 0, control = 1;

    while (string[i] != '\0')
    {
        if (string[i] == '(')
            empilhar('(', p);

        else if (string[i] == ')')
        {
            if (!pilhaE_vazia(p) && p->topo->item == '(')
                desempilhar(p);
            else
            {
                control = 0;
                break;
            }
                
        }
        i++;
    }

    if (!pilhaE_vazia(p))
        control = 0;

    liberar_pilha(p);

    return control;
}

int main()
{
    int n;
    char string[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", string);
        if (contar_parenteses(string))
            printf("correct\n");
        else
            printf("incorrect\n");
    }
    
    return 0;
}