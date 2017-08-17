#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

	typedef struct Opcoes {
		char ** argumento;
		char ** opcao;
		int qOpcao;
		int qArgumento; 
	} opcoes;
	
	opcoes leArgumentos(int argc, char * argv[]) {
		opcoes op;
		int i;
		for(i = 0; i < argc - 1; i++) {
			if(argv[i + 1][0] == '-') {//Verificando se a string começa com '-'
				printf("ok\n");
			} else {
			
			}
		
		}
		
		return op;
		
	}

int main(int argc, char * argv[]) {
	opcoes = op;
	op.qOpcao = 0;
	op.qArgumento = 0;
	int i;
		for(i = 0; i < argc - 1; i++) {
			if(argv[i + 1][0] == '-') {//Verificando se a string começa com '-'
				int t = strlen(argv[i + 1]);
				int j = 0;
				while(j < t) {
					printf("\t\t%c\n", argv[i + 1][j + 1]);
					op->opcao[op.qOpcao]
					op.qOpcao++;
					j++;
				}
			} else {
				printf("%s\n", argv[i + 1]);
			}
		}
		while(op.qOpcao < )
	
	//printf("%s\n", argv[1]);
	//printf("%d\n", argc-1);
	
	return 0;
}
