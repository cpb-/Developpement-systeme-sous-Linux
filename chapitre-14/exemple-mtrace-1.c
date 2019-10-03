// ------------------------------------------------------------------
// exemple-mtrace-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>

int main (void)
{
	char * ptr;

	mtrace();

	if ((ptr = malloc(512)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	/* On ecrase ptr, la premiere zone n'est plus liberable */
	if ((ptr = malloc(512)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	free(ptr);

	return EXIT_SUCCESS;
}

