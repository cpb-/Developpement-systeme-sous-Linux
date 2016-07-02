// ------------------------------------------------------------------
// exemple-qsort.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int compare_entiers (const void * elem_1, const void * elem_2)
{
	return * ((int *)elem_1) - * ((int *)elem_2);
}


#define NB_ENTIERS 100

int main (void)
{
	int	table_entiers[NB_ENTIERS];
	int	i;

	for (i = 0; i < NB_ENTIERS; i ++) {
		/* On limite un peu la taille des entiers pour l'affichage */
		table_entiers[i] = rand() & 0xFFFF;
		fprintf(stdout, "%05d ", table_entiers[i]);
	}
	fprintf(stdout, "\n\n");

	qsort(table_entiers, NB_ENTIERS, sizeof(int), compare_entiers);

	for (i = 0; i < NB_ENTIERS; i ++)
		fprintf(stdout, "%05d ", table_entiers[i]);
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}

