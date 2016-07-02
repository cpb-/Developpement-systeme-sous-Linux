// ------------------------------------------------------------------
// exemple-pty.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE 500

#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

void copie_entrees_sorties (int fd, int sock)
{
	int    max;
	fd_set set;
	char   buffer[4096];
	int    nb_lus;

	max = sock < fd ? fd : sock;
	while (1) {
		FD_ZERO(& set);
		FD_SET(sock, & set);
		FD_SET(fd, & set);
		if (select(max + 1, & set, NULL, NULL, NULL) < 0)
			break;
		if (FD_ISSET(sock, &set)) {
			if ((nb_lus = read(sock, buffer, 4096)) >= 0)
				write(fd, buffer, nb_lus);
			else
				break;
		}
		if (FD_ISSET(fd, &set)) {
			if ((nb_lus = read(fd, buffer, 4096)) >= 0)
				write(sock, buffer, nb_lus);
			else
				break;
		}
	}
}

void traite_connexion (int sock)
{
	int    fd_maitre;
	int    fd_esclave;
	struct termios termios_stdin;
	struct termios termios_maitre;
	char * args [2] = { "/bin/sh", NULL };
	char * nom_esclave;	

	if ((fd_maitre = getpt()) < 0) {
		perror("pas de Pseudo TTY Unix 98 disponibles \n");
		exit(EXIT_FAILURE);
	}
	grantpt(fd_maitre);
	unlockpt(fd_maitre);
	nom_esclave = ptsname(fd_maitre);

	tcgetattr(STDIN_FILENO, & termios_stdin);
	switch (fork()) {
		case -1 :
			perror("fork");
			exit(EXIT_FAILURE);
		case 0 : /* fils */
			close(fd_maitre);
			/* Detachement du terminal de controle precedent */
			setsid();
			/* Ouverture du pseudo-terminal esclave qui devient */
			/* alors le terminal de controle de ce processus.   */
			if ((fd_esclave = open(nom_esclave, O_RDWR)) < 0) {
				perror("open");
				exit(EXIT_FAILURE);
			}
			tcsetattr(fd_esclave, TCSANOW, & termios_stdin);
			dup2(fd_esclave, STDIN_FILENO);
			dup2(fd_esclave, STDOUT_FILENO);
			dup2(fd_esclave, STDERR_FILENO);
			execv(args[0], args);
			break;
		default :
			tcgetattr(fd_maitre, & termios_maitre);
			cfmakeraw(& termios_maitre);
			tcsetattr(fd_maitre, TCSANOW, & termios_maitre);
			copie_entrees_sorties(fd_maitre, sock);
			exit(EXIT_SUCCESS);
	}
}

int main (void)
{
	int                sock;
	int                sock_2;
	struct sockaddr_in adresse;
	socklen_t          longueur;

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	signal(SIGCHLD, SIG_IGN);
	
	memset(& adresse, 0, sizeof(struct sockaddr));
	adresse.sin_family = AF_INET;
	adresse.sin_addr.s_addr = htonl(INADDR_ANY);
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
	fprintf(stdout, "Mon adresse : IP = %s, Port = %u \n", inet_ntoa(adresse.sin_addr), ntohs(adresse.sin_port));

	listen(sock, 5);
	while (1) {
		longueur = sizeof(struct sockaddr_in);
		sock_2 = accept(sock, & adresse, & longueur);
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


