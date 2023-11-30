#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar_char(char c1, char c2){
    if (c1 == c2) return 0;
    else if (c1 < c2) return -1;
    else return 1;
}

int comparar(char s1[], char s2[]){
	int i;

	for (i = 0; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);

	return comparar_char(s1[i], s2[i]);
}

void troca(char **vstr, int p1, int p2){
    char *str;

    str = vstr[p1];
    vstr[p1] = vstr[p2];
    vstr[p2] = str;
}

void sortString(char **vstr, int n, int m, int n_cima, int n_baixo)
{
    int i = n_cima, j = n_baixo, t = 1, x, y;
    char *pivo = vstr[(i + j) / 2];

    // quicksort
    do{
        while ((comparar(vstr[i], pivo) < 0))
            i++;

        while ((comparar(vstr[j], pivo) > 0))
            j--;

        if (i <= j){
            troca(vstr, i, j);
            i++;
            j--;
        }
    }while (i <= j);
    
    if (n_baixo - n_cima > m)
    {
        if (j > n_cima)
            sortString(vstr, n, m, n_cima, j);
        if (i < n_baixo)
            sortString(vstr, n, m, i, n_baixo);
    }
    else
    {
        // Bubblesort
        for (x = 0; (x <= n - 1) && t; x++){
            t = 0;

        for (y = 0; y <= n - x - 2; y++)
            if (comparar(vstr[y], vstr[y + 1]) > 0){
                troca(vstr, y, y + 1);
                t = 1;
            }
        }
    }
}

void liberarChar(char **vstr, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        free(vstr[i]);
    }
    free(vstr);
}

int main(void)
{   
    int qtd; // quantidade de nomes
    int m;
    scanf("%d", &qtd);

    // alocacao dinamica para um conjunto de strings
    char **vstr = (char**) malloc(qtd * sizeof(char*));
    for (int i = 0; i < qtd; i++)
        vstr[i] = (char*) malloc(20 * sizeof(char));

    for (int i = 0; i < qtd; i++) // scaneando os nomes
        scanf("%s", vstr[i]);
    
    scanf("%d", &m); // tamanho da particao

    sortString(vstr, qtd, m, 0, qtd-1);
    for (int i = 0; i < qtd; i++) // imprimir os nomes
        printf("%s\n", vstr[i]);

    liberarChar(vstr, qtd);

    return 0;
}