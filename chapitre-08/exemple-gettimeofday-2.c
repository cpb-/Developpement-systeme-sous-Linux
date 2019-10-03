// ------------------------------------------------------------------
// exemple-gettimeofay-2.c
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
	struct timeval tv[20];
	int i;

	for (i = 0; i < 20; i ++)
		gettimeofday(&(tv[i]), NULL);
	for (i = 0; i < 20; i++)
		fprintf (stdout,"%ld.%06ld\n", tv[i].tv_sec, tv[i].tv_usec);
	return 0;
}

