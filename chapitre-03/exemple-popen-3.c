// ------------------------------------------------------------------
// exemple-popen-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>

int main (void)
{
	FILE * fp;
	char * login;
	char   name[128];
	char   cmd[128];

	if ((login = getlogin()) == NULL)
		strcpy(name, "\"\"");
	else
		strcpy(name, login);
	sprintf(cmd, "./exemple-popen-3.py "
			   "Saisie "
			   "\"Entrez votre nom\" "
			   "%s 2>/dev/null", name); 

	if ((fp = popen(cmd , "r")) == NULL) {
		// Le script est, par exemple, introuvable
		// On va essayer de lire sur stdin.
		fprintf(stdout, "Entrez votre nom : ");
		if (fscanf(stdin, "%s", name) != 1) {
			// La lecture sur stdin echoue...
			// On utilise une valeur par defaut.
			strcpy(name, getlogin());
		}
		fprintf(stdout, "Nom saisi : %s\n", name);
		return 0;
	}

	if (fscanf(fp, "%s", name) != 1) {
		if (pclose(fp) != 0) {
			// Le script a echoue pour une raison quelconque.
			// On recommence la saisie sur stdin.
			fprintf(stdout, "Entrez votre nom : ");
			if (fscanf(stdin, "%s", name) != 1) {
				// La lecture sur stdin echoue...
				// On utilise une valeur par defaut.
				strcpy(name, getlogin());
			}
		} else {
			// L'utilisateur a clique sur Annuler. Il faut
			// abandonner l'operation en cours.
			fprintf(stdout, "Pas de nom fourni - abandon\n");
			return 1;
		}
	} else {
		pclose(fp);
	}
	fprintf(stdout, "Nom saisi : %s\n", name);
	return 0;
}
