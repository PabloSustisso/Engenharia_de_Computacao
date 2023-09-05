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
    char tipo_sangue[2];
    char cpf[11];
    data data_nasc;
    endereco endereco;
}Pessoa;

void criar_lista_contatos(int n, Pessoa pessoas[n])
{
    
    
}

int main(void)
{
    int n; //Quantidade de pessoas a serem cadastradas
    scanf("%d", &n);

    Pessoa pessoas[n]; //Vetor do tipo struct "Pessoa" para armazenar mais de um cadastro

    return 0;
}