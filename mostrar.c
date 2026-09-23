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
		printf("Pressione qualquer tecla para continuar ...\n");
		getchar();
		getchar();
	}
	salvarHistorico(historico);
	pontos(historico);
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
		printf("\nNenhum historico encontrado ainda.\n");
		return;
	}
	fread(historico, sizeof(Respostas), nc, arquivo);
	printf("\n");
	for (int i = 0; i < nc; i++) {
		printf("Dilema %d: voce escolheu a alternativa %d\n", historico[i].dilemas+1, historico[i].alternativas);
	}
	pontos(historico);
	printf("\n");
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

void pontos(Respostas historico[]) {
	int pk=0, pb=0, pm=0, p;	//ponto kant, ponto bentham, ponto mill
	float prk, prb, prm;	//percentuais 

	FILE *arquivo = fopen("historico.dat","rb");
	if (arquivo == NULL) {
		printf("Erro ao acesso o arquivo historico.dat");
		return;
	}
	fread(historico, sizeof(Respostas), nc, arquivo);
	
	switch (historico[0].alternativas) {	//q1
		case 1: 
			pk+=2;
			pb+=2;
			pm+=2;
			break;
		case 2:
			pk+=7;
			pb+=9;
			pm+=8;
			break;
		case 3:
			pk+=6;
			pb+=6;
			pm+=7;
	}
	
	switch (historico[1].alternativas) {	//q2
		case 1: 
			pk+=0;
			pb+=6;
			pm+=3;
			break;
		case 2:
			pk+=9;
			pb+=4;
			pm+=7;
			break;
		case 3:
			pk+=7;
			pb+=8;
			pm+=9;
	}

	switch (historico[0].alternativas) {	//q3
		case 1: 
			pk+=10;
			pb+=1;
			pm+=2;
			break;
		case 2:
			pk+=0;
			pb+=9;
			pm+=8;
			break;
		case 3:
			pk+=4;
			pb+=5;
			pm+=5;
	}

	prk=((float)pk/(pk+pb+pm)*100);
	prb=((float)pb/(pk+pb+pm)*100);
	prm=((float)pm/(pk+pb+pm)*100);

	perfilEtico(prk, prb, prm);
}

void perfilEtico (float prk, float prb, float prm) {
	int preenchidos, total_barras=50;

	//porcentagem de Kant
	preenchidos = (int)(prk*total_barras)/100;
	printf("Etica do Dever (Kant):                     [");
	for (int i=0; i<total_barras; i++) {
		if (i<preenchidos) {
			printf("█");
		}	
		else {
			printf("░");
		}
	}
	printf("] %.1f%%\n", prk);

	//porcentagem de Bentham
	preenchidos = (int)(prb*total_barras)/100;
	printf("Etica Utilitarista Quantitativa (Bentham): [");
	for (int i=0; i<total_barras; i++) {
		if (i<preenchidos) {
			printf("█");
		}	
		else {
			printf("░");
		}
	}
	printf("] %.1f%%\n", prb);

	//porcentagem de Mill
	preenchidos = (int)(prm*total_barras)/100;
	printf("Etica Utilitarista Qualitativa (Mill):     [");
	for (int i=0; i<total_barras; i++) {
		if (i<preenchidos) {
			printf("█");
		}	
		else {
			printf("░");
		}
	}
	printf("] %.1f%%\n", prm);
	printf("\nPressione qualquer tecla para continuar ...");
	getchar();
	getchar();
}
