#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define nc 3 // Quantiade de casos

typedef struct {
	int dilemas;
	int alternativas;
} Respostas;

void menu(char **frases, char **resp, Respostas historico[nc]);
char *criarString(char *texto);
void questoes(char ***frases);
void respostas(char ***resp);
void crescente(char **frases, char **resp, Respostas historico[nc]);
void salvarHistorico(Respostas historico[nc]);
void acessarHistorico(Respostas historico[nc]);
