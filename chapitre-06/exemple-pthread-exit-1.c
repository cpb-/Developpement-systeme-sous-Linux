// ------------------------------------------------------------------
// exemple-pthread-exit-1.c
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
		if (pthread_create(&thr[n], NULL, thread_function, (void *) n) != 0) {
			fprintf(stderr, "Error during pthread_create()\n");
			exit(EXIT_FAILURE);
		}
	}
	while (1) {
		fprintf(stderr, "Main thread\n");
		sleep(1);
	}
}

void *thread_function(void *arg)
{
	long num = (long) arg;
	int i = 0;

	while (1) {
		fprintf(stderr, "Thread #%ld, loop #%d\n", num, i);
		if ((num == 0) && (i == 1))
			pthread_exit(NULL);
		if ((num == 1) && (i == 3))
			return NULL;
		i ++;
		sleep(1);
	}
}

