#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell Cell;

typedef struct ListaE ListaE;

struct Cell{
    int item;
    
    Cell *next;
};



struct ListaE{
    Cell *head;
};


Cell* criar_celula(int key){
    Cell *c = (Cell*) malloc(sizeof(Cell));
    c->item = key;

    c->next = NULL;

    return c;
}

ListaE* criar_listaE(){
    ListaE* l = (ListaE*) malloc(sizeof(ListaE));

    l->head = NULL;

    return l;
}


int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}


int procurar(int key, ListaE *l){
    Cell *aux;
    
    if (l != NULL){
        aux = l->head;

        while (aux != NULL){
            if (aux->item == key)
                return 1;

            aux = aux->next;
        }
    }

    return 0;
}



void inserir_primeiro(int key, ListaE *l){
    Cell *aux;

    if (l == NULL)
        l = criar_listaE();

    aux = criar_celula(key);

    aux->next = l->head;

    l->head = aux;
}


void inserir_ultimo(int key, ListaE *l){
    Cell *aux, *novo;
    
    if (l == NULL)
        l = criar_listaE();

    if (listaE_vazia(l))
        inserir_primeiro(key, l);
    else{
        aux = l->head;

        while(aux->next != NULL)
            aux = aux->next;

        novo = criar_celula(key);

        aux->next = novo;
    }
}


int remover(int key, ListaE *l){
    Cell *auxA, *auxP = NULL;

    if (!listaE_vazia(l)){
        auxA = l->head;

        if(auxA->item == key){
            l->head = l->head->next;
        }else{
            auxP = auxA;

            while((auxA != NULL) && (auxA->item != key)){
                    auxP = auxA;

                auxA = auxA->next;
            }
        }

        if (auxA != NULL){
            if (auxP != NULL)
                auxP->next = auxA->next;

            free(auxA);

            return 1;
        }

    }

    return 0;
}


void imprimir(ListaE *l){
    Cell *aux;
    
    if (!listaE_vazia(l)){
        aux = l->head;

        while (aux != NULL){
            printf("%d ", aux->item);

            aux = aux->next;
        }

        printf("\n");
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


int tamanho_LE(ListaE *l){
    Cell *aux;
    int tam = 0;

     if (!listaE_vazia(l)){
        aux = l->head;

        while(aux != NULL){
            aux = aux->next;

            tam++;
        }
    }

    return tam;
}

int sub_lista(ListaE *l1, ListaE *l2)
{
    Cell *aux1, *aux2;
    int contador = 0, posicao = -1;
    int n = tamanho_LE(l1);

    if ((l1 != NULL) && (l2 != NULL))
    {
        aux1 = l1->head;
        aux2 = l2->head;

        while (aux2 != NULL)
        {
            if (aux1->item == aux2->item)
            {
                posicao = contador;
                aux1 = aux1->next;

                if (aux1 == NULL)
                    return (posicao - n + 1);
            }
            
            else
                aux1 = l1->head;
            
            contador++;
            aux2 = aux2->next;
        }
    }

    return -1;
}

int main()
{
    ListaE *l1, *l2;
    int item = 0;

    l1 = criar_listaE();
    l2 = criar_listaE();

    while (item != -1)
    {
        scanf("%d", &item);

        if (item == -1)
            break;

        inserir_ultimo(item, l1);
    }

    item = 0;
    while (item != -1)
    {
        scanf("%d", &item);

        if (item == -1)
            break;

        inserir_ultimo(item, l2);
    }

    item = sub_lista(l1, l2);
    
    printf("%d", item);

    liberar_LE(l1);
    liberar_LE(l2);

    return 0;
}