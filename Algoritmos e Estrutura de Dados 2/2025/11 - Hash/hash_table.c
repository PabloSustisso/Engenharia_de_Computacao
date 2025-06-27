#include <stdio.h>
#include <stdlib.h>

#define A 0.6180339887

typedef struct{
    int tamanho;
    int *buckets;
}HashTable;

HashTable* gerarHT(unsigned int tam){
    HashTable *t = (HashTable*)malloc(sizeof(HashTable));

    t->tamanho = tam;
    t->buckets = (int*)malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++)
        t->buckets[i] = -1;

    return t;
}

static int hash_code(int key, int tam_tab){
    return tam_tab * ((int)(key * A) % 1);
}

int buscar(unsigned int key, HashTable *t){
    int hc;

    if(t != NULL)
        hc = hash_code(key, t->tamanho);

    if(t->buckets[hc] == key)
        return hc;

    return -1;
}

int inserir(unsigned int key, HashTable *t){
    int hc;

    if(t != NULL){
        hc = hash_code(key, t->tamanho);

        if(t->buckets[hc] < 0){
            t->buckets[hc] = key;

            return 1;
        }

        printf("Houve colisao ao tentar inserir a chave %d!\n", key);
    }

    return 0;
}

int remover(unsigned int key, HashTable *t){
    int posicao = buscar(key, t);

    if(posicao >= 0){
        t->buckets[posicao] = -1;

        return 1;
    }

    return 0;
}

void imprimir_tabela(HashTable *t){
    if(t != NULL){
        for(int i = 0; i < t->tamanho; i++){
            if(t->buckets[i] > -1)
                printf("%d:  %d\n", i, t->buckets[i]);
        }
    }
}

liberar_tabela(HashTable *t){
    if(t != NULL){
        free(t->buckets);
        free(t);

        return 1;
    }

    return 0;
}