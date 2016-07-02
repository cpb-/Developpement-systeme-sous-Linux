// ------------------------------------------------------------------
// exemple-calloc-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define	NB_MEGA	3000

int main (void)
{
	int	i;
	char *	bloc[NB_MEGA];

	for (i = 0; i < NB_MEGA; i ++) {
		if ((bloc[i] = calloc(1, 1024*1024)) == NULL) {
			fprintf(stderr, "Echec pour i = %d\n", i);
			break;
		}
	}
	fprintf(stderr, "Allocation : %d blocs de 1 Mo\n", i);
	
	return EXIT_SUCCESS;
}

