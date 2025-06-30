#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node* next;
}Node;

typedef struct Fila{
    Node* inicio;
    Node* fim;
}Fila;

Fila* criar_fila(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int estaVazia(Fila* f){
    return (f->inicio == NULL);
}

void enfileirar(Fila* f, int key){
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->key = key;
    novo->next = NULL;

    if(estaVazia(f)){
        f->inicio = novo;
        f->fim = novo;
    }else{
        f->fim->next = novo;
        f->fim = novo;
    }
}

int desenfileirar(Fila* f){
    if(estaVazia(f))
        return -1;

    Node* aux = f->inicio;
    int aux_key = aux->key;

    f->inicio = f->inicio->next;

    if(f->inicio == NULL)
        f->fim = NULL;

    free(aux);
    
    return aux_key;
}

void merge(int* vet, int inicio, int meio, int fim){
    Fila* filaEsquerda = criar_fila();
    Fila* filaDireita = criar_fila();

    for (int i = inicio; i <= meio; i++) {
        enfileirar(filaEsquerda, vet[i]);
    }

    for (int i = meio + 1; i <= fim; i++) {
        enfileirar(filaDireita, vet[i]);
    }

    int k = inicio;

    while (!estaVazia(filaEsquerda) && !estaVazia(filaDireita)) {
        if (filaEsquerda->inicio->key <= filaDireita->inicio->key) {
            vet[k] = desenfileirar(filaEsquerda);
        } else {
            vet[k] = desenfileirar(filaDireita);
        }
        k++;
    }

    while (!estaVazia(filaEsquerda)) {
        vet[k] = desenfileirar(filaEsquerda);
        k++;
    }

    while (!estaVazia(filaDireita)) {
        vet[k] = desenfileirar(filaDireita);
        k++;
    }

    free(filaEsquerda);
    free(filaDireita);
}

void mergesort(int* vet, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergesort(vet, inicio, meio);
        mergesort(vet, meio + 1, fim);
        merge(vet, inicio, meio, fim);
    }
}

int* criar_vetor(int n){
    int* v = (int*)malloc(n*  sizeof(int));
    return v;
}

void mostrar_vetor(int* v, int n){
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
}

void ler_inteiros(int* vet, int n){
    for(int i = 0; i < n; i++)
        scanf("%d", &vet[i]);
}

int main(){
    int tam;
    scanf("%d", &tam);

    int* v = criar_vetor(tam);
    ler_inteiros(v, tam);

    mergesort(v, 0, tam - 1);

    mostrar_vetor(v, tam);

    free(v);

    return 0;
}