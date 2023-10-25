#include <stdio.h>
#include <string.h>

int palindromo(char string[], int inicio, int fim)
{
    if (inicio >= fim) // Condicao de parada (verificar a metade da palavra)
        return 1;
    
    if (string[inicio] == string[fim]) // Verificar cada letra da string
        return palindromo(string, inicio+1, fim-1);
    else
        return 0;
}

int main(void)
{
    char str[100];
    scanf("%s", str);

    int tam = strlen(str);

    if (palindromo(str, 0, tam-1))
        printf("palindromo");
    else
        printf("nao palindromo");
    
    return 0;
}