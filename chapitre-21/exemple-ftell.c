// ------------------------------------------------------------------
// exemple-ftell.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	long last;
	long position;
	int  character;
	
	position = ftell(stdin);
	if (position == -1) {
		perror("ftell");
		exit(EXIT_FAILURE);
	}
	last = position;
	while ((character = getchar()) != EOF) {
		if (character == '\n') {
			position = ftell(stdin);
			if (position == -1) {
				perror("ftell");
				exit(EXIT_FAILURE);
			}
			fprintf(stdout, "%ld ", position - last - 1);
			last = position;
		}
	}
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}
