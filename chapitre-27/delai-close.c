// ------------------------------------------------------------------
// delai-close.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/socket.h>

int lecture_arguments (int argc, char * argv[], int server, struct addrinfo **result);

int main (int argc, char * argv[])
{
	int    sock;
	time_t debut;
	time_t fin;
	struct addrinfo *results;
	
	if (lecture_arguments(argc, argv, 1, &results) < 0)
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
	time(& debut);
	while (1) {
		if (bind(sock, results->ai_addr, results->ai_addrlen) == 0)
			break;
		if (errno != EADDRINUSE) {
			perror("bind 2");
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}
	time(& fin);
	fprintf(stdout, "Duree de persistance apres fermeture : %ld \n", fin - debut);
	return 0;
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
	hints.ai_socktype = SOCK_STREAM;
	if (server)
		hints.ai_flags = AI_PASSIVE;
	if ((err = getaddrinfo(hote, port, &hints, results)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
		return -1;
	}
	return 0;
}

