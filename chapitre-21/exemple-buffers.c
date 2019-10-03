// ------------------------------------------------------------------
// exemple-buffers.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char string[10];

	fprintf(stdout, "1 stdout : ligne + \\n\n");
	fprintf(stdout, "2 stdout : ligne seule");
	fprintf(stderr, "\n3 stderr : avant fflush(stdout)\n");
	fflush(stdout);
	fprintf(stderr, "\n4 stderr : apres fflush (stdout)\n");
	fprintf(stdout, "5 stdout : ligne seule ");
	fprintf(stderr, "\n6 stderr : avant fgets(stdin)\n");
	fgets(string, 10, stdin);
	fprintf(stderr, "\n7 stderr : apres fgets(stdin)\n");

	return EXIT_SUCCESS;
}
