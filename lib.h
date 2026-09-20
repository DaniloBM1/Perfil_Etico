#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define nc 3 // Quantiade de casos

void menu(char **frases, char **resp);
void questoes(char **frases);
void respostas(char **resp);
void crescente(char **frases, char **resp);

int main () {
        char **frases, **resp;

        questoes(frases);
        respostas(resp);
        menu(frases, resp);

        return 0;
}
