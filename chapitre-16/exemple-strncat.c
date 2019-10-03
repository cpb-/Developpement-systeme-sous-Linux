// ------------------------------------------------------------------
// exemple-strncat.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 31	/* 20 + 11, cf plus bas */

int main (int argc, char * argv[])
{
	int	 i;
	int	 size;
	char string[MAX_LENGTH + 1];

	strcpy(string, "Arguments: "); /* deja 11 caracteres */

	for (i = 1; i < argc; i ++) {
		size = strlen(string);
		strncat(string, argv[i], MAX_LENGTH - size);
	}
	fprintf(stdout, "%s\n", string);
	return EXIT_SUCCESS;
}

