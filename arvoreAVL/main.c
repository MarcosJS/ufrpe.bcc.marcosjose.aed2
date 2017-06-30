#include "arvoreAVL.h"

int main(int argc, char * argv[]) {

	int erro = 0;

	arvoreAVL * arv = alocarArvore();	

	system("clear");

	switch(argc) {
		case 2:
			if(strcmp(argv[1], "-h") == 0) {
				printf("-o <arquivo> 	:redireciona a saida para o ‘‘arquivo\n");
				printf("-f <arquivo> 	:indica o ‘‘arquivo’’ que contém os dados a serem adicionados na AVL\n");
				printf("-m 		:imprime o menor elemento da AVL\n");
				printf("-M 		:imprime o maior elemento da AVL\n");
				printf("-a <elemento> 	:imprime o antecessor na AVL do ‘‘elemento’’ ou caso contrário imprime -1\n");
				printf("-s <elemento> 	:imprime o sucessor na AVL do ‘‘elemento’’ ou caso contrário imprime -1\n\n\n");
				printf("ATENÇÃO: A ordem dos parametro deve ser exatamento igual ao demonstrado abaixo.\n\n\n");
				printf("\t'$ ./rn -f arquivo-entrada.dat -o saida.dat' - imprimi representacao em arquivo.\n");
				printf("\t'$ ./rn -f arquivo-entrada.dat -o saida.dat' - imprimi representacao da arvore na tela.\n");
				printf("\t'$ ./rn -f arquivo-entrada.dat -M (ou 'm')' - imprimi na tela o maior ou menor elemento\n");
				printf("\t'$ ./rn -f arquivo-entrada.dat -a (ou 's') 25' - imprimi na tela o antecessor ou sucessor, se houver do valor fornecido.\n");
			} else {
				printf("ERRO: Lista de parametros errada! Consulte a ajuda: '-h'");
				erro = 1;
			}
			getchar();
			break;
		case 3:
			if(strcmp(argv[1], "-f") == 0) {
				carregarArvore(arv, argv[2]);
				imprimirArvore(arv->raiz);
			} else {
				printf("ERRO: Lista de parametros errada! Consulte a ajuda: '-h'");
				erro = 1;	
			}
			getchar();	
			break;
		case 4:
			carregarArvore(arv, argv[2]);
			if((strcmp(argv[1], "-f") == 0) && (strcmp(argv[3], "-m") == 0)) {
				no * menor;
				menor = menorElemento(arv->raiz);
				printf("%d\n", menor->chave);
			} else if((strcmp(argv[1], "-f") == 0) && (strcmp(argv[3], "-M") == 0)) {
				no * maior;
				maior = maiorElemento(arv->raiz);
				printf("%d\n", maior->chave);
			} else {
				printf("ERRO: Lista de parametros errada! Consulte a ajuda: '-h'");
				erro = 1;
			}
			getchar();
			break;
		case 5:
			carregarArvore(arv, argv[2]);
			no * temp;
			if((strcmp(argv[1], "-f") == 0) && (strcmp(argv[3], "-o") == 0)) {
				imprimirArvoreArq(arv->raiz, argv[4]);
			} else if((strcmp(argv[1], "-f") == 0) && (strcmp(argv[3], "-a") == 0)) {
				no * anter;
				anter = antecessor(buscarElemento(arv->raiz, atoi(argv[4])));
				printf("%d\n", anter->chave);
			} else if((strcmp(argv[1], "-f") == 0) && (strcmp(argv[3], "-s") == 0)) {
				no * suces;
				suces = sucessor(buscarElemento(arv->raiz, atoi(argv[4])));
				printf("%d\n", suces->chave);
			} else {
				printf("ERRO: Lista de parametros errada! Consulte a ajuda: '-h'");
				erro = 1;
			}
			getchar();
			break;
		default:
			printf("ERRO: parâmetros conflitantes ou faltosos! Consulte a ajuda: '-h'");
			erro = 1;
			getchar();
	}
	/*printf("argc: %d\n", argc);
	printf("argc: %s\n", argv[0]);
	printf("argc: %s\n", argv[1]);
	printf("argc: %s\n", argv[2]);
	printf("argc: %s\n", argv[3]);
	printf("argc: %s\n", argv[4]);
	getchar();*/
	system("clear");

	apagarArvore(arv->raiz);
	
	return erro;
}
