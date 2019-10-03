// ------------------------------------------------------------------
// exemple-strfry.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[])
{
	char *string;

	if (argc != 2) {
		fprintf(stderr, "Syntax: %s string\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	string = strdup(argv[1]);
	strfry(string);
	fprintf(stdout, "%s\n", string);

	return EXIT_SUCCESS;
}

