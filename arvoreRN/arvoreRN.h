#ifndef __ARVORERN_H__
#define __ARVORERN_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NEGRO 1
#define RUBRO 0

//As core serão representas pelos inteiro 0 para vermelho e 1 para preto na variavel cor
typedef struct No {
	int chave;
	int cor; 
	struct No *pai;
	struct No *esq;
	struct No *dir;
} no;

//Estrutura que armazena a arvore
typedef struct ArvoreRN{ 
	no *raiz;
} arvoreRN;

no * alocarNo(int valor);
arvoreRN * alocarArvore();
no * rotacaoSimplesEsq(no * noAtual);
no * rotacaoDuplaDir(no * noAtual);
no * rotacaoSimplesDir(no * noAtual);
no * rotacaoDuplaEsq(no * noAtual);
no * reparacaoArvoreRN(no * noAtual);
no * inserirNo(no * novoNo, no * raizArvore);
no * maiorElemento(no * raizArvore);
no * menorElemento(no * raizArvore);
no * buscarElemento(no * raizArvore, int valor);
no * sucessor(no * x);
no * antecessor(no * x);
void carregarArvore(arvoreRN * arv, char * nomeArq);
void imprimirArvoreArq(no * raizArvore, char * nomeArq);
void apagarNo(no * raizArvore);
void apagarArvore(arvoreRN * arv);

#endif
