#include "argumento.h"
	
opcoes leArgumentos(int argc, char * argv[]) {

	opcoes op;
	op.qOpcao = 0;
	op.qArgumento = 0;
	op.flag = '*';
	op.posicao = -1;
	op.posicaoEntrada;
	op.minimo = 0;
	
	int i;
	
	char entrada = '*';
	
	for(i = 0; i < argc - 1; i++) {
	
		if(argv[i + 1][0] == '-') {
			int t = (strlen(argv[i + 1]) - 1);
			int j = 0;
			
			while(j < t) {
				char parametro = argv[i + 1][j + 1];
				
				switch(parametro) {
					case 'm':
						if(op.minimo == 0) {
							op.minimo = 1;
							op.argumento[op.qArgumento] = "{*}";
							op.qArgumento++;
						}
						break;
					case 'h':
						if(op.flag == '*') {
							op.flag = 'h';
							op.posicao = op.qOpcao;
							getchar();
						}
						break;
					case 'o':
						if(op.flag == '*') {
							op.flag = 'o';
							op.posicao = op.qOpcao;
						}
						break;
					case 'f':
						if(entrada == '*') {
							entrada = 'f';
							op.posicaoEntrada = op.qOpcao;
						}
						break;
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
			op.flag = entrada;
			op.posicao = op.posicaoEntrada;
		} 
	
	return op;
}
