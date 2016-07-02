// ------------------------------------------------------------------
// exemple-atexit.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

void	sortie_1	(void);
void	sortie_2	(void);
void	sortie_3	(void);

int main (void)
{
	if (atexit(sortie_3) != 0)
		fprintf(stderr, "Impossible d'enregistrer sortie_3()\n");
	if (atexit(sortie_2) != 0)
		fprintf(stderr, "Impossible d'enregistrer sortie_2()\n");
	if (atexit(sortie_2) != 0)
		fprintf(stderr, "Impossible d'enregistrer sortie_2()\n");
	if (atexit(sortie_1) != 0)
		fprintf(stderr, "Impossible d'enregistrer sortie_1()\n");
	fprintf(stdout, "Allez... on quitte en revenant de main()\n");
	return EXIT_SUCCESS;
}

void sortie_1 (void)
{
	fprintf(stdout, "Sortie_1 : apelle exit()\n");
	exit(EXIT_SUCCESS);
}

void sortie_2 (void)
{
	fprintf(stdout, "Sortie_2\n");
}

void sortie_3 (void)
{
	fprintf(stdout, "Sortie_3\n");
}

