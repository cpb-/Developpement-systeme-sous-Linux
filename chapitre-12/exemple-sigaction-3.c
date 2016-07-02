// ------------------------------------------------------------------
// exemple-sigaction-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void gestionnaire (int inutilise)
{
}

int main (void)
{
	struct sigaction action;

	signal(SIGUSR1, gestionnaire);
	sigaction(SIGUSR1, NULL, & action);
	
	if (action.sa_handler == gestionnaire)
		fprintf(stdout, "Meme adresse\n");
	else
		fprintf(stdout, "Adresse differente\n");

	return EXIT_SUCCESS;
}
