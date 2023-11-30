#include "lista.h"
#include "lista.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
  int i;

  Lista* L1 = criar_lista();
  Lista* L2 = criar_lista();
  
	for(i=25;i>=1;i--)
	   if(inserir(L1, i))
	     printf("Chave %d inserida!\n",i);
	  else   
	     printf("Falha ao inserir chave %d!\n",i);
	for(i=50;i>=26;i--)  
		if(inserir(L2, i))
	     printf("Chave %d inserida!\n",i);
     else   
	     printf("Falha ao inserir chave %d!\n",i);

	printf("\n");   
	imprimir_lista(L1);
	printf("\n");
	imprimir_lista(L2);  
	printf("\n"); 
	
	Lista* L3 = concatenar(L1, L2);
	imprimir_lista(L3);
	printf("\n");
	
	Lista* L4 = intercalar_ordenado(L1, L2);
	imprimir_lista(L4);
  
	return 0;
}
