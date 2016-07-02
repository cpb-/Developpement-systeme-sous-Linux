// ------------------------------------------------------------------
// exemple-strncat.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LG_MAXI	32	/* 20 + 12, cf plus bas */

int main (int argc, char * argv[])
{
	int	 i;
	int	 taille;
	char chaine[LG_MAXI + 1];

	strcpy(chaine, "Arguments : "); /* deja 12 caracteres */

	for (i = 1; i < argc; i ++) {
		taille = strlen(chaine);
		strncat(chaine, argv[i], LG_MAXI - taille);
	}
	fprintf(stdout, "%s\n", chaine);
	return EXIT_SUCCESS;
}

