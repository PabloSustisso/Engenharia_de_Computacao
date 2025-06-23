#include <stdio.h>
#include <stdlib.h>

int main(){
    system("cls");
    //pode ser o caminho absoluto ou relativo (dentro da pasta)
    FILE *F = fopen("teste.txt", "a+"); //abrindo para escrita, no modo texto

    if(F == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    //fputs("Olá, mas sobrescrevido.", F);
    fclose(F);

    
    printf("%c", fgetc(F));

    return 0;
}