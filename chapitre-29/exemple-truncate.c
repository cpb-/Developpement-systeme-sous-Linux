// ------------------------------------------------------------------
// exemple-truncate.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	long length;

	if ((argc != 3) || (sscanf(argv[2], "%ld", & length) != 1)) {
		fprintf(stderr, "Syntaxe : %s fichier length\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (truncate(argv[1], length) < 0)
		perror(argv[1]);

	return EXIT_SUCCESS;
}
