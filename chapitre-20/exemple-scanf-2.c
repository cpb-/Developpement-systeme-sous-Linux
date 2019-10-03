// ------------------------------------------------------------------
// exemple-scanf-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
	
int main (void)
{
	int i, j, k;

	if (fscanf(stdin, "i = %d j = %d k = %d", & i, & j, & k) == 3)
		fprintf(stdout, "Ok (%d, %d, %d)\n", i, j, k);
	else
		fprintf(stdout, "Erreur\n");

	return EXIT_SUCCESS;
}
