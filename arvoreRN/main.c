#include "arvoreRN.h"
#include "argumento.h"

int main(int argc, char * argv[]) {

	opcoes op = leArgumentos(argc, argv);

	int erro = 0;

	arvoreRN * arv = alocarArvore();	

	system("clear");
	
	if(op.flag == '*') {
	
		printf("ERRO: Lista de parametros errada! Consulte a ajuda: '-h'");
		erro = 1;
		
	} else {

		switch(op.flag) {
			case 'h':
				printf("-o <arquivo> 	:redireciona a saida para o ‘‘arquivo\n");
				printf("-f <arquivo> 	:indica o ‘‘arquivo’’ que contém os dados a serem adicionados na arvore\n");
				printf("-m 		:imprime o menor elemento da Rubro Negra\n");
				printf("-M 		:imprime o maior elemento da Rubro Negra\n");
				printf("-a <elemento> 	:imprime o antecessor na Rubro Negra do ‘‘elemento’’ ou caso contrário imprime -1\n");
				printf("-s <elemento> 	:imprime o sucessor na Rubro Negra do ‘‘elemento’’ ou caso contrário imprime -1\n\n\n");
				printf("ATENÇÃO: Persistindo o erro tente seguir a ordem demonstrada abaixo.\n\n\n");
				printf("\t'$ ./rn -f arquivo-entrada.dat -o saida.dat' - imprimi representacao em arquivo.\n");
				printf("\t'$ ./rn -f arquivo-entrada.dat -o saida.dat' - imprimi representacao da arvore na tela.\n");
				printf("\t'$ ./rn -f arquivo-entrada.dat -M (ou 'm')' - imprimi na tela o maior ou menor elemento\n");
				printf("\t'$ ./rn -f arquivo-entrada.dat -a (ou 's') 25' - imprimi na tela o antecessor ou sucessor, se houver do valor fornecido.\n");
				getchar();
				break;
			case 'f':
				carregarArvore(arv, op.argumento[op.posicao]);
				imprimirArvore(arv->raiz);
				getchar();	
				break;
			case 'm':
				carregarArvore(arv, op.argumento[op.posicaoEntrada]);
				no * menor;
				menor = menorElemento(arv->raiz);
				imprimirNo(menor);
				getchar();
				break;
			case 'M':
				carregarArvore(arv, op.argumento[op.posicaoEntrada]);
				no * maior;
				maior = maiorElemento(arv->raiz);
				imprimirNo(maior);
				getchar();
				break;
			case 'o':
				carregarArvore(arv, op.argumento[op.posicaoEntrada]);
				no * temp;
				imprimirArvoreArq(arv->raiz, op.argumento[op.posicao]);
				getchar();
				break;
			case 'a':
				carregarArvore(arv, op.argumento[op.posicaoEntrada]);
				no * anter;
				anter = antecessor(buscarElemento(arv->raiz, atoi(op.argumento[op.posicao])));
				imprimirNo(anter);
				getchar();
				break;
			case 's':
				carregarArvore(arv, op.argumento[op.posicaoEntrada]);
				no * suces;
				suces = sucessor(buscarElemento(arv->raiz, atoi(op.argumento[op.posicao])));
				imprimirNo(suces);
				getchar();
				break;
			default:
				printf("ERRO: parâmetros conflitantes ou faltosos! Consulte a ajuda: '-h'");
				erro = 1;
				getchar();
		}
	}
	
	system("clear");

	apagarArvore(arv);
	
	return erro;
}
