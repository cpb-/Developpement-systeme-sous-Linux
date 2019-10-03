// ------------------------------------------------------------------
// exemple-realpath.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>

int main (int argc, char * argv[])
{
	char full_path [MAXPATHLEN];
	int i;

	for (i = 0; i < argc; i ++) {
		fprintf(stderr, "%s : ", argv[i]);
		if (realpath(argv[i], full_path) == NULL)
			perror("");
		else
			fprintf(stderr, "%s\n", full_path);
	}

	return EXIT_SUCCESS;
}

