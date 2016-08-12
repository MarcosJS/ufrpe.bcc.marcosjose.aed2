#ifndef __LISTA_H__
#define __LISTA_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct no no;
typedef struct lista lista;

struct no
{
	int valor;
	no* prox;
};


struct lista
{
	no* inicio;
};


void adicionar(lista* l, no* n);
void apagar(lista* l);
void print(lista* l);

no* alocaNo(int v);

#endif // __LISTA_H__
