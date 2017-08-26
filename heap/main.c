#include "heap.h"
#include "argumento.h"
#include "auxiliar.h"

int main(int argc, char * argv[]) {
	
	opcoes op = leArgumentos(argc, argv);
	int erro = 0;
	heap * h = alocarHeap();
	system("clear");
	
	if(op.flag == '*') {
		printMsgErro("Lista de parametros errada! Consulte a ajuda: '-h'");
		erro = 1;
		
	} else {
	
		switch(op.flag) {
			case 'h':
				ShowMsgAlert("help.txt");
				break;
			case 'f':
				carregarHeap(h, op.argumento[op.posicao]);
				if(!op.minimo) {
					imprimirHeap(h);
				} else {
					imprimirHeapMin(h);
				}
				getchar();	
				break;
			case 'o':
				carregarHeap(h, op.argumento[op.posicaoEntrada]);
				if(!op.minimo) {
					imprimirHeapArq(h, op.argumento[op.posicao]);
				} else {
					imprimirHeapMinArq(h, op.argumento[op.posicao]);
				}
				getchar();
				break;
			default:
				printMsgErro("Parâmetros conflitantes ou faltosos! Consulte a ajuda: '-h'");
				erro = 1;
		}
	}

	system("clear");

	//apagarArvore(arv->raiz);
	
	return erro;
}
