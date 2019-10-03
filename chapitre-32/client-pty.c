// ------------------------------------------------------------------
// client-pty.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

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

#define BUFFER_SIZE    1024


int parse_args(int argc, char *argv [], struct sockaddr_in *address, char *protocol);

int main (int argc, char * argv[])
{
	int                sock;
	struct sockaddr_in address;
	char               buffer[BUFFER_SIZE];
	int                count;
	struct termios     termios_stdin, termios_raw;
	fd_set  set;
	
	if (parse_args(argc, argv, &address, "tcp") < 0)
		exit(EXIT_FAILURE);
	address.sin_family = AF_INET;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	if (connect(sock, (struct sockaddr *) &address, sizeof(struct sockaddr_in)) < 0) {
		perror("connect");
		exit(EXIT_FAILURE);
	}
	tcgetattr(STDIN_FILENO, &termios_stdin);
	tcgetattr(STDIN_FILENO, &termios_raw);
	cfmakeraw(& termios_raw);
	tcsetattr(STDIN_FILENO, TCSANOW, &termios_raw);

	while (1) {
		FD_ZERO(&set);
		FD_SET(sock, &set);
		FD_SET(STDIN_FILENO, &set);
		if (select(sock + 1, &set, NULL, NULL, NULL) < 0)
			break;
		if (FD_ISSET(sock, &set)) {
			if ((count = read(sock, buffer, BUFFER_SIZE)) == 0)
				break;
			write(STDOUT_FILENO, buffer, count);
		}
		if (FD_ISSET(STDIN_FILENO, &set)) {
			if ((count = read(STDIN_FILENO, buffer, BUFFER_SIZE)) == 0)
				break;
			write(sock, buffer, count);
		}
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &termios_stdin);
	return EXIT_SUCCESS;
}


int parse_args (int argc, char *argv[], struct sockaddr_in *address, char *protocol)
{
	char  *option_list = "a:p:h";
	int    option;
	
	char *host  = "localhost";
	char *port = "1234";

	struct hostent *hostent;
	struct servent *servent;

	int num;

	while ((option = getopt(argc, argv, option_list)) != -1) {
		switch (option) {
			case 'a' :
				host  = optarg;
				break;
			case 'p' :
				port = optarg;
				break;
			case 'h' :
				fprintf(stderr, "Syntaxe : %s [-a address] [-p port] \n", argv[0]);
				return -1;
			default	: 
				break;
		}
	}
	memset(address, 0, sizeof(struct sockaddr_in));
	if (inet_aton(host, &(address->sin_addr)) == 0) {
		if ((hostent = gethostbyname(host)) == NULL) {
			fprintf(stderr, "host %s inconnu \n", host);
			return -1;
		}
		address->sin_addr.s_addr = ((struct in_addr *) (hostent->h_addr))->s_addr; 
	}
	if (sscanf(port, "%d", &num) == 1) {
		address->sin_port = htons(num);
		return 0;
	}
	if ((servent = getservbyname(port, protocol)) == NULL) {
		fprintf(stderr, "Service %s inconnu \n", port);
		return -1;
	}
	address->sin_port = servent->s_port;
	return 0;
}

