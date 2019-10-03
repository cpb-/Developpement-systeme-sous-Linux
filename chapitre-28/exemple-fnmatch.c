// ------------------------------------------------------------------
// exemple-fnmatch.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <dirent.h>
#include <fnmatch.h>
#include <stdio.h>
#include <stdlib.h>

static char *pattern = NULL;

int directory_selection(const struct dirent *entry)
{
	if (fnmatch(pattern, entry->d_name, FNM_PATHNAME | FNM_PERIOD) == 0)
		return 1;
	return 0;
}

int main (int argc, char * argv[])
{
	struct dirent **list;
	int    nb_entries;
	int    i;

	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s repertoire pattern\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	pattern = argv[2];
	nb_entries = scandir(argv[1], & list, directory_selection, alphasort);
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

