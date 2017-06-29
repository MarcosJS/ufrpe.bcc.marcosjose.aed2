#define TAMANHO 11
typedef struct ElementoH {
	int chave;
	int * prox;
} elementoH;

typedef struct Hash {
	int qtd;
	int TAMANHO;
	ElementoH tabela;
} hash;

elementoH * alocarElementoH(int chave);
hash * alocarHash(int TAMANHO);
int hashing(int chave);
int inserirHash(hash h, elementoH novo);
elementoH buscarHash(hash h, int chave);
int deletarHash(hash h, int chave);
