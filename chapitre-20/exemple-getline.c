// ------------------------------------------------------------------
// exemple-getline.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char *	chaine;
	size_t	taille;
	ssize_t	retour;
	while (1) {
		taille = 0;
		chaine = NULL;
		retour = getline(& chaine, & taille, stdin);	
		if (retour == -1)
			break;
		fprintf(stdout, "%d caracteres lus\n", retour);
		fprintf(stdout, "%d caracteres alloues\n", taille);
		free(chaine);
	}
	return EXIT_SUCCESS;
}

