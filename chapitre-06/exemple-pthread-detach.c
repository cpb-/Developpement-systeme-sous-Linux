// ------------------------------------------------------------------
// exemple-pthread-detach-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_function(void *arg);

int main (int argc, char *argv[])
{
	pthread_t thr; /* La meme variable sera ecrasee a chaque fois */
	int nb_started = 0;

	while (pthread_create(&thr, NULL, thread_function, NULL) == 0) {
		pthread_detach(thr);
		nb_started ++;
		if ((nb_started % 100) == 0)
			fprintf(stdout, "%d thread started\n", nb_started);
	}
	fprintf(stderr, "Failure after %d threads\n", nb_started);

	return EXIT_SUCCESS;
}


void *thread_function(void *arg)
{
	return NULL;
}

