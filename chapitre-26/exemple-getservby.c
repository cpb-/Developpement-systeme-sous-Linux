// ------------------------------------------------------------------
// exemple-getservby.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netdb.h>

void affiche_service(char * nom, char * proto);

int main (int argc, char * argv[])
{
	int i;
	for (i = 1; i < argc; i ++) {
		affiche_service(argv[i], "tcp");
		affiche_service(argv[i], "udp");
	}
	return EXIT_SUCCESS;
}

void affiche_service (char * nom, char * proto)
{
	int    i;
	int    port;
	struct servent * service;
	if (sscanf(nom, "%d", & port) == 1)
		service = getservbyport(htons(port), proto);
	else 
		service = getservbyname(nom, proto);
	if (service == NULL) {
		fprintf(stdout, "%s / %s : inconnu \n", nom, proto);
	} else {
		fprintf(stdout, "%s / %s : %s ( ", nom, proto, service->s_name);
		for (i = 0; service->s_aliases[i] != NULL; i ++)
			fprintf(stdout, "%s ", service->s_aliases[i]);
		fprintf(stdout, ") port = %d\n", ntohs(service->s_port));
	}
}

