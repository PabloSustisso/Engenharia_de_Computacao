#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct aluno
// {
//     char nome[101];
//     int RA;
//     float coef;
// } Aluno;

// int main(void)
// {
//     Aluno variavel;
//     Aluno *ponteiro;

//     ponteiro = &variavel;

//     (*ponteiro).RA = 98765;
//     (*ponteiro).coef = 0.57;
//     strcpy((*ponteiro).nome, "Gil Away");

//     printf("%d %.2f %s", (*ponteiro).RA, (*ponteiro).coef, ponteiro->nome);

//     return 0;
// }

// typedef struct aluno
// {
//     char nome[101];
//     int *RA;
//     float coef;
// } Aluno;

// int main(void)
// {
//     Aluno variavel;
//     int x = 123;
//     variavel.RA = &x;

//     printf("%d", (*variavel.RA));

//     *variavel.RA = 321;

//     printf("%d", (*variavel.RA));

//     return 0;
// }

// int main(void)
// {
//     Aluno variavel;
//     Aluno *ponteiro;

//     ponteiro = &variavel;

//     ponteiro->RA = 12345;
//     ponteiro->coef = 0.65;
//     strcpy(ponteiro->nome, "Roberto");

//     return 0;
// }

typedef struct
{
    float x, y;
} retangulo;

retangulo *soma(retangulo *r1, retangulo *r2)
{
    retangulo aux;
    retangulo *p_aux = &aux;

    p_aux->x = r1->x + r2->x;
    p_aux->y = r1->y + r2->y;

    return p_aux;
}

int main()
{
    retangulo a = {1.5, 2.5}, b = {3.5, 4.5};
    // retangulo *r1, *r2;

    // r1 = &a;
    // r2 = &b;
    // retangulo *p = soma(r1, &r2);

    retangulo *p = soma(&a, &b);
    
    printf("\n%f %f\n", p->x, p->y);
    
    return 0;
}