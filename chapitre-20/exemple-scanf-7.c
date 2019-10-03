// ------------------------------------------------------------------
// exemple-scanf-7.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char string[128];
	int i;

	fprintf(stdout, "Entrez un entier : ");
	fgets(string, 128, stdin);
	if (sscanf(string, "%d\n", & i) == 1)
		fprintf(stdout, "Ok i=%d\n", i);
	else
		fprintf(stdout, "Erreur\n");

	return EXIT_SUCCESS;
}
