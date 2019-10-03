// ------------------------------------------------------------------
// exemple-serveur-anagramme.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/socket.h>

int  tcp_server(const char * service_name);
int  quit_server(void);
void handle_connection(int sock);


int tcp_server(const char * nom_service)
{
	int err;
	int server_socket;
	int connected_server;
	struct addrinfo  hints;
	struct addrinfo *results;
	struct sockaddr_in * addr_in;
	socklen_t length = 0;
	char hostname [NI_MAXHOST];
	char servname [NI_MAXSERV];

	// Creer la socket serveur et lui attribuer un numero de service.
	if ((server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("socket");
		return -1;
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if ((err = getaddrinfo(NULL, nom_service,  &hints, &results)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
		close(server_socket);
		return -1;
	}

	err = bind(server_socket, results->ai_addr, results->ai_addrlen);
	freeaddrinfo(results);
	if (err < 0) {
		perror("bind");
		close(server_socket);
		return -1;
	}

	// Afficher notre adresse locale.
	fprintf(stdout, "Mon adresse >> ");
	length = sizeof(struct sockaddr_in);
	if (getsockname(server_socket, (struct sockaddr *) &addr_in, &length) < 0) {
		perror ("getsockname");
		return -1;
	}
	if (getnameinfo((struct sockaddr *) &addr_in, length,
	                hostname, NI_MAXHOST,
	                servname, NI_MAXSERV,
	                NI_NUMERICHOST | NI_NUMERICSERV) == 0)
		fprintf (stdout, "IP = %s, Port = %s \n", hostname, servname);

	listen(server_socket, 5);

	while (! quit_server()) {
		connected_server = accept(server_socket, NULL, NULL);
		if (connected_server < 0) {
			perror("accept");
			return -1;
		}
		switch (fork()) {
			case 0 : // enfant
				close(server_socket);
				handle_connection(connected_server);
				exit(EXIT_SUCCESS);
			case -1 :
				perror("fork");
				return -1;
			default : // parent
				close(connected_server);
		}
	}

	return 0;
}


int quit_server (void)
{
	return 0;
}


void handle_connection (int sock)
{
	char buffer[256];
	int  length;

	while (1) {
		length = read(sock, buffer, 256);
		if (length < 0) {
			perror("read");
			exit(EXIT_SUCCESS);
		}
		if (length == 0)
			break;
		buffer[length] = '\0';
		strfry(buffer);
		write(sock, buffer, length);
	}
	close(sock);
}


int main (int argc, char * argv[])
{
	return tcp_server("4000");
}

