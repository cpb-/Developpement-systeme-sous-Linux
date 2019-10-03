// ------------------------------------------------------------------
// exemple-pthread-exit-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2019 - Christophe BLAESS <christophe@blaess.fr>
// https://www.blaess.fr/christophe/
// ------------------------------------------------------------------

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *thread_function(void *arg);

int main (void)
{
	pthread_t thr;

	if (pthread_create(& thr, NULL, thread_function, NULL) != 0) {
		fprintf(stderr, "Error during pthread_create()\n");
		exit(EXIT_FAILURE);
	}
	while (1) {
		fprintf(stderr, "Main thread running\n");
		sleep(1);
	}
}

void *thread_function(void *arg)
{
	char *ptr = NULL;

	sleep(4);
	ptr[0] = 'A';
	return NULL;
}

