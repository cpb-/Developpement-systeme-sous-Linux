// ------------------------------------------------------------------
// exemple-scandir.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <dirent.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

regex_t	motif_recherche;

int selection (const struct dirent * entree)
{
	if (regexec(& motif_recherche, entree->d_name, 0, NULL, 0) == 0)
		return 1;
	return 0;
}

int main (int argc, char * argv[])
{
	struct dirent ** liste;
	int    nb_entrees;
	int    i;

	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s repertoire motif\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (regcomp(& motif_recherche, argv[2], REG_NOSUB) !=0) {
		fprintf(stderr, "Motif illegal\n");
		exit(EXIT_FAILURE);
	}
	nb_entrees = scandir(argv[1], & liste, selection, alphasort);
	if (nb_entrees <= 0)
		return EXIT_SUCCESS;
	for (i = 0; i < nb_entrees; i ++) {
		fprintf(stdout, "  %s\n", liste[i]->d_name);
		free(liste[i]);
	}
	fprintf(stdout, "\n");
	free(liste);

	return EXIT_SUCCESS;
}

