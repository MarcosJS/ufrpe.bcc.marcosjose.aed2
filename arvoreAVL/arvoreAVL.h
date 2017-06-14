#ifndef __ARVOREAVL_H__
#define __ARVOREAVL_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct No {
	int chave;
	int altura; 
	struct No *pai;
	struct No *esq;
	struct No *dir;
} no;

typedef struct ArvoreAVL{ 
	no *raiz;
} arvoreAVL;

int maior(int x, int y);
int alturaNo(no * no);
no * alocarNo(int valor);
arvoreAVL * alocarArvore();
int contarArvore(no * noRaiz);
no * rotacaoDireta(no * noRaiz);
no * rotacaoEsquerda(no * noRaiz);
no * rotacaoDuplaDireita(no * noRAiz);
no * rotacaoDuplaEsquerda(no * noRAiz);
no * inserirNo(no *novoNo, no *raizAvore, no * pai);
no * maiorElemento(no * noRaiz);
no * menorElemento(no * noRaiz);
no * buscarElemento(no * noRaiz, int valor);
no * sucessor(no * noRaiz);
no * antecessor(no * noRaiz);
void carregarArvore(arvoreAVL * arv, char *arquivo);
void imprimirArvore(no * noRaiz);
void imprimirArvoreArq(no * noRaiz, char *arquivo);
void apagarArvore(no * noRaiz);

#endif // __ARVOREAVL_H__
