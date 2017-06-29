elementoH * alocarElementoH(int chave) {
	elementoH* novoElemento = (elementoH*) malloc(sizeof(elementoH));
	novoElemento->chave = chave;
	novoElemento->proximo = NULL;
	return novoElemento;
}

hash * alocarHash(int TAMANHO) {
	hash* h = (hash*) malloc(sizeof(hash));
	h->tabela = (elementoH*) malloc(TAMANHO * sizeof(elementoH));
	h->qtd = 0;
	int i;
	for(i = 0; i < TAMANHO; i++) {
		hash->tabela[i] = NULL;
	}
	return hash;
}

int hashing(int chave) {
	if(chave < 0) {
		chave = chave * (-1);
	}
	return chave % TAMANHO;
}

int inserirHash(hash h, elementoH novo) {
	int resultado = -1;
	int posicao = hashing(novo->chave);
	if(h->tabela[pos] != NULL) {
		h->tabela = novo;
		resultado = 1;
	} else {
		elementoH eColidido = h->tabela[pos];
		while(eColidido->proximo != NULL) {
			eColidido = eColidido->proximo;
		}
		eColidido->proximo = novo;
		h->qtd++;
		resultado = 1;
	}
	return resultado;
}

elementoH buscarHash(hash h, int chave) {
	resultado = NULL;
	int posicao = hashing(int chave);
	if(h->tabela[pos] != NULL) {
		elementoH elementoTabela = h->tabela[pos];
		do {
			if(elementoTabela->chave == chave) {
				resultado = elementoTabela;
			}
		} while (elementoTabela->proximo != NULL);
	}
	return resultado;
}

int deletarHash(hash h, int chave) {
	resultado = (-1);
	int posicao = hashing(int chave);
	if(h->tabela[pos] != NULL) {
		elementoH elementoTabela = h->tabela[pos];
		do {
			if(elementoTabela->chave == chave) {
				resultado = NULL;
				h->qtd--;
				resultado  = 1;
			}
		} while (elementoTabela->proximo != NULL);
	}
	return resultado;
}

void carregarArvore(hash h, char * nomeArq) {
	FILE *arquivo;
	arquivo = fopen(nomeArq, "r");
	char linha[10];
	int valor;
	int resultado;
	while(fgets(linha, 10, arquivo) != NULL) {
		valor = atoi(linha);
		elementoH * novoElemento;
		novoElemento = alocarElementoH(valor);
		resultado = inserirHash(h, novoElemento);
		if(resultado == (-1)) {
			printf("\n\t\t\t!!!!!!ERRO: ELEMENTO NÃO PODE SER INSERIDO!!!!!");
			break;
		}
	}
	fclose(arquivo);
}

void imprimirArvoreArq(no * raizArvore, char * nomeArq) {
	FILE *arquivo;
	if(h->qtd > 0) {
		int i;
		for(i = 0; i < TAMANHO 0; i++) {
			arquivo = fopen(nomeArq, "a");
			fprintf(arquivo, "%d: ", i);
			elementoH e = h->tabela[i];
			while(e != NULL) {
				fprintf(arquivo, " %d", e->chave);
				e = e->proximo;
			}
			fprintf(arquivo, "\n");
			fclose(arquivo);
		}
	} else {
		printf("\n\t\t\t!!!!!!ERRO:HASH VAZIA!!!!!");
	}
}
