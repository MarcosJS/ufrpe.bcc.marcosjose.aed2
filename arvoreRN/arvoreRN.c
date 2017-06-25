#include "arvoreRN.h"

//Função que cria um nó da arvore rubro Negra
no * alocarNo(int valor) {
	no * novo = (no*) malloc(sizeof(no));
	novo->chave = valor;
	novo->cor = RUBRO;//Todo nó a ser inserido é RUBRO
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
no * rotacaoSimplesDir(no * noAtual) {
	noAtual->pai->esq = noAtual->dir;
	if(noAtual->dir != NULL) {
		noAtual->dir->pai = noAtual->pai;
	}
	noAtual->dir = noAtual->pai;
	noAtual->pai = noAtual->pai->pai;
	if(noAtual->pai != NULL) {
		if((noAtual->pai->esq != NULL) && (noAtual->pai->esq == noAtual->dir)) {
			noAtual->pai->esq = noAtual;
		} else {
			noAtual->pai->dir = noAtual;
		}
	}
	noAtual->dir->pai = noAtual;
	noAtual->cor = NEGRO;
	noAtual->dir->cor = RUBRO;
	return noAtual;
}

/*Retorna o resultado da chamada recursiva*/
no * rotacaoDuplaDir(no * noAtual) {
	noAtual->dir->pai = noAtual->pai;
	noAtual->pai->esq = noAtual->dir;
	noAtual->dir = noAtual->pai->esq->esq;
	if(noAtual->dir != NULL) {
		noAtual->dir->pai = noAtual;
	}
	noAtual->pai = noAtual->pai->esq;
	noAtual->pai->esq = noAtual;
	return rotacaoSimplesDir(noAtual->pai);
}

/*Retorna o novo nó atual para reparação que sobe até a raiz(ROTAÇÃO INVERSA)*/
no * rotacaoSimplesEsq(no * noAtual) {
	noAtual->pai->dir = noAtual->esq;
	if(noAtual->esq != NULL) {
		noAtual->esq->pai = noAtual->pai;
	}
	noAtual->esq = noAtual->pai;
	noAtual->pai = noAtual->pai->pai;
	if(noAtual->pai != NULL) {
		if((noAtual->pai->dir != NULL) && (noAtual->pai->dir == noAtual->esq)) {
			noAtual->pai->dir = noAtual;
		} else {
			noAtual->pai->esq = noAtual;
		}
	}
	noAtual->esq->pai = noAtual;
	noAtual->cor = NEGRO;
	noAtual->esq->cor = RUBRO;
	return noAtual;
}

/*Retorna o resultado da chamada recursiva (ROTAÇÃO INVERSA)*/
no * rotacaoDuplaEsq(no * noAtual) {
	noAtual->esq->pai = noAtual->pai;
	noAtual->pai->dir = noAtual->esq;
	noAtual->esq = noAtual->pai->dir->dir;
	if(noAtual->esq != NULL) {
		noAtual->esq->pai = noAtual;
	}
	noAtual->pai = noAtual->pai->dir;
	noAtual->pai->dir = noAtual;
	return rotacaoSimplesEsq(noAtual->pai);
}

no * reparacaoArvoreRN(no * noAtual) {
	no * resultado = NULL;
	/*Avaliando se o novo nó é raiz para mudar a cor do nó*/
	if(noAtual->pai == NULL) {
		noAtual->cor = NEGRO;
		resultado = noAtual;
	} else if(noAtual->cor == NEGRO) {
		resultado = reparacaoArvoreRN(noAtual->pai);
	} else  /*{*/
		//printf("!!!!!confirmou ele o no atual tbm é RUBRO\n");
		if((noAtual->dir != NULL && noAtual->dir->cor == RUBRO) || (noAtual->esq != NULL && noAtual->esq->cor == RUBRO)) {
			/*CASO 1: Pai e tio ambos são RUBROs)*/
			if(((noAtual->pai->esq != NULL) && (noAtual->pai->dir != NULL)) && (noAtual->pai->esq->cor == noAtual->pai->dir->cor)) {
				if(noAtual->pai->esq->cor == noAtual->pai->dir->cor) {
					noAtual->pai->cor =  RUBRO;
					noAtual->pai->esq->cor = NEGRO;
					noAtual->pai->dir->cor = NEGRO;
					resultado = reparacaoArvoreRN(noAtual->pai);
				}
				
			/*Caso o no atual seja filho esquerdo*/	
			} else if(noAtual->pai->esq == noAtual) {
				/*CASO 2: Nó RUBRO do mesmo lado do tio que é NEGRO e filho direito*/
				if((noAtual->dir != NULL) && (noAtual->dir->cor == RUBRO)) {
					resultado = rotacaoDuplaDir(noAtual);
					if(resultado->pai != NULL) {
						resultado = reparacaoArvoreRN(resultado->pai);
					}
				} else if((noAtual->esq != NULL) && (noAtual->esq->cor == RUBRO)){
					/*ROTACAO SIMPLES AQUI!!!!!*/
					resultado = rotacaoSimplesDir(noAtual);
					if(resultado->pai != NULL) {
						resultado = reparacaoArvoreRN(resultado->pai);
					}
				}
				
			/*Caso o no atual seja filho direito*/
			} else if(noAtual->pai->dir == noAtual) {
				/*CASO 2: Nó RUBRO do mesmo lado do tio que é NEGRO e filho esquerdo*/
				if((noAtual->esq != NULL) && (noAtual->esq->cor == RUBRO)) {
					/*ROTACAO DUPLA NO AQUI!!!!!*/
					resultado = rotacaoDuplaEsq(noAtual);
					if(resultado->pai != NULL) {
						resultado = reparacaoArvoreRN(resultado->pai);
					}
				/*CASO 3: Nó RUBRO do lado oposto do tio que é NEGRO e filho esquerdo*/
				} else if((noAtual->dir != NULL) && (noAtual->dir->cor == RUBRO)){
					/*ROTACAO SIMPLES AQUI!!!!!*/
					resultado = rotacaoSimplesEsq(noAtual);
					if(resultado->pai != NULL) {
						resultado = reparacaoArvoreRN(resultado->pai);
					}
				}
			} 
		} else {
			resultado = reparacaoArvoreRN(noAtual->pai);
		}
	//} 
	return resultado;
}

//Função que insere um novo nó na arvore rubro negra
no * inserirNo(no * novoNo, no * raizArvore/*, no * pai*/) {
	no * resultado;
	
	/*Raiz da arvore ou folha*/
	if(raizArvore == NULL) {
		resultado = reparacaoArvoreRN(novoNo);
		
	/*Caso chave seja menor que chave do nó atual desco pelo filho esquerdo*/
	}else if(novoNo->chave < raizArvore->chave) {
		if(raizArvore->esq == NULL) {
			raizArvore->esq = novoNo;
			novoNo->pai = raizArvore;
			resultado = reparacaoArvoreRN(raizArvore);
		} else {
			resultado = inserirNo(novoNo, raizArvore->esq);
		}		

	/*Caso chave seja maior ou igual que chave do nó atual desco pelo filho direito*/
	} else {
		if(raizArvore->dir == NULL) {
			raizArvore->dir = novoNo;
			novoNo->pai = raizArvore;
			resultado = reparacaoArvoreRN(raizArvore);
		} else {
			resultado = inserirNo(novoNo, raizArvore->dir);
		}
	}
	return resultado;
}

/*Retorna um nó contendo o maior elemento da arvore*/
no * maiorElemento(no * raizArvore) {
	no * maior = NULL;
	if(raizArvore != NULL) {
		if(raizArvore->dir == NULL) {
			maior = raizArvore;
		} else {
			maior = maiorElemento(raizArvore->dir);
		}
	}
	return maior;
}

/*Retorna um nó contendo o menor elemento da arvore*/
no * menorElemento(no * raizArvore) {
	no * menor = NULL;
	if(raizArvore != NULL) {
		if(raizArvore->esq == NULL) {
			menor = raizArvore;
		} else {
			menor = menorElemento(raizArvore->esq);
		}
	}
	return menor;
}

/*Retorna um nó contendo o elemento passado nos parametros, se houver*/
no * buscarElemento(no * raizArvore, int valor) {
	no * resultado = NULL;
	if(raizArvore != NULL) {	
		if(raizArvore->chave == valor) {
			resultado = raizArvore;
		} else if(valor < raizArvore->chave) {
			resultado =  buscarElemento(raizArvore->esq, valor);
		} else {
			resultado = buscarElemento(raizArvore->dir, valor);
		}
	}
	return resultado;
}

/*Retorna o sucessor na arvore de um elemento dado que exista na arvore*/
no * sucessor(no * x) {
	if(x != NULL) {
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
	}
	return NULL;
}

/*Retorna o antecessor na arvore de um elemento dado que exista na arvore*/
no * antecessor(no * x) {
	if(x != NULL) {
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
	if(raizArvore != NULL) {
		arquivo = fopen(nomeArq, "a");
		fprintf(arquivo, " (");
		fprintf(arquivo, "%d", raizArvore->chave);
		if(raizArvore->cor == 0) {
			fprintf(arquivo, "R");
		} else {
			fprintf(arquivo, "N");
		}
		fclose(arquivo);
		imprimirArvoreArq(raizArvore->esq, nomeArq);
		imprimirArvoreArq(raizArvore->dir, nomeArq);
		arquivo = fopen(nomeArq, "a");
		fprintf(arquivo, ")");
		fclose(arquivo);
	}
}

/*Libera a memoria utilizada para armazenar um no*/
void apagarNo(no * raizArvore) {
	if(raizArvore != NULL) {
		apagarNo(raizArvore->esq);
		apagarNo(raizArvore->dir);
		free(raizArvore);
		raizArvore = NULL;
	}
}

/*Libera a memoria utilizada para armazenar uma arvore*/
void apagarArvore(arvoreRN * arv) {
	apagarNo(arv->raiz);
	if(arv->raiz != NULL) {
		free(arv);
	}
}
