// ------------------------------------------------------------------
// exemple-hsearch.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_entry(char *french, char *english)
{
	ENTRY entry;

	entry.key  = strdup(french);
	entry.data = strdup(english);
	if (hsearch(entry, ENTER) == NULL) {
		perror("hsearch");
		exit(EXIT_FAILURE);
	}
}


int main(int argc, char * argv[])
{
	int    i;
	ENTRY  entry;
	ENTRY *found;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s [mois | jour]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/* 12 mois + 7 jours */
	if (hcreate(19) == 0) { 
		perror("hcreate");
		exit(EXIT_FAILURE);
	}
	add_entry("janvier",   "january");
	add_entry("fevrier",   "february");
	add_entry("mars",      "march");
	add_entry("avril",     "april");
	add_entry("mai",       "may");
	add_entry("juin",      "june");
	add_entry("juillet",   "july");
	add_entry("aout",      "august");
	add_entry("septembre", "september");
	add_entry("octobre",   "october");
	add_entry("novembre",  "november");
	add_entry("decembre",  "december");
	add_entry("lundi",     "monday");
	add_entry("mardi",     "tuesday");
	add_entry("mercredi",  "wednesday");
	add_entry("jeudi",     "thursday");
	add_entry("vendredi",  "friday");
	add_entry("samedi",    "satursday");
	add_entry("dimanche",  "sunday");

	for (i = 1; i < argc; i ++) {
		entry.key = argv[i];
		fprintf(stdout, "%s -> ", argv[i]);
		found = hsearch(entry, FIND);
		if (found == NULL)
			fprintf(stdout, "pas dans la liste \n");
		else
			fprintf(stdout, "%s\n", (char *)found->data);
	}
	hdestroy();

	return EXIT_SUCCESS;
}

