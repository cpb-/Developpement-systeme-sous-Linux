// ------------------------------------------------------------------
// exemple-crypt-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

int main (int argc, char * argv[])
{
	char *hash;

	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s password hash\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	hash = crypt(argv[1], argv[2]);
	if (strcasecmp(hash, argv[2]) == 0)
		fprintf(stdout, "Verification Ok\n");
	else
		fprintf(stdout, "Bad password\n");

	return EXIT_SUCCESS;
}
