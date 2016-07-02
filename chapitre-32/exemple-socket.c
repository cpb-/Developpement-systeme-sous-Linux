// ------------------------------------------------------------------
// exemple-socket.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

void gestionnaire (int numero)
{
	exit(EXIT_SUCCESS);
}

void traite_connexion (int fd)
{
	char chaine[MAX_CANON];
	char * fin;
	FILE * fp;
	
	if ((fp = fdopen(fd, "r+")) == NULL) {
		perror("fdopen");
		exit(EXIT_FAILURE);
	}
	
	if (! isatty(fd)) {
		strcpy(chaine, "Vous n'etes pas connecte sur un terminal ! \n");
		write(fd, chaine, strlen(chaine));
	}
	dup2(fd, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);

	while (1) {
		fprintf(stderr, "->");
		if (fgets(chaine, MAX_CANON, fp) == NULL)
			break;
		if ((fin = strpbrk(chaine, "\n\r")) != NULL)
			fin[0] = '\0';
		if (strcasecmp(chaine, "fin") == 0) {
			kill(getppid(), SIGINT);
			exit(EXIT_SUCCESS);
		}
		system(chaine);
	}
	exit(EXIT_SUCCESS);
}


int main (void)
{
	int                sock;
	int                sock_2;
	struct sockaddr_in adresse;
	socklen_t          longueur;

	if (signal(SIGINT, gestionnaire) != 0) {
		perror("signal");
		exit(EXIT_FAILURE);
	}
	
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	
	memset(& adresse, 0, sizeof(struct sockaddr));
	adresse.sin_family = AF_INET;
	adresse.sin_addr . s_addr = htonl(INADDR_ANY);
	adresse.sin_port = 0;
	
	if (bind(sock, (struct sockaddr *) & adresse, sizeof(adresse)) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}
	
	longueur = sizeof(struct sockaddr_in);
	if (getsockname(sock, (struct sockaddr *) & adresse, & longueur) < 0) {
		perror("getsockname");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Mon adresse : IP = %s, Port = %u \n",
			inet_ntoa(adresse.sin_addr),
			ntohs(adresse.sin_port));

	listen(sock, 5);
	while (1) {
		longueur = sizeof(struct sockaddr_in);
		sock_2 = accept(sock, (struct sockaddr *) & adresse, & longueur);
		if (sock_2 < 0)
			continue;
		switch (fork()) {
			case 0 : /* fils */
				close(sock);
				traite_connexion(sock_2);
				exit(EXIT_SUCCESS);
			default :
				close(sock_2);
				break;
		}
	}
	close(sock);
	return EXIT_SUCCESS;
}

