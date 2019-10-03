// ------------------------------------------------------------------
// exemple-inet-aton.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main (int argc, char * argv[])
{
	struct in_addr address;
	int    i;

	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "inet_aton(%s) = ", argv[i]);
		if (inet_aton(argv[i], & address) == 0) {
			fprintf(stdout, "invalide \n");
			continue;
		}
		fprintf(stdout, "%08X \n", ntohl(address.s_addr));
		fprintf(stdout, "inet_addr (%s) = ", argv[i]);
		if ((address.s_addr = inet_addr(argv[i])) == INADDR_NONE) {
			fprintf(stdout, "invalide \n");
			continue;
		}
		fprintf(stdout, "%08X \n", ntohl(address.s_addr));
		fprintf(stdout, "inet_ntoa (%08X) = %s \n", ntohl(address.s_addr), inet_ntoa(address));
	}

	return EXIT_SUCCESS;
}

