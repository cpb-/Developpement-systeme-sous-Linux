// ------------------------------------------------------------------
// exemple-mtrace-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
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
	free(ptr);

	return EXIT_SUCCESS;
}

