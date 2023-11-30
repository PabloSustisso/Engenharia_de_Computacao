#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
}data;

typedef struct
{
    int num_casa;
    char rua[50];
    char bairro[50];
    char cep[9];
    char estado[50];
}endereco;

typedef union //Para permitir e guardar somente uma das opções de documento
{
    char rg[9];
    char cnh[11];
}rg_cnh;

typedef struct
{
    char nome[100];
    rg_cnh rg_cnh;
    char sexo;
    char tipo_sangue[3];
    char cpf[11];
    data data_nasc;
    endereco endereco;
}Pessoa;

void preencher_lista_contatos(int n, Pessoa pessoas[n])
{
    char opc_doc;

    for (int i = 0; i < n; i++)
    {
        printf("Nome (ate 100 caracteres): ");
        scanf("%s", pessoas[i].nome[100]);

        printf("(RG - R) ou (CNH - C)?");
        scanf("%c", &opc_doc);
        if (opc_doc == 'R' || 'r')
        {
            printf("RG: ");
            scanf("%s", pessoas[i].rg_cnh.rg[9]);
        }
        else if (opc_doc == 'C' || 'c')
        {
            printf("CNH: ");
            scanf("%s", pessoas[i].rg_cnh.cnh[11]);
        }
        
        printf("Sexo (M/F):");
        scanf("%c", pessoas[i].sexo);

        printf("Tipo sanguineo (A+, AB-, ...): ");
        scanf("%s", pessoas[i].tipo_sangue[3]);
        while ((pessoas[i].tipo_sangue) != "A+" || "A-" || "B+" || "B-" || "AB+" || "AB-" || "O+" || "O-")
        {
            printf("\nPor favor, insira um tipo sanguineo valido!\n");
            printf("Tipo sanguineo (A+, AB-, ...): ");
            scanf("%s", pessoas[i].tipo_sangue[3]);
        }
    
        printf("CPF: ");
        scanf("%s", pessoas[i].cpf[11]);

        printf("Data de nascimento: ");
    }
}

int main(void)
{
    int n; //Quantidade de pessoas a serem cadastradas
    scanf("%d", &n);

    Pessoa pessoas[n]; //Vetor do tipo struct "Pessoa" para armazenar mais de um cadastro

    return 0;
}