// ------------------------------------------------------------------
// exemple-reception-multicast.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#include <sys/types.h>
#include <sys/socket.h>

#define LG_BUFFER	1024

int lecture_arguments (int argc, char * argv[], int server, struct addrinfo **result);

int main (int argc, char * argv[])
{
	int   sock;
	char  buffer[LG_BUFFER];
	int   nb_lus;
	struct addrinfo *results;
	struct ip_mreq     requete_multicast;
	
	if (lecture_arguments(argc, argv, 0, &results) < 0)
		exit(EXIT_FAILURE);

	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	if (bind(sock, results->ai_addr, results->ai_addrlen) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}

	requete_multicast.imr_multiaddr.s_addr = 
		((struct sockaddr_in *)results->ai_addr)->sin_addr.s_addr;
	requete_multicast.imr_interface.s_addr = htons(INADDR_ANY);

	if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, & requete_multicast, sizeof(struct ip_mreq)) < 0) {
		perror("setsockopt(IP_ADD_MEMBERSHIP)");
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(results);

	setvbuf(stdout, NULL, _IONBF, 0);
	while (1) {
		if ((nb_lus = recv(sock, buffer, LG_BUFFER, 0)) == 0)
			break;
		if (nb_lus < 0) {
			perror("read");
			break;
		}
		write(STDOUT_FILENO, buffer, nb_lus);
	}
	return EXIT_SUCCESS;
}

int lecture_arguments (int argc, char * argv[], int server, struct addrinfo **results)
{
	char * liste_options = "a:p:h";
	int    option;
	int    err;	
	char * hote  = "localhost";
	char * port = "2000";

	struct addrinfo  hints;

	while ((option = getopt(argc, argv, liste_options)) != -1) {
		switch (option) {
			case 'a' :
				hote  = optarg;
				break;
			case 'p' :
				port = optarg;
				break;
			case 'h' :
				fprintf(stderr, "Syntaxe : %s [-a adresse] [-p port] \n",
						argv[0]);
				return -1;
			default	: 
				break;
		}
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	if (server)
		hints.ai_flags = AI_PASSIVE;
	if ((err = getaddrinfo(hote, port, &hints, results)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
		return -1;
	}
	return 0;
}

