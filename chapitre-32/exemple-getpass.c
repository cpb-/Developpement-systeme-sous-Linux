// ------------------------------------------------------------------
// exemple-getpass.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void)
{
	char * chaine;
	chaine = getpass("Mot de passe : ");
	fprintf(stdout, "Le mot de passe saisi est \"%s\" \n", chaine);
	return EXIT_SUCCESS;
}
