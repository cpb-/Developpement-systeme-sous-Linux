// ------------------------------------------------------------------
// exemple-popen-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>

	int
main (void)
{
	FILE * saisie;
	char * login;
	char   nom [128];
	char   commande [128];

	if ((login = getlogin()) == NULL)
		strcpy(nom, "\"\"");
	else
		strcpy(nom, login);
	sprintf(commande, "./exemple-popen-3.py "
			   "Saisie "
			   "\"Entrez votre nom\" "
			   "%s 2>/dev/null", nom); 

	if ((saisie = popen(commande , "r")) == NULL) {
		// Le script est, par exemple, introuvable
		// On va essayer de lire sur stdin.
		fprintf(stdout, "Entrez votre nom : ");
		if (fscanf(stdin, "%s", nom) != 1) {
			// La lecture sur stdin echoue...
			// On utilise une valeur par defaut.
			strcpy(nom, getlogin());
		}
		fprintf(stdout, "Nom saisi : %s\n", nom);
		return 0;	
	}

	if (fscanf(saisie, "%s", nom) != 1) {
		if (pclose(saisie) != 0) {
			// Le script a echoue pour une raison quelconque.
			// On recommence la saisie sur stdin.
			fprintf(stdout, "Entrez votre nom : ");
			if (fscanf(stdin, "%s", nom) != 1) {
				// La lecture sur stdin echoue...
				// On utilise une valeur par defaut.
				strcpy(nom, getlogin());
			}
		} else {
			// L'utilisateur a clique sur Annuler. Il faut
			// abandonner l'operation en cours.
			fprintf(stdout, "Pas de nom fourni - abandon\n");
			return 1;
		}
	} else {
		pclose(saisie);
	}
	fprintf(stdout, "Nom saisi : %s\n", nom);
	return 0;
}
