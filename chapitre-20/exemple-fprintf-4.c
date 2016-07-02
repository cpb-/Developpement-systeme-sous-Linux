// ------------------------------------------------------------------
// exemple-fprintf-4.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int largeur;
	int precision;

	for (largeur = 1; largeur < 10; largeur ++)
		fprintf(stdout, "|%*d|\n", largeur, largeur);
	for (precision = 0; precision < 10; precision ++)
			fprintf(stdout, "|%.*d|\n", precision, precision);
	return EXIT_SUCCESS;
}


