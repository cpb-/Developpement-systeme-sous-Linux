// ------------------------------------------------------------------
// exemple-alloca.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void recursive_function(int iteration)
{
	char * block;

	fprintf(stdout, "Iteration #%d\n", iteration);
	fflush(stdout);
	if ((block = alloca(512 * 1024)) == NULL) {
		fprintf(stdout, "failed\n");
		return;
	}
	recursive_function(iteration + 1);
}

int main (void)
{
	recursive_function(1);
	return EXIT_SUCCESS;
}
