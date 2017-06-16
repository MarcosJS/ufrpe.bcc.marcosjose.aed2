#include "arvoreRN.h"

//Função que cria um nó da arvore rubro Negra
no * alocarNo(int valor) {
	no * novo = (no*) malloc(sizeof(no));
	novo->chave = valor;
	novo->cor = 0;//Todo nó a ser inserido é vermelho
	novo->pai = NULL;
	novo->esq = NULL;
	novo->dir = NULL;

	return novo;
}

//Função que cria uma estrutura que contém uma arvore rubro negra
arvoreRN * alocarArvore() {
	arvoreRN *arv = (arvoreRN*) malloc(sizeof(arvoreRN));
	arv->raiz = NULL;
	
	return arv;
}

/*Retorna o novo nó atual para reparação que sobe até a raiz*/
no * rotacaoSimplesEsq(no * noAtual) {
	
	noAtual->pai->pai->esq = noAtual->pai->dir;
	noAtual->pai->dir = noAtual->pai->pai;
	noAtual->pai->pai = noAtual->pai->pai->pai;
	noAtual->pai->dir->pai = noAtual->pai;
	noAtual->pai->cor = 1;
	noAtual->pai->dir->cor = 0;
	
	return noAtual->pai;
}

/*Retorna o resultado da chamada recursiva*/
no * rotacaoDuplaDir(no * noAtual) {
	
	noAtual->pai->dir = noAtual->esq;
	noAtual->esq = noAtual->pai;
	noAtual->pai = noAtual->esq->pai;
	noAtual->esq->pai = noAtual;
	
	return rotacaoSimplesEsq(noAtual->esq);
	
}

/*Retorna o novo nó atual para reparação que sobe até a raiz(ROTAÇÃO INVERSA)*/
no * rotacaoSimplesDir(no * noAtual) {
	
	noAtual->pai->pai->dir = noAtual->pai->esq;
	noAtual->pai->esq = noAtual->pai->pai;
	noAtual->pai->pai = noAtual->pai->pai->pai;
	noAtual->pai->esq->pai = noAtual->pai;
	noAtual->pai->cor = 1;
	noAtual->pai->esq->cor = 0;
	
	return noAtual->pai;
}

/*Retorna o resultado da chamada recursiva (ROTAÇÃO INVERSA)*/
no * rotacaoDuplaEsq(no * noAtual) {
	
	noAtual->pai->esq = noAtual->dir;
	noAtual->dir = noAtual->pai;
	noAtual->pai = noAtual->dir->pai;
	noAtual->dir->pai = noAtual;
	
	return rotacaoSimplesDir(noAtual->esq);
	
}
void reparacaoArvoreRN(no * noAtual) {
	
	/*Avaliando se o novo nó é raiz para mudar a cor do nó*/
	if(noAtual->pai == NULL) {
		noAtual->cor = 1;

	} else if(noAtual->cor == 0) {//O nó atual possui um pai e é vermelho

		if(noAtual->pai->cor == 0) {
		
			/*CASO 1: Pai e tio ambos são vermelhos)*/
			if(noAtual->pai->pai->esq->cor == noAtual->pai->pai->dir->cor) {
				noAtual->pai->pai->cor =  0;
				noAtual->pai->pai->esq->cor = 1;
				noAtual->pai->pai->dir->cor = 1;
				resultado = noAtual->pai->pai;
				
			/*Caso o no atual seja filho esquerdo*/	
			} else if(noAtual->pai->pai->esq == noAtual->pai) {
				
				/*CASO 2: Nó vermelho do mesmo lado do tio que é preto e filho direito*/
				if(noAtual->pai->dir == noAtual) {
					/*ROTACAO DUPLA AQUI!!!!!*/
					resultado = rotacaoDuplaDir(noAtual);
					
				/*CASO 3: Nó vermelho do lado oposto do tipo que é preto e filho direito*/
				} else {
					/*ROTACAO SIMPLES AQUI!!!!!*/
					resultado = rotacaoSimplesEsq(noAtual);
				}
				
			/*Caso o no atual seja filho direito*/
			} else {
				
				/*CASO 2: Nó vermelho do mesmo lado do tio que é preto e filho esquerdo*/
				if(noAtual->pai->esq == noAtual) {
					/*ROTACAO DUPLA NO AQUI!!!!!*/
					resultado = rotacaoDuplaEsq(noAtual);
					
				/*CASO 3: Nó vermelho do lado oposto do tio que é preto e filho esquerdo*/
				} else {
					/*ROTACAO SIMPLES AQUI!!!!!*/
					resultado = rotacaoSimplesDir(noAtual);

				}
				
			}
		}
		/*Chamada recursiva caso não seja raiz*/
		reparacaoArvoreRN(resultado);
	}

}

//Função que insere um novo nó na arvore rubro negra
void inserirNo(no * novoNo, no * raizArvore) {
	
	/*Raiz da arvore ou folha*/
	if(raizArvore == NULL) {
		raizArvore = novoNo;
		
		/*Reparacao da arvore apos a inserção*/
		reparacaoArvoreRN(raizArvore);

	/*Caso chave seja menor que chave do nó atual desco pelo filho esquerdo*/
	}else if(novoNo->chave < raizArvore->chave) {
		inserirNo(novoNo, raizArvore->esq);

	/*Caso chave seja maior ou igual que chave do nó atual desco pelo filho direito*/
	} else {
		inserirNo(novoNo, raizArvore->dir);
	}

}

/*Retorna um nó contendo o maior elemento da arvore*/
no * maiorElemento(no * raizArvore) {
	no * maior;
	if(raizArvore->dir == NULL) {
		maior = raizArvore;
	} else {
		maior = maiorElemento(raizArvore->dir);
	}
	
	return maior;
}

/*Retorna um nó contendo o menor elemento da arvore*/
no * menorElemento(no * raizArvore) {
	no * menor;
	if(raizArvore->esq == NULL) {
		menor = raizArvore;
		return menor;
	} else {
		menor = menorElemento(raizArvore->esq);
	}
}

/*Retorna um nó contendo o elemento passado nos parametros, se houver*/
no * BuscarElemento(no * raizArvore, int valor) {
	no * resultado = NULL;	
	if(raizArvore->chave == valor) {
		resultado = raizArvore;
	} else if(valor < raizArvore->chave) {
		resultado =  buscarElemento(raizArvore->esq, valor);
	} else {
		resultado = buscarElemento(raizArvore->dir, valor);
	}
	return resultado;
}

/*Retorna o sucessor na arvore de um elemento dado que exista na arvore*/
no * sucessor(no * x) {
	if(x->dir != NULL) {
		return menorElemento(x->dir);
	} else {
		while(x->pai != NULL) {
			if(x == x->pai->esq) {			
				return x->pai;
			}
			x = x->pai;
		}
	}
	return NULL;
}

/*Retorna o antecessor na arvore de um elemento dado que exista na arvore*/
no * antecessor(no * x) {
	if(x->esq != NULL) {
		return maiorElemento(x->esq);
	} else {
		while(x->pai != NULL) {
			if(x == x->pai->dir) {			
				return x->pai;
			} 
			x = x->pai;
		}
	}
	return NULL;
}

/*Carrega um arvore apartir de um arquivo*/
void carregarArvore(arvoreRN * arv, char * nomeArq) {
	FILE *arquivo;
	arquivo = fopen(nomeArq, "r");
	char linha[10];
	int valor;
	while(fgets(linha, 10, arquivo) != NULL) {
		valor = atoi(linha);
		no * novoNo;
		novoNo = alocarNo(valor);
		arv->raiz = inserirNo(novoNo, arv->raiz);
	}
	fclose(arquivo);
}

/*Imprimi a representação de uma arvore em um arquivo*/
void imprimirArvoreArq(no * raizArvore, char * nomeArq) {
	FILE *arquivo;
	if(noRaiz != NULL) {
		arquivo = fopen(nomeArq, "a");
		fprintf(arquivo, "( ");
		fprintf(arquivo, "%d", raizArvore->chave);
		if(raizArvore->cor == 0) {
			fprintf(arquivo, "R");
		} else {
			fprintf(arquivo, "P");
		}
		fclose(arquivo);
		imprimirArvoreArq(raizArvore->esq, nomeArq);
		imprimirArvoreArq(raizArvore->dir, nomeArq);
		arquivo = fopen(nomeArq, "a");
		fprintf(arquivo, ")");
		fclose(arquivo);
	}
}

/*Libera a memoria utilizada para armazenar a arvore*/
void apagarArvore(raizArvore) {
	if(raizArvore != NULL) {
		apagarArvore(raizArvore->esq);
		apagarArvore(raizArvore->dir);
		free(raizArvore);
		raizArvore = NULL;
	}
}
