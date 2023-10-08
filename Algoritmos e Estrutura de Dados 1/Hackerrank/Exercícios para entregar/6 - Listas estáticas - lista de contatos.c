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
    char **nomes;
    int tam;
};

Lista* criar_lista(int qtd){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->nomes = (char**)malloc(qtd * sizeof(char*));
    
    for (int i = 0; i < qtd; i++)
    {
        l->nomes[i] = (char*)malloc(20 * sizeof(char*));
    }
    
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

int buscar(Lista *l, char chave[]){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
            if (l->nomes[i] == chave)
                return i;
    }

    return -1;
}

int inserir(Lista *l, char chave[]){
    if (!lista_cheia(l)){
        strcpy(l->nomes[l->tam], chave);

        l->tam++;

        return 1;
    }

    return 0;
}

int remover(Lista *l, char chave[]){
    int i, p = buscar(l, chave);

    if (p > -1){
        for (i = p; i < l->tam - 1; i++)
            l->nomes[i] = l->nomes[i + 1];

        l->tam--;

        return 1;
    }

    return 0;
}

void imprimir_lista(Lista *l){
    int i;

    if (!lista_vazia(l)){
        for (i = 0; i < l->tam; i++)
        {
            printf("%s ", l->nomes[i]);
            printf("\n");
        }
    }
}

void buscarChave(char *nome, char palavra_chave[])
{
    int tam_nome = strlen(nome), tam_chave = strlen(palavra_chave), cont = 0, aux;

    for (int i = 0; i < tam_nome; i++)
    {
        aux = i;
        for (int j = 0; j < tam_chave; j++)
        {
            if (nome[aux] == palavra_chave[j])
            {
                cont++;
                aux++;
            }
        }
        if (cont == tam_chave)
        {
            printf("%s\n", nome);
            break;
        }
        else
            cont = 0;
        
    }
    
}

int main(void)
{
    char palavra_chave[MAX_SIZE], aux[MAX_SIZE];
    int qtd;
    Lista *nomes;

    setbuf(stdin, NULL);
    scanf("%s", palavra_chave);
    scanf("%d", &qtd);

    nomes = criar_lista(qtd);

    for (int i = 0; i < qtd; i++)
    {
        scanf("%s", aux);
        inserir(nomes, aux);
    }

    // imprimir_lista(nomes);

    for (int i = 0; i < nomes->tam; i++)
    {
        buscarChave(nomes->nomes[i], palavra_chave);
    }
    
    return 0;
}