// ------------------------------------------------------------------
// exemple-crypt-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>

int main (int argc, char * argv[])
{
	char *	cryptage;
	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s mot_passe bouillie\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	cryptage = crypt(argv[1], argv[2]);
	if (strcasecmp(cryptage, argv[2]) == 0)
		fprintf(stdout, "Verification Ok\n");
	else
		fprintf(stdout, "Mauvais mot de passe\n");
	return EXIT_SUCCESS;
}
