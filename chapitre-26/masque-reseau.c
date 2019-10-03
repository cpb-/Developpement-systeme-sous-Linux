// ------------------------------------------------------------------
// masque-reseau.c
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
	struct in_addr network;
	struct in_addr local;
	
	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "%s : \n", argv[i]);
		if (inet_aton(argv[i], & address) == 0) {
			fprintf(stdout, "  invalide \n");
			continue;
		}
		address.s_addr = ntohl (address . s_addr);
		if (address.s_addr < 0x80000000L) {
			network.s_addr = address.s_addr & 0xFF000000L;
			local.s_addr = address.s_addr & 0x00FFFFFFL;
		} else if (address.s_addr < 0xC0000000L) {
			network.s_addr = address.s_addr & 0xFFFF0000L;
			local.s_addr = address.s_addr & 0x0000FFFFL;
		} else {
			network.s_addr = address.s_addr & 0xFFFFFF00L;
			local.s_addr = address.s_addr & 0x000000FFL;
		}
		network.s_addr = htonl(network.s_addr);
		local.s_addr = htonl(local.s_addr);
		fprintf(stdout, "  addresse reseau = %s\n", inet_ntoa(network));
		fprintf(stdout, "  addresse locale = %s\n", inet_ntoa(local));
	}

	return EXIT_SUCCESS;
}

