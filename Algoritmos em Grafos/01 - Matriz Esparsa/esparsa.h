#include <stdio.h>
#include <stdlib.h>

// --- ESTRUTURAS DE DADOS ---

/**
 * @brief Estrutura que representa um elemento (valor nao nulo) na matriz.
 * Cada elemento contem seu valor, sua linha e um ponteiro para o proximo
 * elemento na mesma coluna.
 */
typedef struct elemento{
    int valor;
    int linha;
    struct elemento *proximo;
}Elemento;

/**
 * @brief Estrutura que representa uma coluna na matriz esparsa.
 * Apenas colunas com elementos nao nulos sao armazenadas.
 * Cada coluna tem um identificador e aponta para a proxima coluna e
 * para o inicio da lista de elementos (linhas) que contem.
 */
typedef struct coluna{
    int id_coluna;
    struct coluna *proximo;
    Elemento *inicio;
}Coluna;

/**
 * @brief Estrutura principal que representa a matriz esparsa.
 * Contem as dimensoes da matriz (linhas e colunas) e um ponteiro
 * para a primeira coluna que possui elementos nao nulos.
 */
typedef struct{
    int qtd_linhas;
    int qtd_colunas;
    Coluna *inicio;
}Matriz_Esparsa;

// --- FUNCOES DE CRIACAO ---

/**
 * @brief Aloca e inicializa um novo no do tipo Elemento.
 * @param linha O indice da linha onde o elemento se encontra.
 * @param valor O valor do elemento a ser armazenado.
 * @return Ponteiro para o novo Elemento criado ou NULL em caso de erro de alocacao.
 */
Elemento* criar_elemento(int linha, int valor){
    Elemento *e = (Elemento*)malloc(sizeof(Elemento));

    // Verifica se a alocacao de memoria foi bem sucedida
    if(e == NULL) return NULL;

    e->valor = valor;
    e->linha = linha;
    e->proximo = NULL;

    return e;
}

/**
 * @brief Aloca e inicializa um novo no do tipo Coluna.
 * @param id O indice que identifica a coluna.
 * @return Ponteiro para a nova Coluna criada ou NULL em caso de erro de alocacao.
 */
Coluna* criar_coluna(int id){
    Coluna *c = (Coluna*)malloc(sizeof(Coluna));

    if(c != NULL){
        c->id_coluna = id;
        c->inicio = NULL; // A coluna comeca vazia, sem elementos
        c->proximo = NULL;
    }

    return c;
}

/**
 * @brief Aloca e inicializa a estrutura principal da Matriz_Esparsa.
 * @param linhas A quantidade total de linhas da matriz.
 * @param colunas A quantidade total de colunas da matriz.
 * @return Ponteiro para a nova Matriz_Esparsa criada ou NULL em caso de erro.
 */
Matriz_Esparsa* criar_matriz(int linhas, int colunas){
    Matriz_Esparsa *m = (Matriz_Esparsa*)malloc(sizeof(Matriz_Esparsa));

    if(m != NULL){
        m->qtd_linhas = linhas;
        m->qtd_colunas = colunas;
        m->inicio = NULL; // A matriz comeca vazia, sem colunas
    }

    return m;
}

// --- FUNCOES DE MANIPULACAO ---

/**
 * @brief Insere ou atualiza um valor em uma determinada posicao (linha, coluna) da matriz.
 * Se o valor for 0, a operacao e ignorada para manter a esparsidade.
 * @param m Ponteiro para a matriz esparsa.
 * @param linha Indice da linha.
 * @param coluna Indice da coluna.
 * @param valor Valor a ser inserido.
 */
void inserir_valor(Matriz_Esparsa *m, int linha, int coluna, int valor){
    // Verificacoes para garantir que a posicao e valida e o valor nao e zero.
    // Valores zero nao sao armazenados em uma matriz esparsa.
    if(
        linha >= m->qtd_linhas ||
        coluna >= m->qtd_colunas ||
        linha < 0 ||
        coluna < 0 ||
        valor == 0
    ) return;

    Coluna *atual = m->inicio;
    Coluna *anterior = NULL;

    // Navega na lista de colunas ate encontrar a posicao correta para a nova
    // coluna ou ate encontrar a coluna ja existente.
    while(atual != NULL && atual->id_coluna < coluna){
        anterior = atual;
        atual = atual->proximo;
    }

    // Caso a coluna nao exista, e necessario cria-la e inseri-la na lista
    // ordenada de colunas.
    if(atual == NULL || atual->id_coluna != coluna){
        Coluna *nova = criar_coluna(coluna);
        if(nova == NULL) return; // Falha na alocacao de memoria

        nova->proximo = atual;
        if(anterior == NULL) // Insercao no inicio da lista de colunas
            m->inicio = nova;
        else // Insercao no meio ou fim da lista
            anterior->proximo = nova;

        atual = nova;
    }

    // Agora, com a coluna correta (existente ou nova), busca-se a posicao
    // do elemento (linha) dentro da lista de elementos da coluna.
    Elemento *elem_atual = atual->inicio;
    Elemento *elem_anterior = NULL;
    while(elem_atual != NULL && elem_atual->linha < linha) {
        elem_anterior = elem_atual;
        elem_atual = elem_atual->proximo;
    }

    // Se o elemento ja existe naquela linha, apenas atualiza o seu valor.
    if(elem_atual != NULL && elem_atual->linha == linha)
        elem_atual->valor = valor;
    // Senao, cria um novo elemento e o insere na lista ordenada de linhas.
    else{
        Elemento *novo_elem = criar_elemento(linha, valor);
        novo_elem->proximo = elem_atual;

        if(elem_anterior == NULL) // Insercao no inicio da lista de elementos
            atual->inicio = novo_elem;
        else // Insercao no meio ou fim
            elem_anterior->proximo = novo_elem;
    }
}

/**
 * @brief Busca e retorna o valor em uma determinada posicao (linha, coluna).
 * @param m Ponteiro para a matriz esparsa.
 * @param linha Indice da linha.
 * @param coluna Indice da coluna.
 * @return O valor na posicao especificada ou 0 se o elemento nao for encontrado.
 */
int buscar_valor(Matriz_Esparsa *m, int linha, int coluna){
    // Procura pela coluna correta
    Coluna *col_atual = m->inicio;
    while(col_atual != NULL && col_atual->id_coluna < coluna)
        col_atual = col_atual->proximo;

    // Se a coluna nao foi encontrada, o valor e zero
    if(col_atual == NULL || col_atual->id_coluna != coluna)
        return 0;

    // Procura pelo elemento (linha) dentro da coluna encontrada
    Elemento *elem_atual = col_atual->inicio;
    while(elem_atual != NULL && elem_atual->linha < linha)
        elem_atual = elem_atual->proximo;

    // Se o elemento nao foi encontrado, o valor e zero
    if(elem_atual == NULL || elem_atual->linha != linha)
        return 0;
    
    // Retorna o valor encontrado
    return elem_atual->valor;
}

/**
 * @brief Imprime a matriz esparsa em seu formato denso (tradicional).
 * @param m Ponteiro para a matriz esparsa.
 */
void imprime_matriz(Matriz_Esparsa *m) {
    printf("\n--- Matriz Esparsa (%d x %d) ---\n", m->qtd_linhas, m->qtd_colunas);
    for (int i = 0; i < m->qtd_linhas; i++) {
        for (int j = 0; j < m->qtd_colunas; j++) {
            // Usa a funcao de busca para obter o valor de cada celula
            printf("%d\t", buscar_valor(m, i, j));
        }
        printf("\n");
    }
    printf("-----------------------------\n");
}

/**
 * @brief Libera toda a memoria alocada para a matriz esparsa.
 * @param m Ponteiro para a matriz esparsa a ser apagada.
 */
void apaga_matriz(Matriz_Esparsa *m) {
    if (m == NULL) return;

    Coluna *col_atual = m->inicio;
    while (col_atual != NULL) {
        // Libera a lista vertical de elementos da coluna atual
        Elemento *elem_atual = col_atual->inicio;
        while (elem_atual != NULL) {
            Elemento *elem_temp = elem_atual;
            elem_atual = elem_atual->proximo;
            free(elem_temp);
        }

        // Libera o no da coluna atual
        Coluna *col_temp = col_atual;
        col_atual = col_atual->proximo;
        free(col_temp);
    }
    
    // Libera a estrutura principal da matriz
    free(m);
}

// --- FUNCOES DE OPERACOES MATEMATICAS ---

/**
 * @brief Cria e retorna a matriz transposta de uma matriz dada.
 * @param m Ponteiro para a matriz original.
 * @return Ponteiro para a nova matriz transposta.
 */
Matriz_Esparsa* criar_transposta(Matriz_Esparsa *m){
    // A matriz transposta tem as dimensoes invertidas
    Matriz_Esparsa *transposta = criar_matriz(m->qtd_colunas, m->qtd_linhas);

    // Percorre todos os elementos da matriz original
    for (int i = 0; i < m->qtd_colunas; i++) {
        for (int j = 0; j < m->qtd_linhas; j++) {
            // Insere o valor de (j, i) da original na posicao (i, j) da transposta
            inserir_valor(transposta, i, j, buscar_valor(m, j, i));
        }
    }

    return transposta;
}

/**
 * @brief Soma duas matrizes (A e B) e armazena o resultado em uma terceira matriz (C).
 * As matrizes A e B devem ter as mesmas dimensoes.
 * @param a Ponteiro para a primeira matriz (A).
 * @param b Ponteiro para a segunda matriz (B).
 * @param c Ponteiro para a matriz de resultado (C).
 */
void somar_matrizes(Matriz_Esparsa *a, Matriz_Esparsa *b, Matriz_Esparsa *c){
    // Verifica se as matrizes tem dimensoes compativeis para a soma
    if(a->qtd_colunas != b->qtd_colunas ||
        a->qtd_linhas != b->qtd_linhas){
            printf("\nPara somar duas matrizes, estas precisam ter as mesmas dimensoes!\n");
            return;
    }
    
    // Percorre cada posicao das matrizes
    for(int i = 0; i < a->qtd_linhas; i++){
        for(int j = 0; j < a->qtd_colunas; j++){
            // Soma os valores das posicoes correspondentes
            int soma = buscar_valor(a, i, j) + buscar_valor(b, i, j);
            // Insere a soma na matriz resultado (se a soma nao for zero)
            inserir_valor(c, i, j, soma);
        }
    }
}

/**
 * @brief Multiplica duas matrizes (A e B) e armazena o resultado em uma terceira matriz (C).
 * O numero de colunas de A deve ser igual ao numero de linhas de B.
 * @param a Ponteiro para a primeira matriz (A).
 * @param b Ponteiro para a segunda matriz (B).
 * @param c Ponteiro para a matriz de resultado (C).
 */
void multiplicar_matrizes(Matriz_Esparsa *a, Matriz_Esparsa *b, Matriz_Esparsa *c){
    // Verifica a condicao para multiplicacao de matrizes:
    // numero de colunas de A deve ser igual ao numero de linhas de B.
    if(a->qtd_colunas != b->qtd_linhas){
        printf("\nPara multiplicar duas matrizes, a quantidade de colunas da matriz A precisa ser igual a quantidade de linhas da matriz B!\n");
        return;
    }

    // Verifica se a matriz de resultado C tem as dimensoes corretas.
    // C deve ter (linhas de A) x (colunas de B).
    if (c->qtd_linhas != a->qtd_linhas || c->qtd_colunas != b->qtd_colunas) {
        printf("\nErro: A matriz de resultado C nao tem as dimensoes corretas.\n");
        printf("Deveria ser (%d x %d).\n", a->qtd_linhas, b->qtd_colunas);
        return;
    }

    // Itera sobre as linhas da matriz A (e da matriz resultado C).
    for (int i = 0; i < a->qtd_linhas; i++) {
        // Itera sobre as colunas da matriz B (e da matriz resultado C).
        for (int j = 0; j < b->qtd_colunas; j++) {
            
            int soma_dos_produtos = 0;

            // Calcula o produto escalar da linha 'i' de A com a coluna 'j' de B.
            // O terceiro loop 'k' percorre as colunas de A e as linhas de B.
            for (int k = 0; k < a->qtd_colunas; k++) {
                soma_dos_produtos += buscar_valor(a, i, k) * buscar_valor(b, k, j);
            }

            // Se o resultado da soma dos produtos for diferente de zero,
            // insere o valor na matriz esparsa C.
            if (soma_dos_produtos != 0) {
                inserir_valor(c, i, j, soma_dos_produtos);
            }
        }
    }
}