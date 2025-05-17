#include <stdio.h>
#include <stdlib.h>

/*
Implemente, utilizando recursão, um dos algoritmos de ordenação
simples apresentados em sala de aula (bublesort, selection sort
ou insertion sort) para a ordenação de uma lista encadeada de floats.
No seu código pode ter, no máximo, apenas um loop.
*/

typedef struct node{
    float item;
    struct node *next;
}node;

typedef struct ListaE{
    node *head;
}ListaE;

ListaE* criar_listaE(){
    ListaE *lista = (ListaE*)malloc(sizeof(ListaE));
    lista->head = NULL;
    return lista;
}

node* criar_node(float key){
    node *novo = (node*)malloc(sizeof(node));
    novo->item = key;
    novo->next = NULL;
    return novo;
}

int listaE_vazia(ListaE *l){
    return (l == NULL) || (l->head == NULL);
}

void inserir_primeiro(ListaE *l, float key){
    node *novo;
    if (l == NULL)
        criar_listaE();
    novo = criar_node(key);
    novo->next = l->head;
    l->head = novo;
}

void inserir_ultimo(ListaE *l, float key){
    node *novo, *aux;
    if (listaE_vazia(l))
        inserir_primeiro(l, key);
    else{
        aux = l->head;
        while (aux->next != NULL)
            aux = aux->next;
        novo = criar_node(key);
        aux->next = novo;
    }
}

void imprimir_listaE(ListaE *l){
    node *aux;
    if (l != NULL){
        aux = l->head;
        while (aux != NULL){
            printf("%.2f ", aux->item);
            aux = aux->next;
        }
    }
}

int liberar_LE(ListaE *l){
    node *auxA, *auxB;
    if(l != NULL){
        auxA = l->head;
        while(auxA != NULL){
            auxB = auxA;
            auxA = auxA->next;
            free(auxB);
        }
        free(l);
    }
    return 1;
}

// funcao auxiliar: faz uma passada de bubble e retorna 1 se houve troca
int bubble_pass(ListaE *l){
    int trocou = 0; // flag da troca inicia em 0 (false)
    node *anterior = NULL; // ponteiro para o node anterior
    node *atual = l->head; // ponteiro para o node atual

    while(atual != NULL && atual->next != NULL){
        if(atual->item > atual->next->item){
            // troca os node (atual->next por atual)
            node *temp = atual->next;
            atual->next = temp->next;
            temp->next = atual;
            
            // isso ocorre somente na primeira troca
            if(anterior == NULL){
                l->head = temp;
            } else{
                anterior->next = temp; // atualizacao do ponteiro anterior
            }
            anterior = temp; // recebe a cabeca atual depois da primeira troca
            trocou = 1; // houve troca
        } else{
            anterior = atual; // passa para o proximo da lista se nao houve troca
            atual = atual->next; // atualizacao do atual para o proximo
        }
    }
    return trocou;
}

// bubblesort recursivo para lista encadeada
void bubble_rec_LE(ListaE *l){
    // condicao de parada: lista nula, cabeca nula ou somente um elemento
    if(l == NULL || l->head == NULL || l->head->next == NULL)
        return;
    // condicao de ativacao: se houve troca
    if(bubble_pass(l)){
        bubble_rec_LE(l);
    }
    return;
}

int main(){

    ListaE *l = criar_listaE();
    float num;

    do{
        scanf("%f", &num);
        if(num == -1)
            break;
        inserir_ultimo(l, num);
    } while(num != -1);

    bubble_rec_LE(l);
    imprimir_listaE(l);

    return 0;
}