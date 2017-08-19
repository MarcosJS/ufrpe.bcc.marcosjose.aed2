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
	
		if(argv[i + 1][0] == '-') {
			int t = (strlen(argv[i + 1]) - 1);
			int j = 0;
			
			while(j < t) {
				char parametro = argv[i + 1][j + 1];
				
				switch(parametro) {
					case 'M':
						if(op.flag == '*') {
							op.flag = 'M';
							op.argumento[op.qArgumento] = "{*}";
							op.qArgumento++;
							op.posicao = op.qOpcao;
						}
					case 'm':
						if(op.flag == '*') {
							op.flag = 'm';
							op.argumento[op.qArgumento] = "{*}";
							op.qArgumento++;
							op.posicao = op.qOpcao;
						}
					case 'h':
						if(op.flag == '*') {
							op.flag = 'h';
							op.posicao = op.qOpcao;
						}
					case 'o':
						if(op.flag == '*') {
							op.flag = 'o';
							op.posicao = op.qOpcao;
						}
					case 'a':
						if(op.flag == '*') {
							op.flag = 'a';
							op.posicao = op.qOpcao;
						}
					case 's':
						if(op.flag == '*') {
							op.flag = 's';
							op.posicao = op.qOpcao;
						}
					case 'f':
						if(entrada == '*') {
							entrada = 'f';
							op.posicaoEntrada = op.qOpcao;
						}
				}
				
				op.qOpcao++;
				j++;
				}
				
			} else {
			op.argumento[op.qArgumento] = argv[i + 1];
			op.qArgumento++;
			}
		}
		
		if(op.flag == '*') {
			getchar();
			op.flag = entrada;
			op.posicao = op.posicaoEntrada;
		} 
	
	return op;
}
