/*Dada uma função que receba uma lista estática de contatos e uma string. Essa função deverá imprimir os contatos que contêm essa string no nome. Por exemplo, para a string "son", podem ser encontrados nomes como: Son**ia, Ander**son, Jeffer**son**.

Input Format

A primeira linha a ser lida deve ser a string que deve ser procurada. Em seguida, deve ser lida um número inteiro referente à quantidade de nomes que devem ser incluídos na lista.

Constraints

Usar TAD de listas estáticas.

Output Format

Imprimir os nomes que contêm a string procurada.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Lista Lista;

struct Lista{
    int item[MAX_SIZE];
    int tam;
};

Lista* criar_lista(){
    Lista *l = (Lista*) malloc(sizeof(Lista));

    l->tam = 0;

    return l;
}

int lista_vazia(Lista *l){
    if (l == NULL)
        return -1;
    else if (l->tam > 0)
        return 0;
    else
        return 1;
}

int lista_cheia(Lista *l){
    if (l == NULL)
        return -1;
    else if (l->tam < MAX_SIZE)
        return 0;
    else
        return 1;
}

int buscar(Lista *l, int chave){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            if (l->item[i] == chave)
                return i;
    }

    return -1;
}

int inserir(Lista *l, int chave){
    if (!lista_cheia(l)){
        l->item[l->tam] = chave;

        l->tam++;

        return 1;
    }

 
    return 0;
}

int remover(Lista *l, int chave){
    int i, p = buscar(l, chave);

    if (p > -1){
        for (i = p; i < l->tam - 1; i++)
            l->item[i] = l->item[i + 1];

        l->tam--;

        return 1;
    }

    return 0;
}

void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            printf("%d ", l->item[i]);

        printf("\n");
    }
}

int main(void)
{
    //int qtd;
    char palavra[] = {'s','o','n'};
    // scanf("%d", &qtd);

    // Lista *nomes;
    // nomes = criar_lista();

    char nome[] = {'a','n','d','e','r','s','o','n'};
    char aux[MAX_SIZE];

    for (int i = 0; i < strlen(palavra); i++)
    {
        for (int j = 0; j < strlen(nome); j++)
        {
            if (nome[j] == palavra[i])
            {
                aux[i] = nome[j];
            }
            else if (aux == palavra)
            {
                printf("%s", nome);
            }
            
        }
    }
    

    

    return 0;
}