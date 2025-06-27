#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id_cliente;
    int n_ordem;
    int t_preparo;
}Pedidos;

Pedidos* criar_pedidos(int n){
    Pedidos *p = (Pedidos*)malloc(n * sizeof(Pedidos));

    return p;
}

void ler_pedidos(Pedidos *p, int n){
    int i = 0;
    int n_ordem, t_preparo;
    
    while(n > 0){
        scanf("%d %d", &n_ordem, &t_preparo);
        p[i].id_cliente = i;
        p[i].n_ordem = n_ordem;
        p[i].t_preparo = t_preparo;

        n--;
        i++;
    }
}

int comp(const void* a, const void* b){
    Pedidos *pa = (Pedidos*)a;
    Pedidos *pb = (Pedidos*)b;

    if((pa->n_ordem+pa->t_preparo) > (pb->n_ordem+pb->t_preparo))
        return 1;
    if((pa->n_ordem+pa->t_preparo) < (pb->n_ordem+pb->t_preparo))
        return -1;
    return 0;
}

void solve(Pedidos *p, int n){
    qsort(p, n, sizeof(Pedidos), comp);

    for(int i = 0; i < n; i++){
        printf("%d ", p[i].id_cliente + 1);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    Pedidos *p = criar_pedidos(n);
    ler_pedidos(p, n);
    solve(p, n);

    free(p);

    return 0;
}