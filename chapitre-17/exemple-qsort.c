// ------------------------------------------------------------------
// exemple-qsort.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int integer_compare(const void *int_1, const void *int_2)
{
	return *((int *)int_1) - *((int *)int_2);
}


#define NB_INTEGERS 100

int main (void)
{
	int	table[NB_INTEGERS];
	int	i;

	for (i = 0; i < NB_INTEGERS; i ++) {
		/* On limite un peu la taille des entiers pour l'affichage */
		table[i] = rand() & 0xFFFF;
		fprintf(stdout, "%05d ", table[i]);
	}
	fprintf(stdout, "\n\n");

	qsort(table, NB_INTEGERS, sizeof(int), integer_compare);

	for (i = 0; i < NB_INTEGERS; i ++)
		fprintf(stdout, "%05d ", table[i]);
	fprintf(stdout, "\n");

	return EXIT_SUCCESS;
}

