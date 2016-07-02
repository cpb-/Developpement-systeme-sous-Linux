// ------------------------------------------------------------------
// exemple-check.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#define NB_CHAR	20

int main (void)
{
	int  i;
	char * table;

	fprintf(stdout, "Allocation de la table\n");	
	table = malloc(NB_CHAR);

	fprintf(stdout, "On deborde vers le haut\n");
	for (i = 0; i <= NB_CHAR; i ++)
		table[i] = 1;
	
	fprintf(stdout, "Liberation de la table\n");
	free(table);

	fprintf(stdout, "Allocation de la table\n");	
	table = malloc(NB_CHAR);

	fprintf(stdout, "On deborde vers le bas\n");
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

	fprintf(stdout, "Et re-liberation de la table !\n");
	free(table);

	return EXIT_SUCCESS;
}

