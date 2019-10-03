// ------------------------------------------------------------------
// exemple-gethostby.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>

int main (int argc, char * argv [])
{
	struct in_addr  address_4;
	struct in6_addr address_6;
	struct hostent     *host;
	struct in_addr     *ip_4;
	struct in6_addr    *ip_6;
	char   buffer[256];
	int    i, j;

	for (i = 1; i < argc; i ++) {
		fprintf(stdout, "%s : ", argv[i]);
		// Verifions d'abord s'il s'agit d'une adresse en notation pointee IPv4
		if (inet_aton(argv [i], & address_4) != 0) {
			// On recupere la structure hostent
			if ((host = gethostbyaddr((char *) & address_4, sizeof(struct in_addr), AF_INET)) == 0) {
				fprintf(stdout, "??? \n");
				continue;
			}
		// Sinon on recherche une adresse IPv6	
		} else if (inet_pton(AF_INET6, argv[i], & address_6) != 0) {
			if ((host = gethostbyaddr((char *) & address_6, sizeof(struct in6_addr), AF_INET6)) == 0) {
				fprintf(stdout, "??? \n");
				continue;
			}
		} else {
			// On interroge la resolution de noms
			if ((host = gethostbyname(argv[i])) == NULL) {
				fprintf(stdout, "??? \n");
				continue;
			}
		}
		// On peut afficher le contenu de la structure hostent
		fprintf (stdout, "%s (", host->h_name);
		for (j = 0; host->h_aliases[j] != NULL; j ++)
			fprintf(stdout, " %s", host->h_aliases[j]);
		fprintf(stdout, " ) : ");
		if (host->h_addrtype == AF_INET6) {
			for (j = 0; host->h_addr_list[j] != NULL; j ++) {
				ip_6 = (struct in6_addr *) (host->h_addr_list[j]);
				inet_ntop(AF_INET6, ip_6, buffer, 256);
				fprintf(stdout, "%s ", buffer);
			}
		} else {
			for (j = 0; host->h_addr_list[j] != NULL; j ++) {
				ip_4 = (struct in_addr *) (host->h_addr_list[j]);
				fprintf(stdout, "%s ", inet_ntoa(* ip_4));
			}
		}
		fprintf(stdout, "\n");
	}

	return EXIT_SUCCESS;
}

