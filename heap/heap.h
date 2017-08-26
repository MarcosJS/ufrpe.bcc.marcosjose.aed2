#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define COMP_MAXIMO 9999
#define MAXIMO 9999999
#define MINIMO -9999999

typedef struct Heap {
	int tam;
	int comp; 
	int h[COMP_MAXIMO];
} heap;

void trocar(heap * h, int i, int maior);
heap * alocarHeap();
int pai(int i);
int esq(int i);
int dir(int i);
void maxHeapify(heap * h, int i);
void minHeapify(heap * h, int i);
void buildMaxHeap(heap * h);
void buildMinHeap(heap * h);
void heapSort(heap * h);
void heapMinSort(heap * h);
void heapMinSort(heap * h);
int heapMaximun(heap h);
int heapMinimun(heap h);
int heapExtractMax(heap * h);
int heapExtractMin(heap * h);
void heapIncreaseKey(heap * h, int i, int chave);
void heapMinIncreaseKey(heap * h, int i, int chave);
void heapMaxInsert(heap * h, int chave);
void heapMinInsert(heap * h, int chave);
void carregarHeap(heap * h, char *nomeArq);
void imprimirHeap(heap * h);
void imprimirHeapArq(heap * h, char *nomeArq);
void imprimirHeapMin(heap * h);
void imprimirHeapMinArq(heap * h, char *nomeArq);

#endif // __HEAP_H__
