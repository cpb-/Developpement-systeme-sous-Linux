// ------------------------------------------------------------------
// exemple-pthread-exit-2.c
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
	pthread_t thr[3];
	long n;

	for (n = 0; n < 3; n ++) {
		if (pthread_create(&thr[n], NULL, thread_function, (void *)n) != 0) {
			fprintf(stderr, "Error during pthread_create()\n");
			exit(EXIT_FAILURE);
		}
	}
	pthread_exit(NULL);
}


void *thread_function(void *arg)
{
	long num = (long) arg;

	while (1) {
		fprintf(stderr, "Thread #%ld\n", num);
		sleep(1);
	}
}

