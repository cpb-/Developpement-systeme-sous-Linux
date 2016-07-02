// ------------------------------------------------------------------
// exemple-strtof.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE

#include <errno.h>
#include <limits.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char   chaine[128];
	char * debut;
	char * fin;
	float  retour;
	
	setlocale(LC_ALL, "");
	while (fgets(chaine, 128, stdin) != NULL) {
		if (chaine[strlen(chaine) - 1] == '\n')
			chaine[strlen(chaine) - 1] = '\0';
		for (fin = debut = chaine; * fin != '\0'; debut = fin) {
 			errno = 0;
			retour = strtof(debut, & fin);
			if (fin == debut) {
				fprintf(stdout, "Erreur \n");
				break;
			}	
			if (errno == ERANGE)
				fprintf(stdout, "Debordement ! \n");
			else 
				fprintf(stdout, "Lu : %f \n", retour);
		}	
	}
	return EXIT_SUCCESS;
}

