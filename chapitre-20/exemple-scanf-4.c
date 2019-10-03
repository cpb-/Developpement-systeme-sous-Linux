// ------------------------------------------------------------------
// exemple-scanf-4.c
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

	do {
		printf("Veuillez entrer un entier : ");
		if (fgets(string, 128, stdin) == NULL)
			return EXIT_FAILURE;
	} while (sscanf(string, "%d", & i) != 1);

	printf ("Ok, vous avez saisi : %d\n", i);

	return EXIT_SUCCESS;
}
