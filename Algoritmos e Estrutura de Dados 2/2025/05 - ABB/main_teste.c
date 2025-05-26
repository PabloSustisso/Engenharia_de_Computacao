#include <stdio.h>
#include <stdlib.h>
#include "ABB.c"

int main(){
    tree *t = criar_tree();
    int n, num;
    scanf("%d", &n);
    
    do{
        scanf("%d", &num);
        inserir(t, num);
        n--;
        if(n == 0)
            break;
    } while(num > 0);
    
    imprimir_folhas(t);
    
    return 0;
}