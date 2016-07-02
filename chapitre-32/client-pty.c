// ------------------------------------------------------------------
// client-pty.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
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

#define LG_BUFFER	1024


int lecture_arguments (int argc, char * argv [], struct sockaddr_in * adresse, char * protocole);

int main (int argc, char * argv[])
{
	int                sock;
	struct sockaddr_in adresse;
	char               buffer[LG_BUFFER];
	int                nb_lus;
	struct termios     termios_stdin, termios_raw;
	
	fd_set  set;
	
	if (lecture_arguments(argc, argv, & adresse, "tcp") < 0)
		exit(EXIT_FAILURE);
	adresse.sin_family = AF_INET;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	if (connect(sock, (struct sockaddr *) & adresse, sizeof(struct sockaddr_in)) < 0) {
		perror("connect");
		exit(EXIT_FAILURE);
	}
	tcgetattr(STDIN_FILENO, & termios_stdin);
	tcgetattr(STDIN_FILENO, & termios_raw);
	cfmakeraw(& termios_raw);
	tcsetattr(STDIN_FILENO, TCSANOW, & termios_raw);

	while (1) {
		FD_ZERO(& set);
		FD_SET(sock, & set);
		FD_SET(STDIN_FILENO, & set);
		if (select(sock + 1, & set, NULL, NULL, NULL) < 0)
			break;
		if (FD_ISSET(sock, & set)) {
			if ((nb_lus = read(sock, buffer, LG_BUFFER)) == 0)
				break;
			write(STDOUT_FILENO, buffer, nb_lus);
		}
		if (FD_ISSET(STDIN_FILENO, & set)) {
			if ((nb_lus = read(STDIN_FILENO, buffer, LG_BUFFER)) == 0)
				break;
			write(sock, buffer, nb_lus);
		}
	}
	tcsetattr(STDIN_FILENO, TCSANOW, & termios_stdin);
	return EXIT_SUCCESS;
}


int lecture_arguments (int argc, char * argv[], struct sockaddr_in * adresse, char * protocole)
{
	char * liste_options = "a:p:h";
	int    option;
	
	char * hote  = "localhost";
	char * port = "2010";

	struct hostent * hostent;
	struct servent * servent;

	int    numero;

	while ((option = getopt(argc, argv, liste_options)) != -1) {
		switch (option) {
			case 'a' :
				hote  = optarg;
				break;
			case 'p' :
				port = optarg;
				break;
			case 'h' :
				fprintf(stderr, "Syntaxe : %s [-a adresse] [-p port] \n", argv[0]);
				return -1;
			default	: 
				break;
		}
	}
	memset(adresse, 0, sizeof(struct sockaddr_in));
	if (inet_aton(hote, & (adresse->sin_addr)) == 0) {
		if ((hostent = gethostbyname(hote)) == NULL) {
			fprintf(stderr, "hote %s inconnu \n", hote);
			return -1;
		}
		adresse->sin_addr.s_addr = ((struct in_addr *) (hostent->h_addr))->s_addr; 
	}
	if (sscanf(port, "%d", & numero) == 1) {
		adresse->sin_port = htons(numero);
		return 0;
	}
	if ((servent = getservbyname(port, protocole)) == NULL) {
		fprintf(stderr, "Service %s inconnu \n", port);
		return -1;
	}
	adresse->sin_port = servent->s_port;
	return 0;
}

