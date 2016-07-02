// ------------------------------------------------------------------
// exemple-glob.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <glob.h>

int main (int argc, char * argv[])
{
	glob_t chemins;
	int    i;
	int    erreur;

	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s motif\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	erreur = glob(argv[1], 0, NULL, & chemins);
	if ((erreur != 0) && (erreur != GLOB_NOMATCH))
		perror(argv[1]);
	for (i = 0; i < chemins.gl_pathc; i ++)
		fprintf(stdout, "%s\n", chemins.gl_pathv[i]);
	globfree(& chemins);
	return EXIT_SUCCESS;
}
