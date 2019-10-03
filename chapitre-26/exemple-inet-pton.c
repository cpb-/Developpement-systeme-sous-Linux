// ------------------------------------------------------------------
// exemple-inet-pton.c
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
	struct in6_addr address_6;
	struct in_addr  address_4;
	int  i;
	char buffer [256];

	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "inet_pton(%s) = ", argv[i]);
		if (inet_pton(AF_INET6, argv[i], & address_6) != 0) {
			fprintf(stdout, "IPv6 : ");
			inet_ntop(AF_INET6, & address_6, buffer, 256);
			fprintf(stdout, "inet_ntop() = %s \n", buffer);
			continue;
		}
		if (inet_pton(AF_INET, argv[i], & address_4) != 0) {
			fprintf(stdout, "IPv4 : ");
			inet_ntop(AF_INET, & address_4, buffer, 256);
			fprintf(stdout, "inet_ntop() = %s \n", buffer);
			continue;
		}
		fprintf(stdout, "invalide \n");
	}

	return EXIT_SUCCESS;
}
