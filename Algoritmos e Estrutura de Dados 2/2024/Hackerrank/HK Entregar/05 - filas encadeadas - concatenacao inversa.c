#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Cell Cell;


typedef struct FilaE FilaE;

struct Cell{
    int item;
    Cell *next;
};


struct FilaE{
    Cell *inicio;
    Cell *fim;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}


FilaE* criar_filaE(){
    FilaE *f = (FilaE*) malloc(sizeof(FilaE));
    
    f->inicio = NULL;
    f->fim = NULL;
    
    return f;
}


int filaE_vazia(FilaE* f){
    return (f == NULL) || (f->inicio == NULL);
}


void enfileirar(int key, FilaE* f){
    Cell *aux;

    if (f == NULL)
        f = criar_filaE();

    aux = criar_celula(key);

    if (f->inicio == NULL)
        f->inicio = f->fim = aux;
    else{
        f->fim->next = aux;
        f->fim = f->fim->next;
    }

}


int desenfileirar(FilaE* f){
    Cell *aux;
    int item = INT_MIN;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        f->inicio = aux->next;
        
        item = aux->item;

        free(aux);
    }

    return item;
}


void imprimir_fila(FilaE* f){
    Cell *aux;

    if (!filaE_vazia(f)){
        aux = f->inicio;

        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->next;
        }
        
        printf("\n");
    }
}


int liberar_filaE(FilaE* f){
    if (!filaE_vazia(f)){
        while (f->inicio != NULL)
            desenfileirar(f);

        free(f);

        return 1;
    }

    return 0;
}

typedef struct PilhaE PilhaE;

struct PilhaE{
    Cell *topo;
};


PilhaE* criar_pilhaE(){
    PilhaE* p = (PilhaE*) malloc(sizeof(PilhaE));

    p->topo = NULL;

    return p;
}


int pilhaE_vazia(PilhaE *p){
    return (p == NULL) || (p->topo == NULL);
}


void empilhar(int key, PilhaE *p){
    Cell *aux;

    if (p == NULL)
        p = criar_pilhaE();

    aux = criar_celula(key);

    aux->next = p->topo;

    p->topo = aux;
}


int desempilhar(PilhaE *p){
    Cell *aux;
    int item = ' ';

    if (!pilhaE_vazia(p)){
        aux = p->topo;
        
        item = aux->item;

        p->topo = aux->next;

        free(aux);
    }

    return item;
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

FilaE *concatenar(FilaE *f1, FilaE *f2)
{
    FilaE *f3 = criar_filaE();
    PilhaE *p1 = criar_pilhaE(), *p2 = criar_pilhaE();

    if (f1 != NULL && f2 != NULL)
    {
        while (!filaE_vazia(f1))
            empilhar(desenfileirar(f1), p1);

        while (!filaE_vazia(f2))
            empilhar(desenfileirar(f2), p2);
    }

    while (!pilhaE_vazia(p1))
        enfileirar(desempilhar(p1), f3);
    
    while (!pilhaE_vazia(p2))
        enfileirar(desempilhar(p2), f3);
    
    
    liberar_pilha(p1);
    liberar_pilha(p2);

    return f3;
}

int main()
{
    FilaE *f1 = criar_filaE(), *f2 = criar_filaE(), *f3;
    int item = 0;

    while (item != -1)
    {
        scanf("%d", &item);

        if (item == -1)
            break;

        enfileirar(item, f1);
    }

    item = 0;
    while (item != -1)
    {
        scanf("%d", &item);

        if (item == -1)
            break;

        enfileirar(item, f2);
    }
    
    f3 = concatenar(f1, f2);
    imprimir_fila(f3);

    liberar_filaE(f1);
    liberar_filaE(f2);
    liberar_filaE(f3);

    return 0;
}