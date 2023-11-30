/* Ponto.c */
#include "Ponto.h"
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

struct ponto {
	float x, y;
};

Ponto* criar(float x, float y){
	Ponto *p = (Ponto*) malloc(sizeof(Ponto));
	p->x = x;
	p->y = y;
	return p;
}
int acessar(Ponto *p, float *x, float *y){
	if (p == NULL)
		return 0;
	*x = p->x;
	*y = p->y;
	return 1;
}
int alterar(Ponto *p, float x, float y){
	if (p == NULL)
		return 0;
	p->x = x;
	p->y = y;
	return 1;
}
float ponto_x(Ponto *p){
	if (p != NULL)
		return p->x;
	return 0;
}
float ponto_y(Ponto *p){
	if (p != NULL)
		return p->y;
	return 0;
}
void imprimir_ponto(Ponto *p){
	if (p != NULL)
		printf("X: %f Y: %f\n", p->x, p->y);
}
float distancia(Ponto *p1, Ponto *p2){
	if ((p1 == NULL) || (p2 == NULL))
		return -1;
	float dx = p1->x - p2->x;
	float dy = p1->y - p2->y;
	return sqrt(dx * dx + dy * dy);
}
