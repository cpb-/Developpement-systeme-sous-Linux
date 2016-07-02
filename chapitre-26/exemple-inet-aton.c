// ------------------------------------------------------------------
// exemple-inet-aton.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main (int argc, char * argv[])
{
	struct in_addr adresse;
	int    i;

	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "inet_aton(%s) = ", argv[i]);
		if (inet_aton(argv[i], & adresse) == 0) {
			fprintf(stdout, "invalide \n");
			continue;
		}
		fprintf(stdout, "%08X \n", ntohl(adresse.s_addr));
		fprintf(stdout, "inet_addr (%s) = ", argv[i]);
		if ((adresse.s_addr = inet_addr(argv[i])) == INADDR_NONE) {
			fprintf(stdout, "invalide \n");
			continue;
		}
		fprintf(stdout, "%08X \n", ntohl(adresse.s_addr));
		fprintf(stdout, "inet_ntoa (%08X) = %s \n", ntohl(adresse.s_addr), inet_ntoa(adresse));
	}
	return EXIT_SUCCESS;
}

