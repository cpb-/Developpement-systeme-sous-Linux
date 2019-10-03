// ------------------------------------------------------------------
// exemple-gethostent.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main (void)
{
	struct hostent *host;

	sethostent(1);
	while ((host = gethostent()) != NULL)
		fprintf(stdout, "%s ", host->h_name);
	fprintf(stdout, "\n");
	endhostent();

	return EXIT_SUCCESS;
}
