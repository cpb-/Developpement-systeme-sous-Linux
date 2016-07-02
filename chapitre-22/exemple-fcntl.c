// ------------------------------------------------------------------
// exemple-fcntl.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main (int argc, char * argv[])
{
	char    numero[5];
	int	fd;
	int	etat;
	if ((argc != 2) 
	 || ((strcasecmp(argv[1], "ferme") != 0)
	  && (strcasecmp(argv[1], "laisse") != 0))) {
		fprintf(stderr, "syntaxe : %s [ferme|laisse]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	fd = open("essai.fcntl", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	write(fd, "AZERTYUIOP", 10);
	if ((etat = fcntl(fd, F_GETFD)) < 0) {	
		perror("fcntl");
		exit(EXIT_FAILURE);
	}
	if (strcasecmp(argv[1] , "ferme") == 0)
		etat |= FD_CLOEXEC;
	else 
		etat &= ~FD_CLOEXEC;
	if (fcntl(fd, F_SETFD, etat) < 0) {
		perror("fcntl");
		exit(EXIT_FAILURE);
	}
	snprintf(numero, 5, "%d", fd);
	execlp("./verifie-descripteur", "./verifie-descripteur", numero, NULL);
	perror("execlp");
	exit(EXIT_FAILURE);
}
