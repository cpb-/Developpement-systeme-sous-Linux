// ------------------------------------------------------------------
// exemple-truncate.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char * argv[])
{
	long longueur;
	if ((argc != 3) || (sscanf(argv[2], "%ld", & longueur) != 1)) {
		fprintf(stderr, "Syntaxe : %s fichier longueur\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (truncate(argv[1], longueur) < 0)
		perror(argv[1]);
	return EXIT_SUCCESS;
}
