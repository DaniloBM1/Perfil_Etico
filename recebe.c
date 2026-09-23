#include "lib.h"

int main () {
        char **frases, **resp;
	Respostas historico[nc] = {0};

        questoes(&frases);
        respostas(&resp);
        menu(frases, resp, historico);

        return 0;
}

void menu(char **frases, char **resp, Respostas historico[]) {
	int op;

	do {
		printf("\nBem vindo ao menu!!!");
		
		do {
			printf("\n\n");
				
			printf("[1] Dilemas\n");
		//	printf("[2] Dilemas em ordem aleatoria\n");
		//	printf("[3] Continuar o Questionario\n");
			printf("[2] Formatar Dados\n");
			printf("[3] Acessar Historico\n");
			printf("[4] Sair\n");
		
				printf("\nSelecione uma opcao: ");
				scanf("%d",& op);

				if (op < 1 || op > 4){
					printf("\nOpcao invalida!!! Tente novamente");
				}
		} while(op < 1 || op > 4);

		switch (op) {
		case 1:
			crescente(frases, resp, historico);
			break;
	/*	case 5:
			continuar(frases, resp, historico);
			break;*/
		case 2:
			printf("\nRemovido com sucesso!!!\n");
			remove("historico.dat");
			break;
		case 3:
			acessarHistorico(historico);
			break;
		case 4:
			FILE *teste = fopen("historico.dat", "rb");
			if (teste != NULL) {
				salvarHistorico(historico);
			}
			printf("\nencerrando programa...\n");
			break;
		}
	} while (op != 4);
}
