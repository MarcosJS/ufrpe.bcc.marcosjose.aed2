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

/*Retorna o novo nó atual no memsmo nível do anterior*/
no * rotacaoSimpleEsq(no * noAtual) {
	
	noAtual->pai->esq = noAtual->dir;
	noAtual->dir = noAtual->dir->esq;
	pai->esq->esq = noAtual;
	
	return noAtual->pai;
}

no * rotacaoDuplaDir(no * noAtual) {
	
	
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
			} else if(noAtual->pai->dir = noAtual) {
				
				/*CASO 2: Filho (nó inserido) do mesmo lado do irmão que é preto*/
				if(noAtual->dir = noInserido) {
					/*ROTACAO DUPLA NO NÓ ATUAL AQUI!!!!!*/
				/*CASO 3: Filho (nó inserido) do lado oposto do irmão que é preto*/
				} else {
					/*ROTACAO SIMPLES NO PAI ATUAL AQUI!!!!!*/
				}
				
			/*Caso o no atual seja filho direito*/
			} else {
				
				/*CASO 2: Filho (nó inserido) do mesmo lado do irmão que é preto*/
				if(noAtual->esq = noInserido) {
				
					/*ROTACAO DUPLA NO NÓ ATUAL AQUI!!!!!*/
					
				/*CASO 3: Filho (nó inserido) do lado oposto do irmão que é preto*/
				} else {
				
					/*ROTACAO SIMPLES NO PAI ATUAL AQUI!!!!!*/

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


