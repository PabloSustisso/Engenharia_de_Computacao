#include<stdio.h>
#include "fila.h"

int main(){

   Fila *f = criar_fila();
   
   enfileirar(f,10);
	 enfileirar(f,15);
	 enfileirar(f,20);
	 enfileirar(f,25);
	 enfileirar(f,5);
	 enfileirar(f,18);
	 enfileirar(f,9);
	 enfileirar(f,30);

	 imprimir_fila(f);
	 
	 printf("Desenfileirado: %d\n",desenfileirar(f));
	 printf("Desenfileirado: %d\n",desenfileirar(f));
	 printf("Desenfileirado: %d\n",desenfileirar(f));
	 enfileirar(f,19);
     enfileirar(f,33);
     enfileirar(f,55);
     enfileirar(f,56);
     printf("Desenfileirado: %d\n",desenfileirar(f));
	 imprimir_fila(f);	 	
		   
   liberar_fila(f);;
   
   
   return 0;
}
