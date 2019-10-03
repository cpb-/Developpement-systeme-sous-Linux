// ------------------------------------------------------------------
// exemple-getaddrinfo-02.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

int main (int argc, char * argv [])
{
	char service[NI_MAXSERV];
	struct addrinfo *result;
	struct addrinfo *info;
	struct addrinfo  hints;
	int i;
	int err;

	for (i = 1; i < argc; i ++) {
		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		fprintf(stdout, "%s : ", argv[i]);
		err = getaddrinfo(NULL, argv[i], &hints, &result);
		if (err != 0) {
			fprintf(stdout, "ERROR: %s\n", gai_strerror(err));
			continue;
		}
		for (info = result; info != NULL; info = info->ai_next) {
			getnameinfo(info->ai_addr, info->ai_addrlen,
			            NULL, 0, service, NI_MAXSERV, NI_NUMERICSERV);
			fprintf(stdout, "%s ", service);
		}
		freeaddrinfo(result);
		fprintf(stdout, "\n");
	}
	return EXIT_SUCCESS;
}

