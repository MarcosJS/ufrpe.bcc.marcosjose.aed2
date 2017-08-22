#ifndef __ARGUMENTO_H__
#define __ARGUMENTO_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 1000

typedef struct Opcoes {
	char opcao[MAX];
	char * argumento[MAX];
	int qOpcao;
	int qArgumento;
	char flag;
	int posicao;
	int posicaoEntrada;
} opcoes;

opcoes leArgumentos(int argc, char * argv[]);

#endif // __ARGUMENTO_H__
