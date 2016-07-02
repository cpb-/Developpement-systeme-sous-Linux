// ------------------------------------------------------------------
// exemple-debordement.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
	char * chaine;
	if (argc < 2) {
		fprintf(stderr, "usage: %s argument\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fprintf(stderr, "Allocation de la memoire...\n");
	chaine = malloc(strlen(argv[1]));
	fprintf(stderr, "Copie de la chaine...\n");
	strcpy(chaine, argv[1]);
	fprintf(stderr, "Affichage de la chaine\n");
	fprintf(stderr, "   %s\n", chaine);
	fprintf(stderr, "Liberation de la chaine\n");
	free(chaine);
	fprintf(stderr, "Fin du programme\n");
	return EXIT_SUCCESS;
}


