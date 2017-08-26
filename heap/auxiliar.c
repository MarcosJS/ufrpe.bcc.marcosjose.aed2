#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.h"

void printMsgErro(char * msg) {
	system("clear");
	printf("\nERRO: %s!\n\n", msg);
	getchar();
}

void ShowMsgAlert(char *txtMsg) {
	system("clear");
	FILE *textMsg;
	textMsg = fopen(txtMsg, "r");
	char linha[100];
	while(fgets(linha, 100, textMsg) != NULL) {
		printf("%s", linha);
	}
	fclose(textMsg);
	getchar();
}
