// ------------------------------------------------------------------
// exemple-strtok-r.c
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
	char	* ligne;
	char	* champs;
	int	n, c;
	char * pointeur;

	if ((ligne = malloc(LG_MAXI)) == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	n = 1;
	while (fgets(ligne, LG_MAXI, stdin) != NULL) {
		fprintf(stdout, "Ligne %d\n", n);
		c = 1;
		champs = strtok_r(ligne, " \t", & pointeur);
		while (champs != NULL) { 
			fprintf(stdout, "  champs %d : %s\n", c, champs);
			champs = strtok_r(NULL, " \t", & pointeur);
			c ++;
		}
		n ++;
	}
	return EXIT_SUCCESS;
}
