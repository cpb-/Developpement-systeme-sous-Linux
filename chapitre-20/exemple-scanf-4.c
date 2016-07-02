// ------------------------------------------------------------------
// exemple-scanf-4.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char ligne[128];
	int i;
	do {
		printf("Veuillez entrer un entier : ");
		if (fgets(ligne, 128, stdin) == NULL)
			return EXIT_FAILURE;
	} while (sscanf(ligne, "%d", & i) != 1);
	printf ("Ok, vous avez saisi : %d\n", i);
	return EXIT_SUCCESS;
}
