// ------------------------------------------------------------------
// exemple-getservent-r.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main (void)
{
	struct servent   service;
	struct servent * retour;
	char   buffer [256];
	
	setservent(0);
	while(getservent_r(& service, buffer, 256, & retour) == 0)
		fprintf(stdout, "%s ", service.s_name);
	endservent();
	fprintf(stdout, "\n");
	return EXIT_SUCCESS;
}
