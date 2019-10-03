// ------------------------------------------------------------------
// exemple-glob.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <glob.h>

int main (int argc, char * argv[])
{
	glob_t paths;
	int    i;
	int    error;

	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s motif\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	error = glob(argv[1], 0, NULL, & paths);
	if ((error != 0) && (error != GLOB_NOMATCH))
		perror(argv[1]);
	for (i = 0; i < paths.gl_pathc; i ++)
		fprintf(stdout, "%s\n", paths.gl_pathv[i]);
	globfree(& paths);

	return EXIT_SUCCESS;
}
