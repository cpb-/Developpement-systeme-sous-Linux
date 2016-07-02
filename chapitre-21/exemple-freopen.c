// ------------------------------------------------------------------
// exemple-freopen.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	fprintf(stdout, "Cette ligne est envoyee sur la sortie normale\n");
	if (freopen("essai.freopen", "w", stdout) == NULL) {
		perror("freopen");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Cette ligne doit se trouver dans le fichier\n");
	return EXIT_SUCCESS;
}

