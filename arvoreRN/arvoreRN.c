#include "arvoreRN.h"

//Função que cria um nó da arvore rubro Negra
no * alocarNo(int valor) {
	no * novo = (no*) malloc(sizeof(no));
	novo->chave = valor;
	novo->cor = VERMELHO;//Todo nó a ser inserido é vermelho
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
	printf("\t\t\t@@@ Entrou na rotacao simples dir\n");
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
	noAtual->cor = PRETO;
	noAtual->dir->cor = VERMELHO;
	return noAtual;
}

/*Retorna o resultado da chamada recursiva*/
no * rotacaoDuplaDir(no * noAtual) {
	printf("\t\t\t@@@ Entrou na rotacao dupla dir\n");
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
	printf("\t\t\t@@@ Entrou na rotacao simples esq\n");
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
	noAtual->cor = PRETO;
	noAtual->esq->cor = VERMELHO;
	return noAtual;
}

/*Retorna o resultado da chamada recursiva (ROTAÇÃO INVERSA)*/
no * rotacaoDuplaEsq(no * noAtual) {
	printf("\t\t\t@@@ Entrou na rotacao dupla esq\n");
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
	printf("\tREPARACAO-> valor no atual: %d cor no atual: %d\n", noAtual->chave, noAtual->cor);
	if(noAtual->pai != NULL) {
		printf("\t valor do pai: %d\n", noAtual->pai->chave);
	}
	/*Avaliando se o novo nó é raiz para mudar a cor do nó*/
	if(noAtual->pai == NULL) {
		noAtual->cor = PRETO;
		resultado = noAtual;
		printf("\tcor da raiz %d alterada para %d\n", resultado->chave, resultado->cor);
		
	} else if(noAtual->cor == PRETO) {
		printf("\t---->o que esta em repacao é preto\n");
		resultado = reparacaoArvoreRN(noAtual->pai);
	} else  /*{*/
		//printf("!!!!!confirmou ele o no atual tbm é vermelho\n");
		if((noAtual->dir != NULL && noAtual->dir->cor == VERMELHO) || (noAtual->esq != NULL && noAtual->esq->cor == VERMELHO)) {
			printf("\t!!!!!confirmou se uns dos filhos sao vermelhos\n");
			/*CASO 1: Pai e tio ambos são vermelhos)*/
			if(((noAtual->pai->esq != NULL) && (noAtual->pai->dir != NULL)) && (noAtual->pai->esq->cor == noAtual->pai->dir->cor)) {
				printf("\tpassou pela comparacao de pai e tio nulos\n");
				//printf("\t valor do pai: %d\nvalor do filho esquerdo do pai: %d\nvalor do filho direito do pai: %d\n", noAtual->pai->chave, noAtual->pai->esq->chave, noAtual->pai->dir->chave);
				//printf("\t ponteiro no atual: %p\nponteiro esquerdo do pai: %p\nponteiro direito do pai: %p\n", noAtual, noAtual->pai->esq, noAtual->pai->dir);
				if(noAtual->pai->esq->cor == noAtual->pai->dir->cor) {
					printf("\tIDENTIFICOU O CASO 1\n");
					noAtual->pai->cor =  VERMELHO;
					noAtual->pai->esq->cor = PRETO;
					noAtual->pai->dir->cor = PRETO;
					printf("\t!!!!!passou pela troca de cores entre tios\n");
					resultado = reparacaoArvoreRN(noAtual->pai);
				}
				
			/*Caso o no atual seja filho esquerdo*/	
			} else if(noAtual->pai->esq == noAtual) {
				printf("\tNo atual e filho esquerdo\n");
				/*CASO 2: Nó vermelho do mesmo lado do tio que é preto e filho direito*/
				if((noAtual->dir != NULL) && (noAtual->dir->cor == VERMELHO)) {
					resultado = rotacaoDuplaDir(noAtual);
					if(resultado->pai != NULL) {
						resultado = reparacaoArvoreRN(resultado->pai);
					}
				} else if((noAtual->esq != NULL) && (noAtual->esq->cor == VERMELHO)){
					/*ROTACAO SIMPLES AQUI!!!!!*/
					resultado = rotacaoSimplesDir(noAtual);
					if(resultado->pai != NULL) {
						resultado = reparacaoArvoreRN(resultado->pai);
					}
				} else {
					printf("\t138- Não é nenhum dos filhos\n");
				}
				
			/*Caso o no atual seja filho direito*/
			} else if(noAtual->pai->dir == noAtual) {
				printf("\tNo atual e filho direito\n");
				/*CASO 2: Nó vermelho do mesmo lado do tio que é preto e filho esquerdo*/
				if((noAtual->esq != NULL) && (noAtual->esq->cor == VERMELHO)) {
					/*ROTACAO DUPLA NO AQUI!!!!!*/
					resultado = rotacaoDuplaEsq(noAtual);
					if(resultado->pai != NULL) {
						resultado = reparacaoArvoreRN(resultado->pai);
					}
				/*CASO 3: Nó vermelho do lado oposto do tio que é preto e filho esquerdo*/
				} else if((noAtual->dir != NULL) && (noAtual->dir->cor == VERMELHO)){
					/*ROTACAO SIMPLES AQUI!!!!!*/
					resultado = rotacaoSimplesEsq(noAtual);
					if(resultado->pai != NULL) {
						resultado = reparacaoArvoreRN(resultado->pai);
					}
				} else {
					printf("\t159- Não é nenhum dos filhos\n");
				}
				
			} else {
				printf("\tNão é nenhum dos filhos do pai\n");
			}
		} else {
			resultado = reparacaoArvoreRN(noAtual->pai);
		}
	//} 
	return resultado;
}

//Função que insere um novo nó na arvore rubro negra
no * inserirNo(no * novoNo, no * raizArvore/*, no * pai*/) {
	printf(">>>inserindo um novo no: %d\n", novoNo->chave);
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
			resultado = inserirNo(novoNo, raizArvore->esq/*, raizArvore*/);
		}		

	/*Caso chave seja maior ou igual que chave do nó atual desco pelo filho direito*/
	} else {
		if(raizArvore->dir == NULL) {
			raizArvore->dir = novoNo;
			novoNo->pai = raizArvore;
			resultado = reparacaoArvoreRN(raizArvore);
		} else {
			resultado = inserirNo(novoNo, raizArvore->dir/*, raizArvore*/);
		}
	}
	return resultado;
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
	} else {
		menor = menorElemento(raizArvore->esq);
	}
	return menor;
}

/*Retorna um nó contendo o elemento passado nos parametros, se houver*/
no * buscarElemento(no * raizArvore, int valor) {
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
		//printf("valor alocado no nó: %d\n", novoNo->chave);
		arv->raiz = inserirNo(novoNo, arv->raiz/*, NULL*/);
		printf("nova raiz apos no inserido: %d\n", arv->raiz->chave);
	}
	printf("linha 237:-----Raiz: %d cor: %d\n", arv->raiz->chave, arv->raiz->cor);
	printf("linha 238:-----filho direito: %d\n", arv->raiz->dir->chave);
	printf("linha 239:-----filho esquerdo: %d\n", arv->raiz->esq->chave);
	fclose(arquivo);
}

/*Imprimi a representação de uma arvore em um arquivo*/
void imprimirArvoreArq(no * raizArvore, char * nomeArq) {
	FILE *arquivo;
	if(raizArvore != NULL) {
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
void apagarArvore(no * raizArvore) {
	if(raizArvore != NULL) {
		apagarArvore(raizArvore->esq);
		apagarArvore(raizArvore->dir);
		free(raizArvore);
		raizArvore = NULL;
	}
}
