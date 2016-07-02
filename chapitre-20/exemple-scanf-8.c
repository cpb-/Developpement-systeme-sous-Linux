// ------------------------------------------------------------------
// exemple-scanf-8.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE	/* pour avoir getline() */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char *	ligne;
	size_t 	taille;

	int	position;
	int	type_champ;
	int	entier;
	float	reel;

	while (1) {
		fprintf(stdout, "<type> <valeur> :\n");
		ligne = NULL;
		taille = 0;
		if (getline(& ligne, & taille, stdin) == -1)
			break;
		if (sscanf(ligne, "%d %n", & type_champ, & position) != 1) {
			fprintf(stdout, "Entrez le type (0=int, 1=float) "
					 "suivi de la valeur\n");
			free(ligne);
			continue;
		}
		if (type_champ == 0) {
			if (sscanf(& (ligne[position]), "%d", &entier) != 1)
				fprintf(stdout, "Valeur entiere attendue\n");
			else
				fprintf(stdout, "Ok : %d\n", entier);
		} else if (type_champ == 1) {
			if (sscanf(& (ligne[position]), "%f", & reel) != 1)
				fprintf(stdout, "Valeur reelle attendue\n");
			else
				fprintf(stdout, "Ok : %e\n", reel);
		} else {
			fprintf(stdout, "Type inconnu (0 ou 1)\n");
		}
		free(ligne);
	}
	return EXIT_SUCCESS;
}
