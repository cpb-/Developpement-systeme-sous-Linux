// ------------------------------------------------------------------
// exemple-getservby.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>

void display_service(char *name, char *proto);

int main (int argc, char * argv[])
{
	int i;
	for (i = 1; i < argc; i ++) {
		display_service(argv[i], "tcp");
		display_service(argv[i], "udp");
	}
	return EXIT_SUCCESS;
}

void display_service(char *name, char *proto)
{
	int    i;
	int    port;
	struct servent *service;

	if (sscanf(name, "%d", &port) == 1)
		service = getservbyport(htons(port), proto);
	else 
		service = getservbyname(name, proto);
	if (service == NULL) {
		fprintf(stdout, "%s / %s : inconnu \n", name, proto);
	} else {
		fprintf(stdout, "%s / %s : %s ( ", name, proto, service->s_name);
		for (i = 0; service->s_aliases[i] != NULL; i ++)
			fprintf(stdout, "%s ", service->s_aliases[i]);
		fprintf(stdout, ") port = %d\n", ntohs(service->s_port));
	}
}

