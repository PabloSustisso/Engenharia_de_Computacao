#include <stdio.h>
#include "esparsa.h"

Matriz_Esparsa* matriz_trabalho(){
    Matriz_Esparsa *m = criar_matriz(6, 7);
    inserir_valor(m, 0, 0, 2);
    inserir_valor(m, 1, 5, 45);
    inserir_valor(m, 1, 6, 13);
    inserir_valor(m, 2, 4, 89);
    inserir_valor(m, 3, 2, 12);
    inserir_valor(m, 5, 4, 3);

    return m;
}

void teste2(Matriz_Esparsa *m){
    m = matriz_trabalho();

    printf("--- INICIO DOS TESTES DA BIBLIOTECA DE MATRIZ ESPARSA ---\n");

    // --- 1. Teste de Criacao, Insercao e Impressao ---
    printf("\n========================================================\n");
    printf("1. TESTE: Criacao de Matriz, Insercao e Impressao\n");
    printf("========================================================\n");

    printf("-> Matriz A (%dx%d) criada.\n", m->qtd_linhas, m->qtd_colunas);
    imprime_matriz(m);

    // --- 2. Teste de Busca de Valor ---
    printf("\n========================================================\n");
    printf("2. TESTE: Busca de Valores em Matriz A\n");
    printf("========================================================\n");
    printf("-> Buscando valor em (0,0). Esperado: 2. Resultado: %d\n", buscar_valor(m, 0, 0));
    printf("-> Buscando valor em (5,4). Esperado: 3. Resultado: %d\n", buscar_valor(m, 5, 4));
    printf("-> Buscando valor em (2,0) (posicao vazia). Esperado: 0. Resultado: %d\n", buscar_valor(m, 2, 0));

    // --- 3. Teste de Matriz Transposta ---
    printf("\n========================================================\n");
    printf("3. TESTE: Criacao de Matriz Transposta\n");
    printf("========================================================\n");
    printf("-> Criando a transposta da Matriz A...\n");
    Matriz_Esparsa *transpostaM = criar_transposta(m);
    printf("-> Matriz Transposta de A (6x7):");
    imprime_matriz(transpostaM);
}

// Funcao principal para testar a biblioteca de Matriz Esparsa
int main() {
    Matriz_Esparsa *m;

    // Cria uma matriz A de tamanho 4x5
    Matriz_Esparsa *matrizA = criar_matriz(4, 5);
    printf("-> Matriz A (4x5) criada.\n");

    // Insere alguns valores
    inserir_valor(matrizA, 0, 2, 10);
    inserir_valor(matrizA, 1, 1, 20);
    inserir_valor(matrizA, 1, 3, -5);
    inserir_valor(matrizA, 2, 4, 30);
    inserir_valor(matrizA, 3, 0, 40);

    //passo 1 ao 3
    teste2(m);

    Matriz_Esparsa *transpostaA = criar_transposta(matrizA);
    printf("-> Matriz A original (4x5):");
    imprime_matriz(matrizA);
    printf("-> Matriz Transposta de A (5x4):");
    imprime_matriz(transpostaA);


    // --- 4. Teste de Soma de Matrizes ---
    printf("\n========================================================\n");
    printf("4. TESTE: Soma de Matrizes (A + B = C)\n");
    printf("========================================================\n");
    
    // Cria uma matriz B para somar com A
    Matriz_Esparsa *matrizB = criar_matriz(4, 5);
    inserir_valor(matrizB, 0, 2, 7);    // Soma com elemento existente em A
    inserir_valor(matrizB, 1, 1, -15);  // Soma com elemento existente em A
    inserir_valor(matrizB, 3, 3, 50);   // Soma com elemento nao existente em A
    printf("-> Matriz B (4x5) criada para a soma:\n");
    imprime_matriz(matrizB);

    // Cria a matriz C para receber o resultado
    Matriz_Esparsa *matrizSoma = criar_matriz(4, 5);

    printf("-> Somando Matriz A + Matriz B...\n");
    somar_matrizes(matrizA, matrizB, matrizSoma);

    printf("-> Matriz Resultado da Soma (C):");
    imprime_matriz(matrizSoma);
    printf("-> Verificacao: C(0,2)=10+7=17, C(1,1)=25-15=10, C(3,3)=0+50=50\n");


    // --- 5. Teste de Multiplicacao de Matrizes ---
    printf("\n========================================================\n");
    printf("5. TESTE: Multiplicacao de Matrizes (A * TranspostaA = D)\n");
    printf("========================================================\n");
    // Para multiplicar, o numero de colunas de A (5) deve ser igual
    // ao numero de linhas da TranspostaA (5). O resultado sera 4x4.
    
    // Cria a matriz D para receber o resultado da multiplicacao
    Matriz_Esparsa *matrizMult = criar_matriz(4, 4);

    printf("-> Multiplicando Matriz A (4x5) por sua Transposta (5x4)...\n");
    multiplicar_matrizes(matrizA, transpostaA, matrizMult);

    printf("-> Matriz Resultado da Multiplicacao (D):");
    imprime_matriz(matrizMult);
    printf("-> Verificacao manual de D(0,0): (linha 0 de A) . (coluna 0 de TranspostaA) = 10*10 = 100\n");
    printf("-> Verificacao manual de D(1,1): (linha 1 de A) . (coluna 1 de TranspostaA) = 25*25 + (-5)*(-5) = 625 + 25 = 650\n");

    // --- Teste de erro na multiplicacao ---
    printf("\n-> Tentando multiplicar matrizes com dimensoes incompativeis (A * B)...\n");
    multiplicar_matrizes(matrizA, matrizB, matrizMult); // Deve imprimir uma mensagem de erro


    // --- 6. Teste de Liberacao de Memoria ---
    printf("\n========================================================\n");
    printf("6. TESTE: Liberacao de toda a memoria alocada\n");
    printf("========================================================\n");

    apaga_matriz(matrizA);
    apaga_matriz(matrizB);
    apaga_matriz(transpostaA);
    apaga_matriz(matrizSoma);
    apaga_matriz(matrizMult);
    printf("-> Todas as matrizes foram liberadas da memoria.\n");

    printf("\n--- FIM DOS TESTES ---\n");

    return 0;
}