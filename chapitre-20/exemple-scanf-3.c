// ------------------------------------------------------------------
// exemple-scanf-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int i;
	do {
		printf("Veuillez entrer un entier : ");
	} while (scanf("%d", & i) != 1);
	printf ("Ok, vous avez saisi : %d\n", i);
	return EXIT_SUCCESS;
}
