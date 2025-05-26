#ifndef ABB_H
#define ABB_H

typedef struct tree tree;

typedef struct node node;

tree* criar_tree();

node* criar_node(int key);

int arvore_vazia(tree *t);

node* buscar_iterativo(tree *t, int key);

node *buscar(tree *t, int key);

void inserir(tree *t, int key);

void imprimir(tree *t);

#endif // ABB_H