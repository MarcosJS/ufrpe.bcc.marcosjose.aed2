#include "argumento.h"
	
opcoes leArgumentos(int argc, char * argv[]) {

	opcoes op;
	op.qOpcao = 0;
	op.qArgumento = 0;
	op.flag = '*';
	op.posicao = -1;
	op.posicaoEntrada;
	
	int i;
	
	char entrada = '*';
	
	for(i = 0; i < argc - 1; i++) {
	
		if(argv[i + 1][0] == '-') {//Verificando se a string começa com '-'
			int t = (strlen(argv[i + 1]) - 1);
			int j = 0;
			
			while(j < t) {//Separando e incluindo na lista as opcoes
				//printf("\t\t%c\n", argv[i + 1][j + 1]);
				
				//op.opcao[op.qOpcao] = argv[i + 1][j + 1];
				
				if((argv[i + 1][j + 1] == 'M')) {
					if(op.flag == '*') {
						op.flag = 'M';
						op.argumento[op.qArgumento] = "{*}";
						op.qArgumento++;
						op.posicao = op.qOpcao;
					}
				} else if((argv[i + 1][j + 1] == 'm')) {
					if(op.flag == '*') {
						op.flag = 'm';
						op.argumento[op.qArgumento] = "{*}";
						op.qArgumento++;
						op.posicao = op.qOpcao;
					}
				} else if(argv[i + 1][j + 1] == 'h') {
					if(op.flag == '*') {
						op.flag = 'h';
						op.posicao = op.qOpcao;
					}
				} else if(argv[i + 1][j + 1] == 'o') {
					if(op.flag == '*') {
						op.flag = 'o';
						op.posicao = op.qOpcao;
					}
				} else if(argv[i + 1][j + 1] == 'a') {
					if(op.flag == '*') {
						op.flag = 'a';
						op.posicao = op.qOpcao;
					}
				} else if(argv[i + 1][j + 1] == 's') {
					if(op.flag == '*') {
						op.flag = 's';
						op.posicao = op.qOpcao;
					}
				} else if(argv[i + 1][j + 1] == 'f') {
					if(entrada == '*') {
						entrada = 'f';
						op.posicaoEntrada = op.qOpcao;
					}
				}
				
				op.qOpcao++;
				j++;
				}
				
			} else {//Separando e incluindo na lista os argumentos
			//printf("%s\n", argv[i + 1]);
			op.argumento[op.qArgumento] = argv[i + 1];
			op.qArgumento++;
			}
		}
		
		if(op.flag == '*') {
			printf("\tTrocando flag: %c\n", op.flag);
			op.flag = entrada;
			op.posicao = op.posicaoEntrada;
		} 
	
	return op;
}
