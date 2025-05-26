#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int item;
    struct node *pai;
    struct node *left;
    struct node *right;
}node;

typedef struct tree{
    node *raiz;
}tree;

tree* criar_tree(){
    tree *t = (tree*)malloc(sizeof(tree));
    t->raiz = NULL;
    return t;
}

node* criar_node(int key){
    node *novo = (node*)malloc(sizeof(node));
    novo->item = key;
    novo->pai = NULL;
    novo->left = NULL;
    novo->right = NULL;

    return novo;
}

int arvore_vazia(tree *t){
    return (t ==  NULL) || (t->raiz == NULL);
}

node* buscar_iterativo(tree *t, int key){
    node *aux = NULL;

    if(t != NULL){
        aux = t->raiz;

        while(aux != NULL && aux->item != key){
            if(key < aux->item)
                aux = aux->left;
            else aux = aux->right;
        }
    }
    return aux;
}

node *search(node *n, int key){
    if(n == NULL || n->item == key)
        return n;
    if(key < n->item)
        return search(n->left, key);
    else
        return search(n->right, key);
}

node *buscar(tree *t, int key){
    if(t == NULL)
        return NULL;
    return search(t->raiz, key);
}

node* inserir_recursivo(node *n, int key) {
    if (n == NULL) {
        return criar_node(key);
    }

    if (key <= n->item) {
        node *filho = inserir_recursivo(n->left, key);
        n->left = filho;
        filho->pai = n;
    } else {
        node *filho = inserir_recursivo(n->right, key);
        n->right = filho;
        filho->pai = n;
    }

    return n;
}

void inserir(tree *t, int key) {
    t->raiz = inserir_recursivo(t->raiz, key);
}

void infix(node *n){
    if(n != NULL){
        infix(n->left);
        printf("%d ", n->item);
        infix(n->right);
    }
}

void imprimir_ordenado(tree *t){
    infix(t->raiz);
}

void infix_folhas(node *n){
    if(n != NULL){
        infix_folhas(n->left);
        if(n->left == NULL && n->right == NULL)
            printf(" %d", n->item);
        infix_folhas(n->right);
    }
}

void imprimir_folhas(tree *t){
    infix_folhas(t->raiz);
}

void pos_liberar(node *n){
    if(n != NULL){
        pos_liberar(n->left);
        pos_liberar(n->right);
        free(n);
    }
}

void liberar_ABB(tree *t){
    pos_liberar(t->raiz);
    free(t);
}

int main(){
    tree *t = criar_tree();
    int n, num;
    scanf("%d", &n);
    
    do{
        scanf("%d", &num);
        inserir(t, num);
        n--;
        if(n == 0)
            break;
    } while(num > 0);
    
    imprimir_folhas(t);
    liberar_ABB(t);
    
    return 0;
}