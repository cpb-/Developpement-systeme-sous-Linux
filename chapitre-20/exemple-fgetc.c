// ------------------------------------------------------------------
// exemple-fgetc.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int i;
	while ((i = fgetc(stdin)) != EOF)
		fprintf(stdout, " %02X\n", i);
	return EXIT_SUCCESS;
}

