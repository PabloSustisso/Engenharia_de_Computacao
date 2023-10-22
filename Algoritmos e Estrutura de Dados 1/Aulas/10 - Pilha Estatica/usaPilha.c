#include "pilha.h"
#include "pilha.c"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i;

  Pilha *ptr = criar_pilha();
  if (ptr == NULL)
  {
    printf("Erro ao criar a pilha!\n");
    exit(1);
  }

  for (i = -50; i < 50; i++)
    if (!empilhar(ptr, i))
      printf("Erro ao empilhar!");

  imprimir_pilha(ptr);

  liberar_pilha(ptr);

  return 0;
}