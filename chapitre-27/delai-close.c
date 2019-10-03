// ------------------------------------------------------------------
// delai-close.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/socket.h>

int parse_args(int argc, char * argv[], int server, struct addrinfo **result);

int main (int argc, char * argv[])
{
	int    sock;
	time_t start_time;
	time_t end_time;
	struct addrinfo *results;
	
	if (parse_args(argc, argv, 1, &results) < 0)
		exit(EXIT_FAILURE);

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	if (bind(sock, results->ai_addr, results->ai_addrlen) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}

	listen(sock, 5);
	close(accept(sock, NULL, 0));
	close(sock);
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	time(& start_time);
	while (1) {
		if (bind(sock, results->ai_addr, results->ai_addrlen) == 0)
			break;
		if (errno != EADDRINUSE) {
			perror("bind 2");
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}
	time(& end_time);
	fprintf(stdout, "Duree de persistance apres fermeture : %ld \n", end_time - start_time);

	return 0;
}




int parse_args (int argc, char * argv[], int server, struct addrinfo **results)
{
	char *option_list = "a:p:h";
	int   option;
	int   err;	
	char *host  = "localhost";
	char *port = "2000";

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

