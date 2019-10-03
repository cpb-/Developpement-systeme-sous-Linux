// ------------------------------------------------------------------
// exemple-strcasecmp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[])
{
	int	compare;

	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s string_1 string_2\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	compare = strcasecmp(argv[1], argv[2]);
	fprintf(stdout, "%s  %c %s \n", argv[1],
			(compare > 0 ? '>' : (compare == 0 ? '=' :  '<' )),
			argv[2]);
			
	return EXIT_SUCCESS;
}

