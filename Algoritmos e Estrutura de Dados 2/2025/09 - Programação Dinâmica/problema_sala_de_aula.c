#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define um valor máximo para N
#define N 10

// Vetor global para armazenar os tamanhos das strings
// baseado na sequência de Fibonacci.
int F[N + 1];

// Função para pré-calcular os comprimentos das strings T(0) até T(n)
// T(0) = "a" -> comprimento 1
// T(1) = "b" -> comprimento 1
// T(i) = T(i-1)T(i-2) -> comprimento F[i-1] + F[i-2]
void calcular_tamanhos_fibonacci(int n) {
    if (n < 0) return;

    // Ajuste para os comprimentos das strings base
    F[0] = 1;
    if (n >= 1) {
        F[1] = 1;
    }

    // Calcula os tamanhos seguintes
    for (int i = 2; i <= n; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
}

// Função iterativa "simples" para gerar a string T(n)
char* gerar_string_recorrente(int n) {
    if (n < 0) return NULL;

    // 1. Pré-calcula todos os tamanhos necessários de uma vez
    calcular_tamanhos_fibonacci(n);

    // 2. Aloca a "tabela" para guardar todas as strings de T(0) a T(n)
    char** T = (char**)malloc((n + 1) * sizeof(char*));
    if (T == NULL) {
        printf("Erro de alocacao para a tabela de ponteiros!\n");
        return NULL;
    }

    // 3. Constrói as strings de baixo para cima (bottom-up)
    for (int i = 0; i <= n; i++) {
        // Aloca memória para a string T[i], incluindo espaço para o '\0'
        T[i] = (char*)malloc((F[i] + 1) * sizeof(char));
        if (T[i] == NULL) {
            printf("Erro de alocacao para a string T[%d]!\n", i);
            // Em caso de erro, libera toda a memória já alocada
            for(int j = 0; j < i; j++) free(T[j]);
            free(T);
            return NULL;
        }

        // Casos base
        if (i == 0) {
            strcpy(T[i], "a");
        } else if (i == 1) {
            strcpy(T[i], "b");
        }
        // Passo iterativo
        else {
            // Forma correta e segura de concatenar:
            // 1. Copia a primeira parte para o destino (que está vazio)
            strcpy(T[i], T[i - 1]);
            // 2. Anexa a segunda parte ao final do destino
            strcat(T[i], T[i - 2]);
        }
    }

    // 4. O resultado final está em T[n].
    // Copiamos para uma nova string para poder liberar a tabela inteira.
    char* resultado_final = (char*)malloc((F[n] + 1) * sizeof(char));
    if (resultado_final != NULL) {
        strcpy(resultado_final, T[n]);
    }

    // 5. Libera toda a memória usada pela tabela temporária T
    for (int i = 0; i <= n; i++) {
        free(T[i]);
    }
    free(T);

    return resultado_final;
}


int main() {
    int n = 10; // Exemplo: T(4) deve ser "babba"

    if (n > N) {
        printf("N muito grande! Aumente o #define N.\n");
        return 1;
    }

    printf("Calculando T(%d)...\n", n);
    char* resultado = gerar_string_recorrente(n);

    if (resultado != NULL) {
        printf("Resultado para T(%d): %s\n", n, resultado);
        // Libera a memória do resultado final que foi retornado
        free(resultado);
    } else {
        printf("Nao foi possivel gerar a string.\n");
    }

    return 0;
}