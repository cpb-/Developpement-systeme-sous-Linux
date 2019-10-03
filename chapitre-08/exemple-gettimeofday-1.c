// ------------------------------------------------------------------
// exemple-gettimeofday-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

int main (void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL) != 0) {
		perror("gettimeofday");
		exit(EXIT_FAILURE);
	}
	fprintf (stdout, "time() : %ld \n", time (NULL));
	fprintf (stdout, "gettimeofday() : %ld.%06ld\n",
		tv.tv_sec, tv.tv_usec);
	return 0;
}

