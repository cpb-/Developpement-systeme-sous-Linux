// ------------------------------------------------------------------
// exemple-scandir.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <dirent.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

regex_t	pattern;

int selection(const struct dirent * entry)
{
	if (regexec(& pattern, entry->d_name, 0, NULL, 0) == 0)
		return 1;
	return 0;
}

int main (int argc, char * argv[])
{
	struct dirent **list;
	int    nb_entries;
	int    i;

	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s repertoire motif\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (regcomp(& pattern, argv[2], REG_NOSUB) !=0) {
		fprintf(stderr, "Motif illegal\n");
		exit(EXIT_FAILURE);
	}
	nb_entries = scandir(argv[1], & list, selection, alphasort);
	if (nb_entries <= 0)
		return EXIT_SUCCESS;
	for (i = 0; i < nb_entries; i ++) {
		fprintf(stdout, "  %s\n", list[i]->d_name);
		free(list[i]);
	}
	fprintf(stdout, "\n");
	free(list);

	return EXIT_SUCCESS;
}

