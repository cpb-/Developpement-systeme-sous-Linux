// ------------------------------------------------------------------
// exemple-check.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define NB_CHAR	20

int main (void)
{
	int  i;
	char *table;

	fprintf(stdout, "Allocation de la table\n");	
	table = malloc(NB_CHAR);

	fprintf(stdout, "Debordement vers le haut\n");
	for (i = 0; i <= NB_CHAR; i ++)
		table[i] = 1;
	
	fprintf(stdout, "Liberation de la table\n");
	free(table);

	fprintf(stdout, "Allocation de la table\n");	
	table = malloc(NB_CHAR);

	fprintf(stdout, "Debordement vers le bas\n");
	i = NB_CHAR;
	while (i >= 0)
		table[--i] = 1;
	
	fprintf(stdout, "Liberation de la table\n");
	free(table);

	fprintf(stdout, "Allocation de la table\n");	
	table = malloc(NB_CHAR);

	fprintf(stdout, "Ecriture normale\n");
	for (i = 0; i < NB_CHAR; i ++)
		table[i] = 0;

	fprintf(stdout, "Liberation de la table\n");
	free(table);

	fprintf(stdout, "Double liberation de la table !\n");
	free(table);

	return EXIT_SUCCESS;
}

