// ------------------------------------------------------------------
// exemple-client-anagramme.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/socket.h>

#define BUFFER_SIZE	1024


int parse_args(int argc, char * argv[], int server, struct addrinfo **result);

int main (int argc, char * argv[])
{
	int    sock;
	char   buffer [BUFFER_SIZE];
	int    bytes;
	
	struct addrinfo *results;
	
	if (parse_args(argc, argv, 0, &results) < 0)
		exit(EXIT_FAILURE);

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	if (connect(sock, results->ai_addr, results->ai_addrlen) < 0) {
		perror("connect");
		exit(EXIT_FAILURE);
	}
	freeaddrinfo(results);
	while (1) {
		if (fgets(buffer, 256, stdin) == NULL)
			break;
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		if (write(sock, buffer, strlen(buffer)) < 0) {
			perror("write");
			break;
		}
		if ((bytes = read(sock, buffer, BUFFER_SIZE)) == 0)
			break;
		if (bytes < 0) {
			perror("read");
			break;
		}
		fprintf(stdout, "%s\n", buffer);
	}

	return EXIT_SUCCESS;
}


int parse_args (int argc, char * argv[], int server, struct addrinfo **results)
{
	char *option_list = "a:p:h";
	int   option;
	int   err;	
	char *host  = "localhost";
	char *port = "4000";
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
	hints.ai_socktype = SOCK_STREAM;
	if (server)
		hints.ai_flags = AI_PASSIVE;
	if ((err = getaddrinfo(host, port, &hints, results)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
		return -1;
	}

	return 0;
}

