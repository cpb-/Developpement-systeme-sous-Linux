// ------------------------------------------------------------------
// exemple-getaddrinfo.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2015-2016 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int main (int argc, char * argv [])
{
	char host[NI_MAXHOST];
	struct addrinfo *result;
	struct addrinfo *info;
	struct addrinfo  hints;
	int i;
	int err;

	for (i = 1; i < argc; i ++) {
		memset(&hints, 0, sizeof(hints));
		hints.ai_family = AF_INET;
		hints.ai_socktype = 0;
		hints.ai_protocol = 0;
		hints.ai_flags = AI_NUMERICHOST;
		fprintf(stdout, "%s : ", argv[i]);
		err = getaddrinfo(argv[i], NULL, &hints, & result);
		if (err != 0) {
			fprintf(stdout, "%s\n", gai_strerror(err));
			continue;
		} else {
			for (info = result; info != NULL; info = info->ai_next) {
				getnameinfo(info->ai_addr, info->ai_addrlen,
				            host, sizeof(host), NULL, 0, 0);
				fprintf(stdout, "%s ", host);
			}
			freeaddrinfo(result);
		}
		fprintf(stdout, "\n");
	}
	return EXIT_SUCCESS;
}

