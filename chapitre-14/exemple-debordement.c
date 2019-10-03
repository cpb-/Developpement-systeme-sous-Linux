// ------------------------------------------------------------------
// exemple-debordement.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	char *string;

	if (argc < 2) {
		fprintf(stderr, "usage: %s string\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "Allocation de la memoire...\n");
	string = malloc(strlen(argv[1]));
	fprintf(stderr, "Copie de la chaine...\n");
	strcpy(string, argv[1]);
	fprintf(stderr, "Affichage de la chaine\n");
	fprintf(stderr, "   %s\n", string);
	fprintf(stderr, "Liberation de la chaine\n");
	free(string);
	fprintf(stderr, "Fin du programme\n");
	return EXIT_SUCCESS;
}


