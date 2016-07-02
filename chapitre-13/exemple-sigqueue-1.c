// ------------------------------------------------------------------
// exemple-sigqueue-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void usage(const char * nom)
{
	fprintf(stderr, "usage: %s [-signal] [valeur] pid\n", nom);
	exit(EXIT_FAILURE);
}

int main (int argc, char * argv [])
{
	int   numero;
	int   pid;
	union sigval valeur;

	switch(argc) {
		case 4:
			if (sscanf(argv[1], "%d", & numero) != 1)
				usage(argv[0]);
			if (sscanf(argv[2], "%d", & valeur.sival_int) != 1)
				usage(argv[0]);
			if (sscanf(argv[3], "%d", & pid) != 1)
				usage(argv[0]);
			if (numero >= 0)
				usage(argv[0]);
			break;
		case 3:
			if (sscanf(argv[1], "%d", & numero) != 1)
				usage(argv[0]);
			if (sscanf(argv[2], "%d", & pid) != 1)
				usage(argv[0]);
			if (numero >= 0) {
				valeur.sival_int = numero;
				numero = -SIGTERM;
			} else {
				valeur.sival_int = 0;
			}
			break;
		case 2 : 
			if (sscanf(argv[2], "%d", & pid) != 1)
				usage(argv[0]);
			numero = -SIGTERM;
			valeur.sival_int = 0;
			break;
		default:
			usage(argv[0]);
	}
	if (sigqueue((pid_t) pid, -numero, valeur) < 0) {
		perror("sigqueue");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

