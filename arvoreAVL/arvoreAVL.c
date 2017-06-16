#include "arvoreAVL.h"

int maior(int x, int y) {
	int resultado;
	if(x > y) {
		resultado = x;
	} else {
		resultado = y;
	}
	return resultado;
}

int alturaNo(no * no) {//Esta função trata os casos em que o nó é 'NULL'.
	int altura;
	if(no == NULL) {
		altura = -1;
	} else {
		altura = no->altura;
	}
	return altura;
}

int calcularAltura(no * no) {//Esta função trata os casos em que um ponteiro é comparado com 'NULL'.
	int novaAltura;
	if((no->esq != NULL) && (no->dir != NULL)) {
		novaAltura = maior(no->esq->altura, no->dir->altura) + 1;
	} else if((no->esq == NULL) && (no->dir == NULL)) {
		novaAltura = 0;
	} else {
		if((no->esq == NULL)) {
			novaAltura = no->dir->altura + 1;
		} else {
			novaAltura = no->esq->altura + 1;
		}
	}
	return novaAltura;
}

no * alocarNo(int valor) {
	no* novo = (no*) malloc(sizeof(no));
	novo->chave = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->pai = NULL;
	novo->altura = 0;

	return novo;
}

arvoreAVL * alocarArvore() {
	arvoreAVL *arv1 = (arvoreAVL*) malloc(sizeof(arvoreAVL));
	return arv1;
}

/* Na rotação a direita a raiz torna-se filho direito de seu filho esquerdo e recebe o 
** filho direito de seu filho esquerdo.*/
no * rotacaoDireita(no * noRaiz) {
	no * novaRaiz;

	novaRaiz = noRaiz->esq;//Guarda-se o membro que irá tomar o lugar da raiz.
	novaRaiz->pai = noRaiz->pai;//Aponta para o pai da antiga raiz
	noRaiz->esq = novaRaiz->dir;
	if(noRaiz->esq != NULL) {
		noRaiz->esq->pai = noRaiz;//Aponta para antiga raiz como pai
	}
	novaRaiz->dir = noRaiz;
	noRaiz->pai = novaRaiz;//Aponta para novaRaiz como pai
	
	noRaiz->altura = calcularAltura(noRaiz);//A altura no antigo nó é atualizada.
	novaRaiz->altura = calcularAltura(novaRaiz);//A altura no novo nó é atualizada.

	return novaRaiz;
	
}

/* Na rotação a esquerda a raiz torna-se filho esquerdo de seu filho direito e recebe o 
** filho esquerdo de seu filho direito.*/
no * rotacaoEsquerda(no * noRaiz) {
	no * novaRaiz;

	novaRaiz = noRaiz->dir;
	novaRaiz->pai = noRaiz->pai;
	noRaiz->dir = novaRaiz->esq;
	if(noRaiz->dir != NULL) {
		noRaiz->dir->pai = noRaiz;
	}
	novaRaiz->esq = noRaiz;
	noRaiz->pai = novaRaiz;

	noRaiz->altura = calcularAltura(noRaiz);
	novaRaiz->altura = calcularAltura(novaRaiz);

	return novaRaiz;
	
}

no * rotacaoDuplaDireita(no * noRaiz) {
	noRaiz->esq = rotacaoEsquerda(noRaiz->esq);
	return rotacaoDireita(noRaiz);
}

no * rotacaoDuplaEsquerda(no * noRaiz) {
	noRaiz->dir = rotacaoDireita(noRaiz->dir);
	return rotacaoEsquerda(noRaiz);
}

/* Obs.:A raiz deve sempre ser passada na primeira chamada com o pai igual a null!*/
no * inserirNo(no  * novoNo, no * raizArvore, no * pai) {
	
	if(raizArvore == NULL) {//Folha da arvore
		raizArvore = novoNo;
		raizArvore->pai = pai;
		
		//return raizArvore;
	} else {
		
		if(novoNo->chave < raizArvore->chave) {//Aqui aplica-se a recursividade se valor menor.
			raizArvore->esq = inserirNo(novoNo, raizArvore->esq, raizArvore);
			raizArvore->altura = calcularAltura(raizArvore);

			/* Avaliando o balanceamento do nó. Se estiver desbalanceada na sub-arvore 
			** esquerda o valor será igual a 2*/
			if((alturaNo(raizArvore->esq) - alturaNo(raizArvore->dir)) == 2) {
				if(raizArvore->esq->esq != NULL){//Último nó que gera desbalanceamento na direção da sub-arvore.
					raizArvore = rotacaoDireita(raizArvore);
				} else {//Último nó que gera desbalanceamento está na direção contrária à da sub-arvore.
					raizArvore = rotacaoDuplaDireita(raizArvore);
				}
			}
 
		} else {//Aqui aplica-se a recursividade se valor maior.
			raizArvore->dir = inserirNo(novoNo, raizArvore->dir, raizArvore);
			raizArvore->altura = calcularAltura(raizArvore);

			/* Avaliando o balanceamento do nó. Se estiver desbalanceada na sub-arvore 
			** esquerda o valor será igual a -2*/
			if((alturaNo(raizArvore->esq) - alturaNo(raizArvore->dir)) == -2) {
				if(raizArvore->dir->dir != NULL){
					raizArvore = rotacaoEsquerda(raizArvore);
				} else {
					raizArvore = rotacaoDuplaEsquerda(raizArvore);
				}
			}

		}

	}

	return raizArvore;

}

/* Retorna o maior elemento apartir de um nó dado.*/
no * maiorElemento(no * noRaiz) {
	no * maior;
	if(noRaiz->dir == NULL) {
		maior = noRaiz;
		return maior;
	} else {
		maior = maiorElemento(noRaiz->dir);
	}
}

/* Retorna o menor elemento apartir de um nó dado.*/
no * menorElemento(no * noRaiz) {
	no * menor;
	if(noRaiz->esq == NULL) {
		menor = noRaiz;
		return menor;
	} else {
		menor = menorElemento(noRaiz->esq);
	}
}

/* Retorna um nó em uma arvore segundo o valor dado.*/
no * buscarElemento(no * noRaiz, int valor) {
	no * resultado;	
	if(noRaiz == NULL || noRaiz->chave == valor) {
		return noRaiz;
	} else if(valor < noRaiz->chave) {
		return buscarElemento(noRaiz->esq, valor);
	} else {
		return buscarElemento(noRaiz->dir, valor);
	}
}

/* Retorna o sucessor de um nó em uma arvore segundo um nó dado que exista na arvore.*/
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

/* Retorna o antecessor de um nó em uma arvore segundo um nó dado.*/
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

/* Carrega uma arvore apartir de um arquivo.*/
void carregarArvore(arvoreAVL * arv, char *nomeArq) {
	FILE *arquivo;
	arquivo = fopen(nomeArq, "r");
	char linha[10];
	int valor;
	while(fgets(linha, 10, arquivo) != NULL) {
		valor = atoi(linha);
		no * novoNo;
		novoNo = alocarNo(valor);
		arv->raiz = inserirNo(novoNo, arv->raiz, NULL);
	}
	fclose(arquivo);
}

/* Imprimi a representação de uma arvore em um arquivo.*/
void imprimirArvoreArq(no * noRaiz, char *nomeArq) {
	FILE *arquivo;
	if(noRaiz != NULL) {
		arquivo = fopen(nomeArq, "a");
		fprintf(arquivo, "( ");
		fprintf(arquivo, "%d", noRaiz->chave);
		fclose(arquivo);
		imprimirArvoreArq(noRaiz->esq, nomeArq);
		imprimirArvoreArq(noRaiz->dir, nomeArq);
		arquivo = fopen(nomeArq, "a");
		fprintf(arquivo, ")");
		fclose(arquivo);
	}
}

/* Libera memoria utilizada para armazenar uma arvore.*/
void apagarArvore(no * noRaiz) {
	if(noRaiz != NULL) {
		apagarArvore(noRaiz->esq);
		apagarArvore(noRaiz->dir);
		free(noRaiz);
		noRaiz = NULL;
	}
}
