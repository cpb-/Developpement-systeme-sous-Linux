// ------------------------------------------------------------------
// exemple-wordexp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wordexp.h>
#include <sys/wait.h>

#define LINE_LENGTH  256

void display_error(int err_num)
{
	switch (err_num) {
		case WRDE_BADCHAR :
			fprintf(stderr, "Caractere interdit\n");
			break;
		case WRDE_BADVAL :
			fprintf(stderr, "Variable indefinie\n");
			break;
		case WRDE_CMDSUB :
			fprintf(stderr, "Invocation de commande interdite\n");
			break;
		case WRDE_NOSPACE :
			fprintf(stderr, "Pas assez de memoire\n");
			break;
		case WRDE_SYNTAX :
			fprintf(stderr, "Erreur de syntaxe\n");
			break;
		default :
			break;
	}
}


int main (void)
{
	char      line[LINE_LENGTH];
	wordexp_t words;
	int       error;
	pid_t     pid;

	while (1) {
		fprintf(stdout, "-> ");
		if (fgets(line, LINE_LENGTH, stdin) == NULL)
			break;
		if (strlen(line) == 0)
			continue;
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		if ((error = wordexp(line, &words, WRDE_SHOWERR)) != 0) {
			display_error(error);
			goto fin_boucle;
		}
		if (words.we_wordc == 0)
			goto fin_boucle;
		if (strcmp(words.we_wordv[0], "set") == 0) {
			if (words.we_wordc != 3) {
				fprintf(stderr, "syntaxe : set variable valeur\n");
				goto fin_boucle;
			}
			if (setenv(words.we_wordv[1],words.we_wordv[2], 1) < 0)
				perror("");
			goto fin_boucle;
		}
		if ((pid = fork()) < 0) {
			perror("fork");
			goto fin_boucle;
		}
		if (pid == 0) {
			execvp(words.we_wordv[0],words.we_wordv);
			perror(words.we_wordv [0]);
			exit(EXIT_FAILURE);
		} else {
			wait(NULL);
		}
		fin_boucle :
			wordfree(&words);
	}
	fprintf(stdout, "\n");

	return EXIT_SUCCESS;
}

