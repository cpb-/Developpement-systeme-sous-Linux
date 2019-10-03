// ------------------------------------------------------------------
// exemple-getpass.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	char * string;

	string = getpass("Mot de passe : ");
	fprintf(stdout, "Le mot de passe saisi est \"%s\" \n", string);

	return EXIT_SUCCESS;
}
