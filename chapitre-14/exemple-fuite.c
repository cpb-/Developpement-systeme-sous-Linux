// ------------------------------------------------------------------
// exemple-fuite.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define NB_BLOCS  10
#define TAILLE_BLOC 1024

int main(void)
{
	int i;
	char * ptr[NB_BLOCS];

	fprintf(stderr, "Allocation de %d blocs\n", NB_BLOCS);
	for (i = 0; i < NB_BLOCS; i ++)
		ptr[i] = malloc(TAILLE_BLOC);
	fprintf(stderr, "Utilisation des blocs\n");
	for (i = 0; i < NB_BLOCS; i ++)
		memset(ptr[i], i, TAILLE_BLOC);
	fprintf(stderr, "Liberation des blocs\n");
	for (i = NB_BLOCS - 1; i > 0; i --)
		free(ptr[i]);
	return EXIT_SUCCESS;
}


