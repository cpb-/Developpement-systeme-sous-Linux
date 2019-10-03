// ------------------------------------------------------------------
// exemple-getservent-r.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main (void)
{
	struct servent  service;
	struct servent *serv_entry;
	char   buffer [256];
	
	setservent(0);
	while(getservent_r(& service, buffer, 256, &serv_entry) == 0)
		fprintf(stdout, "%s ", service.s_name);
	endservent();
	fprintf(stdout, "\n");

	return EXIT_SUCCESS;
}
