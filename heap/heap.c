#include "heap.h"
#include "auxiliar.h"

void trocar(heap * h, int i, int maior) {
	int temp = h->h[i];
	h->h[i] = h->h[maior];
	h->h[maior] = temp;
}

heap * alocarHeap() {
	heap* h = (heap*) malloc(sizeof(heap));
	h->tam = 0;
	h->comp = 1;

	return h;
}

int pai(int i) {
	return i/2;
}

int esq(int i) {
	return i*2;
}

int dir(int i) {
	return i*2+1;
}

void maxHeapify(heap * h, int i) {
	int e = esq(i);
	int d = dir(i);
	int maior = 0;
	
	if((e <= h->tam - 1) && (h->h[e] > h->h[i])) {
		maior = e;
	} else {
		maior = i;
	}
	if((d <= h->tam - 1) && (h->h[d] > h->h[maior])) {
		maior = d;
	}
	if(maior != i) {
		trocar(h, i, maior);
		maxHeapify(h, maior);
	}
}

void minHeapify(heap * h, int i) {
	int e = esq(i);
	int d = dir(i);
	int menor = 0;
	
	if((e <= h->tam - 1) && (h->h[e] < h->h[i])) {
		menor = e;
	} else {
		menor = i;
	}
	if((d <= h->tam - 1) && (h->h[d] < h->h[menor])) {
		menor = d;
	}
	if(menor != i) {
		trocar(h, i, menor);
		minHeapify(h, menor);
	}
}

void buildMaxHeap(heap * h) {
	h->tam = h->comp;
	int i;
	for(i = ((h->comp - 1)/2); i > 0; i--) {
		maxHeapify(h, i);
	}
}

void buildMinHeap(heap * h) {
	h->tam = h->comp;
	int i;
	for(i = ((h->comp - 1)/2); i > 0; i--) {
		minHeapify(h, i);
	}
}

void heapSort(heap * h) {
	buildMaxHeap(h);
	
	int i;
	for(i = h->tam - 1; i > 0; i--) {
		trocar(h, 1, i);
		h->tam--;
		maxHeapify(h, 1);
	}
}

void heapMinSort(heap * h) {
	buildMinHeap(h);
	
	int i;
	for(i = h->tam - 1; i > 0; i--) {
		trocar(h, 1, i);
		h->tam--;
		minHeapify(h, 1);
	}
}

int heapMaximun(heap h) {
	return h.h[1];
}

int heapMinimun(heap h) {
	return h.h[1];
}

int heapExtractMax(heap * h) {
	if(h->tam < 1) {
		printMsgErro("Heap underflow");
		return MINIMO;
	} else {
		int max = h->h[1];
		h->h[1] = h->h[h->tam];
		h->tam--;
		maxHeapify(h, 1);
		return max;
	}
}

int heapExtractMin(heap * h) {
	if(h->tam < 1) {
		printMsgErro("Heap underflow");
		return MINIMO;
	} else {
		int min = h->h[1];
		h->h[1] = h->h[h->tam];
		h->tam--;
		minHeapify(h, 1);
		return min;
	}
}

void heapIncreaseKey(heap * h, int i, int chave) {
	if(chave < h->h[i]) {
		printMsgErro("Nova chave menor que a atual");
	} else {
		h->h[i] = chave;
		while((i > 1) && (h->h[pai(i)] < h->h[i])) {
			trocar(h, h->h[i], pai(i));
			i = pai(i);
		}
	}
}

void heapMinIncreaseKey(heap * h, int i, int chave) {
	if(chave > h->h[i]) {
		printMsgErro("Nova chave menor que a atual");
	} else {
		h->h[i] = chave;
		while((i > 1) && (h->h[pai(i)] > h->h[i])) {
			trocar(h, h->h[i], pai(i));
			i = pai(i);
		}
	}
}

void heapMaxInsert(heap * h, int chave) {
	h->tam++;
	h->h[h->tam] = MINIMO;
	heapIncreaseKey(h, h->tam, chave);
}

void heapMinInsert(heap * h, int chave) {
	h->tam++;
	h->h[h->tam] = MAXIMO;
	heapMinIncreaseKey(h, h->tam, chave);
}

void carregarHeap(heap * h, char *nomeArq) {
	FILE *arquivo;
	arquivo = fopen(nomeArq, "r");
	char linha[10];
	int valor;
	while(fgets(linha, 10, arquivo) != NULL) {
		valor = atoi(linha);
		h->h[h->comp] = valor;
		h->comp++;
	}
	fclose(arquivo);
}

void imprimirHeap(heap * h) {
	heapSort(h);
	
	/*int j;
	for(j = 1; j < h->comp; j++) {
		printf("%d ", h->h[j]);
	}
	printf("\nCOMPRIMENTO = %d", h->comp);
	printf("\nTAMANHO = %d", h->tam);
	printf("\n");
	getchar();*/
	
	int i;
	for(i = h->comp - 1; i > 0; i--) {
		printf("%d ", h->h[i]);
	}
}

void imprimirHeapArq(heap * h, char *nomeArq) {
	heapSort(h);
	FILE *arquivo;
	arquivo = fopen(nomeArq, "a");
	int i;
	for(i = h->comp - 1; i > 0; i--) {
		fprintf(arquivo, "%d ", h->h[i]);
	}
	fclose(arquivo);
}

void imprimirHeapMin(heap * h) {
	heapMinSort(h);
	
	int i;
	for(i = h->comp - 1; i > 0; i--) {
		printf("%d ", h->h[i]);
	}
}

void imprimirHeapMinArq(heap * h, char *nomeArq) {
	heapMinSort(h);
	FILE *arquivo;
	arquivo = fopen(nomeArq, "a");
	int i;
	for(i = h->comp - 1; i > 0; i--) {
		fprintf(arquivo, "%d ", h->h[i]);
	}
	fclose(arquivo);
}
