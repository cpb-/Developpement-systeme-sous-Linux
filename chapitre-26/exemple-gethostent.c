// ------------------------------------------------------------------
// exemple-gethostent.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main (void)
{
	struct hostent * hote;
	sethostent(1);
	while ((hote = gethostent()) != NULL)
		fprintf(stdout, "%s ", hote->h_name);
	fprintf(stdout, "\n");
	endhostent();
	return EXIT_SUCCESS;
}
