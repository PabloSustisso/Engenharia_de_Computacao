#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define TAM_MAX 100

typedef struct Pilha Pilha;

struct Pilha{
    int item[TAM_MAX];
    int topo;
};

// Criar uma pilha vazia
Pilha* criar_pilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    p->topo = -1;

    return p;
}

// Verificar se a pilha esta cheia (stack overflow)
int pilha_cheia(Pilha *p){
    
    if (p == NULL)
        return -1;
    else if (p->topo >= (TAM_MAX - 1))
        return 1;
    else
        return 0;
}

// Verificar se a pilha esta vazia (stack underflow)
int pilha_vazia(Pilha *p){
    
    if (p == NULL)
        return -1;
    else if (p->topo < 0)
        return 1;
    else
        return 0;
}

// Inserir um novo item na pilha, caso houver espaco
int empilhar(Pilha *p, int item){
    // Se a pilha for nula, reservar um espaco na memoria para ela
    if (p == NULL)
        p = criar_pilha();

    if (!pilha_cheia(p)){
        p->topo++; // a pilha aumenta

        p->item[p->topo] = item; // um novo item eh empilhado

        return 1; // operacao bem sucedida
    }

    return 0; // operacao mal sucedida
}

// Remover item do topo da pilha, caso essa estrutura nao estiver vazia
int desempilhar (Pilha *p){
    int item = INT_MIN;

    if (!pilha_vazia(p)){
        item = p->item[p->topo];

        p->topo--;
    }

    return item;
}

// Imprimir conteudo da pilha
void imprimir_pilha(Pilha *p){
    
    Pilha aux = *p;
    int item;

    while (!pilha_vazia(&aux)){
        item = desempilhar(&aux);

        printf("%d ", item);
    }
}

// Liberar a pilha
void liberar_pilha(Pilha *p){
    if (p != NULL)
        free(p);
}


// Obter a posicaoo da pilha em que esta o topo
int obter_posicao_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->topo;
    else
        return -1;
}


// Retorna o valor que esta no topo. Caso a pilha estiver vazia, sera retornado INT_MIN.
int acessar_valor_topo(Pilha *p){
    if (!pilha_vazia(p))
        return p->item[p->topo];
    else
        return INT_MIN;
}

Pilha *concatPilha(Pilha *p1, Pilha *p2)
{
    int item;

    Pilha *p3, *par, *impar, *par2, *impar2;
    p3 = criar_pilha();
    par = criar_pilha();
    impar = criar_pilha();
    par2 = criar_pilha();
    impar2 = criar_pilha();

    while (p2->topo != -1)
    {
        item = desempilhar(p2);

        if (item % 2 == 0)
        {
            empilhar(par, item);
        }
        else
            empilhar(impar, item);
    }
    while (p1->topo != -1)
    {
        item = desempilhar(p1);

        if (item % 2 == 0)
        {
            empilhar(par2, item);
        }
        else
            empilhar(impar2, item);
    }
    while (impar->topo != -1)
    {
        item = desempilhar(impar);
        empilhar(p3, item);
    }
    while (impar2->topo != -1)
    {
        item = desempilhar(impar2);
        empilhar(p3, item);
    }
    while (par->topo != -1)
    {
        item = desempilhar(par);
        empilhar(p3, item);
    }
    while (par2->topo != -1)
    {
        item = desempilhar(par2);
        empilhar(p3, item);
    }

    liberar_pilha(par);
    liberar_pilha(par2);
    liberar_pilha(impar);
    liberar_pilha(impar2);
    
    return p3;
}

int main(void)
{
    int num, num2;

    Pilha *p1, *p2, *p3;
    p1 = criar_pilha();
    p2 = criar_pilha();
    p3 = criar_pilha();
    
    do
    {
        scanf("%d", &num);
        
        if (num != -1)
        {
            empilhar(p1, num);
        }
    } while (num != -1);
    
    do
    {
        scanf("%d", &num2);
        
        if (num2 != -1)
        {
            empilhar(p2, num2);
        }
    } while (num2 != -1);

    p3 = concatPilha(p1, p2);
    liberar_pilha(p1);
    liberar_pilha(p2);
    imprimir_pilha(p3);
    liberar_pilha(p3);

    return 0;
}
