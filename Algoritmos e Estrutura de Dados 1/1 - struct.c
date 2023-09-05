#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
   char nome[101];
   int RA;
   float coef; 
}Aluno;

void imprime_struct(Aluno a)
{
    printf("Nome: %s", a.nome);
    printf("RA: %d", a.RA);
    printf("\nCoeficiente: %.3f\n", a.coef);
}

int main(void)
{
    int i;

    Aluno a[2];

    for (i = 0; i < 2; i++)
    {
        printf("Nome: ");
        //scanf("%s", a[i].nome);
        setbuf(stdin, NULL);
        fgets(a[i].nome, sizeof(a[i].nome), stdin);
        
        printf("RA: ");
        scanf("%d", &a[i].RA);
        printf("Coeficiente: ");
        scanf("%f", &a[i].coef);
        printf("\n");
    }

    system("cls");

    for (i = 0; i < 2; i++)
    {
        imprime_struct(a[i]);
    }
    
    return 0;
}