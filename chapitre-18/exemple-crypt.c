// ------------------------------------------------------------------
// exemple-crypt.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>

int main (int argc, char * argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s password salt\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%s\n", crypt(argv[1], argv[2]));
	exit(EXIT_SUCCESS);
}
