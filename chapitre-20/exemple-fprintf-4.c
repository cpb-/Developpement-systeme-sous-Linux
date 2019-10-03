// ------------------------------------------------------------------
// exemple-fprintf-4.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int width;
	int precision;

	for (width = 1; width < 10; width ++)
		fprintf(stdout, "|%*d|\n", width, width);
	for (precision = 0; precision < 10; precision ++)
			fprintf(stdout, "|%.*d|\n", precision, precision);

	return EXIT_SUCCESS;
}


