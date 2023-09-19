#include "Ponto.h"
#include "Ponto.c"
#include <stdio.h>
int main(void){
		float d;
		Ponto *p1 = criar(0, 0);
		Ponto *p2 = criar(4.5, 4.5);
		
		d = distancia(p1, p2);
		printf("distancia entre pontos: %f\n", d);
		
		alterar(p1, 1.5, 1.5);
		
		return 0;
}
