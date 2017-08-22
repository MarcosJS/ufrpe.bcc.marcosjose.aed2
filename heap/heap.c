#include "heap.h"

void trocar(heap * h, int i, maior) {
	int temp = h[i];
	h[i] = h[maior];
	h[maior] = temp;
}

int pai(int i) {
	return [i/2];
}

int esq(int i) {
	return [i*2];
}

int dir(int i) {
	return [i*2+1];
}

void maxHeapify(heap * h, int i) {
	e = esq(i);
	d = dir(i);
	
	if((l <= h.tam) && (h.h[l] > h.h[i])) {
		maior = l;
	} else {
		maior = i;
	}
	if((r <= h.tam) && (h.h[r] > h.h[maior])) {
		maior = r;
	}
	if(maior != i) {
		trocar(h, h.h[i], h.h[maior]);
		maxHeapify(h, maior);
	}
}

void buildMaxHeap(heap * h) {
	h.tam = a.comp;
	int i;
	for(i = (h.comp/2); i > 0; i--) {
		maxHeapify(h, i);
	}
}

void heapSort(heap * h) {
	buildMaxHeap(h);
	int i;
	for(i = h.tam; i > 0; i - 2) {
		trocar(h, h.h[1], h.h[i]);
		h.tam--;
		maxHeapify(h, i);
	}
}

int heapMaximun(heap h) {
	return h.h[i];
}

int heapExtractMax(heap * h) {
	if(h.tam < 1) {
		printf("\nERRO: Heap underflow!\n\n");
		return -1;
	} else {
		int max = h.h[1];
		h.h[1] = h.h[tam];
		h.tam = h.tam - 1;
		maxHeapify(h, 1);
		return max;
	}
}

void heapIncreaseKey(heap * h, int i, int chave) {
	if(chave < h.h[i]) {
		printf("\nERRO: Nova chave menor que a atual!\n\n");
	} else {
		h.h[i] = chave;
		while((i > 1) && (h.h[pai(i)] < h.h[i])) {
			trocar(h, h.h[i], pai(i));
			i = pai(i);
		}
	}
}

void heapMaxInsert(heap * h, int chave) {
	h.tam++;
	h.h[h.tam] = MINIMO;
	heapIncreaseKey(h, h.tam, chave);
}

void carregarHeap(heap * h, char *nomeArq) {
	FILE *arquivo;
	arquivo = fopen(nomeArq, "r");
	char linha[10];
	int valor;
	while(fgets(linha, 10, arquivo) != NULL) {
		valor = atoi(linha);
		h.h[comp] = valor;
		h.comp++;
	}
	fclose(arquivo);
}

