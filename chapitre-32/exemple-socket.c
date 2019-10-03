// ------------------------------------------------------------------
// exemple-socket.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
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

void sigint_handler(int unused_num)
{
	exit(EXIT_SUCCESS);
}

void handle_connection(int fd)
{
	char string[MAX_CANON];
	char *end;
	FILE *fp;

	if ((fp = fdopen(fd, "r+")) == NULL) {
		perror("fdopen");
		exit(EXIT_FAILURE);
	}

	if (! isatty(fd)) {
		strcpy(string, "Vous n'etes pas connecte sur un terminal ! \n");
		write(fd, string, strlen(string));
	}
	dup2(fd, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	dup2(fd, STDERR_FILENO);

	while (1) {
		fprintf(stderr, "-> ");
		if (fgets(string, MAX_CANON, fp) == NULL)
			break;
		if ((end = strpbrk(string, "\n\r")) != NULL)
			end[0] = '\0';
		if (strcasecmp(string, "end") == 0) {
			kill(getppid(), SIGINT);
			exit(EXIT_SUCCESS);
		}
		system(string);
	}
	exit(EXIT_SUCCESS);
}


int main (void)
{
	int   sock;
	int   sock_2;
	socklen_t  length;
	struct sockaddr_in address;

	if (signal(SIGINT, sigint_handler) != 0) {
		perror("signal");
		exit(EXIT_FAILURE);
	}

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	memset(& address, 0, sizeof(struct sockaddr));
	address.sin_family = AF_INET;
	address.sin_addr . s_addr = htonl(INADDR_ANY);
	address.sin_port = 0;

	if (bind(sock, (struct sockaddr *) &address, sizeof(address)) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}

	length = sizeof(struct sockaddr_in);
	if (getsockname(sock, (struct sockaddr *) &address, &length) < 0) {
		perror("getsockname");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Mon address : IP = %s, Port = %u \n",
			inet_ntoa(address.sin_addr),
			ntohs(address.sin_port));

	listen(sock, 5);
	while (1) {
		length = sizeof(struct sockaddr_in);
		sock_2 = accept(sock, (struct sockaddr *) &address, &length);
		if (sock_2 < 0)
			continue;
		switch (fork()) {
			case 0 :
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

