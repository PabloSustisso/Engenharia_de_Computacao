
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Definição do Tipo Abstrato de Dados (TAD) para processamento de matrizes
/* Crie um TAD para processamento de matrizes com a seguinte estrutura e 
operações, onde m é a matriz, l é a quantidade de linhas e c é a quantidade de colunas: */
typedef struct{
    int **arr; // Matriz l x c (arranjo bidimensional)
    int l; // quantidade de linhas
    int c; // quantidade de colunas
}Matriz;

// Exercício:
/* Input Format

Na primeira linha, devem ser lidos dois números inteiros (e.g. l e c).

Em seguida, ler l x c elementos.

Após, ler dois números inteiros, sendo o primeiro a posição de uma linha (pl) e o segundo, a posição de uma coluna (pc).

Por fim, ler quatro números inteiros referentes a posição de uma submatriz.

Constraints

.

Output Format

Na primeira linha, imprimir a linha da posição pl retornada pela função obter_linha.

Na segunda linha, imprimir '\n'.

Na terceira linha, imprimir a coluna da posição pc retornada pela função obter_coluna.

Na quarta linha, imprimir '\n'.

A partir da quinta linha, imprimir a submatriz. */

// Função para inicializar uma matriz com l linhas e c colunas
Matriz * iniciar(int l, int c)
{
    Matriz *matriz = (Matriz*)malloc(sizeof(Matriz));

    matriz->arr = (int**)malloc(l * sizeof(int*));
    matriz->l = l;
    matriz->c = c;
    
    for (int i = 0; i < l; i++) // Alocando dinamicamente as colunas da matriz
    {
        matriz->arr[i] = (int*)malloc(c * sizeof(int));
    }

    return matriz;
};

// Função para alterar o valor na posição [i][j] da matriz
void alterar(Matriz *m, int x, int i, int j);

// Função para obter uma linha da matriz na posição i e copiá-la para um vetor
int *obter_linha(Matriz *m, int i)
{
    int *vet_linha;
    vet_linha = (int*)malloc(m->c * sizeof(int));

    for (int j = 0; j < m->c; j++)
    {
        vet_linha[j] = m->arr[i][j];
    }

    return vet_linha;
};

// Função para obter uma coluna da matriz na posição i e copiá-la para um vetor
int *obter_coluna(Matriz *m, int i)
{
    int *vet_coluna;
    vet_coluna = (int*)malloc(m->l * sizeof(int));

    for (int j = 0; j < m->l; j++)
    {
        vet_coluna[j] = m->arr[j][i];
    }
    
    return vet_coluna;
};

// Função para obter uma submatriz a partir de intervalos da matriz principal
Matriz *obter_submat(Matriz *m, int li, int ci, int lf, int cf)
{
    Matriz *sub_matriz = iniciar((lf-li+1), (cf-ci+1));

    int a = 0, b = 0;

    for (int i = li; i <= lf; i++)
    {   
        for (int j = ci; j <= cf; j++) // Percorrer a matriz principal dentro do intervalo de posição fornecido
        {
            sub_matriz->arr[a][b] = m->arr[i][j]; 
            b++;
        }
        b = 0; // Resetando o índice das colunas para a próxima linha
        a++; // Índice para percorrer a submatriz
    }

    return sub_matriz;
};

// Imprimir matriz alocada dinamicamente da Struct Matriz de tamanho l x c
void imprimirMatriz(Matriz *m, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", m->arr[i][j]);
        }
        printf("\n");
    }
    
}

// Imprimir vetor de tamanho c
void imprimirVetor(int *vet, int c)
{
    for (int i = 0; i < c; i++)
    {
        printf("%d ", vet[i]);
    }
}

// Função principal e chamada das TADs
int main(void)
{
    int l, c, num, pl, pc, li, lf, ci, cf;
    scanf("%d %d", &l, &c);

    Matriz *matriz, *sub_mat;

    matriz = iniciar(l, c); // Iniciando a matriz principal com l x c

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &num);
            matriz->arr[i][j] = num; // Preenchendo a matriz principal com valores fonecidos pelo usuário
        }
    }
    
    //printf("\n");
    //imprimirMatriz(matriz, l, c);

    scanf("%d %d", &pl, &pc);
    imprimirVetor(obter_linha(matriz, pl), c);
    printf("\n\n");
    
    imprimirVetor(obter_coluna(matriz, pc), l);
    printf("\n\n");

    scanf("%d %d %d %d", &li, &ci, &lf, &cf);
    sub_mat = iniciar((lf-li+1), (cf-ci+1)); // Usa-se lf-li+1 para evitar o overflow e underflow e fazer a leitura do tamanho da matriz corretamente
    sub_mat = obter_submat(matriz, li, ci, lf, cf);
    imprimirMatriz(sub_mat, (lf-li+1), (cf-ci+1));

    return 0;
}