// ------------------------------------------------------------------
// exemple-demon-anagramme.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>

#include <sys/socket.h>

int  serveur_tcp (const char * service_name);
int  quitter_le_serveur (void);
void traite_connexion (int sock);


int serveur_tcp (const char * nom_service)
{
	int err;
	int sock_serveur;
	int sock_connectee;
	struct addrinfo  hints;
	struct addrinfo *results;

	struct sockaddr_in * addr_in;
	socklen_t length = 0;
	char hostname [NI_MAXHOST];
	char servname [NI_MAXSERV];

	// Creer la socket serveur et lui attribuer un numero de service.
	if ((sock_serveur = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		syslog(LOG_ERR, "socket: %m");
		return -1;
	}

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	if ((err = getaddrinfo(NULL, nom_service,  &hints, &results)) != 0) {
		syslog(LOG_ERR, "getaddrinfo: %s", gai_strerror(err));
		close(sock_serveur);
		return -1;
	}

	err = bind(sock_serveur, results->ai_addr, results->ai_addrlen);
	freeaddrinfo(results);
	if (err < 0) {
		syslog(LOG_ERR, "bind: %m");
		close(sock_serveur);
		return -1;
	}

	// Afficher notre adresse locale.
	length = sizeof(struct sockaddr_in);
	if (getsockname(sock_serveur, (struct sockaddr *) &addr_in, &length) < 0) {
		syslog(LOG_ERR, "getsockname");
		return -1;
	}
	if (getnameinfo((struct sockaddr *) &addr_in, length,
	                hostname, NI_MAXHOST,
	                servname, NI_MAXSERV,
	                NI_NUMERICHOST | NI_NUMERICSERV) == 0) 
		syslog(LOG_INFO, "IP = %s, Port = %s", hostname, servname);

	listen(sock_serveur, 5);

	while (! quitter_le_serveur()) {
		sock_connectee = accept(sock_serveur, NULL, NULL);
		if (sock_connectee < 0) {
			syslog(LOG_ERR, "accept: %m");
			return -1;
		}
		switch (fork()) {
			case 0 : // fils
				close(sock_serveur);
				traite_connexion(sock_connectee);
				exit(EXIT_SUCCESS);
			case -1 :
				syslog(LOG_ERR, "fork: %m");
				return -1;
			default : // pere
				close(sock_connectee);
		}
	}
	return 0;
}

int quitter_le_serveur (void)
{
	return 0;
}

void traite_connexion (int sock)
{
	char buffer[256];
	int  longueur;

	while (1) {
		longueur = read(sock, buffer, 256);
		if (longueur < 0) {
			syslog(LOG_ERR, "read: %m");
			exit(EXIT_SUCCESS);
		}
		if (longueur == 0)
			break;
		buffer[longueur] = '\0';
		strfry(buffer);
		write(sock, buffer, longueur);
	}
	close(sock);
}

int main (int argc, char * argv[])
{
	int i;
	
	chdir("/");
	if (fork() != 0)
		exit(EXIT_SUCCESS);
	setsid();
	if (fork() != 0)
		exit(EXIT_SUCCESS);
	for (i = 0; i < sysconf(_SC_OPEN_MAX); i ++)
		close(i);
	serveur_tcp("6000");
	return EXIT_SUCCESS;
}

