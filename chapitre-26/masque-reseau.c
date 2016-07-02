// ------------------------------------------------------------------
// masque-reseau.c
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
	int i;
	struct in_addr adresse;
	struct in_addr reseau;
	struct in_addr locale;
	
	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "%s : \n", argv[i]);
		if (inet_aton(argv[i], & adresse) == 0) {
			fprintf(stdout, "  invalide \n");
			continue;
		}
		adresse.s_addr = ntohl (adresse . s_addr);
		if (adresse.s_addr < 0x80000000L) {
			reseau.s_addr = adresse.s_addr & 0xFF000000L;
			locale.s_addr = adresse.s_addr & 0x00FFFFFFL;
		} else if (adresse.s_addr < 0xC0000000L) {
			reseau.s_addr = adresse.s_addr & 0xFFFF0000L;
			locale.s_addr = adresse.s_addr & 0x0000FFFFL;
		} else {
			reseau.s_addr = adresse.s_addr & 0xFFFFFF00L;
			locale.s_addr = adresse.s_addr & 0x000000FFL;
		}
		reseau.s_addr = htonl(reseau.s_addr);
		locale.s_addr = htonl(locale.s_addr);
		fprintf(stdout, "  adresse reseau = %s\n", inet_ntoa(reseau));
		fprintf(stdout, "  adresse locale = %s\n", inet_ntoa(locale));
	}
	return EXIT_SUCCESS;
}

