// ------------------------------------------------------------------
// exemple-calloc-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define	NB_Ko	3000000

int main (void)
{
	int	i;
	char ** bloc;
	bloc = calloc(NB_Ko, sizeof(char *));
	if (bloc == NULL) {
		fprintf(stderr, "Echec pour l'allocation du tableau\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < NB_Ko; i ++) {
		if ((bloc[i] = calloc(1, 1024)) == NULL) {
			fprintf(stderr, "Echec pour i = %d\n", i);
			break;
		}
	}
	fprintf(stderr, "Allocation : %d blocs de 1 Ko\n", i);
	
	return EXIT_SUCCESS;
}

