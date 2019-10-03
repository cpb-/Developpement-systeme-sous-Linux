// ------------------------------------------------------------------
// exemple-malloc-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	NB_BLOCKS 2000

int main (void)
{

	int	i;
	char *	block[NB_BLOCKS];

	for (i = 0; i < NB_BLOCKS; i ++) {
		if ((block[i] = malloc(1024*1024)) == NULL) {
			fprintf(stderr, "Failed for i = %d\n", i);
			break;
		}
	}
	fprintf(stderr, "Allocated: %d blocks\n", i);

	fprintf(stderr, "Writing into the blocks...\n");

	for (i = 0; i < NB_BLOCKS; i ++) {
		memset(block[i], 1, 1024*1024);
		fprintf(stderr, "%d ", i);
	}	

	return EXIT_SUCCESS;
}

