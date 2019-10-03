// ------------------------------------------------------------------
// exemple-fuite.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NB_BLOCKS  10
#define BLOCK_SIZE 1024

int main(void)
{
	int i;
	char * ptr[NB_BLOCKS];

	fprintf(stderr, "Allocation de %d blocs\n", NB_BLOCKS);
	for (i = 0; i < NB_BLOCKS; i ++)
		ptr[i] = malloc(BLOCK_SIZE);
	fprintf(stderr, "Utilisation des blocs\n");
	for (i = 0; i < NB_BLOCKS; i ++)
		memset(ptr[i], i, BLOCK_SIZE);
	fprintf(stderr, "Liberation des blocs\n");
	for (i = NB_BLOCKS - 1; i > 0; i --)
		free(ptr[i]);
	return EXIT_SUCCESS;
}


