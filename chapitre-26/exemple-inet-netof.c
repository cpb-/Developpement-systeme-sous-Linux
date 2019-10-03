// ------------------------------------------------------------------
// exemple-inet-netof.c
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
	int i;
	struct in_addr address;
	unsigned long int network;
	unsigned long int local;
	
	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "inet_netof(%s) = ", argv[i]);

		if (inet_aton(argv[i], & address) == 0) {
			fprintf(stdout, "invalide \n");
			continue;
		}
		network = inet_netof(address);
		local = inet_lnaof(address);
		fprintf(stdout, "%08lX + %08lX\n", network, local);
	}

	return EXIT_SUCCESS;
}
