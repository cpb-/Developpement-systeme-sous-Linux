// ------------------------------------------------------------------
// exemple-pty.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
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

void copy_input_output(int fd, int sock)
{
	int    max;
	fd_set set;
	char   buffer[4096];
	int    bytes;

	max = sock < fd ? fd : sock;
	while (1) {
		FD_ZERO(&set);
		FD_SET(sock, &set);
		FD_SET(fd, &set);
		if (select(max + 1, &set, NULL, NULL, NULL) < 0)
			break;
		if (FD_ISSET(sock, &set)) {
			if ((bytes = read(sock, buffer, 4096)) >= 0)
				write(fd, buffer, bytes);
			else
				break;
		}
		if (FD_ISSET(fd, &set)) {
			if ((bytes = read(fd, buffer, 4096)) >= 0)
				write(sock, buffer, bytes);
			else
				break;
		}
	}
}


void handle_connection(int sock)
{
	int    master_fd;
	int    slave_fd;
	struct termios stdin_termios;
	struct termios master_termios;
	char * args [2] = { "/bin/sh", NULL };
	char * slave_name;

	if ((master_fd = getpt()) < 0) {
		perror("pas de Pseudo TTY Unix 98 disponibles \n");
		exit(EXIT_FAILURE);
	}
	grantpt(master_fd);
	unlockpt(master_fd);
	slave_name = ptsname(master_fd);

	tcgetattr(STDIN_FILENO, &stdin_termios);
	switch (fork()) {
		case -1 :
			perror("fork");
			exit(EXIT_FAILURE);
		case 0 :
			close(master_fd);
			/* Detachement du terminal de controle precedent */
			setsid();
			/* Ouverture du pseudo-terminal esclave qui devient */
			/* alors le terminal de controle de ce processus.   */
			if ((slave_fd = open(slave_name, O_RDWR)) < 0) {
				perror("open");
				exit(EXIT_FAILURE);
			}
			tcsetattr(slave_fd, TCSANOW, &stdin_termios);
			dup2(slave_fd, STDIN_FILENO);
			dup2(slave_fd, STDOUT_FILENO);
			dup2(slave_fd, STDERR_FILENO);
			execv(args[0], args);
			break;
		default :
			tcgetattr(master_fd, &master_termios);
			cfmakeraw(&master_termios);
			tcsetattr(master_fd, TCSANOW, &master_termios);
			copy_input_output(master_fd, sock);
			exit(EXIT_SUCCESS);
	}
}

int main (void)
{
	int   sock;
	int   sock_2;
	socklen_t   length;
	struct sockaddr_in address;

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	signal(SIGCHLD, SIG_IGN);
	
	memset(& address, 0, sizeof(struct sockaddr));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = 0;
	
	if (bind(sock, (struct sockaddr *) & address, sizeof(address)) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}
	
	length = sizeof(struct sockaddr_in);
	if (getsockname(sock, (struct sockaddr *) & address, & length) < 0) {
		perror("getsockname");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Mon address : IP = %s, Port = %u \n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

	listen(sock, 5);
	while (1) {
		length = sizeof(struct sockaddr_in);
		sock_2 = accept(sock, & address, & length);
		if (sock_2 < 0)
			continue;
		switch (fork()) {
			case 0 : /* fils */
				close(sock);
				handle_connection(sock_2);
				exit(EXIT_SUCCESS);
			default :
				close(sock_2);
				break;
		}
	}
	close(sock);
	return EXIT_SUCCESS;
}


