// ------------------------------------------------------------------
// exemple-reception-multicast.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
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

#define BUFFER_SIZE	1024

int parse_args(int argc, char * argv[], int server, struct addrinfo **result);

int main (int argc, char * argv[])
{
	int   sock;
	char  buffer[BUFFER_SIZE];
	int   bytes;
	struct addrinfo *results;
	struct ip_mreq   multicast_req;
	
	if (parse_args(argc, argv, 0, &results) < 0)
		exit(EXIT_FAILURE);

	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	if (bind(sock, results->ai_addr, results->ai_addrlen) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}

	multicast_req.imr_multiaddr.s_addr = 
		((struct sockaddr_in *)results->ai_addr)->sin_addr.s_addr;
	multicast_req.imr_interface.s_addr = htons(INADDR_ANY);

	if (setsockopt(sock, IPPROTO_IP, IP_ADD_MEMBERSHIP, & multicast_req, sizeof(struct ip_mreq)) < 0) {
		perror("setsockopt(IP_ADD_MEMBERSHIP)");
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(results);

	setvbuf(stdout, NULL, _IONBF, 0);
	while (1) {
		if ((bytes = recv(sock, buffer, BUFFER_SIZE, 0)) == 0)
			break;
		if (bytes < 0) {
			perror("read");
			break;
		}
		write(STDOUT_FILENO, buffer, bytes);
	}
	return EXIT_SUCCESS;

}



int parse_args(int argc, char * argv[], int server, struct addrinfo **results)
{
	char * option_list = "a:p:h";
	int    option;
	int    err;	
	char * host  = "localhost";
	char * port = "2000";
	struct addrinfo  hints;

	while ((option = getopt(argc, argv, option_list)) != -1) {
		switch (option) {
			case 'a' :
				host  = optarg;
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
	if ((err = getaddrinfo(host, port, &hints, results)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
		return -1;
	}

	return 0;
}

