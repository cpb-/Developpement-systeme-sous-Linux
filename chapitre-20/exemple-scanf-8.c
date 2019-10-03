// ------------------------------------------------------------------
// exemple-scanf-8.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE	/* pour avoir getline() */

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char   *string;
	size_t  size;
	int     position;
	int     type;
	int     integer;
	float   real;

	while (1) {
		fprintf(stdout, "<type> <valeur> :\n");
		string = NULL;
		size = 0;
		if (getline(&string, &size, stdin) == -1)
			break;
		if (sscanf(string, "%d %n", &type, &position) != 1) {
			fprintf(stdout, "Entrez le type (0=int, 1=float) "
					 "suivi de la valeur\n");
			free(string);
			continue;
		}
		if (type == 0) {
			if (sscanf(&(string[position]), "%d", &integer) != 1)
				fprintf(stdout, "Valeur entiere attendue\n");
			else
				fprintf(stdout, "Ok : %d\n", integer);
		} else if (type == 1) {
			if (sscanf(&(string[position]), "%f", &real) != 1)
				fprintf(stdout, "Valeur reelle attendue\n");
			else
				fprintf(stdout, "Ok : %e\n", real);
		} else {
			fprintf(stdout, "Type inconnu (0 ou 1)\n");
		}
		free(string);
	}
	return EXIT_SUCCESS;
}
