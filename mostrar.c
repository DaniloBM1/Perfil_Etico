#include "lib.h"

void crescente (char **frases, char **resp, Respostas historico[]) {
	int i;
	
	for (i = 0; i<nc; i++) {
		printf("\n%s", frases[i]);
		printf("Selecione: ");
		historico[i].dilemas = i;
		scanf("%d",& historico[i].alternativas);
		printf("\nAnalises:\n");
		printf("\n%s\n", resp[i]);
		printf("Pressione qualquer tecla para continuar ...");
		getchar();
		getchar();
	}
	salvarHistorico(historico);
}

void salvarHistorico(Respostas historico[]) {
	FILE *arquivo = fopen("historico.dat", "wb");
	if (arquivo == NULL) {
		printf("Erro!!! falha no salvarHistorico");
		return;
	}

	fwrite(historico, sizeof(Respostas), nc, arquivo);
	fclose(arquivo);
}

void acessarHistorico(Respostas historico[]) {
	FILE *arquivo = fopen("historico.dat","rb");
	if (arquivo == NULL) {
		printf("Nenhum historico encontrado ainda.\n");
		return;
	}
	fread(historico, sizeof(Respostas), nc, arquivo);
	for (int i = 0; i < nc; i++) {
		printf("Dilema %d: voce escolheu a alternativa %d\n", historico[i].dilemas+1, historico[i].alternativas);
	}
}

void continuar(char **frases, char **resp, Respostas historico[]) {
		int i, a;
	
	for (i = 0; i<nc; i++) {
		if (historico[i].dilemas==0) {
			printf("\n%s", frases[i]);
			printf("Selecione: ");
			scanf("%d",& a);
			historico[i].dilemas = i;
			scanf("%d",& historico[i].alternativas);
			printf("\nAnalises:\n");
			printf("\n%s\n", resp[i]);
			printf("Pressione qualquer tecla para continuar ...");
			getchar();
			getchar();
		}
	}
	printf("\nTodos dilemas foram respondidos");
	salvarHistorico(historico);
}
