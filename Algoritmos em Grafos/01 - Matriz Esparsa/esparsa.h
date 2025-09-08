#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    int linha;
    struct elemento *proximo;
}Elemento;

typedef struct coluna{
    int id_coluna;
    struct coluna *proximo;
    Elemento *inicio;
}Coluna;

typedef struct{
    int qtd_linhas;
    int qtd_colunas;
    Coluna *inicio;
}Matriz_Esparsa;

Elemento* criar_elemento(int linha, int valor){
    Elemento *e = (Elemento*)malloc(sizeof(Elemento));

    if(e == NULL) return NULL;

    e->valor = valor;
    e->linha = linha;
    e->proximo = NULL;

    return e;
}

Coluna* criar_coluna(int id){
    Coluna *c = (Coluna*)malloc(sizeof(Coluna));

    if(c != NULL){
        c->id_coluna = id;
        c->inicio = NULL;
        c->proximo = NULL;
    }

    return c;
}

Matriz_Esparsa* criar_matriz(int linhas, int colunas){
    Matriz_Esparsa *m = (Matriz_Esparsa*)malloc(sizeof(Matriz_Esparsa));

    if(m != NULL){
        m->qtd_linhas = linhas;
        m->qtd_colunas = colunas;
        m->inicio = NULL;
    }

    return m;
}

void inserir_valor(Matriz_Esparsa *m, int linha, int coluna, int valor){
    //verificacoes para nao extrapolar os limites da matriz
    if(
        linha >= m->qtd_linhas || 
        coluna >= m->qtd_colunas || 
        linha < 0 || 
        coluna < 0 ||
        valor == 0
    ) return;

    Coluna *atual = m->inicio;
    Coluna *anterior = NULL;

    while(atual != NULL && atual->id_coluna < coluna){
        anterior = atual;
        atual = atual->proximo;
    }

    //caso a coluna nao exista
    if(atual == NULL || atual->id_coluna != coluna){
        Coluna *nova = criar_coluna(coluna);
        if(nova == NULL) return; //falha na alocacao

        nova->proximo = atual;
        if(anterior == NULL)
            m->inicio = nova;
        else
            anterior->proximo = nova;

        atual = nova;
    }

    Elemento *elem_atual = atual->inicio;
    Elemento *elem_anterior = NULL;
    while(elem_atual != NULL && elem_atual->linha < linha) {
        elem_anterior = elem_atual;
        elem_atual = elem_atual->proximo;
    }

    if(elem_atual != NULL && elem_atual->linha == linha)
        elem_atual->valor = valor;
    else{
        Elemento *novo_elem = criar_elemento(linha, valor);
        novo_elem->proximo = elem_atual;

        if(elem_anterior == NULL)
            atual->inicio = novo_elem;
        else
            elem_anterior->proximo = novo_elem;
    }
}

int buscar_valor(Matriz_Esparsa *m, int linha, int coluna){
    Coluna *col_atual = m->inicio;
    while(col_atual != NULL && col_atual->id_coluna < coluna)
        col_atual = col_atual->proximo;

    if(col_atual == NULL || col_atual->id_coluna != coluna)
        return 0;

    Elemento *elem_atual = col_atual->inicio;
    while(elem_atual != NULL && elem_atual->linha < linha)
        elem_atual = elem_atual->proximo;

    if(elem_atual == NULL || elem_atual->linha != linha)
        return 0;
    
    return elem_atual->valor;
}

void imprime_matriz(Matriz_Esparsa *m) {
    printf("\n--- Matriz Esparsa (%d x %d) ---\n", m->qtd_linhas, m->qtd_colunas);
    for (int i = 0; i < m->qtd_linhas; i++) {
        for (int j = 0; j < m->qtd_colunas; j++) {
            printf("%d\t", buscar_valor(m, i, j));
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}

//1) desaloca todos os elementos da matriz e libera a memoria
void apaga_matriz(Matriz_Esparsa *m) {
    if (m == NULL) return;

    Coluna *col_atual = m->inicio;
    while (col_atual != NULL) {
        //libera a lista vertical de elementos da coluna atual
        Elemento *elem_atual = col_atual->inicio;
        while (elem_atual != NULL) {
            Elemento *elem_temp = elem_atual;
            elem_atual = elem_atual->proximo;
            free(elem_temp);
        }

        //libera o no da coluna atual
        Coluna *col_temp = col_atual;
        col_atual = col_atual->proximo;
        free(col_temp);
    }
    
    //libera a estrutura principal da matriz
    free(m);
}

//2)cria a transposta de uma matriz
Matriz_Esparsa* criar_transposta(Matriz_Esparsa *m){
    Matriz_Esparsa *transposta = criar_matriz(m->qtd_colunas, m->qtd_linhas);

    for (int i = 0; i < m->qtd_colunas; i++) {
        for (int j = 0; j < m->qtd_linhas; j++) {
            inserir_valor(transposta, i, j, buscar_valor(m, j, i));
        }
    }

    return transposta;
}