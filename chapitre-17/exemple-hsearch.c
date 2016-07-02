// ------------------------------------------------------------------
// exemple-hsearch.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ajoute_entree (char * francais, char * anglais)
{
	ENTRY	entree;

	entree.key  = strdup(francais);
	entree.data = strdup(anglais);
	if (hsearch(entree, ENTER) == NULL) {
		perror("hsearch");
		exit(EXIT_FAILURE);
	}
}

int main (int argc, char * argv[])
{
	int		i;
	ENTRY	entree;
	ENTRY *	trouve;

	if (argc < 2) {
		fprintf(stderr, "Syntaxe : %s [mois | jour]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/* 12 mois + 7 jours */
	if (hcreate(19) == 0) { 
		perror("hcreate");
		exit(EXIT_FAILURE);
	}
	ajoute_entree("janvier",   "january");
	ajoute_entree("fevrier",   "february");
	ajoute_entree("mars",      "march");
	ajoute_entree("avril",     "april");
	ajoute_entree("mai",       "may");
	ajoute_entree("juin",      "june");
	ajoute_entree("juillet",   "july");
	ajoute_entree("aout",      "august");
	ajoute_entree("septembre", "september");
	ajoute_entree("octobre",   "october");
	ajoute_entree("novembre",  "november");
	ajoute_entree("decembre",  "december");
	ajoute_entree("lundi",     "monday");
	ajoute_entree("mardi",     "tuesday");
	ajoute_entree("mercredi",  "wednesday");
	ajoute_entree("jeudi",     "thursday");
	ajoute_entree("vendredi",  "friday");
	ajoute_entree("samedi",    "satursday");
	ajoute_entree("dimanche",  "sunday");

	for (i = 1; i < argc; i ++) {
		entree.key = argv[i];
		fprintf(stdout, "%s -> ", argv[i]);
		trouve = hsearch(entree, FIND);
		if (trouve == NULL)
			fprintf(stdout, "pas dans la liste \n");
		else
			fprintf(stdout, "%s\n", (char *)trouve->data);
	}
	hdestroy();

	return EXIT_SUCCESS;
}

