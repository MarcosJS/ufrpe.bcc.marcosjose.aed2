#ifndef __ARVORERN_H__
#define __ARVORERN_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

#endif
