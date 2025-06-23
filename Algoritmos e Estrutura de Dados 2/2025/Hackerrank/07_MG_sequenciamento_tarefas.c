#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id; 
    int tempo_exec; 
    int deadline; 
}Tarefas;

Tarefas* criar_tarefas(int n){
    Tarefas *t = (Tarefas*)malloc(n * sizeof(Tarefas));

    return t;
}

void ler_tarefas(Tarefas *t, int n){
    int i = 0;
    int tempo_exec, deadline, id = 0;

    while(n > 0){
        scanf("%d %d", &tempo_exec, &deadline);
        t[i].id = id;
        t[i].tempo_exec = tempo_exec;
        t[i].deadline = deadline;

        i++;
        n--;
        id++;
    }
}

// apenas para facilitar minha vida, aprendi usar o qsort em C
int comp(const void* a, const void* b){
    Tarefas *tA = (Tarefas*)a;
    Tarefas *tB = (Tarefas*)b;

    if((tA->deadline-tA->tempo_exec) > (tB->deadline-tB->tempo_exec))
        return -1;
    if((tA->deadline-tA->tempo_exec) < (tB->deadline-tB->tempo_exec))
        return 1;
    return 0;
}

int solve(Tarefas *t, int n){
    //ordenando por (deadline - tempo_exec), ou seja, saldo de tempo
    //quanto maior o saldo, mais pro inicio vai ser ordenado
    qsort(t, n, sizeof(Tarefas), comp); //amem aleluia

    int atraso_max = 0;

    for(int i = 0; i < n; i++){
        printf("%d ", t[i].id);

        int atraso_atual = t[i].deadline - t[i].tempo_exec;

        atraso_max += atraso_atual;
    }

    if(atraso_max > 0)
        return 0;
    if(atraso_max < 0)
        atraso_max = atraso_max*(-1);

    return atraso_max;
}

int main(){
    int n;
    scanf("%d", &n);

    Tarefas *t = criar_tarefas(n);
    ler_tarefas(t, n);
    int resultado = solve(t, n);

    printf("\n%d", resultado);
    
    free(t);

    return 0;
}