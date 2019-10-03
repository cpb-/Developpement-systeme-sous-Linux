// ------------------------------------------------------------------
// exemple-strtol.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char string[128];
	char *end;
	long value;

	while (fgets(string, 128, stdin) != NULL) {
		value = strtol(string, &end, 0);
		if (end == string) {
			fprintf(stdout, "Erreur \n");
			continue;
		}	
		if (((value == LONG_MAX) || (value == LONG_MIN))
		 && (errno == ERANGE)) {
			fprintf(stdout, "Debordement ! \n");
			continue;
		}
		fprintf(stdout, "Lu : %ld \n", value);
	}
	return EXIT_SUCCESS;
}
