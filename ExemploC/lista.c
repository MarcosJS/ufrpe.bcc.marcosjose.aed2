#include "lista.h"

void adicionar(lista* l, no* n)
{
	n->prox = l->inicio;
	l->inicio = n;
}

void apagar(lista* l)
{
	no* aux1 = l->inicio;
	no* aux2;
	while(aux1 != NULL)
	{
		aux2 = aux1->prox;
		free(aux1);
		aux1 = aux2;
	}
}

void print(lista* l)
{
	no* aux = l->inicio;
	while(aux != NULL)
	{
		printf("%d ", aux->valor);
		aux = aux->prox;
	}
}

no* alocaNo(int v)
{
	no* novo = (no*) malloc(sizeof(no));
	novo->valor = v;
	novo->prox = NULL;
	return novo;
}
