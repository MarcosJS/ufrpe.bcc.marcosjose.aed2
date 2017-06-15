#include "arvoreRN.h"

//Função que cria um nó da arvore rubro Negra
no * nonoNo(int valor) {
	no * novo = (no*) malloc(siseof(no));
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
	
	return rotacaoSimplesEsq(noAtual->dir);
	
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


