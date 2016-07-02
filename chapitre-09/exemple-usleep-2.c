// ------------------------------------------------------------------
// exemple-usleep-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main (int argc, char * argv[])
{
	struct timeval tv_avant;
	struct timeval tv_apres;
	struct timeval tv_duree;
	long int duree_sommeil;
	long int sommeil_voulu;
	int i;

	if ((argc != 2) || (sscanf(argv[1], "%ld", & sommeil_voulu) != 1)) {
		fprintf(stderr, "usage: %s duree_sommeil_en_us\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 10; i ++) {
		gettimeofday(& tv_avant, NULL);
		usleep(sommeil_voulu);
		gettimeofday(& tv_apres, NULL);
		timersub(& tv_apres, & tv_avant, & tv_duree);
		duree_sommeil = tv_duree.tv_sec * 1000000
		               + tv_duree.tv_usec;
	}
	fprintf(stdout, "%ld\n", duree_sommeil);
	return EXIT_SUCCESS;
}
