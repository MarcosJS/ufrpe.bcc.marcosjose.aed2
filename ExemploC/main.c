
#include "lista.h"


int main()
{

	lista* l = (lista*) malloc(sizeof(lista));
	no* novo = alocaNo(10);
	no* novo2 = alocaNo(20);
	no* novo3 = alocaNo(30);

	adicionar(l, novo);
	adicionar(l, novo2);
	adicionar(l, novo3);

	print(l);
	printf("Editado apartir do repositório");

	apagar(l);
	free(l);

}
