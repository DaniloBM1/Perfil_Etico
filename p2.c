#include "lib.h"

void menu(char **frases, char **resp) {
	int op;

	do {
		printf("\n\nBem vindo ao questionario casos morais e etica!!!");
		
		do {
			printf("\n\n");
				
			printf("[1] Dilemas em ordem crescente\n");
			printf("[2] Dilemas em ordem aleatoria\n");
			printf("[3] Continuar o Questionario\n");
			printf("[4] Formatar Dados\n");
			printf("[5] Acessar Historico\n");
			printf("[6] Sair\n");
		
				printf("\nSelecione uma opcao: ");
				scanf("%d",& op);

				if (op < 1 || op > 6){
					printf("\nOpcao invalida!!! Tente novamente");
				}
		} while(op < 1 || op > 6);

		switch (op) {
		case 1:
			crescente(frases, resp);
			break;
		case 6:
			printf("\nencerrando programa...\n");
			break;
		}
	} while (op != 6);
}

void questoes (char **frases) {
	// Aloca vetor de ponteiros dinâmico 
	*frases = malloc(nc * sizeof(char*));
	
	//Frases pre-definidas
	//questão 1
	char *frase1 = "1) Um engenheiro prometeu a um colega recomenda-lo para uma vaga. Depois descobre que \noutro candidato é tecnicamente mais qualificado e que a segurança de um projeto \ndepende dessa escolha.\n   [1] Cumprir a promessa ao amigo, mesmo sabendo que nao e o mais qualificado.\n   [2] Recomendar o mais qualificado, quebrando a promessa.\n   [3] Recomendar ambos e deixar a decisao para terceiros.\n";

	// Alocacada posicao com o tamanho exato da frase (strlen) [string lenght]
	// e copia o conteudo (strcpy) [string copy]
	frases[0] = malloc((strlen(frase1) + 1) * sizeof(char));
	strcpy(frases[0], frase1);

	//questão 2
	char *frase2 = "2) Uma estagiaria comete um erro em um experimento que atrasa a pesquisa do\nlaboratorio em semanas. O professor responsavel pode: assumir o erro como\nproprio para nao prejudicar a carreira dela, deixar claro que foi ela, ou\nreportar de forma neutra sem citar nomes.\n   [1] Assumir a culpa, mentindo sobre a autoria do erro.\n   [2] Relatar com precisao, identificando quem errou.\n   [3] Relatar o erro tecnicamente, sem atribuir autoria pessoal.\n";

        frases[1] = malloc((strlen(frase2) + 1) * sizeof(char));
        strcpy(frases[1], frase2);

	frases[0] = malloc((strlen(frase1) + 1) * sizeof(char));
        strcpy(frases[0], frase1);

	//questão 3
        char *frase3 = "3) Uma pessoa esconde em sua casa um judeu perseguido pelo regime nazista. Um oficial bate a porta e pergunta diretamente se ha alguem escondido ali.\n   [1] Dizer a verdade, entregando o inocente ao oficial.\n   [2] Mentir, negando que ha alguem escondido.\n   [3] Recusar-se a responder, mantendo silencio diante da pergunta.\n";

        frases[2] = malloc((strlen(frase3) + 1) * sizeof(char));
        strcpy(frases[2], frase3);

	//questões 4
}

void respostas (char **resp) {
	*resp = malloc(nc * sizeof(char*));
	
	//resposta 1
	char *resp1 = "Para Kant, a resposta certa e romper a promessa e indicar o candidato mais\nqualificado: quando duas obrigacoes entram em conflito, o dever de nao colocar\nvidas em risco pesa mais do que o dever de manter a palavra dada.\n\nPara Bentham, a mesma escolha e a que melhor se sustenta: nenhuma outra\nalternativa produz tanto beneficio quanto garantir a seguranca do projeto,\no que torna obvio o calculo entre lealdade pessoal e bem-estar coletivo.\n\nPara Mill, romper a promessa tambem e o caminho mais coerente: decidir pelo\nmerito, e nao pela amizade, e exatamente o que se espera de um julgamento\nimparcial diante do bem comum.\n";

	resp[0] = malloc((strlen(resp1) + 1) * sizeof(char));
	strcpy(resp[0], resp1);

	//resposta 2
	char *resp2 = "Para Kant, a resposta correta e relatar o erro com precisao, identificando quem\no cometeu: mentir para proteger alguem, mesmo por boa intencao, nunca deixa de\nser mentira, e o dever de dizer a verdade nao admite excecoes.\n\nPara Bentham, a alternativa mais equilibrada e relatar o erro tecnicamente,\nsem atribuir autoria pessoal: essa opcao preserva o bem-estar da estagiaria\nsem comprometer a integridade do relatorio, produzindo o melhor saldo entre\nhonestidade e dano evitado.\n\nPara Mill, a mesma solucao e a mais coerente: relatar com precisao tecnica,\nmas sem expor a autora, concilia a exigencia de honestidade institucional com\numa protecao razoavel ao individuo — o equilibrio que a imparcialidade exige.\n";

        resp[1] = malloc((strlen(resp2) + 1) * sizeof(char));
        strcpy(resp[1], resp2);

	//resposta 3
	char *resp3 = "Para Kant, a resposta certa e dizer a verdade, mesmo entregando o inocente: o\ndever de veracidade nao admite excecao, nem mesmo diante de consequencias\ntragicas — mentir, por mais bem-intencionado que seja, continua sendo uma\nviolacao direta do dever.\n\nPara Bentham, a escolha mais defensavel e mentir, negando que ha alguem\nescondido: evitar a morte do inocente maximiza o bem-estar e minimiza o\nsofrimento total, o que torna essa a alternativa de maior utilidade, mesmo a\ncusta da honestidade.\n\nPara Mill, mentir tambem e o caminho mais coerente: a imparcialidade \nexige proteger a vida em risco,\nmesmo que isso signifique romper a regra da veracidade em nome de um bem\nmaior.\n";

        resp[2] = malloc((strlen(resp3) + 1) * sizeof(char));
        strcpy(resp[2], resp3);

	//resposta 4
}

void crescente (char **frases, char **resp) {
	int i, a;
	
	for (i = 0; i<nc; i++) {
		printf("\n%s", frases[i]);
		printf("Selecione: ");
		scanf("%d",& a);
		printf("\nAnalises:\n");
		printf("\n%s\n", resp[i]);
	}
}
