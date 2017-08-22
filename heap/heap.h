#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXIMO 9999;
#define MINIMO -9999999;

typedef struct Heap {
	int tam;
	int comp; 
	int h[MAXIMO];
} heap;

void trocar(heap * h, int i, maior);
int pai(int i);
int esq(int i);
int dir(int i);
void maxHeapify(heap * h, int i);
void buildMaxHeap(heap * h);
void heapSort(heap * h);
int heapMaximun(heap h);
int heapExtractMax(heap * h);
void heapIncreaseKey(heap * h, int i, int chave);
void heapMaxInsert(heap * h, int chave);

#endif // __HEAP_H__
