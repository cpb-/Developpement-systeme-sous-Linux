// ------------------------------------------------------------------
// exemple-strsep.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LG_MAXI	256

int main (void)
{
	char * ligne;
	char * champs;
	int    n, c;
	char * pointeur;

	if ((ligne = malloc(LG_MAXI)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	n = 1;
	while (fgets(ligne, LG_MAXI, stdin) != NULL) {
		fprintf(stdout, "Ligne %d\n", n);
		c = 1;
		pointeur = ligne;
		while (1) {
			champs = strsep(& pointeur, " \t");
			if (champs == NULL)
				break;
			if (champs[0] == '\0')
				continue;
			fprintf(stdout, "  champs %d : %s\n", c, champs);
			c ++;
		}
		n ++;
	}

	return EXIT_SUCCESS;
}
