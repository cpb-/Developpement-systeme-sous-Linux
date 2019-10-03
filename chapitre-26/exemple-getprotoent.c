// ------------------------------------------------------------------
// exemple-getprotoent.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main (void)
{
	struct protoent *proto;

	setprotoent(0);
	while ((proto = getprotoent()) != NULL)
		fprintf(stdout, "%s ", proto->p_name);
	endprotoent();
	fprintf(stdout, "\n");

	return EXIT_SUCCESS;
}
