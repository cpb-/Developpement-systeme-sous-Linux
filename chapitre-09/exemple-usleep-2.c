// ------------------------------------------------------------------
// exemple-usleep-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main (int argc, char * argv[])
{
	struct timeval before;
	struct timeval after;
	struct timeval diff;
	long int duration;
	long int sleep_time;

	if ((argc != 2) || (sscanf(argv[1], "%ld", &sleep_time) != 1)) {
		fprintf(stderr, "usage: %s sleep_time_in_us\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	gettimeofday(&before, NULL);
	usleep(sleep_time);
	gettimeofday(&after, NULL);
	timersub(&after, &before, &diff);
	duration = diff.tv_sec * 1000000
	         + diff.tv_usec;
	fprintf(stdout, "%ld\n", duration);
	return EXIT_SUCCESS;
}
