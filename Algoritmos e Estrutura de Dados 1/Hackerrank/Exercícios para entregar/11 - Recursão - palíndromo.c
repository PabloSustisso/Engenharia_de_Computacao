#include <stdio.h>
#include <string.h>

void palindromo(char string[], int inicio, int fim)
{
    if (inicio >= fim){ // Condicao de parada (verificar a metade da palavra)
        printf("palindromo");
        return 0;
    }
    if (string[inicio] == string[fim]) // Verificar cada letra da string
        palindromo(string, inicio+1, fim-1);
    else
        printf("nao palindromo");
}

int main(void)
{
    char str[100];
    scanf("%s", str);

    int tam = strlen(str);

    palindromo(str, 0, tam-1);
    
    return 0;
}