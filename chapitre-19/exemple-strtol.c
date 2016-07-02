// ------------------------------------------------------------------
// exemple-strtol.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char chaine[128];
	char * fin;
	long retour;
	while (fgets(chaine, 128, stdin) != NULL) {
		retour = strtol(chaine, & fin, 0);
		if (fin == chaine) {
			fprintf(stdout, "Erreur \n");
			continue;
		}	
		if (((retour == LONG_MAX) || (retour == LONG_MIN))
		 && (errno == ERANGE)) {
			fprintf(stdout, "Debordement ! \n");
			continue;
		}
		fprintf(stdout, "Lu : %ld \n", retour);
	}
	return EXIT_SUCCESS;
}
