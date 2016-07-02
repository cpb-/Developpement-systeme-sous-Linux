// ------------------------------------------------------------------
// exemple-atoi.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	char chaine [128];
	while (fgets(chaine, 128, stdin) != NULL)
		fprintf(stdout, "Lu : %d \n", atoi(chaine));
	return EXIT_SUCCESS;
}

