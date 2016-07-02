// ------------------------------------------------------------------
// exemple-ftell.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	long derniere;
	long position;
	int  caractere;
	
	position = ftell(stdin);
	if (position == -1) {
		perror("ftell");
		exit(EXIT_FAILURE);
	}
	derniere = position;
	while ((caractere = getchar()) != EOF) {
		if (caractere == '\n') {
			position = ftell(stdin);
			if (position == -1) {
				perror("ftell");
				exit(EXIT_FAILURE);
			}
			fprintf(stdout, "%ld ", position - derniere - 1);
			derniere = position;
		}
	}
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}
