// ------------------------------------------------------------------
// exemple-wordexp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wordexp.h>
#include <sys/wait.h>

#define LG_LIGNE	256

void affiche_erreur (int numero)
{
	switch (numero) {
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
	char ligne[LG_LIGNE];
	wordexp_t       mots;
	int           erreur;
	pid_t            pid;

	while (1) {
		fprintf(stdout, "-> ");
		if (fgets(ligne, LG_LIGNE, stdin) == NULL)
			break;
		if (strlen(ligne) == 0)
			continue;
		if (ligne[strlen(ligne) - 1] == '\n')
			ligne[strlen(ligne) - 1] = '\0';
		if ((erreur = wordexp(ligne, & mots, WRDE_SHOWERR)) != 0) {
			affiche_erreur(erreur);
			goto fin_boucle;
		}
		if (mots.we_wordc == 0)
			goto fin_boucle;
		if (strcmp(mots.we_wordv[0], "set") == 0) {
			if (mots.we_wordc != 3) {
				fprintf(stderr, "syntaxe : set variable valeur\n");
				goto fin_boucle;
			}
			if (setenv(mots.we_wordv[1], mots.we_wordv[2], 1) < 0)
				perror("");
			goto fin_boucle;
		}
		if ((pid = fork()) < 0) {
			perror("fork");
			goto fin_boucle;
		}
		if (pid == 0) {
			execvp(mots.we_wordv[0], mots.we_wordv);
			perror(mots.we_wordv [0]);
			exit(EXIT_FAILURE);
		} else {
			wait(NULL);
		}
		fin_boucle :
			wordfree(& mots);
	}
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}

