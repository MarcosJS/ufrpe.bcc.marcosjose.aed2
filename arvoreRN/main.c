#include "arvoreRN.h"

int main(int argc, char * argv[]) {

	int erro = 0;

	arvoreRN * arv = alocarArvore();	

	system("clear");

	switch(argc) {
		case 2:
			if(strcmp(argv[1], "-h") == 0) {
				printf("-o <arquivo> 	:redireciona a saida para o ‘‘arquivo\n");
				printf("-f <arquivo> 	:indica o ‘‘arquivo’’ que contém os dados a serem adicionados na Rubro Negra\n");
				printf("-m 		:imprime o menor elemento da Rubro Negra\n");
				printf("-M 		:imprime o maior elemento da Rubro Negra\n");
				printf("-a <elemento> 	:imprime o antecessor na Rubro Negra do ‘‘elemento’’ ou caso contrário imprime -1\n");
				printf("-s <elemento> 	:imprime o sucessor na Rubro Negra do ‘‘elemento’’ ou caso contrário imprime -1\n\n\n");
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
				if(menor != NULL) {
					if(menor->cor == 1) {
						printf("%dN\n", menor->chave);
					} else {
						printf("%dR\n", menor->chave);
					}
				} else {
					printf("ERRO: A arvore está vazia! Indique um novo arquivo para alimentar a arvore");
				}
			} else if((strcmp(argv[1], "-f") == 0) && (strcmp(argv[3], "-M") == 0)) {
				no * maior;
				maior = maiorElemento(arv->raiz);
				if(maior != NULL) {
					if(maior->cor == 1) {
						printf("%dN\n", maior->chave);
					} else {
						printf("%dR\n", maior->chave);
					}
				} else {
					printf("ERRO: A arvore está vazia! Indique um novo arquivo para alimentar a arvore");
				}
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
				if(anter != NULL) {
					if(anter->cor == 1) {
						printf("%dN\n", anter->chave);
					} else {
						printf("%dR\n", anter->chave);
					}
				} else {
					printf("ERRO: O elemento informado não existe na arvore! Tente novamente.");
				}
			} else if((strcmp(argv[1], "-f") == 0) && (strcmp(argv[3], "-s") == 0)) {
				no * suces;
				suces = sucessor(buscarElemento(arv->raiz, atoi(argv[4])));
				if(suces != NULL) {
					if(suces->cor == 1) {
						printf("%dN\n", suces->chave);
					} else {
						printf("%dR\n", suces->chave);
					}
				} else {
					printf("ERRO: O elemento informado não existe na arvore! Tente novamente.");
				}
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
	
	system("clear");

	apagarArvore(arv);
	
	return erro;
}
