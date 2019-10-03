// ------------------------------------------------------------------
// exemple-pthread-attr-1.c
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
	pthread_t thr;
	pthread_attr_t attr;
	int nb_started = 0;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	while (pthread_create(&thr, &attr, thread_function, NULL) == 0) {
		nb_started ++;
		if ((nb_started % 100) == 0)
			fprintf(stderr, "%d threads started\n", nb_started);
	}
	pthread_attr_destroy(& attr);
	fprintf(stderr, "Failure after %d threads\n", nb_started);
	return EXIT_SUCCESS;
}

void *thread_function(void *arg)
{
	return NULL;
}

