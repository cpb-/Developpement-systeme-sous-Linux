// ------------------------------------------------------------------
// exemple-atoi.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char string[128];

	while (fgets(string, 128, stdin) != NULL)
		fprintf(stdout, "Lu : %d \n", atoi(string));

	return EXIT_SUCCESS;
}

