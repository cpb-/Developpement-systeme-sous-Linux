// ------------------------------------------------------------------
// exemple-alloca.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void fonction_recursive (int iteration)
{
	char * bloc;

	fprintf(stdout, "Iteration %d\n", iteration);
	fflush(stdout);
	if ((bloc = alloca(512 * 1024)) == NULL) {
		fprintf(stdout, "Echec\n");
		return;
	}
	fonction_recursive(iteration + 1);
}

int main (void)
{
	fonction_recursive(1);
	return EXIT_SUCCESS;
}
