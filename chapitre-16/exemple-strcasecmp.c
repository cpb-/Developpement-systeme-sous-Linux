// ------------------------------------------------------------------
// exemple-strcasecmp.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[])
{
	int	compar;

	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s chaine_1 chaine_2\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	compar = strcasecmp(argv[1], argv[2]);
	fprintf(stdout, "%s  %c %s \n", argv[1],
			(compar > 0 ? '>' : (compar == 0 ? '=' :  '<' )),
			argv[2]);
			
	return EXIT_SUCCESS;
}

