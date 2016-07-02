// ------------------------------------------------------------------
// exemple-strfry.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[])
{
	char * chaine;

	if (argc != 2) {
		fprintf(stderr, "Syntaxe : %s chaine\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	chaine = strdup(argv[1]);
	strfry(chaine);
	fprintf(stdout, "%s\n", chaine);
	return EXIT_SUCCESS;
}

